/**********************************************
*Name: �Թ����
***********************************************/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#define  m   8  /*�Թ���ʵ����*/
#define  n    8  /*�Թ���ʵ����*/


typedef int Status;
typedef struct
{
	int x;
	int y;
}PosType;         //λ�õ�����
typedef struct
{
	int ord;      //ͨ������·���ϵġ���š�
	PosType seat; //ͨ�������Թ��еġ�����λ�á�
	int di;       //�Ӵ�ͨ����������һͨ����ġ�����, //����Ϊ1����Ϊ2����Ϊ3����Ϊ4��
}MazeType;
typedef struct  
{
	MazeType *base;
	MazeType *top;
	int stacksize;
}MazeStack;


#include <iostream>
using namespace std;
Status InitStack(MazeStack &S);
Status Push(MazeStack &S, MazeType &e);
Status Pop(MazeStack &S, MazeType &e);
Status StackEmpty(MazeStack &S);
Status MazePath(PosType start, PosType end);
Status Pass(PosType &pos);
void FootPrint(PosType pos);
PosType NextPos(PosType curPos, int &i);
void MakePrint(PosType pos);
//�Թ���ͼ��0��ʾǽ�ڣ�1��ʾͨ·,���:mazeMap[1][1],����mazeMap[8][8]                       

int mazeMap[m+2][n+2] =
{  //0,1,2,3,4,5,6,7,8,9
    {1,1,1,1,1,1,1,1,1,1}, //0
    {1,0,0,1,0,0,0,1,0,1}, //1
    {1,0,0,1,0,0,0,1,0,1}, //2
    {1,0,0,0,0,1,1,0,0,1}, //3
    {1,0,1,1,1,0,0,0,0,1}, //4
    {1,0,0,0,1,0,0,0,0,1}, //5
    {1,0,1,0,0,0,1,0,0,1}, //6
    {1,0,1,1,1,0,1,1,0,1}, //7
    {1,1,0,0,0,0,0,0,0,1}, //8
    {1,1,1,1,1,1,1,1,1,1}  //9
}; 

int main()
{
	PosType mazeStart, mazeEnd;
	mazeStart.x = 1;
	mazeStart.y = 1;
	mazeEnd.x = 8;
	mazeEnd.y = 8;
	cout << "�Թ�: " << endl;
	for(int i = 0; i < 10; ++i)
	{
		for(int j = 0; j < 10; ++j)
			cout << mazeMap[i][j];
		cout << endl;
	}
	cout << endl << endl;
	if(MazePath(mazeStart, mazeEnd))
		cout << endl << "��ͨ�Թ�" << endl;
	else
		cout << endl << "�߲�ͨ�Թ�" << endl;
	// system("PAUSE");
	return 0;
}


Status InitStack(MazeStack &S)
{
	// S.base = (MazeType *)malloc(STACK_INIT_SIZE * sizeof(MazeType));
    S.base = new MazeType[STACK_INIT_SIZE];
	if(!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Push(MazeStack &S, MazeType &e)
{
	if(S.top - S.base >= S.stacksize)
	{
		S.base = (MazeType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(MazeType));
		if(!S.base)
			exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}
Status Pop(MazeStack &S, MazeType &e)
{
	if(S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
Status StackEmpty(MazeStack &S)
{
	if(S.base == S.top)
		return OK;
	return ERROR;
}
Status MazePath(PosType start, PosType end)
{
	PosType curpos;
	MazeStack S;
	MazeType e;
	int curstep;
	InitStack(S);
	curpos = start; //�趨��ǰλ��Ϊ���λ��
	curstep = 1; //̽����һ��
	cout << "���: "<< "(" <<start.y << "," << start.x << ")" << endl;
	do
	{
		if(Pass(curpos)) //��ǰλ�ÿ���ͨ��������δ���ߵ���ͨ����
		{
			FootPrint(curpos); //�����㼣
			e.ord = curstep;
			e.seat = curpos;
			e.di = 1; 
			Push(S, e); //����·��
			if(curpos.x == end.x && curpos.y == end.y)
			{
				cout << endl << "�յ� (" << e.seat.y << "," << e.seat.x << ")";
				return TRUE; //�����յ㣨���ڣ�
			}
			curpos = NextPos(curpos, e.di); //��һλ���ǵ�ǰλ�õĶ���
			++curstep; //̽����һ��
		}
		else //��ǰλ�ò���ͨ��
		{
			if(!StackEmpty(S))
			{
				Pop(S, e);
				while(e.di == 4 && !StackEmpty(S))
				{
					MakePrint(e.seat); //���²���ͨ���ı��
					Pop(S, e);
					cout << "���˵�(" << e.seat.y << "," << e.seat.x << ")";
				}
				if(e.di < 4)
				{
					++e.di; //����һ������̽��
					Push(S, e); 
					curpos = NextPos(e.seat, e.di); //�趨��ǰλ���Ǹ��·����ϵ����ڿ�
				}
			}
		}
	}while(!StackEmpty(S));
	
	return FALSE;
}

Status Pass(PosType &pos)
{
	if(mazeMap[pos.y][pos.x] == 1)
		return FALSE;
	cout << "->(" << pos.y << "," << pos.x << ")";
	return TRUE;
}

void FootPrint(PosType pos)
{
	mazeMap[pos.y][pos.x] = 2; //���߹���·����Ϊ2
}
PosType NextPos(PosType curPos, int &i)
{
	switch(i) //˳ʱ�뷽��
	{
	case 1:
		++curPos.x; //��
		if(mazeMap[curPos.y][curPos.x] != 2)
			break;
		--curPos.x;
	case 2:
		i = 2;
		++curPos.y; //��
		if(mazeMap[curPos.y][curPos.x] != 2)
			break;
		--curPos.y;
	case 3:
		i = 3;
		--curPos.x; //��
		if(mazeMap[curPos.y][curPos.x] != 2)
			break;
		++curPos.x;
	case 4:
		i = 4;
		--curPos.y; //��
		if(mazeMap[curPos.y][curPos.x] == 2)
		{
			++curPos.y;
			mazeMap[curPos.y][curPos.x] = 1;  
		}
		break;
	}
	
	return curPos;
}
void MakePrint(PosType pos)
{
	cout << endl << "(" << pos.y << "," << pos.x << ")�߲�ͨ������";
	mazeMap[pos.y][pos.x] = 1; //���߲�ͨ�Ŀ��滻Ϊǽ��  
}