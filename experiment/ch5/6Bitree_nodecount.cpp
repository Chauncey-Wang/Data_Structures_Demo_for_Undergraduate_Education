//算法5.6 统计二叉树中结点的个数
#include<iostream>
using namespace std;

//二叉树的二叉链表存储表示
typedef struct BiNode
{				
	char data;						//结点数据域
	struct BiNode *lchild,*rchild;	//左右孩子指针
}BiTNode,*BiTree;

//用算法5.3建立二叉链表
void CreateBiTree(BiTree &T)
{	
	//按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//递归结束，建空树
	else{							
		T=new BiTNode;
		T->data=ch;					//生成根结点
		CreateBiTree(T->lchild);	//递归创建左子树
		CreateBiTree(T->rchild);	//递归创建右子树
	}								//else
}									//CreateBiTree

int NodeCount(BiTree T)
{
     if(T==NULL) return 0;  			// 如果是空树，则结点个数为0，递归结束
     else return NodeCount(T->lchild)+ NodeCount(T->rchild) +1;
     //否则结点个数为左子树的结点个数+右子树的结点个数+1
} 

int LeafCount(BiTree T){
 	if(T==NULL) 	//如果是空树返回0
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1; //如果是叶子结点返回1
	else return LeafCount(T->lchild) + LeafCount(T->rchild);
}


void CreateBiTree_Manual(BiTree &T){
	// 第一层
	T=new BiTNode;
	T->data='A'; 
	T->lchild=T->rchild=NULL;  //避免地址悬空
	// 第二层
	T->lchild=new BiTNode;
	T->lchild->data='B'; 
	T->lchild->lchild=T->lchild->rchild=NULL;
	// 第三层
	T->lchild->lchild=new BiTNode;
	T->lchild->lchild->data='C';
	T->lchild->rchild=new BiTNode;
	T->lchild->rchild->data='D';
	T->lchild->lchild->lchild=T->lchild->lchild->rchild=NULL;
	T->lchild->rchild->lchild=T->lchild->rchild->rchild=NULL;
	// 第4层
	T->lchild->rchild->lchild=new BiTNode;
	T->lchild->rchild->lchild->data='E';
	T->lchild->rchild->rchild=new BiTNode;
	T->lchild->rchild->rchild->data='F';
	T->lchild->rchild->lchild->lchild=T->lchild->rchild->lchild->rchild=NULL;
	T->lchild->rchild->rchild->lchild=T->lchild->rchild->rchild->rchild=NULL;
	// 第5层
	T->lchild->rchild->lchild->rchild=new BiTNode;
	T->lchild->rchild->lchild->rchild->data='G';
	T->lchild->rchild->lchild->rchild->lchild=T->lchild->rchild->lchild->rchild->rchild=NULL;
}
/*
    A
   / 
  B
 / \
C   D
   / \
  E   F
   \
    G
*/

int main()
{
	BiTree tree;
	// cout<<"请输入建立二叉链表的序列：\n";
	// CreateBiTree(tree);
	CreateBiTree_Manual(tree);
	cout<<"结点个数为："<<NodeCount(tree)<<endl;
	cout<<"叶子个数为："<<LeafCount(tree)<<endl;
	return 0;

}
