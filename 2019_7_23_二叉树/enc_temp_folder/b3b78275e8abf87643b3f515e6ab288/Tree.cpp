#include"Tree.h"
#include<stack>
#include<queue>


/*BTNode* CreateBinTree(BTDataType* array, int size) //创建完全二叉树
{
	BTNode *ptree = (BTNode*)malloc(sizeof(BTNode)*size);
	int i;
	for (i = 0; i<size; i++)
	{
	      ptree[i]._data = array[i];//数组a只起到一个赋值的作用
	      ptree[i]._pLeft = NULL;
		  ptree[i]._pRight = NULL;
	}
	for (i = 0; i <= size / 2 - 1; i++)//原来的父亲节点范围为1~n/2,现在0~n/2-1,所以注意n/2要取到等
	{
		 if (2 * i + 1 <= size - 1)
			 ptree[i]._pLeft = &ptree[2 * i + 1];//把第2*i+1个结点的地址赋给左孩子
		 if (2 * i + 2 <= size - 1)
			 ptree[i]._pRight = &ptree[2 * i + 2];
	}
	return ptree;
}*/

BTNode* CreateBinTree(BTDataType* array, int* index)
{
	if (array[*index] == '#')
	{
		return NULL;
	}
	BTNode *node = (BTNode *)malloc(sizeof(BTNode));
	node->_data = array[*index];
	(*index)++;
	node->_pLeft = CreateBinTree(array, index);
	(*index)++;
	node->_pRight = CreateBinTree(array, index);
	return node;
}
BTNode* CopyBinTree(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return NULL;
	}
	BTNode *nRoot = (BTNode *)malloc(sizeof(BTNode));
	nRoot->_data = pRoot->_data;
	nRoot->_pLeft = CopyBinTree(pRoot->_pLeft);
	nRoot->_pRight = CopyBinTree(pRoot->_pRight);
	return nRoot;
}

void DestroyBinTree(BTNode** pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	DestroyBinTree((&(*pRoot)->_pLeft));
	DestroyBinTree((&(*pRoot)->_pRight));
	free(pRoot);
}

void PreOrder(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	printf("%c ", pRoot->_data);
	PreOrder(pRoot->_pLeft );
	PreOrder(pRoot->_pRight);
}

void InOrder(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	PreOrder(pRoot->_pLeft);
	printf("%d", pRoot->_data);
	PreOrder(pRoot->_pRight);
}

void PostOrder(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	PreOrder(pRoot->_pLeft);
	PreOrder(pRoot->_pRight);
	printf("%d", pRoot->_data);
}


void PreOrderNor(BTNode* pRoot)//先序遍历，非递归
{
	if (pRoot == NULL)
	{
		return;
	}
	BTNode *stack[100];
	int stacktop = -1;
	BTNode *pMove = pRoot;
	while (pMove != NULL || stacktop != -1)
	{
		while (pMove != NULL)
		{
			printf("%c ", pMove->_data);
			stack[++stacktop] = pMove;
			pMove = pMove->_pLeft;
		}
		if (stacktop != -1)
		{
			pMove = stack[stacktop--];
			pMove = pMove->_pRight;
		}
	}
}

void InOrderNor(BTNode* pRoot)
{
	BTNode * stack[100];
	int stacktop = -1;
	BTNode * pMove = pRoot;
	while (pMove != NULL || stacktop != -1)
	{
		while (pMove != NULL)
		{
			stack[++stacktop] = pMove;
			pMove = pMove->_pLeft;
		}
		if (stacktop != -1)
		{
			pMove = stack[stacktop--];
			printf("%c ", pMove->_data);
			pMove = pMove->_pRight;
		}
	}
}

void PostOrderNor(BTNode* pRoot)
{
	BTNode *stack[100];
	int stacktop = -1;
	BTNode *pMove = pRoot;
	BTNode *last = NULL;
	while (pMove)
	{
		stack[++stacktop] = pMove;
		pMove = pMove->_pLeft;
	}
	while (stacktop != -1)
	{
		pMove = stack[stacktop--];
		//如果右边为空，或者右边已经被访问过
		if (pMove->_pRight == NULL || pMove->_pRight == last)
		{
			printf("%c ", pMove->_data);
			last = pMove;
		}
		else
		{
			stack[++stacktop] = pMove;
			pMove = pMove->_pRight;
			while (pMove)
			{
				stack[++stacktop] = pMove;
				pMove = pMove->_pLeft;
			}
		}
	}
}
void LevelOrder(BTNode* pRoot)
{
	std::queue<BTNode *> q;
	BTNode *cur = pRoot;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (cur->_pLeft != NULL)
		{
			q.push(cur->_pLeft);
		}
		if (cur->_pRight != NULL)
		{
			q.push(cur->_pRight);
		}
		printf("%c ", cur->_data);
	}
}

int GetNodeCount(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	int left = GetNodeCount(pRoot->_pLeft);
	int right = GetNodeCount(pRoot->_pRight);
	return left + right + 1;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
int Height(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);
	return max(left, right) + 1;
}

int IsBalanceTree(BTNode* pRoot)//判断二叉树是否平衡，(左右高度之差不大于1)
{
	if (pRoot == NULL)
	{
		return 1;
	}
	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);
	int gap = left - right;
	if (gap > 1 || gap < -1)
	{
		return 0;
	}
	//判断其子结点
	return IsBalanceTree(pRoot->_pLeft) && IsBalanceTree(pRoot->_pRight);
}

int GetLeafNodeCount(BTNode* pRoot) // 求叶子结点的个数
{
	if (pRoot == NULL)
	{
		return 0;
	}
	if (pRoot->_pLeft == NULL&&pRoot->_pRight == NULL)
	{
		return 1;
	}
	return GetLeafNodeCount(pRoot->_pLeft) + GetLeafNodeCount(pRoot->_pRight);
}

int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	if (K == 1)
	{
		return 1;
	}
	return GetKLevelNodeCount(pRoot->_pLeft, K - 1) + GetKLevelNodeCount(pRoot->_pRight, K - 1);
}

BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode)
{
	if (pRoot == NULL)
	{
		return NULL;
	}
	if (pRoot == pNode)
	{
		return pRoot;
	}
	GetNodeParent(pRoot->_pLeft, pNode);
	GetNodeParent(pRoot->_pRight, pNode);
	return NULL;
}

void swap(BTNode *a, BTNode *b)
{
	BTNode temp = *a;
	*a = *b;
	*b = temp;
}
BTNode* Mirror(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return NULL;
	}
	swap(pRoot->_pLeft, pRoot->_pRight);
	Mirror(pRoot->_pLeft);
	Mirror(pRoot->_pRight);
	return pRoot;
}