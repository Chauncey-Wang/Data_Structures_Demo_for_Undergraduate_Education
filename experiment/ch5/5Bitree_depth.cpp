//�㷨5.5 ��������������
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

int Depth(BiTree T)
{ 
	int m,n;
	if(T == NULL ) return 0;        //����ǿ��������Ϊ0���ݹ����
	else 
	{							
		m=Depth(T->lchild);			//�ݹ��������������ȼ�Ϊm
		n=Depth(T->rchild);			//�ݹ��������������ȼ�Ϊn
		if(m>n) return(m+1);		//�����������Ϊm ��n�Ľϴ��߼�1
		else return (n+1);
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
	T->rchild=new BiTNode;
	T->rchild->data='H'; 
	T->lchild->lchild=T->lchild->rchild=NULL;
	T->rchild->lchild=T->rchild->rchild=NULL;
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
   / \
  B   H
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
	cout<<"�������Ϊ��"<<Depth(tree)<<endl;
	return 0;

}
