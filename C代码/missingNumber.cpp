#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
*给你一个数组{0, 1, 2, 3 .., n}，其中有一个数字缺失。 请把这个数缺失的数字找出来
*算法：把数组元素出现的次数清空。然后遍历数组，将出现的数存放在一个变量中，将变量作为数组的下标写进数组。
//标记着该数已出现 
*@numsSize 如果是4个数字的话，实际的是有5个，因为缺失了一个，那么数组的下标就应该到arr【5】； 
* +1就是把所有的遍历一遍（包括missing那个），而第二个for循环没有加一，是因为数字只有4个（是缺少一个的） 
*/
int missingNumber(int* nums,int numsSize) {
	int* arr = (int*)malloc(sizeof( numsSize+1 ));
	int i;
	for (i = 0; i < numsSize+1; i++) {
		arr[i] = false;
	}
	for (i = 0; i < numsSize; i++) {
		int index = nums[i];
		arr[index] = true;
	}
	for (i = 0;i < numsSize+1; i++) {
		if (arr[i] == false) {
			return i;
		}
	}
	return 0;
}


/**
*算法优化：空间复杂度 
*利用等差求和公式把数组的元素相加起来，然后把数组的元素一个一个减去，剩下的就是missing的值 
*
*/ 

//int missingNumber(int* nums, int numsSize) {
//	int sum = numsSize * (numsSize + 1) / 2;
//	int i;
//	for (i = 0; i < numsSize; i++ ) {
//		sum = sum - nums[i];
//	} 
//	return sum;
//}



int main() {
	int arr[4] = {1,0,2,4};
	int r = missingNumber(arr,4);
	printf("%d\n",r);
	return 0;
} 
