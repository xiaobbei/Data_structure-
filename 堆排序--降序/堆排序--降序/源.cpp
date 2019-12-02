#include<iostream>
#include<vector>
using namespace std;


void adjust_smore_heap(vector<int>& arr, int index, int size)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int min = index;
	if (left < size && arr[left] < arr[min])
		min = left;
	if (right < size && arr[right] < arr[min])
		min = right;
	
	if (min != index)
	{
		swap(arr[min], arr[index]);
		adjust_smore_heap(arr, min, size);
	}
}

void heapSort(vector<int>& arr, int size)
{
	adjust_smore_heap(arr, 0, size);
	for (int i = size - 1; i >= 0; --i)
	{
		swap(arr[i], arr[0]);
		adjust_smore_heap(arr, 0, i);
	}
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
}
int main()
{
	vector<int> arr = { 9, 8, 5, 6, 7, 4, 2, 3, 1 };
	heapSort(arr, arr.size());
	system("pause");
	return 0;
}