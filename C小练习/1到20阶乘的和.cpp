#include <iostream>
using namespace std;

//这里主要的是阶乘问题，
//巧妙地运用i和t的关系，t = t * i; t的值不断改变，每次*i的时候，t都是i-1的阶乘
//比如 当i为4的时候，t已经是1*2*3了。 
int main() {
	float sum = 0;
	float t= 1;
	for (int i=1; i<=20; i++) {
		t = t * i;
		sum = sum + t;
	}
	
	cout<<"1到20阶乘的和是："<<sum;
	
	return 0;
}
