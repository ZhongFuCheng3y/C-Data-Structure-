#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int num;
	struct node* next;
}NODE, *PNODE;
//创建一个生成节点的函数，数据域是用户输出的，指针域是指向NULL 
PNODE new_node(int num) {
	PNODE n=(PNODE)malloc(sizeof(NODE));
	n->num = num;
	n->next = NULL;
	return n;
}
//将一个数组转化成链表 
int main() {
	
	int A[5] = {2, 5, 4, 7, 8};
	int i;
	PNODE head = new_node(A[0]);
	PNODE p = head;
	for (i=1; i<5; i++) {
		PNODE n = new_node(A[i]);
		p->next = n;
		p = p->next;
	}
	//插入节点
	//n1->next = p->next;     这里是让原本p指向的指针改变成n1指向 能够让p原来指向的节点的链的断掉 
	//p->next = n1;           p指向n1 
	p = head;         	 //这里p的位置已经变了，所以要重置 
	while (p->num != 4) {
		p = p->next;
	}
	PNODE n1 = new_node(6);
	n1->next = p->next;
	p->next = n1;
	
	//删除节点
	//要找到删除元素值的前一个位置 
	p = head;			//这里p的位置已经变了，所以要重置 
	NODE* pr;
	while (p->next->num != 8) {
		p = p->next;
	} 
	pr = p->next;
	p->next = p->next->next;
	free(pr);
	
	
	p= head;
	while (p != NULL) {
		printf("%d\n", p->num);
		p = p->next;
	}
	
	return 0;
}
