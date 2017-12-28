#include <iostream> 
using namespace std;
#define N 10

int main () {
	int arr[N][N]={0};
	for (int i=0; i<N; i++) {
		for (int j=0; j<=i; j++) {
			if(j == 0 && i == j ) {
				arr[i][j]=1;
				arr[i][j]=1;
			}else{
				arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
			}
		
		}
	}	
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<=i; j++) {
			cout<<arr[i][j]<<"     ";
		}
		cout<<endl;	
	}
	
	return 0;
}
