#include <stdio.h>
#define UINT unsigned char

/**
*题目：将二进制的数字倒转 
*算法：把二进制分为两部分，进行交换，不断缩小两部分的个数，直到两个两个数交换 
*过滤：将二进制用00001111过滤，提取右边的数字，左移4位，变成了左边的数字。
*      将二进制先右移4位，变成了右边的数字,再过滤。
*      相加以后，左边和右边就倒过来了. 
*/



UINT reverse(UINT a) {
	int m_4 = 0x0f;
	int m_2 = 0x33;
	int m_1 = 0x55;
	
	int b = ( (a & m_4) << 4 ) + ( (a >> 4) & m_4 );
	int c = ( (b & m_2) << 2 ) + ( (b >> 2) & m_2 );
	int d = ( (c & m_1) << 1 ) + ( (c >> 1) & m_1 );
	
	return d;
	
}

int main() {
	UINT a = 67;
	UINT b = reverse(a);
	UINT c = reverse(b);
	
	printf("%d %d \n", a, c);
	return 0; 
}
