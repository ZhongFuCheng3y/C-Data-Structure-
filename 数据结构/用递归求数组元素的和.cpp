#include <iostream>
using namespace std;
/* 
int sum(int arr[],int n)
{
	if(n==0)
		return arr[0];
	else
		return sum(arr,n-1)+arr[n];
}
*/
                  //两种方法 
int sum(int arr[],int L,int R)
{
	if(L==R)
		return arr[L];
	else
		return (arr[L]+sum(arr,L+1,R));
}
int main()
{
	int arr[9]={1,2,3,4,5,6,7,8,10};
	int g=sum(arr,0,8);//数组的下标为8 
	cout<<g;
	return 0;
}
