#include <iostream>
#include <cstring>
using namespace std;
//求1995以内最大的对称数 
/**
*思路： 将一个数字改变成二进制，二进制当做字符串存入字符数组 （字符数组末尾需要'/0'）
*判断最后一个与第一个是否相等，以此类推 ，直到i<j 
*/
void dec2bin(int num,char result[])//转换二进制 
{
	int i=0;
	while(num>0)
	{
		int q=num/2;
		int r=num%2;
		result[i]=r+'0';
		i++;
		num=q;
	}
	result[i]='\0';
}

int is_symmetric(char input[])
{
	int n=strlen(input);
	int i=0;
	int j=n-1;
	while(i<j)
	{
		if(input[i]==input[j])
		{
			i++;
			j--;
		}
		else
			return 0;
	}
	return 1;
}

int main()
{
	int num;
	char result[20];
	for(num=1993;num>0; num--)
	{
		dec2bin(num,result);
		if(is_symmetric(result)==1)
		{
			printf("%d\n",num);
			printf("%s\n",result);			
			break;
		}
		
	}
	
	return 0;
	
}
 
