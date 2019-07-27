#include"SeqList.h"

int main()
{
	SeqList ps ;
	SeqListInit(&ps);
	SeqListPushBack(&ps, 1);
	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 3);
	SeqListPushBack(&ps, 4);
	SeqListPushBack(&ps, 5);
	SeqListPushBack(&ps, 6);
	SeqListPushBack(&ps, 7);
	SeqListPushBack(&ps, 8);
	SeqListPushFront(&ps, 0);
	SeqListInsert(&ps, 1, 9);
	SeqListErase(&ps, 1);
	int i = SeqListFind(&ps, 8);//如果找不到返回-1
	printf("%d\n", i);
	SeqListRemove(&ps, 1); 
	SeqListFront(&ps);  // 如果顺序表为空返回-1
	SeqListBack(&ps);	// 如果顺序表为空返回-1
	printf("%d\n ",i);
	printSeqList(&ps);
	system("pause");
	return 0;
}