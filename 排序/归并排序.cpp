#include <stdio.h>


/*
*算法：将一个数组分为两部分，用递归切割左部分和右部分，直到排好顺序 
*		再将两个有顺序的数组合并成一个数组 
*
*/ 

void merge(int arr[],int L,int M,int R)
{
	int LEFT_SIZE=M-L;//左边的个数 
	int RIGHT_SIZE=R-M+1;//右边的个数 
	int left[LEFT_SIZE];
	int right[RIGHT_SIZE];
	int i,j,k;
	
	for(i=L;i<M;i++)
		left[i-L]=arr[i];
	for(i=M;i<=R;i++)
		right[i-M]=arr[i];	 
	i=0; j=0; k=L;
	while(i<LEFT_SIZE&& j<RIGHT_SIZE)
	{
		if(left[i]<right[j])
		{
			arr[k]=left[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=right[j];
			j++;
			k++;
		}
	}
	while(i<LEFT_SIZE) //如果右边的数已经全部到数组里边了，剩下左边的数就依次添加到数组里面 
	{
		arr[k]=left[i];
		i++;
		k++;
	}
	while(j<RIGHT_SIZE)
	{
		arr[k]=right[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[],int L,int R)
{
	if(L==R)
		return;//如果只有一个，那么就不用排序了 
	else
	{
		int M=(L+R)/2;//取中间的数 
		mergeSort(arr,L,M);//左边不断分割 
		mergeSort(arr,M+1,R);//右边不断分割 
		merge(arr,L,M+1,R);//M+1 
	}	

}

int main()
{
	int arr[10]={4,6,2,557,8,4,7,5,9,};
	int L=0;
	int R=9;
	mergeSort(arr,L,R);
	int i;
	for(i=0;i<=R;i++)
		printf("%d  ",arr[i]);
	return 0;
	
}


