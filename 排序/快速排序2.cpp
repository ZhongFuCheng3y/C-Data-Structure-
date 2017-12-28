#include <stdio.h>


/**
*算法：将一个数组的最右边一个数作为支点，将i和j从0开始遍历，如果发现元素比支点小，那么i和j交换（实际没有变换） 
*如果元素比支点大，那么i就+1 
*此时i走在j的前面，判断i指向的元素大小 
*目的就是保证j的左边比支点小，i的右边比支点大 
*最后将支点和j指向的元素（当i遍历完之后）互换  
*最后调用一下快速排序函数 
*/

int partition(int arr[], int L, int R) {
	int pivot = arr[R];
	int i;
	int j = L;
	for (i = L; i < R; i++) {
		if (arr[i] < pivot) {
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			j++;
		}
	}
	int temp = arr[j];
	arr[j] = arr[R];
	arr[R] = temp;
	return j;
}

void quickSort(int arr[], int L, int R) {
	if(L < R) {
		int M = partition(arr, L, R);
		quickSort(arr, L, M-1);
		quickSort(arr, M+1,R);
	}
}


int main() {
	int arr[] = {3,6,8,1,4,5};
	quickSort(arr, 0, 5);
	 
	for (int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);		
	}
	printf("\n");
	return 0;
}
