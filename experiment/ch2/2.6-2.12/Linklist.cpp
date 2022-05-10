#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType; //ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

typedef struct LNode {
	char data; //����������
	struct LNode *next; //����ָ����
} LNode, *LinkList; //LinkListΪָ��ṹ��LNode��ָ������

Status InitList_L(LinkList &L) { //�㷨2.6 ������ĳ�ʼ��
	//����һ���յĵ�����L
	L = new LNode; //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	L->next = NULL; //ͷ����ָ�����ÿ�
	return OK;
}

Status ListInsert_L(LinkList &L, int i, char e) { //�㷨2.9 ������Ĳ���
	//�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��
	int j;
	LinkList p, s;
	p = L;
	j = 0;
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}//���ҵ�i-1����㣬pָ��ý��
	if (!p || j > i - 1)
		return ERROR; //i��n+1����i��1
	s = new LNode; //�����½��*s 
	s->data = e; //�����*s����������Ϊe
	s->next = p->next; //�����*s��ָ����ָ����ai
	p->next = s; //�����*p��ָ����ָ����*s
	return OK;
} //ListInsert_L

LNode *LocateElem_L(LinkList L, char e) { //�㷨2.8 ��ֵ����
	//�ڴ�ͷ���ĵ�����L�в���ֵΪe��Ԫ��
	LinkList p;
	p = L->next;
	while (p && p->data != e)//˳�������ɨ�裬ֱ��pΪ�ջ�p��ָ�������������e
		p = p->next; //pָ����һ�����
	return p; //���ҳɹ�����ֵΪe�Ľ���ַp������ʧ��pΪNULL 
} //LocateElem_L

LNode *Traversal_L(LinkList L) { //����
	LinkList p;
	p = L->next;
	while (p)//˳�������ɨ�裬ֱ��pΪ�ջ�p��ָ�������������e
    {
        cout << p->data << endl;
        cout << p->next << endl;
        p = p->next; //pָ����һ�����
    }
		
	return p; //���ҳɹ�����ֵΪe�Ľ���ַp������ʧ��pΪNULL 
} //LocateElem_L


int main() {
	LinkList L, p;
    InitList_L(L);
    ListInsert_L(L, 1, 'a');
    ListInsert_L(L, 2, 'b');
    ListInsert_L(L, 3, 'c');
    Traversal_L(L);

	return 0;
}
