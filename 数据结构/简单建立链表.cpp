#include <iostream>
using namespace std;
/*
*思路： 创建一个结构体，链表有数据域和指针域 
* 		指针域是指向自己数据结构体的指针 
*		为数据赋值，每一个指针域指向的是下一个节点的地址 
*		p=p->pNext 不断指向下一个节点的地址 
*
*/


typedef struct node
{
	int num;//数据域 
	struct node *next;//指向自己数据结构的指针 
}NODE;


main()
{
	NODE n1,n2,n3;//为数据域赋值 
	n1.num=5;
	n2.num=7;
	n3.num=9;
	
	n1.next=&n2;//next是指针类型，所以要取地址。 
	n2.next=&n3;
	n3.next=NULL;
	NODE *p=&n1;//定义一个指针指向n1 
	while (p!=NULL)
	{
		cout<<p->num<<endl;
		p=p->next;//指向下一个元素 
	} 
	return 0; 
} 
 
