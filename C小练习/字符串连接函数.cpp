#include <iostream>
#include <cstring>
using namespace std;
//连接函数，会自动删除数组1末尾的'\0' 

int main() {
	char str1[100] ="Good moring!"; 
	char str2[100];
	cout<<"请输入您的名字：";
	cin>>str2;
	strcat(str1,str2);
	cout<<str1<<endl;
	
	
	return 0;
}
