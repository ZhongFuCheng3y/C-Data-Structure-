#include <iostream>
using namespace std;




/**
*插入排序算法： 
*	将一个数组元素插入一段已经排好顺序的数组 
*	令i和n指向该元素，并把它赋值给变量key，
*   用该元素与前面排好顺序的数组作比较，如果前面的元素比该key大，那么前面的元素往后覆盖
*   arr[i]=arr[i-1];i--；  此时i已经在i-1的位置上了 
*   i不断减少，直到发现前面的元素比key小，或者i已经到达0（无法与前面的数作比较）
*	最后只需要把key赋值给arr[i]上	 
*/
 
void insert(int arr[],int n)
{
	int key=arr[n];
	int i=n;
	while(arr[i-1]>key)
	{
		arr[i]=arr[i-1];
		i--;
		if(i==0)
		break;
	}
	arr[i]=key;
}

void insertionSort(int arr[],int n)
{
	int i;
	for (i=1;i<n;i++)
	{
		insert(arr,i);
	} 
}

//不用递归的
void InsertSortArray(int arr[],int n)
{
	for(int i=1;i<n;i++)// 循环从第二个数组元素开始 
	{
		int temp=arr[i];//temp标记为未排序的第一个元素 
		while(i>=0&&arr[i-1]>temp)//将temp与已排序元素从大到小比较，寻找temp应插入的元素 
		{
			arr[i]=arr[i-1];
			i--;
		}
		arr[i]=temp;
	}
		
} 

//将数组分为 
main()
{
	int arr[]={99,2,3,1,22,88,7,77,54};
	int i;
	insertionSort(arr,9);
	for(int i=0;i<9;i++)
		cout<<arr[i]<<endl;
	return 0;
} 
