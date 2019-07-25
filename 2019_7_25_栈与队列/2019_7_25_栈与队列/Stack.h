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
	int _top; // 标记栈顶位置
}Stack;

void StackInit(Stack* ps); // 初始化栈

void StackPush(Stack* ps, SDataType data); // 入栈

void StackPop(Stack* ps);  //出栈

SDataType StackTop(Stack* ps);// 返回栈顶元素

int StackSize(Stack* ps); //获取栈的有效值的个数

int StackEmpty(Stack* ps); //检测栈是否为空，如果为空返回非零结果，如果不为空返回0 

void StackDestroy(Stack* ps); // 销毁栈

bool isValid(char * s); //括号匹配问题