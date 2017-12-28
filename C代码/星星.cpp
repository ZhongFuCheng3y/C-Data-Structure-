#include <stdio.h>

/**
*@n表示的是n行 
*@L表示的是最长的那一行 
*@a表示画星星
*@s表示画空格 
*/


/**
*思路：先把第n行画出来，再添加一个for循环成为三角形 
*星星数就等于2n-1； 
*空格：因为最长的一行没有空格，所以根据规律得出：（最长的一行减去行数）s=L-n 
*菱形其实就是倒三角，行为L-1，行数不断减少，直到为1 
*/

int main() {
	int L = 4;
	int n = 1 ;
	int i;
	for (n=1; n<=L; n++) {
		int s = L - n;
		//画空格 
		for(i=1; i<=s; i++) {
			printf(" ");
		}
		//画星星 
		int a = 2 * n - 1;
		for (i=1; i<=a; i++) {
			printf("*");
		}
		printf("\n");
	}
//	for (n=L-1; n>=1; n--){
//		int s = L - n;
//		//画空格 
//		for(i=1; i<=s; i++) {
//			printf(" ");
//		}
//		//画星星 
//		int a = 2 * n - 1;
//		for (i=1; i<=a; i++) {
//			printf("*");
//		}
//		printf("\n");
//	}
	return 0;
}
