#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType; //ElemType 为可定义的数据类型，此设为int类型

typedef struct LNode {
	char data; //结点的数据域
	struct LNode *next; //结点的指针域
} LNode, *LinkList; //LinkList为指向结构体LNode的指针类型

Status InitList_L(LinkList &L) { //算法2.6 单链表的初始化
	//构造一个空的单链表L
	L = new LNode; //生成新结点作为头结点，用头指针L指向头结点
	L->next = NULL; //头结点的指针域置空
	return OK;
}

Status ListInsert_L(LinkList &L, int i, char e) { //算法2.9 单链表的插入
	//在带头结点的单链表L中第i个位置插入值为e的新结点
	int j;
	LinkList p, s;
	p = L;
	j = 0;
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}//查找第i-1个结点，p指向该结点
	if (!p || j > i - 1)
		return ERROR; //i＞n+1或者i＜1
	s = new LNode; //生成新结点*s 
	s->data = e; //将结点*s的数据域置为e
	s->next = p->next; //将结点*s的指针域指向结点ai
	p->next = s; //将结点*p的指针域指向结点*s
	return OK;
} //ListInsert_L

LNode *LocateElem_L(LinkList L, char e) { //算法2.8 按值查找
	//在带头结点的单链表L中查找值为e的元素
	LinkList p;
	p = L->next;
	while (p && p->data != e)//顺链域向后扫描，直到p为空或p所指结点的数据域等于e
		p = p->next; //p指向下一个结点
	return p; //查找成功返回值为e的结点地址p，查找失败p为NULL 
} //LocateElem_L

LNode *Traversal_L(LinkList L) { //遍历
	LinkList p;
	p = L->next;
	while (p)//顺链域向后扫描，直到p为空或p所指结点的数据域等于e
    {
        cout << p->data << endl;
        cout << p->next << endl;
        p = p->next; //p指向下一个结点
    }
		
	return p; //查找成功返回值为e的结点地址p，查找失败p为NULL 
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
