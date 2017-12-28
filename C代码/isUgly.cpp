#include <iostream>
using namespace std;

//判断一个数字是不是ugly number（分解出来的质因数只有2、3、5这3个数字）
//如果是由2,3,5组成的，那么这个数不断除以2,3,5，最后得出的是1，这个数就是纯粹用2,3,5组成的
 



//如果输入的值是0的话，那么这个函数就会死循环；

 
bool isUgly(int num){
	if(num<=0){
		return false;
	}
	else{
		while(num%2==0){
			num=num/2;
		}
		while(num%3==0){
			num=num/3;
		}
		while(num%5==0){
			num=num/5;
		}
		if(num==1){
			return true;
		}
		else{
			return false;
		}
	}
}
//如果一个数%2，%3，%5最后的值是1的话，那么这个数是由若干个2,3,5构成的。。 
int main(){
	if( isUgly(30) ){
		cout<<"这个数是Ugly num";	
	}
	else{
		cout<<"这个数不是Ugly num";
	}
	return 0;
	
}
