#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void sort(char** arr,int n)
{
	int i,j;
	for(i=n-1;i>0;i--)
		for(j=0;j<=1;j++)//冒泡排序 
			if(strcmp(arr[j],arr[j+1])>0)//比较字符串大小只能用strcmp 
				{
					char *temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
} 

int main()
{
	int count;
	int i;
	
	char** arr=(char **)malloc(sizeof(char*) * 3);//创建一个字符串数组 
	for(i=0;i<3;i++)                              //char *是一个字符串 
	{											  //char **是一个字符串数组  malloc前面强制转换 
		arr[i]=(char *)malloc(sizeof(char)*10);   //为 字符串开辟空间 
		scanf("%s",arr[i]);
		
	}
	sort(arr,3);
	for(i=0;i<3;i++)
		printf("%s\n",arr[i]);
	
	return 0;
	
}
