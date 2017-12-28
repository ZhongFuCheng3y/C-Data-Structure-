#include <iostream>
using namespace std;
/*
*思路：转置就是[i][j]和[j][i]转换 
*因为根据第0行没有元素转换，第1行只有一个数转置，第2行有两个数转置，比如：第一行中的第0列需要转换 。以此类推
*所以j<i，如果j<=n那么就有几个数多次被转置了 
*/

void fun(int arr[][3],int n);


int main(){
	int arr[3][3]={1,2,3,4,5,6,7,8,9,};
	fun(arr,3);	
	return 0;
}

void fun(int arr[][3],int n){
	int t;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			t=arr[i][j];
			arr[i][j]=arr[j][i];
			arr[j][i]=t;
	    }
	    
	}
	cout<<"交换后的数组："<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++){
			cout<<arr[i][j];
		}
		printf("\n");
	}
	
		
}
 
