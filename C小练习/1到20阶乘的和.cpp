#include <iostream>
using namespace std;

//������Ҫ���ǽ׳����⣬
//���������i��t�Ĺ�ϵ��t = t * i; t��ֵ���ϸı䣬ÿ��*i��ʱ��t����i-1�Ľ׳�
//���� ��iΪ4��ʱ��t�Ѿ���1*2*3�ˡ� ...
int main() {
	float sum = 0;
	float t= 1;
	for (int i=1; i<=20; i++) {
		t = t * i;
		sum = sum + t;
	}
	
	cout<<"1��20�׳˵ĺ��ǣ�"<<sum;
	
	return 0;
}
