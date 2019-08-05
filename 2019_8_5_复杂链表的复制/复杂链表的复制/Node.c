#include"Node.h"

Node *createNode(int val)
{
	Node *head = (Node *)malloc(sizeof(Node));
	if (head == NULL)
	{
		printf("´´½¨Ê§°Ü£¡");
		return NULL;
	}
	head->val = val;
	head->next = NULL;
	head->_random = NULL;
	return head;
}

void Display(Node *head)
{
	Node *p = head;
	while (p)
	{
		printf("%d::%d-->", p->val, p->_random->val);
		p = p->next;
		printf("\n");
	}
}

Node copyNode(Node *head)
{
	Node *pold = NULL;
	Node *pnew = NULL;
	Node *rhead = NULL;
	pold = head;
	while (pold != NULL)
	{
		
	}
}