#include<iostream>
#include<vector>

using namespace std;

void swap(int* a,int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selectSort(vector<int>& arr)
{
	for(int i = 0;i<arr.size();++i)
	{
		int min = arr.size() - 1;
		for(int j = i;j<arr.size();++j)
		{
			if(arr[j]<arr[min])
				min = j;
		}
		swap(&arr[i],&arr[min]); 
	}
}
int main()
{
	int a[] = {1,5,6,9,8,7};
	vector<int> arr(a,a+6);
	selectSort(arr); 
	for(int i = 0;i<arr.size();++i)
	{
		cout<<arr[i]<<" ";			
	} 
	return 0;
}
