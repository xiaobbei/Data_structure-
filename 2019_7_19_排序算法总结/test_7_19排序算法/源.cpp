#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void printfSort(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}

void insertionSort(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		int key = a[i];
		int j;
		for (j = i - 1; j >= 0 && a[j] > key; --j)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

void insertSortWithGap(int a[], int size)
{
	int gap = size / 3 + 1;
	while (gap == 1)
	{
		for (int i = 0; i < size; ++i)
		{
			int key = a[i];
			int j;
			for (j = i - gap; j >= 0 && a[j] > key; j -= gap)
			{
				a[j + gap] = a[j];
			}
			a[j + gap] = key;
		}
		gap = gap / 3 + 1;
	}
}

void selectSort(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		int min = size - 1;
		for (int j = i; j < size; ++j)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		swap(&a[i], &a[min]);
	}
}

void selectSort2(int a[],int size)
{
	for (int i = 0; i < size - i; i++)
	{
		int min = size - 1;
		int max = 0;
		for (int j = i; j < size - i; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
			if (a[max] < a[j])
			{
				max = j;
			}
		}

		swap(&a[i], &a[min]);
		if (max == i)
		{
			max = min;
		}
		swap(&a[max], &a[size - i - 1]);
	}
}

void  heapitf(int a[], int size, int index)//建大堆，降序排列
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	if (left >= size)
	{
		return;
	}
	int max = left;
	if (right < size && a[right] >a[left])
	{
		max = right;
	}
	if (a[index] >= a[max])
	{
		return;
	}
	int temp = a[max];
	a[max] = a[index];
	a[index] = temp;
	
	heapitf(a, size, max);
}

void heapity2(int a[], int size, int index)//建小堆
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	if (left >= size)
	{
		return;
	}
	int min = left;
	if (right < size && a[right] < a[min])
	{
		min = right;
	}
	if (a[index] < a[min])
	{
		return;
	}
	swap(&a[index], &a[min]);
	heapity2(a, size, min);
}

void BubbleSort(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		int flag = 0;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (a[j]>a[j+1])
			{
				swap(&a[j], &a[j+1]);
				flag = 1;

			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
void createHeap(int a[], int size)
{
	for (int i = (size -2)/2;i>=0;--i)
	{
		heapity2(a,size,i);
	}
}
int partition1(int a[], int left, int right)
{
	int begin = left;
	int end = right;
	int key = a[right];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		swap(&a[begin], &a[end]);
	}
	swap(&a[end], &a[right]);
	return begin;
}

int partition2(int a[], int left, int right)
{
	int begin = left;
	int end = right;
	int key = a[right];
	while (begin < end)
	{
		while (begin <end && a[begin]<=key)
		{
			begin++;
		}
		a[end] = a[begin];
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[begin] = a[end];
	}
	a[begin] = key;
	return end;
}
int  partition3(int a[], int left, int right)
{
	int div = left; 
	for (int i = left; i < right; ++i)
	{
		if (a[i] < a[right])
		{
			swap(&a[i], &a[div]);
			div++;
		}
	}
	swap(&a[div], &a[right]);
	return div;
}
void quickSortInternal(int a[], int left,int right)
{
	if (left >= right)
	{
		return;
	}
	int i = partition3(a, left, right);
	
	quickSortInternal(a, left, i-1);
	quickSortInternal(a, i+1, right);
}

void quickSort(int a[], int size)
{
	int left = 0;
	int right = size - 1;
	quickSortInternal(a, left, right);
}

void Merge(int *a, int left, int mid, int right)
{
	int *temp = (int *)malloc(sizeof(int)*(right - left));
	int index = 0;
	int l = left;
	int m = mid + 1;
	while (l <= mid&&m <= right)
	{
		if (a[l] <= a[m])
		{
			temp[index++] = a[l++];
		}
		else
		{
			temp[index++] = a[m++];
		}
	}
	while (l <= mid)
	{
		temp[index++] = a[l++];
	}
	while (m <= right)
	{
		temp[index++] = a[m++];
	}
	for (int i = 0, j = left; j <= right; ++j)
	{
		a[j] = temp[i++];
	}
}

void Mergesort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int mid = left + ((right - left) >> 1);
	Mergesort(a, left, mid);
	Mergesort(a, mid + 1, right);
	Merge(a, left, mid, right);
}


void CountSort(int *a, int size)
{
	int min = a[0];
	int max = a[0];
	int index = 0;
	for (int i = 0; i < size; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int range = max - min + 1;
	int *temp = (int*)calloc(range, sizeof(int));
	for (int i = 0; i < size; ++i)
	{
		temp[a[i] - min]++;
	}
	for (int i = 0; i < range; i++)
	{
		while (temp[i]--)
		{
			a[index++] = i + min;
		}
	}
	free(temp);
	temp = NULL;
}
int main()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,2,3,6 };
	int size = sizeof(a) / sizeof(a[0]);
	CountSort(a, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}