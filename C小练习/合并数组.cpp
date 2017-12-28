#include <iostream>
using namespace std;


int main() {
	int arr[4] = {7,4,2,1};
	int arr1[4] = {9,8,5,3};
	int arr2[8];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i <4 && j < 4) {
		if(arr[i] > arr1[j]) {
			arr2[k] = arr[i];
			i++;
			k++;
		}
		else {
			arr2[k] = arr1[j];
			j++;
			k++;
		}
	}
	while (i < 4) {
		arr2[k] = arr[i];
		k++;
		i++;
	}
	while (j < 4) {
		arr2[k] = arr1[j];
		k++;
		j++;
	}
	cout<<"合并后的数组：";
	for (k=0; k<8; k++) {
		cout<<arr2[k]<<"    ";
	}
	return 0;
}
