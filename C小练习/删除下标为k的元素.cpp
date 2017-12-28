#include <iostream>
using namespace std;

/*
*思路：把k赋值给i，让i的后面一项等于前面一项，实际上就是往前移，直到整个数组移完 
*最后将m减1即可。 
*
*/

int main() {
	int const N = 10;
	int arr[N] = {2,6,9,12,32,45,54,57};
	int m = 8;
	int k;
	int i;
	
	cout<<"输入您需要删除的元素下标";
	cin>>k;
	
	for(i=k; i<N-1; i++) {
		arr[i] = arr[i+1];
	}
	m--;
	
	for (i=0; i<m; i++) {
		cout<<arr[i]<<"  ";
		
	}
	cout<<endl;
	
	
	
	return 0;
} 
