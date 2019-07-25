#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int QDataType;

typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;


void QueueInit(Queue* q); //初始化队列

void QueuePush(Queue* q, QDataType data); //入队

void QueuePop(Queue* q);//出队

QDataType QueueFront(Queue* q);//获取队头元素

QDataType QueueBack(Queue* q);//获取队尾元素

int QueueSize(Queue* q);//获取队的元素个数

int QueueEmpty(Queue* q);//检测队列是否为空,为空返回非0，为空返回0

void QueueDestroy(Queue* q);//	销毁队列

void printQueue(Queue *q); //打印队列