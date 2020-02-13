#include<iostream>
#include<vector>

using namespace std;

void InsertSortWithGap(vector<int>& arr)
{
	int gap = arr.size()/3+1;
	while(gap != 1)
	{
		for(int i = 0;i<arr.size();++i)
		{
			int key = arr[i];
			int j;
			for(j = i-gap;j>=0 && arr[j]>key;j-=gap)
				arr[j+gap] = arr[j];
			arr[j + gap] = key; 	
		}
		gap = gap/3+1;	
	}	
} 
int main()
{
	int a[] = {1,5,6,9,8,7};
	vector<int> arr(a,a+6);
	InsertSortWithGap(arr);
	for(int i = 0;i<arr.size();++i)
	{
		cout<<arr[i]<<" ";			
	} 
	return 0;
}
