#include <stdio.h>

int main()
{
	int a,b;
	int c;
	FILE* file=fopen("data.txt","r");//FILE*是数据类型 ,r是读入 
	FILE* f2=fopen("result.txt","w");//file是变量名，w 是写入 
	 
	fscanf(file,"%d",&a);
	fscanf(file,"%d",&b);
	c=a+b; 
	fprintf(f2,"%d\n",c);
	fclose(file);
	fclose(f2);
	return 0;
} 
