#include <stdio.h>
#include <malloc.h>

struct BTNode
{
	char data;
	struct BTNode* pLchild;//左子树 
	struct BTNode* pRchild;//右子树 
}; 

struct BTNode* CreateBTree();
void PreTraverseBTree(struct BTNode* pT);

int main()
{
	struct BTNode* pT=CreateBTree();
	PreTraverseBTree(pT);
	return 0; 
}


struct BTNode* CreateBTree()
{
	struct BTNode* pA=(struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pB=(struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pC=(struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pD=(struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pE=(struct BTNode*)malloc(sizeof(struct BTNode));
	
	pA->data='A';
	pB->data='B';
	pC->data='C';
	pD->data='D';
	pE->data='E';
	
	pA->pLchild=pB;
	pA->pRchild=pC;
	pB->pLchild=pB->pRchild=NULL;
	pC->pLchild=pD;
	pC->pRchild=NULL;
	pD->pLchild=NULL;
	pD->pRchild=pE;
	pE->pLchild=pE->pRchild=NULL;
	return pA; 
}
//先序输出 
void PreTraverseBTree(struct BTNode* pT)
{
	if(NULL!=pT)
	{
		printf("%c\n",pT->data);
			if(NULL!=pT->pLchild)//自己调用自己 
			{
				PreTraverseBTree(pT->pLchild);
			}
			if(NULL!=pT->pRchild)
			{
				PreTraverseBTree(pT->pRchild);
			}
	}//中序和后序同理，pT->pLchild可以代表整个左子树 
}
//先序伪算法：
		//首先访问先序根节点 
		//再先序访问左子树
		//最后先序访问右子树 
//中序遍历【中间访问根节点】
//方法：(1)中序遍历左子树
//      (2)再访问根节点
//      (3)再中序遍历右子树

//后序遍历【最后访问根节点】
//方法：(1)先中序遍历左子树
//      (2)在中序遍历右子树
//      (3)再访问根节点
