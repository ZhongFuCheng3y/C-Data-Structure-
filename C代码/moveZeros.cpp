#include <stdio.h>

/**
*题目：将一个数组的元素，其中是0的，放在数组的最后 
*算法：把数组遍历一次，如果发现0，那么zero+1； 
*  如果当前的元素不等于0，那么把当前元素往前面移，移的位数刚好是arr[i-zeros]
* 最后把数组最后的元素改成0 （zero大小有关） 
*实际上就是遇到0之后，就把数组的元素往前移
*遇到第2个0，不能立即往前面移，先跳过0，然后下面的元素再多移一位即可 
*/

void moveZeros(int arr[], int n) {
	int zeros = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (arr[i] != 0) {
			arr[i-zeros] = arr[i];
		}
		else {
			zeros++;
		}
	}
	
	i = n - zeros;
	while (i < n) {
		arr[i] = 0;
		i++;
	}
}

/**
*另外一种算法：把数组分为几部分，j之前的没有0，j到i之间的都是0，i后面的还没遍历 
*如果i指向的元素不等于0，那么将i指向的元素和j指向的元素交换， 
*如果i指向的元素等于0，那么就扩大i到j的范围，i++ 
*/

void moveZeros2(int arr[], int n) {
	int j = 0;
	int i;
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j++;
		}
	}
}


int main() {
	int arr[8]={1,3,5,3,3,0,7,0};
	moveZeros2(arr, 8);
	int i;
	for(i = 0; i < 8; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}




