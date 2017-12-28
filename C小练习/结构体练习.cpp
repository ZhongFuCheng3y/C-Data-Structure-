#include <iostream>
using namespace std;

typedef struct student {
	char name[10];
	char num[20];		
	int mark[30]; 

}student1;
	

int main() {
	student1 student2[10];
	int sum = 0;
	int arr[10];
	int max;
	int x = 0;
	int temp = 0;
	for (int i=0; i<3; i++) {
		cout<<"输入学生的学号:";
		cin>>student2[i].num;
		cout<<"输入学生的姓名:";
		cin>>student2[i].name;
		cout<<"输入学生的成绩:";
		for(int j=0; j<3; j++) {
			cin>>student2[i].mark[j];
			sum = sum+student2[i].mark[j];
		}
		arr[x] = sum;
		max = arr[0];
		sum = 0;
		x++;
	
	}
	for (int x = 0; x<3; x++) {
		if(arr[x] > max) {
			max = arr[x];
			temp = x;
		}
	}
	cout<<"最高分是："<<max<<endl<<"最高成绩的学生是："<<student2[temp].name;
	

	
	
	return 0;
} 
