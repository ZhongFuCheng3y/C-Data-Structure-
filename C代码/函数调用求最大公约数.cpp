#include <iostream>
using namespace std;
//算法:
//     求一个数的最大公约数，就是两个数相余，直到余数为0，如果余数不为0，就用除数和余数求余，
//     若发现余数为0，那么当前的除数就是最大公约数 
//     两个数的大小不必理会  例如：5和35   5%35=5，随后 35%5=0，  最大公约数为5 
int gcd(int a,int b)
{
	int r=a%b;//当余数为零时，b就是最大公约数 
	if(r==0)
		return b;
	else 
		return gcd(b,r);//实际上就是b和r求余 
} 

int main()
{
	int a, b;
	cin>>a>>b;
	int g=gcd(a,b);
	cout<<g<<endl;
	return 0;
	 
}
