#include"Stack.h"


/*
SDataType* _array;
	int _capacity;
	int _top; // ±ê¼ÇÕ»¶¥Î»ÖÃ
*/
void StackInit(Stack* ps)
{
	ps->_array = (SDataType *)malloc(sizeof(int)*100);
	ps->_capacity = 100;
	ps->_top = 0;
}

void StackPush(Stack* ps, SDataType data)
{
	if (ps->_top == ps->_capacity)
	{
		int new_capacity = 2 * ps->_capacity;
		SDataType *new_array = (SDataType*)malloc(sizeof(SDataType)*new_capacity);
		memcpy(new_array, ps->_array, ps->_capacity * sizeof(SDataType));
		free(ps->_array);
		ps->_array = new_array;
	}
	ps->_array[ps->_top++] = data;
}

void StackPop(Stack* ps)
{
	if (ps->_top == 0)
	{
		return;
	}
	ps->_array[ps->_top--];
}

SDataType StackTop(Stack* ps)
{
	if (ps->_top == 0)
	{
		return -1;
	}
	return ps->_array[ps->_top-1];
}

int StackSize(Stack* ps)
{
	return ps->_top;
}

int StackEmpty(Stack* ps)
{
	if (ps->_top == 0)
	{
		return 1;
	}
	return 0;
}

void StackDestroy(Stack* ps)
{
	ps->_top = 0;
	ps->_capacity = 0;
	ps->_array = NULL;
}

bool isValid(char * s)
{
	Stack p;
	int length = strlen(s);
	for (int i = 0; i < length; ++i)
	{
		char ch = s[i];
		switch (ch)
		{
		case '(':
		case'[':
		case'{':
			StackPush(&p, ch);
			break;
		case ')':
		case ']':
		case '}':
			if (StackSize(&p) == 0)
			{
				return false;
			}
			char c = StackTop(&p);
			StackPop(&p);
			if (!(c == '('&&ch == ')' || c == '['&&ch == ']' || c == '{'&&ch == '}'))
			{
				return false;
			}
			break;
		}
	}
	if(StackSize(&p)!=0)
	{
		return false;
	}
	return true;
}


