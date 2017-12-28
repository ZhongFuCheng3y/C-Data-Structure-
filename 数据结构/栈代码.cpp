#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*
*栈始终遵循着先进后出的原则 
*定义的栈结构体，实际上就是两个指针，这两个指针时是指向节点的，分别定义了栈顶和栈尾 
*
*
*/ 



//这里创建一个结构体变量，里面有数据域，指针域
 
typedef struct Node
{
	int data;
	struct Node* pNext;
} NODE,*PNODE;
//这里创建一个结构体变量，是定义为指向栈顶和栈尾的两个指针 
typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom; 
}STACK, *PSTACK;

void traverse(PSTACK pS);
void push(PSTACK pS,int val);
void init(PSTACK pS); 
bool empty(PSTACK pS);
bool pop(PSTACK pS,int* pVal);
void clear(PSTACK pS);

int main(void)
{
	int pVal;
	STACK S;
	init(&S);
	push(&S,2);
	push(&S,6);
	push(&S,7);
	push(&S,8);
	push(&S,9);
	traverse(&S);
	pop(&S,&pVal);
	traverse(&S);
	return 0;
}
//初始化
//创建一个头结点，令pTop（一个指向结构体的指针）指向头结点 
//将顶部赋值给底部，并顶部的指针域设置为NULL 
void init(PSTACK pS)
{
	pS->pTop=(PNODE)malloc(sizeof(NODE));
	if(pS->pTop==NULL)
	{
		printf("动态内存分配失败！\n");
		exit(-1); 
	}
	else
	{
		pS->pBottom=pS->pTop;
		pS->pTop->pNext=NULL;//ps->top指向的是空节点，Ps->pTop->next表示的是指向空节点的那个指针域 
	}
}
//压栈
//思路：
//		创建一个新节点，赋值给新节点，让新节点指向上面创建的空节点，然后令指向栈顶的指针指向新节点 
// 		pNew->pNext= ps->pTop表示的是新节点的指针域存放栈顶的地址（能够让栈顶本来指向的地方给pNew指向） 
//      最后就是让栈顶指向新元素 
void push(PSTACK pS,int val)
{
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	
	pNew->data=val;
	pNew->pNext=pS->pTop;
	pS->pTop=pNew;
	
	return;
}
//遍历：
//		定义一个指针从栈顶开始，只要指针不到栈尾，就一直输出循环 
void traverse(PSTACK pS)
{
	PNODE p=pS->pTop;
	
	while(p!=pS->pBottom)
	{
		printf("%d  ",p->data);
		p=p->pNext;
	}
	printf("\n");
	return;
}
//只要栈顶和栈尾的指向是相同的，那么这个栈是空的 
bool empty(PSTACK pS)
{
	if(pS->pTop==pS->pBottom)
		return true;
	else
		return false;
}

//把pS所指向 栈出栈一次，并把出栈的元素存入pVal形参所指向的变量中，成功返回true，失败返回false 
//出栈实际就是栈顶往下面移一位 
//思路：  首先定义一个指针r指向栈顶，然后将栈顶的数据存储起来
//		将r的指针域赋值给指向栈顶的指针（实际就是栈顶往下面移一位），出栈了。 
bool pop(PSTACK pS,int* pVal)
{
	if(empty(pS))
		return false;
	else
	{
		PNODE r=pS->pTop;
		*pVal=r->data;
		pS->pTop=r->pNext;
		free(r);
		r=NULL;
	}
		return true; 
}

//清空整个栈
//思路：将p指向的下一个节点赋值给q，然后清空p的内存，再将q重新赋值给p，依此循环，直到p指向了栈尾 
// 		最后栈顶和栈尾的指针会指向空节点 
void clear(PSTACK pS)
{
	if(empty(pS))
		return;
	else
	{
		PNODE p=pS->pTop;
		PNODE q=NULL;
		
		while (p!=pS->pBottom)
		{
			q=p->pNext;
			free(p);
			p=q;
		}
		pS->pTop=pS->pBottom;
	}
}



