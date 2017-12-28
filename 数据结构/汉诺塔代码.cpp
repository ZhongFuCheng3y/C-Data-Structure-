#include <iostream>
using namespace std;


/*
* @A,@B,@C表示的是三根柱子 
* 把柱子分成两段，递归调用函数 
* 可以发现，n-1是绕过C移动到B的 ，然后从B绕过A移动到C 
*
*/ 
void hanoi(int n,char A,char B,char C)
{
	if(n==1)
		printf("%c ->%c\n",A,C); 
	else
	{
		hanoi(n-1,A,C,B);//n-1绕过C到B 
		printf("%c ->%c\n",A,C);
		hanoi(n-1,B,A,C);
	}
} 

int main()
{
	hanoi (2,'A','B','C');
	return 0;
}
