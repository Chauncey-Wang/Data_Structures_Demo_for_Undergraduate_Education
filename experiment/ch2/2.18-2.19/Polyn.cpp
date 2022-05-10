#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#define ERROR 0

typedef struct PNode {
	float coef; //ϵ��
	int expn; //ָ��
	struct PNode *next;
} PNode, *Polynomial;
string head_1, head_2;
int temp;
char st = 'A';


void InitPoly_L(Polynomial &L) //����������
{
	L = new PNode;
	L->next = NULL;
}


void CreatPolyn(Polynomial &P, int m) //����ʽ�Ĵ���
{
	//����m���ϵ����ָ����������ʾһ������ʽ����������P
	Polynomial q, pre, s;
	int i;
	P = new PNode;
	P->next = NULL; //�Ƚ���һ����ͷ���ĵ�����
	char filename[20] = { 0 };
	cout << "�������йض���ʽp" << char(st + 32) << "ϵ����ָ���������ļ����ƣ��ļ���+��.txt������Poly" << st << ".txt����" << endl;
	++st;
	gets(filename);
	fstream file;
	file.open(filename);
	if (!file) {
		cout << "δ�ҵ�����ļ����޷��򿪣�" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2;
	while (!file.eof())
	{
		s = new PNode; //�����½��
		file >> s->coef >> s->expn; //����Ԫ��ֵ
		pre = P; //pre���ڱ���q��ǰ������ֵΪͷ���
		q = P->next;
		while (q && q->expn < s->expn) //ͨ���Ƚ�ָ���ҵ���һ������������ָ������q
		{
			pre = q;
			q = q->next;
		} //while
		s->next = q; //��������s���뵽q����ǰ�����pre֮��
		pre->next = s;
	}//for
	file.close();
} //CreatPolyn

void AddPolyn(Polynomial &Pa, Polynomial &Pb) //�㷨2.19 ����ʽ�����
{
	//����ʽ�ӷ���Pa=Pa+Pb��������������ʽ�Ľ�㹹�ɡ��Ͷ���ʽ��
	Polynomial r, p1, p2, p3;
	float sum;
	p1 = Pa->next;
	p2 = Pb->next; //p1��p2��ֵ�ֱ�ָ��Pa��Pb�ĵ�һ�����
	p3 = Pa; //p3ָ��Ͷ���ʽ�ĵ�ǰ��㣬��ֵΪPa
	while (p1 && p2) //p1��p2���ǿ�
	{
		if (p1->expn == p2->expn) //ָ�����
		{
			sum = p1->coef + p2->coef; //sum���������ϵ����
			if (sum != 0) //ϵ���Ͳ�Ϊ0
			{
				p1->coef = sum; //�޸�Pa��ǰ���p1��ϵ��ֵΪ����ϵ���ĺ�
				p3->next = p1;
				p3 = p1; //���޸ĺ��Pa��ǰ���p1����p3֮��p3ָ��p1
				p1 = p1->next; //p1ָ���һ��
				r = p2;
				p2 = p2->next;
				delete r; //ɾ��Pb��ǰ���r
			} else //ϵ����Ϊ0
			{
				r = p1;
				p1 = p1->next;
				delete r; //ɾ��Pb��ǰ���p1
				r = p2;
				p2 = p2->next;
				delete r; //ɾ��Pb��ǰ���p2
			}
		} else if (p1->expn < p2->expn) //Pa��ǰ���p1��ָ��ֵС
		{
			p3->next = p1; //��p1����p3֮��
			p3 = p1; //p3ָ��p1
			p1 = p1->next; //p1ָ���һ��
		} else //Pa��ǰ���p2��ָ��ֵС
		{
			p3->next = p2; //��p2����p3֮��
			p3 = p2; //p3ָ��p2
			p2 = p2->next; //p2ָ���һ��
		}
	} //while
	p3->next = p1 ? p1 : p2; //����ǿն���ʽ��ʣ���
	delete Pb; //�ͷ�Pb��ͷ���
} //AddPolyn

void PrintElem_L(Polynomial L){
	Polynomial p;
	p = L->next;
	while(p){
		cout << p->expn << ',';
		p = p->next;
		}
	cout << endl;
}

int main() {
    float PolyA_coef[]={7,3,9,5};
    int   PolyA_expn[]={0,1,8,17};
    float PolyB_coef[]={8,22,-9};
    int   PolyB_expn[]={1,7,8};

	Polynomial Pa, Pb;
    InitPoly_L(Pa);
    InitPoly_L(Pb);
	// Polynomial p;
	int i;
    PNode *p, *r;

    r = Pa;
    for(int j=0;j<sizeof(PolyA_expn)/sizeof(int);j++){
        p = new PNode;
        p->coef = PolyA_coef[j];
        p->expn = PolyA_expn[j];
        p->next = NULL;
		r->next = p;
        r = p;
    }

    r = Pb;
    for(int j=0;j<sizeof(PolyB_expn)/sizeof(int);j++){
        p = new PNode;
        p->coef = PolyB_coef[j];
        p->expn = PolyB_expn[j];
        p->next = NULL;
		r->next = p;
        r = p;
    }

    // PrintElem_L(Pa);

	AddPolyn(Pa, Pb);
	cout << "����ʽPa��Pb��Ӻ�Ľ���ǣ�\n";
	p = Pa->next;
	i = 0;
	while (p) //�����Ӻ�Ľ����ÿһ����x^n��ʾ
	{
		if (i)
			cout << " + ";
		cout << "(" << p->coef << ") * x^" << p->expn;
		p = p->next;
		i = 1;
	}
	cout << endl;
	return 0;
}