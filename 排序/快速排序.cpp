#include <stdio.h>

/*
*算法： 把第一个元素作为支点，找到low大于支点的，high小于支点的，然后交换 
*		最后把第一个元素放入low里面，返回low的值 
*		递归调用函数，分切两边，low到pos-1，pos+1到high 
*
*
*
*/ 




void QuickSort(int* arr,int low,int high);
int FindPos(int* arr,int low,int high);


int main()
{
	int arr[6]={5,3,-88,77,44,-1};
	int i;
	QuickSort(arr,0,5);
	for(i=0;i<6;i++)
		printf("%d   ",arr[i]);
	printf("\n");
	return 0;
}

int FindPos(int* arr,int low,int high)
{
	int val=arr[low];
	
	while(low<high)
	{
		while(low<high&&arr[high]>=val)
			--high;
		arr[low]=arr[high];
		while(low<high&&arr[low]<=val)
			++low;
		arr[high]=arr[low];
	}
		arr[low]=val;
	return low;
}



void QuickSort(int arr[],int low,int high)
{
	int pos;
	if(low<high)
	{		
		pos=FindPos(arr,low,high);
		QuickSort(arr,low,pos-1);//劈两半，左边 
		QuickSort(arr,pos+1,high); //右边 
	}
	return;
} 



