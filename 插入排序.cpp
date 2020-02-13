#include<iostream>
#include<vector>
using namespace std;

void InsertSort(vector<int>& a)
{
	for(int i = 0;i<a.size();++i)
	{
		int key = a[i];
		int j;
		for(j = i-1;j>=0 && a[j]>key; --j)
		{
			a[j+1] = a[j];
		}
		a[j+1] = key;
	} 
} 


int main()
{
	int a[] = {1,5,6,9,8,7};
	vector<int> arr(a,a+6);
	InsertSort(arr);
	for(int i = 0;i<arr.size();++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
 } 
