#include <iostream>
#include <cstring>
using namespace std;

/*
输入一段字符，计算出里面单词的个数，单词之间用空格隔开 ,一个空格隔开，就代表着一个单词了 
思路：
	首先计算出字符串的长度，把字符遍历一遍
	累计由空格串转换为非空格串的次数，次数就是单词的个数 
	定义一个标志性变量flag，0表示的是空格状态，1表示的是非空格状态
	字符串只有空格状态和非空格状态，所以if(单词是空格状态)。。能进入else if(flag==0)肯定就是非空格状态了
	用else 和else if 的区别，else是计算出字母的个数，只要该字符不是空格，字母个数就+1 
	而else if增加flag==0条件，说明当前的字符不是空格并且flag不为1，那么单词就不+1 



*/
int main() {
	char arr[40];
	int i = 0;
	int number = 0;
	int flag = 0;
	cout<<"请输入一行字符：";
	cin.getline(arr,39);
	for (i=0; i<strlen(arr); i++) {
		if (arr[i] == ' ') {
			flag = 0;
		}
		else if (flag == 0) {
			number++;
			flag = 1;
		}
	}
	cout<<"单词的个数是："<<number;
	return 0;
} 
