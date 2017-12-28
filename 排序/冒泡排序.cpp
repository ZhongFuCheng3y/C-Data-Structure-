#include <iostream>
using namespace std;

/*
*冒泡排序算法：
*			 i从0开始，i与i+1比较，如果i>i+1，那么就互换 
*			 i不断增加，直到i<n-1（n是数组元素的个数，n-1是数组最后一个元素，如果i=n-1，那么i+1就没有元素了） 
*			 一趟下来，可以让数组元素中最大值排在数组的最后面 
*		     1： 从n个开始，每排好一次最大值，i就减1，直到剩下一个元素 
*			 2：直接递归，定义L和R（数组的下标），排第一次是i<=R-1；递归调用bubble（L,R-1） 
*/ 



void  bubble(int arr[],int n)
{
	int i;
	int temp;
	for (i=0;i<n-1;i++)//只需要n-1次交换。 
	{
		if(arr[i]>arr[i+1])
		{
			temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
		}
	}
}

void bubbleSort (int arr[],int n)
{
	int i;
	for (i=n;i>=1;i--)//从n个排到第一个 
	{
		bubble(arr,i);
	}
}


//这种比较好理解 
void bubble(int arr[],int L,int R)
{
	if(L==R)
	;
	else
	{
		int i;
		for(i=L;i<=R-1;i++)//i只能到达R-1 
			if(arr[i]>arr[i+1])
			{
				int temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		bubble(arr,L,R-1);//第一轮已排好R 
	}
}


int main()
{
	int arr[]={2,3,4,511,66,777,444,555,9999};
	bubbleSort(arr,8);
	for (int i=0;i<9;i++)
		cout<<arr[i]<<endl;
	return 0;
}
