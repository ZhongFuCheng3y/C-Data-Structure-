#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>//exit函数

struct Arr
{
	int *pBase;//存储的是数组第一个元素的地址
	int len;//数组所能容纳的最大元素的个数 
	int cnt;//当前数组有效的元素个数 
};

void init_arr(struct Arr* pArr, int length);//初始化 
bool append_arr(struct Arr* pArr,int val);//追加
bool insert_arr(struct Arr* pArr,int pos,int val);//pos的值从1开始 
bool delete_arr(struct Arr* pArr,int pos,int *pVal); 
bool is_empty(struct Arr* pArr);
bool is_full(struct Arr* pArr);
void sort_arr(struct Arr* pArr);
void show_arr(struct Arr* pArr);
void inversion_arr(struct Arr* pArr);

int main()
{
	int val;
	struct Arr arr;
	init_arr(&arr,6);
	append_arr(&arr,3);
	append_arr(&arr,14);
	append_arr(&arr,4);
	append_arr(&arr,6);
	append_arr(&arr,7);
	append_arr(&arr,8);
	delete_arr(&arr,6,&val); 
	show_arr(&arr);
//	inversion_arr(&arr);
//	printf("倒置输出：");
//	show_arr(&arr);
//	printf("冒泡输出");
//	sort_arr(&arr);
//	show_arr(&arr);
	return 0;
}
//为一个数组开辟堆的空间，大小为lenth 
void init_arr(struct Arr *pArr,int length)
{
	pArr->pBase=(int*)malloc(sizeof(int)*length);
	if(NULL==pArr->pBase)
	{
		printf("动态内存分配失败!");
		exit(-1);//终止整个程序 
	}
	else
	{
		pArr->len=length;
		pArr->cnt=0;
	}
	return;//告诉别人这个函数终止了 
}
//有效元素跟数组的长度一致时，这个数组就是满了 
bool is_full(struct Arr* pArr)
{
	if(pArr->cnt==pArr->len)
		return true;
	else
		return false;
}
//数组的有效元素为0时，这个数组就是空的 
bool is_empty(struct Arr* pArr)
{
	if(0==pArr->cnt)
		return true;
	else
		return false;
}

void show_arr(struct Arr* pArr)
{
	if( is_empty(pArr))//pArr本来就是地址，所以参数是pArr 
		printf("数组为空！\n");
	else
		{
			for(int i=0;i<pArr->cnt;i++)
			printf("%d     ",pArr->pBase[i]);//pArr本身就是一个结构体变量
			printf("\n");
		}
}

bool append_arr(struct Arr* pArr,int val)
{
	if( is_full(pArr))
		return false;
	//不满时追加
	pArr->pBase[pArr->cnt]=val;
	(pArr->cnt)++;
	return true; 
}
/*
*@pos表示的是要插入的位置，pos是从1开始的 
*cnt是有效数字的个数 
*如果pos<1和pos大于有效数字的2位 pos>cnt+1  假如cnt为3，pos为5 
*i表示的数组下标，有效数字的个数永远比下标小一位 ，所以 i=pArr->cnt-1
*i>=pos-1因为pos是比i大一位的，并且在移动时，pos所在的位置的元素也需要往后面移 
*
*
*/

bool insert_arr(struct Arr* pArr,int pos,int val)
{
	int i;
	if(is_full(pArr))
		return false;
	if(pos<1 || pos>pArr->cnt+1)//如果五个元素，只放了3个，不能插入第5个元素，没有第四个 
		return false; 
	for(i=pArr->cnt-1;i>=pos-1;i--)
	{
		pArr->pBase[i+1]=pArr->pBase[i];
	}
	pArr->pBase[pos-1]=val;
	pArr->cnt++;
	return true;
}
/*
*i=pos  删除一个位置的元素就是将后面的一位往前面移 
* 因为i是下标，pos是从1开始的，所以，i=pos，此时的i就是pos的下一位 
* i是需要小于有效的元素个数的， 因为i是下标，有效元素的个数总比i多一位  有效元素个数为1时，i为0 
*如果删除的是有效元素的最后一位，那么直接减少一个有效的元素个数就行了 
*
*/ 
bool delete_arr(struct Arr* pArr,int pos,int *pVal)
{
	if(is_empty(pArr))
		return false;
	if(pos<1||pos>pArr->cnt)//pos不能大于元素的个数
		return false;
	*pVal=pArr->pBase[pos-1];
	for(int i=pos;i<pArr->cnt;i++)// i是下标，i要从pos后面一位开始，也就是pos的值 
		pArr->pBase[i-1]=pArr->pBase[i];
		pArr->cnt--;
	return true;
	
}

void inversion_arr(struct Arr* pArr)
{
	int i=0;
	int j=pArr->cnt-1;
	while(i<j)
	{
		int temp=pArr->pBase[i];
		pArr->pBase[i]=pArr->pBase[j];
		pArr->pBase[j]=temp;
		i++;
		j--;
	}
	return;
} 

void sort_arr(struct Arr* pArr)
{
	int i,j;
	for(i=0;i<pArr->cnt;i++)
		for(j=i+1;j<pArr->cnt;j++)
			if(pArr->pBase[i]>pArr->pBase[j])
			{
				int temp=pArr->pBase[i];
				pArr->pBase[i]=pArr->pBase[j];
				pArr->pBase[j]=temp;
			}
}
