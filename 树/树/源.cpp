#include<iostream>

using namespace std;

typedef struct Node
{//定义二叉树结构
	char data;
	struct Node *lchild, *rchild;
}*BiTree, BiTNode;


void CreateBiTree(BiTree &T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		T = nullptr;
	else
	{
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

void InOrderTraverse(BiTree &T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}

//判断两个树是否一样
bool isSameTree(BiTree& p, BiTree& q) {	 
	if (p == nullptr && q == nullptr)
	{
		return true;
	}
	if (p!=nullptr && q!=nullptr &&p->data == q->data)
	{
		return isSameTree(p->lchild, q->lchild) && isSameTree(p->rchild, q->rchild);
		
	}
	else
	{
		return false;
	}
}

//求树的高度
int Depth(BiTree & T)
{
	if (T == nullptr)
	{
		return 0;
	}
	else
	{
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		return m > n ? m + 1 : n + 1;
	}
}

//求树的叶子节点数
int GetleafCount(BiTree &T)
{
	if (T == nullptr)
	{
		return 0;
	}
	else if (T->lchild == nullptr && T->rchild == nullptr)
		return 1;
	return GetleafCount(T->lchild) + GetleafCount(T->rchild);
}
 
//求第K层节点数
int GetKlevelCount(BiTree &T, int k)
{
	if (T == nullptr)
		return 0;
	else if (k == 1)
		return 1;
	else
	{
		return GetKlevelCount(T->lchild, k - 1) + GetKlevelCount(T->rchild, k - 1);
	}
}
 
//度为1的结点数
int Node_1_Count(BiTree &T)
{
	if (T == nullptr)
		return 0;
	if ((!T->lchild) && (T->rchild) || (T->lchild) && (!T->rchild))
		return 1 + Node_1_Count(T->lchild) + Node_1_Count(T->rchild);
	else
		return Node_1_Count(T->lchild) + Node_1_Count(T->rchild);
}

//求二叉树结点个数
int GetNodeCount(BiTree &T)
{
	if (T == nullptr)
	{
		return 0;
	}
	int left = GetNodeCount(T->lchild);
	int right = GetNodeCount(T->rchild);
	return left + right + 1;
}

//打印叶子结点到根结点的路径
void PrintAllPath(BiTree &T,char path[],int pathlen)
{
	if (T != nullptr)
	{
		path[pathlen] = T->data;
		if (T->lchild == nullptr && T->rchild == nullptr)
		{
			for (int i = 0; i <= pathlen; ++i)
			{
				cout << path[i] << " ";
			}
			cout << endl;
		}
		else
		{
			PrintAllPath(T->lchild, path, pathlen + 1);
			PrintAllPath(T->rchild, path, pathlen + 1);
		}
	}
}

//双端遍历
void DoublePrint(BiTree &T)
{
	if(T != nullptr)
	{
		cout << T->data << " ";
		DoublePrint(T->lchild);
		cout << T->data << " ";
		DoublePrint(T->rchild);
	}
}

//左右子树互换位置
void ExchangeNode(BiTree &T)
{
	BiTree temp = T;
	if (T != nullptr)
	{
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
		ExchangeNode(T->lchild);
		ExchangeNode(T->rchild);
	}
}

int main()
{
	BiTree T = nullptr;
	BiTree P = nullptr;
	CreateBiTree(T);
	InOrderTraverse(T);
	cout << endl;
	ExchangeNode(T);
	InOrderTraverse(T);
	system("pause");
	return 0;
}