#include <iostream>
using namespace std;
/*
求"1！+4！(2的平方)+9！(3的平方)的值 
思路：定义f1函数计算平方值，然后定义f2函数计算乘积
	  将平方值代入f2中，可以求出该数的乘积，将乘积的值返回给f1函数,f1的值再返回给主函数； 
	  最后主函数sum累加即可 
	  
	 


*/

long f1(int p) {
	int k;
	long r;
	long f2(int );
	k = p * p;
	r = f2(k);
	return r;
	
} 

long f2 (int q) {
	long c = 1;
	int i;
	for (i=1; i<=q; i++) {
		c = c * i;
	}
	return c;
}

int main() {
	int i;
	long s = 0;
	for (i=1; i<=3; i++) {
		s = s + f1(i);
	}
	cout<<"1！+4！+9！="<<s<<endl;
	return 0;
}
