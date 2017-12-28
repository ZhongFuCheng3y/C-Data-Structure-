#include <stdio.h>
#include <stdbool.h>
//判断一个数是不是2的某次方 
//算法：如果是2的某次方，那么一直取余，最后会等于1 
//如果n==0；，那么就会死循环

 
bool isPowerOfTwo(int n){
	if(n==0){
		return false;
	}

	while(n % 2 == 0){
		n=n/2;
	}
	if(n == 1){
		return true;
	}
	else{
		return false;
	}
}
//还有一种逻辑与运算符方法
//算法： 2的n次方都有一个特点，二进制都是1000000
// 如果 2的n次方的二进制-1和2的n次方二进制做按位与运算，那么得出的结果肯定是0 
//巧妙运用了运算符·2的平方的特点。、 

bool isPowerOfTwo(int n) {
	if(n <= 0){
		return false;
	}
	else if(n == 1){
		return true;
	}
	else{
		if( (n & (n-1) ) == 0){
			return true;
		}
		else{
			return false;
		}
	}
}

int main() {
	printf("%d\n",isPowerOfTwo(16));
	return 0;
}
