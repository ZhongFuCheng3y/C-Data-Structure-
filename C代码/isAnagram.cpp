#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//给定两个字符串s和t，判断这两个字符串中的字母是不是完全一样（顺序可以不一样） 
//基本算法： 将字符串遍历一遍，找出字母的下标，将字母的下标存入数组中。 
// +1表示出现过一次。如果两个数组中的元素出现的次数相同，那么成立 


bool isAnagram(char s[], char t[]){
	int statS[26] = {0};//将所有的数设置为0 
	int statT[26] = {0};
	int lenS = strlen(s);
	int lenT = strlen(t);
	int i;
	for(i=0; i<lenS; i++){
		int index = s[i]-'a';//这里能够计算出字符在数组中的位置。比如'b'-'a' 为1，在数组中，b的下标就是1 
		statS[index]++;	//这里++ ， 重复了多少次，数值就是多少，因为初始值为0 
	}

	for(i=0; i<lenT; i++){
		int index = t[i]-'a';
		statT[index]++;	
	}
	//这里比较的是元素大小，相当于就是元素出现的次数。
	//把整个数组遍历一遍，只要没有不一样的，那么这两个字符串的字母就是一样了（不算顺序） 
	for(i=0; i<26; i++){
		if(statS[i] != statT[i]){
			return false;
		}	
	}
	return true;
}

int main(){
	
	char s[] = "ttn";
	char t[] = "nnt";
	printf("%d\n",isAnagram(s,t));
	return 0;
}
  
