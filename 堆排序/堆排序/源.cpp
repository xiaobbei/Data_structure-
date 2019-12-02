#include<iostream>
#include<vector>
using namespace std;

//先创建大顶堆
void adjust(vector<int>& arr, int index, int size)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int max = index;
	if (left<size && arr[left]>arr[max])
		max = left;
	if (right<size && arr[right] >arr[max])
		max = right;

	if (max != index)
	{
		swap(arr[max], arr[index]);
		adjust(arr, max, size);
	}
	
}

//对大顶堆进行不断调整
void heapSort(vector<int>& arr, int size)
{
	for (int i = size / 2 - 1; i >= 0; --i)
	{
		adjust(arr, i, size);
	}
	for (int i = size - 1; i >= 0;i--)
	{
		swap(arr[0], arr[i]);
		adjust(arr,0,i);
	}
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
}

int main()
{
	vector<int> arr = { 8, 1, 14, 3, 21, 5, 7, 10 };
	heapSort(arr, arr.size());
	system("pause");
	return 0;
}