#include <iostream>
using namespace std;

int main(int argc,char** argv)//argc记录参数数量
{
	//argv 字符串数组，当argc【0】时，输出程序的名字 
	cout<<argc<<endl;
	cout<<*argv+1<<endl;
	return 0;
}

