#include"Queue.h"

void QueueInit(Queue* q)
{
	q->_front = q->_rear = NULL;
}

void QueuePush(Queue* q, QDataType data) //入队
{
	QNode *node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	if (q->_front == NULL)
	{
		q->_front = node;
		q->_rear = node;
	}
	q->_rear->_pNext = node;
	q->_rear = node;
}

void QueuePop(Queue* q) //出队
{
	if (q->_front == q->_rear)
	{
		return;
	}
	QNode *p = (QNode *)malloc(sizeof(QNode));
	p = q->_front;
	q->_front = p->_pNext;
	if (q->_front == NULL)
	{
		return;
	}
	free(p);
}


QDataType QueueFront(Queue* q)
{
	if (q->_front == NULL)
	{
		return -1;
	}
	return  q->_front->_data;

}


QDataType QueueBack(Queue* q)
{
	if (q->_front == NULL)
	{
		return -1;
	}
	return q->_rear->_data;
}

int QueueSize(Queue* q)
{
	int count = 0;
	QNode *pCur;
	//assert(q);
	pCur = q->_front;
	while (pCur)
	{
		pCur = pCur->_pNext;
		count++;
	}
	return count;
}

int QueueEmpty(Queue* q)
{
	if (q->_front == q->_rear )
	{
		return 1;
	}
	return 0;
}

void QueueDestroy(Queue* q)
{
	QNode * node = NULL;
	while(q->_front!=q->_rear )
	{
		node = q->_front->_pNext;
		
		free(q->_front);
		q->_front = node;
	}
	free(node);
}

void printQueue(Queue *q)
{
	QNode *Cur = q->_front;
	if (Cur == NULL)
	{
		return;
	}
	while (1)
	{
		printf("%d ", Cur->_data);
		if (Cur==q->_rear)
		{
			break;
		}
		Cur = Cur->_pNext;
	}
}