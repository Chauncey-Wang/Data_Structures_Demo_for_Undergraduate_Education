//�㷨5.6 ͳ�ƶ������н��ĸ���
#include<iostream>
using namespace std;

//�������Ķ�������洢��ʾ
typedef struct BiNode
{				
	char data;						//���������
	struct BiNode *lchild,*rchild;	//���Һ���ָ��
}BiTNode,*BiTree;

//���㷨5.3������������
void CreateBiTree(BiTree &T)
{	
	//�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//�ݹ������������
	else{							
		T=new BiTNode;
		T->data=ch;					//���ɸ����
		CreateBiTree(T->lchild);	//�ݹ鴴��������
		CreateBiTree(T->rchild);	//�ݹ鴴��������
	}								//else
}									//CreateBiTree

int NodeCount(BiTree T)
{
     if(T==NULL) return 0;  			// ����ǿ������������Ϊ0���ݹ����
     else return NodeCount(T->lchild)+ NodeCount(T->rchild) +1;
     //���������Ϊ�������Ľ�����+�������Ľ�����+1
} 

int LeafCount(BiTree T){
 	if(T==NULL) 	//����ǿ�������0
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1; //�����Ҷ�ӽ�㷵��1
	else return LeafCount(T->lchild) + LeafCount(T->rchild);
}


void CreateBiTree_Manual(BiTree &T){
	// ��һ��
	T=new BiTNode;
	T->data='A'; 
	T->lchild=T->rchild=NULL;  //�����ַ����
	// �ڶ���
	T->lchild=new BiTNode;
	T->lchild->data='B'; 
	T->lchild->lchild=T->lchild->rchild=NULL;
	// ������
	T->lchild->lchild=new BiTNode;
	T->lchild->lchild->data='C';
	T->lchild->rchild=new BiTNode;
	T->lchild->rchild->data='D';
	T->lchild->lchild->lchild=T->lchild->lchild->rchild=NULL;
	T->lchild->rchild->lchild=T->lchild->rchild->rchild=NULL;
	// ��4��
	T->lchild->rchild->lchild=new BiTNode;
	T->lchild->rchild->lchild->data='E';
	T->lchild->rchild->rchild=new BiTNode;
	T->lchild->rchild->rchild->data='F';
	T->lchild->rchild->lchild->lchild=T->lchild->rchild->lchild->rchild=NULL;
	T->lchild->rchild->rchild->lchild=T->lchild->rchild->rchild->rchild=NULL;
	// ��5��
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
	// cout<<"�����뽨��������������У�\n";
	// CreateBiTree(tree);
	CreateBiTree_Manual(tree);
	cout<<"������Ϊ��"<<NodeCount(tree)<<endl;
	cout<<"Ҷ�Ӹ���Ϊ��"<<LeafCount(tree)<<endl;
	return 0;

}
