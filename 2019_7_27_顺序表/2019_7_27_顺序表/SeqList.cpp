#include"SeqList.h"


void expendSeqList(PSeqList ps)
{
	DataType *old = ps->_array;
	ps->_capacity = 2 * ps->_capacity;
	ps->_array = (DataType *)malloc(sizeof(DataType)*ps->_capacity);
	for (int i = 0; i < ps->_size; ++i)
	{
		ps->_array[i] = old[i];
	}
}

void SeqListInit(PSeqList ps)
{
	ps->_array = (DataType *)malloc(sizeof(DataType) * 5);
	if (ps->_array == NULL)
	{
		printf("申请失败!");
		return;
	}
	//memset(ps->_array, 0, sizeof(SeqList) * 5;
	ps->_capacity = 5;
	ps->_size = 0;
}

void SeqListDestroy(PSeqList ps)
{
	free(ps);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}

void SeqListPushBack(PSeqList ps, DataType data)
{
	if (ps->_size == ps->_capacity)
	{
		expendSeqList(ps);
	}
	ps->_array[ps->_size++] = data;
}

void SeqListPopBack(PSeqList ps)
{
	if (ps->_size == 0)
	{
		return;
	}
	ps->_array[ps->_size--];
}

void SeqListPushFront(PSeqList ps, DataType data)
{
	if (ps->_size == 0)
	{
		ps->_array[ps->_size++] = data;
	}
	else
	{
		if (ps->_size == ps->_capacity)
		{
			expendSeqList(ps);
		}
		else
		{
			for (int i = ps->_size; i >= 0; --i)
			{
				ps->_array[i + 1] = ps->_array[i];
			}
			ps->_array[0] = data;
			ps->_size++;
		}
	}
}

void SeqListPopFront(PSeqList ps)
{
	if (ps->_size == 0)
	{
		return;
	}
	for (int i = 0; i < ps->_size; ++i)
	{
		ps->_array[i] = ps->_array[i+1];
	}
	ps->_size--;
}

void SeqListInsert(PSeqList ps, int pos, DataType datda)
{
	if (pos<0 || pos>ps->_size+1 )
	{
		return;
	}
	if (ps->_size == ps->_capacity)
	{
		printf("顺序表已满，无法插入\n");
		return;
	}
	for (int i = ps->_size; i >= pos; --i)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[pos] = datda;
	ps->_size++;
}

void SeqListErase(PSeqList ps, int pos)
{
	if (ps->_size == 0)
	{
		return;
	}
	if (pos > ps->_size)
	{
		printf("删除位置错误!\n");
		return;
	}
	for (int i = pos; i <= ps->_size; ++i)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;

}

int SeqListFind(PSeqList ps, DataType data)  //如果没找到返回-1
{
	if (ps->_size == 0)
	{
		return -1;
	}
	for (int i = 0; i <= ps->_size; ++i)
	{
		if (ps->_array[i] == data)
		{
			return i;
		}
	}
	return -1;
}

void SeqListRemove(PSeqList ps, DataType data) //删除第一个出现的data
{
	if (ps->_size == 0)
	{
		return;
	}
	int i = 0;
	for (i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] == data)
		{
			ps->_array[i] = ps->_array[i + 1];
			ps->_size--;
			break;
		}
	}
	for (int j = i; j < ps->_size; ++j)
	{
		ps->_array[j] = ps->_array[j + 1];
	}
}

void SeqListRemoveAll(PSeqList ps, DataType data) // 删除所有的data
{
	if (ps->_size == 0)
	{
		return;
	}
	int d = 0;
	for (int i = 0; i < ps->_size; ++i)
	{
		while (ps->_array[i + d] == data)
			d++;
		ps->_array[i] = ps->_array[i + d];
	}
	ps->_size -= d;
}

int SeqListSize(PSeqList ps)
{
	return ps->_size;
}

int SeqListCapacity(PSeqList ps)
{
	return ps->_capacity;
}

int SeqListEmpty(PSeqList ps)
{
	if (ps->_size == 0)
	{
		printf("为空");
		return 0;
	}
	return 1;
}

DataType SeqListFront(PSeqList ps)
{
	if (ps->_size == 0)
	{
		return -1;
	}
	return ps->_array[0];
}

DataType SeqListBack(PSeqList ps)
{
	if (ps->_size == 0)
	{
		return -1;
	}
	return ps->_array[ps->_size-1];
}


void printSeqList(PSeqList ps)
{
	if (ps->_size != 0)
	{
		for (int i = 0; i < ps->_size; ++i)
		{
			printf("%d ", ps->_array[i]);
		}
	}
}