#pragma once

#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int val;
	struct Node *next;
	struct Node *_random;
}Node;

Node *createNode(int val);
void Display(Node *head);
Node copyNode(Node *head);