#include <iostream>
using namespace std;

int main() {
	char arr[100];
	char arr2[100];
	char arr3[100];
	char *p;
	char *q;
	int i = 0;
	
	cout<<"输入一个字符串:";
	gets(arr);
	p = arr;
	while (*p != '\0') {
		arr3[i] = *p;
		i++;
		p++; 
	}
	
	cout<<"输入另外一个字符串：";
	gets(arr2);
	q = arr2;
	while (*q != '\0') {
		arr3[i] = *q;
		i++;
		q++; 
	}
	
	puts(arr3);
	return 0;
} 
