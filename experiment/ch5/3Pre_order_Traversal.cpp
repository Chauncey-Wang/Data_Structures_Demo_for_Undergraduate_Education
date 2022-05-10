//算法5.3 先序遍历的的顺序建立二叉链表
#include<iostream>
using namespace std;

//二叉树的二叉链表存储表示
typedef struct BiNode
{				
	char data;						//结点数据域
	struct BiNode *lchild,*rchild;	//左右孩子指针
}BiTNode,*BiTree;

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

//用算法5.1 中序遍历的递归算法							
void InOrderTraverse(BiTree T)
{  
	//中序遍历二叉树T的递归算法
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
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
	cout<<"所建立的二叉链表中序序列：\n";
	InOrderTraverse(tree);
	cout<<endl;
	return 0;
}
