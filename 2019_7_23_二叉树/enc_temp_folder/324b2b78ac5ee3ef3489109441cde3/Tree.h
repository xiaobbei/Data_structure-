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

BTNode* CreateBinTree(BTDataType* array, int* index);//����������

BTNode* CopyBinTree(BTNode* pRoot);//����һ��������

void DestroyBinTree(BTNode** pRoot);//����һ��������

void PreOrder(BTNode* pRoot);//�������

void PreOrderNor(BTNode* pRoot);

void InOrder(BTNode* pRoot);

void InOrderNor(BTNode* pRoot);

void PostOrder(BTNode* pRoot);

void PostOrderNor(BTNode* pRoot);

void LevelOrder(BTNode* pRoot); 

int GetNodeCount(BTNode* pRoot);//��������Ľ����

int Height(BTNode* pRoot);//��������ĸ߶�

int IsBalanceTree(BTNode* pRoot);//�ж϶������Ƿ�ƽ��

int GetLeafNodeCount(BTNode* pRoot);//��Ҷ�ӽ��ĸ���

int GetKLevelNodeCount(BTNode* pRoot, int K);//���K��Ľ����

BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);//��˫�׽��

BTNode* Mirror(BTNode* pRoot);