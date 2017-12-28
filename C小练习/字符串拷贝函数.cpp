#include <iostream>
#include <cstring>
using namespace std;
//串结束表示'\0'也会一同拷贝，第二个参数可以是字符串常量 
int main() {
	char str1[100];
	char str2[100];
	char str3[] = "c++编程";
	strcpy(str1,str3);
	strcpy(str2,"C++编程很有趣");
	cout<<"str1="<<str1<<endl;
	cout<<"str2="<<str2<<endl;
	
	
	
	return 0;
} 
