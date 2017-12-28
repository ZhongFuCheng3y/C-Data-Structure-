#include <stdio.h>

/**
*给你一个数组，除了其中一个数字外，其他数字都出现了两次。
请把这个只出现一次的数字找出来。
*算法：数出数组的元素出现的次数 （将arr[第几个数]在整个数组遍历一遍，看出现是否两次）如果只出现一次，那么这个数就是singlenumber 
*@n n表示的是数组的长度，
*@k k表示的是这个数字在数组出现的次数 
*/

int countLetter(int* arr, int n, int k) {
	int i;
	int c=0;
	for (i = 0; i < n ; i++) {
		if(arr[i] == k) {
			c++;
		}
	}
	return c;
}

int singleNumber (int* nums, int numsSize) {
	int i;
	for (i = 0 ; i < numsSize; i++) {
		int count = countLetter(nums, numsSize ,nums[i]);
		if (count == 1){
			return nums[i];
		}
		
	}
	return 0;
}
/**
*算法优化：
*使用异或运算符，基本原理：如果两个数相等，使用^运算符，那么结果为0
*算法：将数组遍历一遍，i用1开始，将数组的元素全部^，剩下的数就是只出现一次的
*/

int singleNumber(int* nums, int numsSize) {
	int k = nums[0];
	int i;
	for (int i = 1; i < numsSize; i++) {
		k = (k ^ nums[i]);
	}
	return k;
}
 

int main() {
	int arr[7]={5,7,4,4,7,8,8};
	int r = singleNumber(arr, 7);
	printf("%d\n", r);
	return 0;
	
}
