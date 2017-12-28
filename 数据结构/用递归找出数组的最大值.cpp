#include <iostream>
using namespace std;



//很多时候就是把问题分为两部分，然后递归一大部分的问题，从而找到结果 
/* 
int findMax(int arr[],int n)
{
	if(n==0)
		return arr[0];
	if(findMax(arr,n-1)>arr[n])//findMax()函数一直循环 
		return findMax(arr,n-1);//把数组分两部分，一部分一直循环找出最大值
								//一部分就是arr【n】 
	else 
		return arr[n];
		
} 
*/                   //两种方法 
int findMax(int arr[], int L,int R)
{
	if(L==R)
		return arr[L];
	else
	{
		int a=arr[L];
		int b=findMax(arr,L+1,R);
		if (a>b)
			return a;
		else 
			return b;
	}
} 



	 
int main()
{
	int arr[9]={1,52,3,4,5,6,7,8,44};
	int g=findMax(arr,0,8);//8是数组的下标 
	cout<<g;
	return 0;
}
