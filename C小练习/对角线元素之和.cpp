#include <iostream>
using namespace std;

int main() {
	int arr[4][4];
	int i;
	int j;
	int sum;
	cout<<"依次输入第一行第二行第三行第四行的值："<<endl;
	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			cin>>arr[i][j];
		}
	}
	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			if(i == j) {
				sum += arr[i][j];
			}
		}
	}
	cout<<"对角线的元素之和为:"<<sum;
	
	
	return 0;
}
