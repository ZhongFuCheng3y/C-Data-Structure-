#include <iostream>
#include <iomanip>
using namespace std;
/*
*将一个二维数组每列的最小值找出来，放到另外一个数组里边 
*思路：用j控制行数，min= arr[0][j]，这个外循环，能让二维数组中的第一行的每一个都成为最小值 
*然后让最小值跟当列的每一行相比。这样就能够找到当列的最小值 
*最后就把最小值赋给另外一个数组就行了 
*
*
*/

int main() {
	int arr[3][4] = {23,106,8,25, 
					  9,73,19,28,
					56,25,67,137};
	int arr2[4] = {0};
	int i, j, min;
	for (j=0; j<=3; j++) {
		min = arr[0][j];
		for (i=1; i<=2; i++) {
			if(arr[i][j] < min) {
				min = arr[i][j];
			}
		}
		arr2[j] = min;
	}
	
	cout<<"b的数组是：";
	for (j=0; j<4; j++) {
		cout<<arr2[j]<<"  ";
	}
	
	
	
	return 0;
}
