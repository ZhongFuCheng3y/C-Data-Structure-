#include <stdio.h>
#include <stdlib.h>
//两个数组有序合并起来，形成一个有顺序的数组。
//算法：用i和j分别指向两个数组的第一个元素，直到i小于该数组的个数，j小于该数组的个数。比较指向i，j元素的大小。
//将小的那个元素放进arr数组中，下标+1  无论哪个数大，执行完一次后，k要+1
//上述的比较完之后，如果哪个数组剩下的元素未能写进arr数组，那么用while语句写入arr数组
 

 
void merge(int* nums1,int m,int* nums2,int n){
	int *arr=(int *)malloc(sizeof(m+n));
	int i=0;
	int j=0;
	int k=0;
	while(i < m && j < n){
		if(nums1[i]<nums2[j]){
			arr[k]=nums1[i];
			i++;
		}
		else{
			arr[k]=nums2[j];
			j++;
		}
		k++;
	}
	while(i<m){
		arr[k]=nums1[i];
		i++;
		k++;
	}
	while(j<n){
		arr[k]=nums2[j];
		j++;
		k++;
	}
	for(i=0;i<k;i++){
		nums1[i]=arr[i];
	}
}

void printfArray(int *nums1,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d   ",nums1[i]);
	}
	printf("\n");
}


int main(){
	int nums1[100]={3,5,6,7,44,66,99};
	int nums2[4]={1,4,8,9};
	
	merge(nums1,7,nums2,4);
	printfArray(nums1,11);
	
	return 0;
}




