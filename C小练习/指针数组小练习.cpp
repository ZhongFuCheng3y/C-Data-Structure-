#include <iostream>
using namespace std;

int main() {
	int arr[100] = {0};
	int len;
	int average;
	int sum = 0;
	int *p;
	int *q;
		
	cout<<"输入长度：";
	cin>>len;
	
	for (int i=0; i<len; i++) {
		cin>>arr[i];
	}
	
	for (int i=0; i<len; i++) {
		sum = sum + arr[i];
	}
	p = arr;
	q = arr;
	average = sum / len;
	for(int i=0; i<len; i++) {
		if(*p < arr[i]) {
			p = arr+i;
		}
		if(*q > arr[i]) {
			q = arr+i; 
		}
	}



	cout<<"最大值："<<*p<<endl;
	cout<<"最小值："<<*q<<endl;
	cout<<"平均值："<<average<<endl;
	
	
	return 0;
} 
