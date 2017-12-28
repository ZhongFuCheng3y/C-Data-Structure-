#include <stdio.h>
#include <malloc.h>

typedef struct node{
	int num;
	struct node* left;
	struct node* right;
}NODE;//节点 

typedef struct{
	NODE* root;
}TREE;//树根 

TREE* new_tree(){//构建一个树根 
	TREE* tree=(TREE*)malloc(sizeof(TREE));
	tree->root=NULL;
	return tree;
}
NODE* new_node(int num){//构建一个节点 
	NODE* node=(NODE*)malloc(sizeof(NODE));
	node->num=num;
	node->left=NULL;
	node->right=NULL;
	return node;
}

void insert(TREE* tree,int n){			//插入节点到树里边 
	if(tree->root==NULL){				//当树根是空的时候，把节点插入树根 
		tree->root=new_node(n);
	}
	else{
		NODE* p=tree->root;
		NODE* parent;
		while(p!=NULL){
			parent=p;//parent 记录p的路径 
			if(n <  p->num ){
			p=p->left; 
		}
		else if(n > p->num){
			p=p->right;
		}
		else{
			return;
		}
	}
	if(n< parent->num){//小的放左边，大的放右边 
		parent->left=new_node(n);
	}
	else{
		parent->right=new_node(n);
	}
  }
}


NODE* search(TREE* tree, int n){
	NODE* p=tree->root;
	while(p!=NULL){
		if(n<p->num){
			p=p->left;
		}
		else if(n>p->num){
			p=p->right;
		}
		else{
			return p;
		}
	}
	return NULL;
}
//先序遍历 
void preOrder(NODE* node){
	if(node!=NULL){
		printf("%d  ",node->num);
		preOrder(node->left);
		preOrder(node->right);
	}
}


int main(){
	int arr[]={2,3,66,445,63,77};
	int i;
	TREE* tree=new_tree();
	for(i=0;i<6;i++){
		insert(tree,arr[i]);
	}
	NODE* p=search(tree,3);
	if(p==NULL){
		printf("meiyou");
	}
	else{
		printf("you");
	}
	preOrder(tree->root);
	
	return 0; 
}



