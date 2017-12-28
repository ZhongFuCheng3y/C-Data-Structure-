#include <stdio.h>
#include <malloc.h>

/*
*队列的原则是先进先出，我们研究的是循环静态队列 
*rear指向的是有效数据的下一个元素（此时rear指向的位置是没有有效数据的） *******************这里最重要 
*front指向的是第一个元素 
*在入队时，如果数组长度是6， f指向的下标是1，r指向的下标是5（此时r指向的位置是没有有效数据的） 
*我们都知道r要往后面移一位，让数据 存放在5的位置，此时的r只能移到下标为0的数据 所以得出r=（r+1)%数组长度 
*我们得出一个算法：由于r和f的位置是不明确的，没有大小之分，r和f在移动的过程中，很有可能会超出队列长度
*此时，我们可以得出下标r=（r+1）%数组长度，可以让r或f不断地移动，不会超出队列长度 
*即使是没有超出数组的长度，比如r的下标是2，往后面移一位是3，那么r=（2+1）%6，此时的下标一样是3 
*/ 


typedef struct Queue
{
	int *pBase;//指向数组的变量 
	int front;//下标 
	int rear;//末尾 
}QUEUE;


void init(QUEUE*);
bool en_queue(QUEUE*,int val);
void traverse_queue(QUEUE*);
bool full_queue(QUEUE*);
bool out_queue(QUEUE*,int *pVal);
bool emput_queue(QUEUE*);


int main(void)
{
	int val;
	QUEUE Q;
	init(&Q);
	en_queue(&Q,1);
	en_queue(&Q,5);
	en_queue(&Q,6);
	en_queue(&Q,7);
	en_queue(&Q,8);
	traverse_queue(&Q);
	if(out_queue(&Q,&val))
	{
		printf("出队成功，出队的元素是%d \n",val); 
	}
	else
		printf("出队失败");
	traverse_queue(&Q);
	return 0;
}

//初始化 
void init(QUEUE *pQ)
{
	pQ->pBase=(int *)malloc(sizeof(int)*6);//构建一个数组，由pBase指向 
	pQ->front=0;
	pQ->rear=0;
}
//判断队列是否满了
// 少用队列中的一个元素，如果r和f紧挨着，那么队列就是满了 
bool full_queue(QUEUE* pQ)
{
	if((pQ->rear+1)%6==pQ->front)//循环的静态队列 
		return true;
	else
		return false;
}


bool en_queue(QUEUE* pQ,int val)//入队 
{
	if(full_queue(pQ))
		return false;
	else
	{
		pQ->pBase[pQ->rear]=val;
		pQ->rear=(pQ->rear+1)%6;
		
		return true;
	}	
}

void traverse_queue(QUEUE* pQ)
{
	int i=pQ->front;//遍历，用一个变量指向第一个下标，当i与rear不相等时，就输出 
	
	while(i!=pQ->rear)
	{
		printf("%d  ",pQ->pBase[i]);
		i=(i+1)%6;	
	}
	printf("\n");
	return;
}

//当front的值和rear的值相等，这个队列就是空的。 
bool emput_queue(QUEUE* pQ)//判断是否为空数列 
{
	if(pQ->front==pQ->rear)
		return true;
	else
		return false;
}
//出队就是让front往前面移一位 
bool out_queue(QUEUE* pQ,int *pVal)//出队 
{
	if(emput_queue(pQ))
		return false; 
	else
	{
		*pVal=pQ->pBase[pQ->front];
		pQ->front=(pQ->front+1)%6;
		return true;
	}
}

