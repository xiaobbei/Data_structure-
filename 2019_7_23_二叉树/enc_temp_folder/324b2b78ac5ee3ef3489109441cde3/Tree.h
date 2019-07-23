#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;

BTNode* CreateBinTree(BTDataType* array, int* index);//创建二叉树

BTNode* CopyBinTree(BTNode* pRoot);//拷贝一个二叉树

void DestroyBinTree(BTNode** pRoot);//销毁一个二叉树

void PreOrder(BTNode* pRoot);//先序遍历

void PreOrderNor(BTNode* pRoot);

void InOrder(BTNode* pRoot);

void InOrderNor(BTNode* pRoot);

void PostOrder(BTNode* pRoot);

void PostOrderNor(BTNode* pRoot);

void LevelOrder(BTNode* pRoot); 

int GetNodeCount(BTNode* pRoot);//求二叉树的结点数

int Height(BTNode* pRoot);//求二叉树的高度

int IsBalanceTree(BTNode* pRoot);//判断二叉树是否平衡

int GetLeafNodeCount(BTNode* pRoot);//求叶子结点的个数

int GetKLevelNodeCount(BTNode* pRoot, int K);//求第K层的结点数

BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);//求双亲结点

BTNode* Mirror(BTNode* pRoot);