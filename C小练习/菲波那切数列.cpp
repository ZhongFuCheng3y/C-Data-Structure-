#include <iostream>
using namespace std;
//菲波那切数列：fn=fn-1+fn-2   f1 = 1; f2 = 1; 
int main() {
	double f1;
	double f2;
	int i;
	f1 = f2 = 1;
	for (i=1; i<=10; i++) {
		
		cout<<"     "<<f1<<"     "<<f2;
		f1 = f1 + f2;//这里的f1指的是第三个数字 
		f2 = f2 + f1;//这里的f2指的是第四个数字 
		//从上面可以得出，f1和f2是会不断改变的，所以值是一路往下增加 
		//控制每输出4个数字就换行    
		if(i % 2 == 0) {
			cout<<endl;
		}
	}
	
	
	
	
	return 0;
}
