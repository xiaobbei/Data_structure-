#include"Tree.h"

int main()
{
	char a[] = "ABF###CD##E##";
	int j = 0;
	BTNode * bt = CreateBinTree(a, &j);
	PreOrder(bt);
	BTNode * ct = Mirror(bt);
	PreOrder(ct);
	system("pause");
	return 0;
}