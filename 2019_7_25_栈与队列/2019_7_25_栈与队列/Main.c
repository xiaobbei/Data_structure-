#include"Queue.h"
#include"Stack.h"

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 10);
	QueuePush(&q, 20);
	QueuePush(&q, 30);
	QueuePush(&q, 40);
	QueuePush(&q, 60);
	printQueue(&q);
	printf("\n");
	QueueDestroy(&q);
	printQueue(&q);
	int i = QueueEmpty(&q);
	printf("%d ", i);
	system("pause");
	return 0;
}