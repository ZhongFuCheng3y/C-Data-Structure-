#include <iostream>
using namespace std;


/*
*  算法： 
*		用两个变量L，R分别指向数组的首位和最后一位，用（L+R）/2作为支点	
*		目的是左边的是小的，右边的是大的 
*		while（i<=j）只要i和j没有错开，就一直循环。
*		直到找到i那边比支点大的数，直到找到j那边比支点小的数
*		交换左边和右边 ，最终支点的左边就是小于支点的，右边就是大于支点的 
*		递归出口就是：（L<j) (i<R)递归左边做快速排序，右边做快速排序 
*/


 
void quicksort (int arr[],int L,int R)
{
	int i=L;//L和R分别是数组的最左端和最右端 
	int j=R;
	int pivot =arr[(L+R)/2];
	
	while(i<=j)
	{
		while (arr[i]<pivot)//直到找到比支点大时，才停止 
			i++;
		while (arr[j]>pivot)//直到找到比支点小时，才停止 
			j--;
		if(i<=j)//在错开之前才进行交换	
		{
			int temp=arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if(L<j)//递归出口 
		quicksort(arr,L,j);//递归 
	if(i<R)
		quicksort(arr,i,R);
}

int main()
{
	int arr[]={1,4,5,67,2,7,8,6,9,44};
	quicksort(arr,0,9);
	for (int i=0;i<10;i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}
