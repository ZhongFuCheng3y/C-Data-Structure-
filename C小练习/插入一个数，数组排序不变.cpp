#include <iostream>
using namespace std;
/*
*主要思路：要插入的元素应当从数组最后一个寻找，直到找到元素的大小是比插入的小 
*在找到元素的大小是比插入的小 之前，所有的元素都应该往后面移一位，i不断减少， 
*当找到元素的大小比插入的值小时候，我们就把n插入到arr【i+1】处， 
*因为i本来就是在数组的元素中不断比较的， 
*
*/


int main() {
	int const N = 10;
	int arr[N] = {2,6,9,12,32,45,54};
	int m = 7;
	int n;
	int i;
	cout<<"输入你要插入的元素:";
	cin>>n;
	
	for (i=m-1; i>=0 && n<arr[i]; i--) {
		arr[i+1] = arr[i];

	}
	arr[i+1] = n;
	m++;
	for (i=0; i<m; i++) {
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
	
	
	
	
	return 0;
}
