#include <iostream>
using namespace std;

//把一个数字的各个数位上的数加起来，直到只剩下一个一位数
//首先就是把数字不断拆开一位数，用%10的方法，将每位数相加到sum里面去，直到这个数没法拆分了
//然后将sum（此时的sum有可能是大于0的），那么需要继续判断，将sum给 while(sum>=10)判断，
//如果大于0，则重复上个函数 

int sumDigits(int num) {
	int sum = 0;
	
	while(num != 0){
		int d = num%10;
		sum = sum+d;
		num = num/10;
	}
	
	return sum;//这里就是把一个数的各个数位上的数加起来，返回sum 
}

//如果这个数大于10，那么就重复执行上面的函数， 

int addDigits(int num){
	
	while( num >= 10){
		  num = sumDigits(num);
	}
	
	return num;
}

int main(){
	
	int num = addDigits(721);
	
	cout<<num;
	
	return 0;
}

/*
只要这个数是大于10的，我就把它分解，用while语句，其中调用了另一个函数而已
 
*/
