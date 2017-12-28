#include <stdio.h>
#include <iostream>
#include <string.h> 
using namespace std;

/*
*两个很大很大的数相加，int之间的相加不能满足 
*把数据装进一个字符数组，算出字符数组的长度，将数组的最后一位与输入的数组的最后一位交换 num[j] = num[n-i]，直到把n交换完 
*然后将数组前面的数全部化字符0 
*随后将字符数组转化为数字 
*进位问题：如果两个数相加是大于0的，那么前一位num【i-1】就加上num/10 ，当前num就取num%10； 
*/ 



 
void move_num(char num[])
{
	int n=strlen(num);//计算出字符串的长度 
	int j=100;
	int i;
	for(i=1; i<=n; i++)//将已知数组最后一位与数组长度中的最后一位作交换 
	{
		num[j] = num[n-i];
		j--;
	}
	while (j>=0)//将数组前面的数化作字符0 
	{
		num[j]='0';
		j--;
	}
}

void conv_num(char num[])//将字符转化为数字 
{
	int i;
	for(int i=0;i<=100;i++)
		num[i]=num[i]-'0';
}

void add(char num1[],char num2[] )
{
	int i;
	int sum;
	for(i=100;i>0;i--){ 
		num1[i] = num1[i] + num2[i];//个位相加减 
		if(num1[i] >= 10){
			num1[i-1] += num1[i]/10;//进位时的情况 
			num1[i] = num1[i]%10;
		}
	} 
}

void printfNum(char num[])
{
	int i;
	while(num[i]==0)
		i++;
	for(;i<=100;i++)
		printf("%d",num[i]);//打印的是数字 
}

int main()
{
	char num1[101];
	char num2[101];
	scanf("%s",num1);
	scanf("%s",num2);
	move_num(num1);
	move_num(num2);
	conv_num(num1);
	conv_num(num2);
	add(num1,num2);	
	printfNum(num1);
	return 0;
}
