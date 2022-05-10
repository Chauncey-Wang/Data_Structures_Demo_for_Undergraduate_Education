/**********************************************
*Name: 迷宫求解
***********************************************/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#define  m   8  /*迷宫的实际行*/
#define  n    8  /*迷宫的实际列*/


typedef int Status;
typedef struct
{
	int x;
	int y;
}PosType;         //位置的类型
typedef struct
{
	int ord;      //通道块在路径上的“序号”
	PosType seat; //通道块在迷宫中的“坐标位置”
	int di;       //从此通道块走向下一通道块的“方向”, //（东为1，南为2，西为3，北为4）
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
//迷宫地图，0表示墙壁，1表示通路,入口:mazeMap[1][1],出口mazeMap[8][8]                       

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
	cout << "迷宫: " << endl;
	for(int i = 0; i < 10; ++i)
	{
		for(int j = 0; j < 10; ++j)
			cout << mazeMap[i][j];
		cout << endl;
	}
	cout << endl << endl;
	if(MazePath(mazeStart, mazeEnd))
		cout << endl << "走通迷宫" << endl;
	else
		cout << endl << "走不通迷宫" << endl;
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
	curpos = start; //设定当前位置为入口位置
	curstep = 1; //探索第一步
	cout << "起点: "<< "(" <<start.y << "," << start.x << ")" << endl;
	do
	{
		if(Pass(curpos)) //当前位置可以通过，即是未曾走到的通道块
		{
			FootPrint(curpos); //留下足迹
			e.ord = curstep;
			e.seat = curpos;
			e.di = 1; 
			Push(S, e); //加入路径
			if(curpos.x == end.x && curpos.y == end.y)
			{
				cout << endl << "终点 (" << e.seat.y << "," << e.seat.x << ")";
				return TRUE; //到达终点（出口）
			}
			curpos = NextPos(curpos, e.di); //下一位置是当前位置的东邻
			++curstep; //探索下一步
		}
		else //当前位置不能通过
		{
			if(!StackEmpty(S))
			{
				Pop(S, e);
				while(e.di == 4 && !StackEmpty(S))
				{
					MakePrint(e.seat); //留下不能通过的标记
					Pop(S, e);
					cout << "倒退到(" << e.seat.y << "," << e.seat.x << ")";
				}
				if(e.di < 4)
				{
					++e.di; //换下一个方向探索
					Push(S, e); 
					curpos = NextPos(e.seat, e.di); //设定当前位置是该新方向上的相邻块
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
	mazeMap[pos.y][pos.x] = 2; //将走过的路径设为2
}
PosType NextPos(PosType curPos, int &i)
{
	switch(i) //顺时针方向
	{
	case 1:
		++curPos.x; //东
		if(mazeMap[curPos.y][curPos.x] != 2)
			break;
		--curPos.x;
	case 2:
		i = 2;
		++curPos.y; //南
		if(mazeMap[curPos.y][curPos.x] != 2)
			break;
		--curPos.y;
	case 3:
		i = 3;
		--curPos.x; //西
		if(mazeMap[curPos.y][curPos.x] != 2)
			break;
		++curPos.x;
	case 4:
		i = 4;
		--curPos.y; //北
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
	cout << endl << "(" << pos.y << "," << pos.x << ")走不通，作废";
	mazeMap[pos.y][pos.x] = 1; //将走不通的块替换为墙壁  
}