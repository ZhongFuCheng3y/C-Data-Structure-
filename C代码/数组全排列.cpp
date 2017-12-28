#include <iostream>
using namespace std;


/*
* 全排列就是将数组能够组合的所有情况都排列出来 
*算法：    
*       把数组的每个数都充当一次第一位，然后递归调用函数 全排列p+1到q
*		交换时，p是永远首位的，i++.    i与p交换    能够使数组的元素都当一次首位 
*		因为阻止重复全排列，所以将数字调换完后，要调换回来 
*		递归出口就是：只有一个元素时，全排列就是他自己 
*		
*/



void swap(int arr[],int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
		
}

void printfArray(int arr[],int n)
{
	int i;
	for (i=0;i<n;i++)
		cout<<arr[i];
	cout<<endl;
} 

void perm(int arr[],int p,int q)
{
	if(q==p)
		printfArray(arr,q+1) ;
	else
	{
		int i;
		for(i=p;i<=q;i++)
		{
			swap(arr,p,i);
			perm(arr,p+1,q);
			swap(arr,i,p);
		}
	}	
}

int main()
{
	int arr[3]={1,2,3};
	perm(arr,0,2);
	return 0;
}
