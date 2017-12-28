#include <stdio.h>
#include <string.h>
#define N 7
/**
*将罗马字转化为阿拉伯数字 
*算法：首先 将字符和值分别存入数组中，当程序员输入字符串时，把字符串改成数字 
*核心： 找出当中字符串代表的值最大的位置， 递归调用romanToNumber 
*max=left - right  
*
*/

char digits[N] = {'I', 'V', 'X', 'L', 'C','D', 'M'} ;
int  values[N] = { 1,  5, 10, 50, 100, 500, 1000};


int digitsToValues(char ch) {
	int i;
	for (i=0; i<N; i++) {
		if (digits[i] == ch) {
			return values[i];
		}
	}
	return 0;
}

int findMaxIndex(char str[], int L, int R) {
	int max = digitsToValues(str[L]);
	int maxIndex = L;
	int i;
	for (i=L; i<R; i++) {
		int num = digitsToValues(str[i]);
		if(num > max) {
			max = num;
			maxIndex = i;
		}
	}
	return maxIndex;
}

int romanToNumber(char str[], int L, int R) {
	if (L == R) {
		return digitsToValues(str[L]);	
	}
	else if (L > R) {
		return 0;
	}
	else {
		int mi = findMaxIndex(str, L, R);
		int max = digitsToValues(str[mi]);
		int left = romanToNumber(str, L, mi-1);
		int right = romanToNumber(str, mi+1, R);
		return max - left + right;
	}
	
}

int romanToNumber2(char str[]) {
	int L = 0;
	int R = strlen(str) - 1;
	return romanToNumber(str, L, R);
}

int main() {
	char str[]="XVIII";
	int result = romanToNumber2(str);
	printf("%d\n", result);
	return 0;
	
}
