#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
给你一个长度为n的数组，其中有一个数字出现的次数至少为n/2，找出这个数字
其实就是一个数字出现的次数多于数组一半的长度； 
算法：利用数据结构中的压栈和出栈的方法，最后剩下的元素就是出现的次数至少为n/2。 
如果栈是空的，那么先把数据存进去，然后继续遍历其他的数据，只要发现栈中的数据和遍历中的数据不一样，
那么就出栈， 如果是相同的，那么就top+1
其实就是捉住数字出现的次数多于数组一半的长度这里入手。 
如果这个数出现的次数是大于这个数组长度的2/1，那么最后留下的肯定是这个数

 
*/
int majorityElement(int* nums, int numsSize){
	int* stack = (int*)malloc(sizeof(numsSize));
	int top = -1;
	for(int i=0; i<numsSize; i++){
		if(top == -1){
			stack[++top] = nums[i];
		}
		else if(stack[top] == nums[i]){
			stack[++top] = nums[i];
		}
		else{
			top--;
		}
	}
	return stack[0];
}





//其实是没有必要用整个栈来存储数组的元素的，因为栈存放的元素都是一样的，
//所以可以只用count来表示整个栈 。cand表示存储在栈的元素 
//count表示的是在栈里面出现多少次 
//优化空间复杂度：
int majorityElement(int *nums, int numsSize){
	int cand;
	int count=0;
	int i;
	for(i=0;i<numsSize;i++){
		if(count == 0){
			cand = nums[i];
			count++;
		}
		else if(cand==nums[i]){
			count++;
		}
		else{
			count--;
		}
	}
	return cand;
} 




int main() {
	int nums[]={1,3,3,3,2,3,4};
	int result=majorityElement(nums,7);
	printf("%d\n",result);
	return 0;
}
