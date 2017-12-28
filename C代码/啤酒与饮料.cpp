#include <iostream>
using namespace std;
/*
*   啤酒每罐2.3元，饮料每罐1.9元。小明买了若干啤酒和饮料，一共花了82.3元。    
*	我们还知道他买的啤酒比饮料的数量少，请你计算他买了几罐啤酒
* 
*算法： 
*	用两个for循环，从0开始，再写出对应的条件即可 
*/
int main() {


	for (int i=0; i<37; i++) {
		for (int j=0; j<44; j++) {
			if(2.3 * i + j * 1.9 == 82.3&&i < j){
				cout<<i<<endl;
				cout<<j<<endl;
			}
		}
	}
	return 0;
}
