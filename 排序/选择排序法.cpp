#include <iostream>
using namespace std;

/*
*思路：每一次找到数组最大元素的下标，然后与最后一个元素交换 
*		用while（n>1）循环  n-- 
*
*
*
*/


int findMaxPos(int arr[],int n)
{
	int max=arr[0];
	int pos=0;//记录最大值的变量 
	for (int i=1;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			pos=i;//获取到最大值的位置 
		}
	}
	return pos;
}

void selectionSort(int arr[],int n)
{
	while (n>1)//直到n为1时，才停止交换 
	{
		int pos=findMaxPos(arr,n);
		int temp=arr[pos];//位置不断交换 
		arr[pos]=arr[n-1];
		arr[n-1]=temp;
		n--;//
	}
}

int main()
{
	int arr[]={5,32,7,89,2,3,4,8,9}; 
	selectionSort(arr,9);
	for (int i=0;i<9;i++)
	cout<<arr[i]<<endl; 
}
