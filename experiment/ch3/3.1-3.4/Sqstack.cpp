/***˳��ջ��ʵ��***/

#include<iostream>
#include<fstream>
using namespace std;

//˳��ջ����
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE  100//˳��ջ�洢�ռ�ĳ�ʼ������
typedef int Status;
typedef char SElemType;

typedef struct {
	SElemType *base;//ջ��ָ��
	SElemType *top;//ջ��ָ��
	int stacksize;//ջ���õ��������
} SqStack;

//�㷨3.1��˳��ջ�ĳ�ʼ��
Status InitStack(SqStack &S) {  //�˴�&Ϊreference
	//����һ����ջS
	S.base = new SElemType[MAXSIZE];//Ϊ˳��ջ��̬����һ���������ΪMAXSIZE������ռ�
	if (!S.base)
		exit(OVERFLOW); //�洢����ʧ��  exit���Թر������ļ�����ֹ����ִ�еĽ��̡�
	S.top = S.base; //top��ʼΪbase����ջ
	S.stacksize = MAXSIZE; //stacksize��Ϊջ���������MAXSIZE
	return OK;
}

bool StackEmpty(SqStack S) {
	if (S.top==S.base)
		return true;
	else
		return false;
}


//�㷨3.2��˳��ջ����ջ
Status Push(SqStack &S, SElemType e) {
	// ����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base == S.stacksize)
		return ERROR; //ջ��
	*(S.top++) = e; //Ԫ��eѹ��ջ����ջ��ָ���1
	return OK;
}
//�㷨3.3��˳��ջ�ĳ�ջ
Status Pop(SqStack &S, SElemType &e) {
	//ɾ��S��ջ��Ԫ�أ���e������ֵ	
	if (S.base == S.top)
		return ERROR;//ջ��
	e = *(--S.top); //ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}
//�㷨3.4��ȡ˳��ջ��ջ��Ԫ��
char GetTop(SqStack S) {//����S��ջ��Ԫ�أ����޸�ջ��ָ��
	if (S.top != S.base) //ջ�ǿ�
		return *(S.top - 1); //����ջ��Ԫ�ص�ֵ��ջ��ָ�벻�� return *(--S.top);
}

// int main() {
// 	SqStack s;
// 	int choose, flag = 0;
// 	SElemType j, e, t;
// 	cout << "1.��ʼ��\n";
// 	cout << "2.��ջ\n";
// 	cout << "3.��ջ��Ԫ��\n";
// 	cout << "4.��ջ\n";
// 	cout << "0.�˳�\n\n";
//
// 	choose = -1;
// 	while (choose != 0) {
// 		cout << "��ѡ��:";
// 		cin >> choose;
// 		switch (choose) {
// 		case 1://�㷨3.1��˳��ջ�ĳ�ʼ��
// 			if (InitStack(s)) {
// 				flag = 1;
// 				cout << "�ɹ���ջ���г�ʼ��\n\n";
// 			} else
// 				cout << "��ʼ��ջʧ��\n\n";
// 			break;
// 		case 2: {//�㷨3.2��˳��ջ����ջ
// 			fstream file;
// 			file.open("SqStack.txt");//
// 			if (!file) {
// 				cout << "����δ�ҵ��ļ���\n\n" << endl;
// 				exit(ERROR);
// 			}
// 			if (flag) {
// 				flag = 1;
// 				cout << "��ջԪ������Ϊ��\n";
// 				while (!file.eof()) {
// 					file >> j;
// 					if (file.fail())
// 						break;
// 					else {
// 						Push(s, j);
// 						cout << j << "  ";
// 					}
// 				}
// 				cout << endl << endl;
// 			} else
// 				cout << "ջδ������������ѡ��\n\n";
// 			file.close();
// 		}
// 			break;
// 		case 3://�㷨3.3��˳��ջ�ĳ�ջ
// 			if(flag != -1 && flag != 0)
// 				cout << "ջ��Ԫ��Ϊ��\n" << GetTop(s) << endl << endl;
// 			else
// 				cout << "ջ����Ԫ�أ�������ѡ��\n" << endl;
// 			break;
// 		case 4://�㷨3.4��ȡ˳��ջ��ջ��Ԫ��
// 			cout << "���ε�����ջ��Ԫ��Ϊ:\n";
// 			while (Pop(s, t)){
// 				flag = -1;
// 				cout << t << "  ";
// 			}
// 			cout << endl << endl;
// 			break;
// 		}
// 	}
// 	return 0;
// }


int main() {
	SqStack s;
	InitStack(s);
	cout << "��ʼ��ջ" << endl;
	Push(s, 'a');
	cout << GetTop(s) << endl;
	Push(s, 'b');
	cout << GetTop(s) << endl;
	Push(s, 'c');
	cout << GetTop(s) << endl;
	Push(s, 'd');
	cout << GetTop(s) << endl;

	cout << "��ջ���" << endl;
	
	cout << "ջ�ڵ�ֵ��" ;
	for(int i=0; i<(s.top - s.base); i++){
		cout << *(s.base+i) ;
	}
	cout << endl;

	cout << "��ʼ��ջ" << endl;

	SElemType t;
	Pop(s, t);
	cout << t << endl;
	Pop(s, t);
	cout << t << endl;
	Pop(s, t);
	cout << t << endl;
	Pop(s, t);
	cout << t << endl;

	return 0;
}


