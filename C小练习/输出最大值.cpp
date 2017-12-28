#include <iostream>
using namespace std;

int main() {
	int max = 0;
	double average = 0;
	double sum = 0;
	int n;
	cout<<"输入你要计算的个数：";
	cin>>n; 
	cout<<endl;
	cout<<"输入数值：";
	int arr[n];
	for (int i=0; i<n; i++) {
		cin>>arr[i];
	}
	max = arr[0];
	for(int i=0; i<n; i++) {
		sum += arr[i];
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	average = sum / n;
	cout<<"少于平均分的有：";
	for(int i=0; i<n; i++) {
		if(arr[i] < average) {
			cout<<arr[i]<<"    ";
		}
	}
	cout<<endl;
	
	cout<<"最大值是："<<max;
	
	return 0;
}
