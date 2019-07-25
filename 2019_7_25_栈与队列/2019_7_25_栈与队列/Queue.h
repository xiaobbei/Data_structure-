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


void QueueInit(Queue* q); //��ʼ������

void QueuePush(Queue* q, QDataType data); //���

void QueuePop(Queue* q);//����

QDataType QueueFront(Queue* q);//��ȡ��ͷԪ��

QDataType QueueBack(Queue* q);//��ȡ��βԪ��

int QueueSize(Queue* q);//��ȡ�ӵ�Ԫ�ظ���

int QueueEmpty(Queue* q);//�������Ƿ�Ϊ��,Ϊ�շ��ط�0��Ϊ�շ���0

void QueueDestroy(Queue* q);//	���ٶ���

void printQueue(Queue *q); //��ӡ����