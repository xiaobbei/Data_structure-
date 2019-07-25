#pragma once
#include<stdio.h>
#include<stdbool.h>

#include <stdlib.h>
#include <string.h>
#include <assert.h> 

typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;
	int _capacity;
	int _top; // ���ջ��λ��
}Stack;

void StackInit(Stack* ps); // ��ʼ��ջ

void StackPush(Stack* ps, SDataType data); // ��ջ

void StackPop(Stack* ps);  //��ջ

SDataType StackTop(Stack* ps);// ����ջ��Ԫ��

int StackSize(Stack* ps); //��ȡջ����Чֵ�ĸ���

int StackEmpty(Stack* ps); //���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 

void StackDestroy(Stack* ps); // ����ջ

bool isValid(char * s); //����ƥ������