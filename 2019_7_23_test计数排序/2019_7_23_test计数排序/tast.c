#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

void  Mergearray(int a[], int low, int mid, int high)
{
	int  *temp = (int *)malloc(sizeof(int)*(high - low));
	if (temp == NULL)
	{
		return;
	}
	int l = low;
	int m = mid;
	int index = 0;
	while (l < mid && m < high)
	{
		if (a[l] < a[m])
		{
			temp[index++] = a[l++];
		}
		else
		{
			temp[index++] = a[m++];
		}
	}
	while (l < mid)
	{
		temp[index++] = a[l++];
	}
	while (m < high)
	{
		temp[index++] = a[m++];
	}
	for (int i = 0, j = low; j < high; ++j)
	{
		a[j] = temp[i++];
	}
	free(temp);
}

void MergeSort(int a[], int low, int high)
{
	if (high - low == 1)
	{
		return;
	}
	int mid = (low + high) / 2;
	MergeSort(a, low, mid);
	MergeSort(a, mid, high);
	Mergearray(a, low, mid, high);
}

void printfArray(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
}


void CountSort(int a[], int size)
{
	int min = a[0];
	int max = a[0];
	int j = 0;
	for (int i = 0; i < size; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int s = max - min + 1;
	int *temp = (int *)malloc(sizeof(int)*s);
	memset(temp, 0, sizeof(int)*s);
	for (int i = 0; i < size; ++i)
	{
		temp[a[i] - min]++;
	}
	for (int i = 0; i < s; ++i)
	{
		while (temp[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(temp);
}


int main()
{
	int a[] = { 9,8,7, 8,8,8,6,5,4,3,2,1 };
	int size = sizeof(a) / sizeof(a[0]);
	CountSort(a, size);
	printfArray(a, size);
	system("pause");
	return 0;
}