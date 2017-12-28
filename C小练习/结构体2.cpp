#include <iostream>
using namespace std;

typedef struct library {
	char name[20];
	char autor[20];
	char adress[20];
	double price;
}book;

void show(book book2[]) {
	for (int i=0; i<2; i++) {
		cout<<"第"<<i<<"本书的价格是"<<book2[i].price<<endl;
		cout<<"第"<<i<<"本书的名字是"<<book2[i].name<<endl;
		cout<<"第"<<i<<"本书的出版社是"<<book2[i].adress<<endl;
		cout<<"第"<<i<<"本书的作者是"<<book2[i].autor<<endl;
		cout<<endl;
		cout<<endl;
			

	}
}

int main() {
	book book2[5];
	double sum = 0;
	int arr[5];
	for (int i=0; i<2; i++) {
		cout<<"输入出版社名称：";
		cin>>book2[i].adress;
		cout<<"输入作者:";
		cin>>book2[i].autor;
		cout<<"输入价格：";
		cin>>book2[i].price;
		cout<<"输入书的名字";
		cin>>book2[i].name;
		sum+=book2[i].price;
		cout<<endl;
		cout<<endl;
	}
	cout<<"2本书的平均价格："<<sum/2<<endl<<endl;
	show(book2);

	
	return 0;
}
