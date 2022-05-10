//�㷨5.3 ��������ĵ�˳������������
#include<iostream>
using namespace std;

//�������Ķ�������洢��ʾ
typedef struct BiNode
{				
	char data;						//���������
	struct BiNode *lchild,*rchild;	//���Һ���ָ��
}BiTNode,*BiTree;

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

//���㷨5.1 ��������ĵݹ��㷨							
void InOrderTraverse(BiTree T)
{  
	//�������������T�ĵݹ��㷨
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
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
	cout<<"�������Ķ��������������У�\n";
	InOrderTraverse(tree);
	cout<<endl;
	return 0;
}
