#include <iostream>
#include <cstring>
/*
*写出一段程序， 当你输入a+b或者a-b之类的，能够算出答案 
*算法：
*		输入的是一串字符，要进行符号（加号和减号）（数字）的分类，并且输入的数字字符要改变为阿拉伯数字		    
*		判断当前的是加号还是减号 return  a+b或者a-b 
*		进行运算，实际就是看有多少个运算符，while循环，直到运算符全部用光 
*		用一个result变量存入第0个元素，如果没有运算符，直接输出result 
*
*/

int values[100];
char opts[100];
int countV=0;
int countO=0;

void tokenize(char buffer[])
{
	int i;
	int n=strlen(buffer);
	for(i=0;i<n;i++)
	{
		if(buffer[i]>='0'&&buffer[i]<='9')
		{
			values[countV]=buffer[i]-'0';
			countV++;
		}
		else
		{
			opts[countO]=buffer[i];
			countO++;
		}
	}
}

int calculate(int a,int b,char o)
{
	if(o=='+')
		return a+b;
	else
		return a-b;
}

int computeAll()
{
	int result=values[0];
	int i=1;
	int j=0;
	while(j<countO)
	{
		int a=result;
		int b=values[i];
		char o=opts[j];
		result=calculate(a,b,o);
		j++;
		i++;
	}
	return result;
}

int main()
{
	char buffer[1024];
	int i;
	scanf("%s",buffer);
	
	tokenize(buffer);
	int result=computeAll();
/*	for(int i=0;i<countV;i++) { 
		printf("%d\n",values[i]);
		
	}	
*/							
	//测试是否能录入数字			
/*		for(int i=0;i<countO;i++) { 
			printf("%c\n",opts[i]);
		}	
*/								
	//测试是否能录入字符 
	printf("%d\n",result);
	return 0;
}

