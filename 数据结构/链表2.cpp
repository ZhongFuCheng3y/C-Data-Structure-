#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE,*PNODE;//定义一个结构体变量 

PNODE create_list(void);
void traverse_list(PNODE pHead); 
bool is_empty(PNODE pHead);
bool insert_list(PNODE,int,int);
int length_list(PNODE);
bool delete_list(PNODE,int,int*);//把哪个节点给删除了 
void sort_list(PNODE); 

int main(void)
{
	PNODE pHead =NULL;//定义 一个结构体变量pHead 
	pHead=create_list();//创建一个函数，返回pHead的值 
	traverse_list(pHead);
	int val;
	if( delete_list(pHead,2,&val) )
		printf("删除成功，元素是:%d\n",val);
	else
		printf("删除失败\n");
	traverse_list(pHead);
	return 0;
}
/*
*思路： 创建一个不存放数据的头结点 
*		PNODE pTail=pHead;//如果节点只有一个，那么pTail也是尾节点
*		按照用户输入多少个节点并给出值，动态创建节点的空间 
*		把新生成的节点挂到pHead上面。此时我们需要一个永远指向Null的指针（也就上面的第二行） 
*		首先pNew赋值数据域，pTail->next=pNew  将新生成的节点挂在尾指针后面    
*		pNew->next->NULL将新生成的节点指向空 
*		再把pNew赋值给pTail，这样就能够使pTail永远指向NULL； 
*/ 

PNODE create_list(void)
{
	int len;
	int i;
	int val;
	//创建一个不存放有效数据的头结点 
	PNODE pHead=(PNODE)malloc(sizeof(NODE));
	if(pHead==NULL)
	{
		printf("分配失败，程序终止！");
		exit(-1); 
	}
	PNODE pTail=pHead;//如果节点只有一个，那么pTail也是尾节点 
	pTail->pNext=NULL;//永远指向尾节点 
	printf("请输入您需要生成的链表节点的个数:len=");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("请输入第%d个节点的值",i+1);
		scanf("%d",&val);
		PNODE pNew=(PNODE)malloc(sizeof(NODE)); 
		if(pNew==NULL)
		{
			printf("分配失败，程序终止！\n");
			exit(-1);
		}
		pNew->data=val;//节点的数据域是val 
		pTail->pNext=pNew;//pTail指向pNew 
		pNew->pNext=NULL;//pNew指向NULL 
		pTail=pNew;//将pNew赋给pTail            使pTail永远指向尾节点 
	}
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p=pHead->pNext;//定义一个指向第一个有效数据节点的指针 
	while(p!=NULL)
	{
		printf("%d	",p->data);
		p=p->pNext;
	} 
	printf("\n");
	return; 
}

bool is_empty(PNODE pHead)
{
	if(pHead->pNext==NULL)//判断链表是否为空 
		return true;
	else
		return false; 
} 
//计算出链表的长度 
int length_list(PNODE pHead)
{
	int cnt=0;
	PNODE p=pHead->pNext; 
	while(p!=NULL)
	{
		cnt++;
		p=p->pNext;
	}
	return cnt;
}

void sort_list(PNODE pHead)
{
	int i,j,temp;
	int len= length_list(pHead);//首先要知道链表的长度 
	PNODE p,q;
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)//冒泡排序 
		for(j=i+1,q=p->pNext;j<len;++j,q=q->pNext) 
				if(p->data>q->data)
				{
					temp=p->data;
					p->data=q->data;
					q->data=temp;
				}
				
} 



/*
*  在链表的第pos个节点的前面插入一个新的节点 ，该节点的值是val，并且pos从1开始
*  思路：要想插入一个节点，首先直到插入节点的前一个节点 
*	@pos我们定义pos必须知道前面一个节点，比如（只有3个节点，你的插入位置不能超过4）	
*	@i    p开始的是指向phead的，i=0可以看作是phead（头结点）的位置，i<pos-1这里
*	如果pos的值是2,那么p->next就会移动到首节点上，也就是链表的第1个有效值，也是要插入位置的前一个节点 
*   如果没有减一，也以pos=2为例，语句会循环两次，此时p会指向到pos的位置上，也就是链表的第二位 
*	p ！= NULL（确保p不会超出整张链表节点个数）  i< pos-1（找出要插入节点位置的前一个节点） 
*	多定义一个临时变量q，首先把p的指针域赋值给q（q存放p的指针域），q=p->pNext
*	然后将pNew的地址赋值给p的指针域（p指向pNew）                   p->pNext=pNew
*	q再存放pNew的地址 （pNew指向q）                                pNew->pNext=q
*	这样我们就可以使p指向pNew，pNew的指针域指向q 
	第二种：													pNew->pNext = p->PNext 
																p->pNext = pNew 
*/ 
bool insert_list(PNODE pHead,int pos,int val)
{
	int i=0;
	PNODE p=pHead;
	while(p!=NULL && i<pos-1)//要插入节点，至少需要知道前一个节点 
	{ 
		p=p->pNext;
		++i;
	}
	if(i>pos-1||p==NULL)
		return false;
	
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	if(NULL==pNew)
	{
		printf("动态分配内存失败!\n");
		exit(-1);
	}
	pNew->data=val;
	PNODE q=p->pNext;//q是p的下一个节点 
	p->pNext=pNew;//p节点处指向pNew 
	pNew->pNext=q;//pNew下一个节点是q 
	return true;
}

/*
*思路：
*		
*		i<pos-1（找出要删除节点的前一位节点）   
*		p->pNext != NULL;（确保删除的节点是存在的） 
*

*/ 
bool delete_list(PNODE pHead,int pos ,int* pVal)
{
	int i=0;
	PNODE p=pHead;
	while(p->pNext!=NULL && i<pos-1)//要删除的后面元素不能为空 
	{
		p=p->pNext;
		++i;
	}
	if(i>pos-1||p->pNext==NULL)
		return false;
	
	PNODE q=p->pNext;//用q保存p的下一个节点，后面可以释放，不用导致内存泄露 
	*pVal=q->data;
	//删除p节点后面的节点 
	p->pNext=p->pNext->pNext;
	free(q);
	q=NULL;
	
	return true;
	
}


