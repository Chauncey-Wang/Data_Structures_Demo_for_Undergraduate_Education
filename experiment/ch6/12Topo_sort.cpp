//算法6.12　拓扑排序

#include <iostream>
using namespace std;

#define MVNum 100                       	//最大顶点数
#define OK 1	
#define ERROR 0 

typedef char VerTexType;

//- - - - -图的邻接表存储表示- - - - - 
typedef struct ArcNode{                		//边结点 
    int adjvex;                          	//该边所指向的顶点的位置 
    struct ArcNode *nextarc;          		//指向下一条边的指针 
}ArcNode; 

typedef struct VNode{ 
    VerTexType data;                    	//顶点信息 
    ArcNode *firstarc;                		//指向第一条依附该顶点的边的指针 
}VNode, AdjList[MVNum];               		//AdjList表示邻接表类型 

typedef struct{ 
    AdjList vertices;                 		//邻接表 
	AdjList converse_vertices;				//逆邻接表
    int vexnum, arcnum;              		//图的当前顶点数和边数 
}ALGraph;
//- - - - - - - - - - - - - - - -

//- - - - -顺序栈的定义- - - - -
typedef struct{
	int *base;
	int *top;
	int stacksize;
}spStack;
//- - - - - - - - - - - - - - - -

int indegree[MVNum];						//数组indegree存放个顶点的入度
spStack S;

//------------栈的相关操作----------------------
void InitStack(spStack &S){
	//初始化栈
	S.base = new int[MVNum];
	if(!S.base)
		exit(1);
	S.top = S.base;
	S.stacksize = MVNum;
}//InitStack

void Push(spStack &S , int i){
	//进栈
	if(S.top - S.base == S.stacksize)
		return;
	*S.top++ = i;
}//Push

void Pop(spStack &S , int &i){
	//出栈
	if(S.top == S.base)
		return;
	i = *--S.top;
}//Pop

bool StackEmpty(spStack S){
	//判断栈是否为空
	if(S.top == S.base)
		return true;
	return false;
}//StackEmpty
//-------------------------------------------------

int LocateVex(ALGraph G , VerTexType v){
	//确定点v在G中的位置
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vertices[i].data == v)
			return i;
		return -1;
}//LocateVex

int CreateUDG(ALGraph &G){ 
	//创建有向图G的邻接表、逆邻接表
	int i , k;
	
	cout <<"请输入总顶点数，总边数，以空格隔开:";
	cin >> G.vexnum >> G.arcnum;				//输入总顶点数，总边数 
    cout << endl;
	
	cout << "输入点的名称，如a" << endl;
	
	for(i = 0; i < G.vexnum; ++i){          	//输入各点，构造表头结点表
		cout << "请输入第" << (i+1) << "个点的名称:";
		cin >> G.vertices[i].data;           	//输入顶点值
		G.converse_vertices[i].data = G.vertices[i].data;
		//初始化表头结点的指针域为NULL 
		G.vertices[i].firstarc=NULL;			
		G.converse_vertices[i].firstarc=NULL;
    }//for
	cout << endl;
	cout << "输入边依附的顶点，如a b" << endl;
	for(k = 0; k < G.arcnum;++k){        		//输入各边，构造邻接表
		VerTexType v1 , v2;
		int i , j;
		cout << "请输入第" << (k + 1) << "条边依附的顶点:";
		cin >> v1 >> v2;                		//输入一条边依附的两个顶点
		i = LocateVex(G, v1);  j = LocateVex(G, v2);
		//确定v1和v2在G中位置，即顶点在G.vertices中的序号 

		ArcNode *p1=new ArcNode;               	//生成一个新的边结点*p1 
		p1->adjvex=j;                   		//邻接点序号为j
		p1->nextarc = G.vertices[i].firstarc;  G.vertices[i].firstarc=p1;
		//将新结点*p1插入顶点vi的边表头部

		ArcNode *p2=new ArcNode;               	//生成一个新的边结点*p1 
		p2->adjvex=i;                   		//逆邻接点序号为i
		p2->nextarc = G.converse_vertices[j].firstarc;  G.converse_vertices[j].firstarc=p2;
		//将新结点*p1插入顶点vi的边表头部
    }//for 
    return OK; 
}//CreateUDG

int CreateUDG_Manual(ALGraph &G){ 
	//创建有向图G的邻接表、逆邻接表
	int i , k;

	G.vexnum = 6;
	G.arcnum = 8;

	G.converse_vertices[0].data=G.vertices[0].data='0';
	G.converse_vertices[1].data=G.vertices[1].data='1';
	G.converse_vertices[2].data=G.vertices[2].data='2';
	G.converse_vertices[3].data=G.vertices[3].data='3';
	G.converse_vertices[4].data=G.vertices[4].data='4';
	G.converse_vertices[5].data=G.vertices[5].data='5';
	
	cout << "输入点的名称，如a" << endl;
	
	for(i = 0; i < G.vexnum; ++i){          	//输入各点，构造表头结点表
		G.vertices[i].firstarc=NULL;			
		G.converse_vertices[i].firstarc=NULL;
    }//for

	ArcNode *p1=new ArcNode;               	//生成一个新的边结点*p1 
	ArcNode *p2=new ArcNode; 
	p1->adjvex=1;                   		//邻接点序号为j  0 1
	p1->nextarc = G.vertices[0].firstarc;  G.vertices[0].firstarc=p1;
	p2->adjvex=0;                   		//逆邻接点序号为i
	p2->nextarc = G.converse_vertices[1].firstarc;  G.converse_vertices[1].firstarc=p2;
	delete [] p1;
	delete  p1;
	// p1=NULL;

	ArcNode *p3=new ArcNode;               	//生成一个新的边结点*p1 
	ArcNode *p4=new ArcNode; 
	p3->adjvex=3;                   		//邻接点序号为j  0 3
	p3->nextarc = G.vertices[0].firstarc;  G.vertices[0].firstarc=p3;
	p4->adjvex=0;                   		//逆邻接点序号为i
	p4->nextarc = G.converse_vertices[3].firstarc;  G.converse_vertices[3].firstarc=p4;

	ArcNode *p5=new ArcNode;               	//生成一个新的边结点*p1 
	ArcNode *p6=new ArcNode; 
	p5->adjvex=5;                   		//邻接点序号为j  1 5
	p5->nextarc = G.vertices[1].firstarc;  G.vertices[1].firstarc=p5;
	p6->adjvex=1;                   		//逆邻接点序号为i
	p6->nextarc = G.converse_vertices[5].firstarc;  G.converse_vertices[5].firstarc=p6;

	ArcNode *p7=new ArcNode;               	//生成一个新的边结点*p1 
	ArcNode *p8=new ArcNode; 
	p7->adjvex=1;                   		//邻接点序号为j  2 1
	p7->nextarc = G.vertices[2].firstarc;  G.vertices[2].firstarc=p7;
	p8->adjvex=2;                   		//逆邻接点序号为i
	p8->nextarc = G.converse_vertices[1].firstarc;  G.converse_vertices[1].firstarc=p8;

	ArcNode *p9=new ArcNode;               	//生成一个新的边结点*p1 
	ArcNode *p10=new ArcNode; 
	p9->adjvex=5;                   		//邻接点序号为j  2 5
	p9->nextarc = G.vertices[2].firstarc;  G.vertices[2].firstarc=p9;
	p10->adjvex=2;                   		//逆邻接点序号为i
	p10->nextarc = G.converse_vertices[5].firstarc;  G.converse_vertices[5].firstarc=p10;

	ArcNode *p11=new ArcNode;               	//生成一个新的边结点*p1 
	ArcNode *p12=new ArcNode; 
	p11->adjvex=0;                   		//邻接点序号为j  4 0
	p11->nextarc = G.vertices[4].firstarc;  G.vertices[4].firstarc=p11;
	p12->adjvex=4;                   		//逆邻接点序号为i
	p12->nextarc = G.converse_vertices[0].firstarc;  G.converse_vertices[0].firstarc=p12;

	ArcNode *p13=new ArcNode;               	//生成一个新的边结点*p1 
	ArcNode *p14=new ArcNode; 
	p13->adjvex=1;                   		//邻接点序号为j  4 1
	p13->nextarc = G.vertices[4].firstarc;  G.vertices[4].firstarc=p13;
	p14->adjvex=4;                   		//逆邻接点序号为i
	p14->nextarc = G.converse_vertices[1].firstarc;  G.converse_vertices[1].firstarc=p14;

	ArcNode *p15=new ArcNode;               	//生成一个新的边结点*p1 
	ArcNode *p16=new ArcNode; 
	p15->adjvex=5;                   		//邻接点序号为j  4 5
	p15->nextarc = G.vertices[4].firstarc;  G.vertices[4].firstarc=p15;
	p16->adjvex=4;                   		//逆邻接点序号为i
	p16->nextarc = G.converse_vertices[5].firstarc;  G.converse_vertices[5].firstarc=p16;
    return OK; 
}//CreateUDG


void FindInDegree(ALGraph G){
	//求出各顶点的入度存入数组indegree中 
	int i , count;

	for(i = 0 ; i < G.vexnum ; i++){
		count = 0;
		ArcNode *p = G.converse_vertices[i].firstarc;
		if(p){
			while(p){
				p = p->nextarc;
				count++;
			}
		}
		indegree[i] = count;
	}
}//FindInDegree

int TopologicalSort(ALGraph G , int topo[]){ 
    //有向图G采用邻接表存储结构 
    //若G无回路，则生成G的一个拓扑序列topo[]并返回OK，否则ERROR 
	int i , m;
    FindInDegree(G);              				//求出各顶点的入度存入数组indegree中 
    InitStack(S);                          		//栈S初始化为空 
    for(i = 0; i < G.vexnum; ++i)
		if(!indegree[i]) Push(S, i);     		//入度为0者进栈 
	m = 0;                               		//对输出顶点计数，初始为0 
	while(!StackEmpty(S)){                		//栈S非空 
		Pop(S, i);                          	//将栈顶顶点vi出栈
		topo[m]=i;                         		//将vi保存在拓扑序列数组topo中 
		++m;                             		//对输出顶点计数 
		ArcNode *p = G.vertices[i].firstarc;    //p指向vi的第一个邻接点 
		while(p){
			int k = p->adjvex;					//vk为vi的邻接点   
			--indegree[k];                   	//vi的每个邻接点的入度减1 
			if(indegree[k] ==0)  Push(S, k);	//若入度减为0，则入栈 
			p = p->nextarc;                		//p指向顶点vi下一个邻接结点 
		}//while 
	}//while
	
	if(m < G.vexnum)  return ERROR;    			//该有向图有回路 
	else return OK;
}//TopologicalSort 

int main(){
	cout << "************算法6.12　拓扑排序**************" << endl << endl;
	ALGraph G;
	// CreateUDG(G);
	CreateUDG_Manual(G);

	cout << "打印有向无环图的出度" << endl;
	for(int i = 0 ; i < G.vexnum ; ++i){
			VNode temp = G.vertices[i];
			ArcNode *p = temp.firstarc;
			if(p == NULL){
				cout << G.vertices[i].data;
			}
			else{
				cout << temp.data;
				while(p){
					cout << "->";
					cout << p->adjvex;
					p = p->nextarc;
				}
			}
			cout << endl;
		}
	
	cout << endl;
	cout << "打印有向无环图的入度" << endl;
	for(int i = 0 ; i < G.vexnum ; ++i){
			VNode temp = G.converse_vertices[i];
			ArcNode *p = temp.firstarc;
			if(p == NULL){
				cout << G.converse_vertices[i].data;
			}
			else{
				cout << temp.data;
				while(p){
					cout << "->";
					cout << p->adjvex;
					p = p->nextarc;
				}
			}
			cout << endl;
		}

	int *topo = new int [G.vexnum];
	
	cout << endl;
	cout << "有向图的邻接表、逆邻接表创建完成!" << endl << endl;

	if(TopologicalSort(G , topo)){
		cout << "该有向图的拓扑有序序列为：";
		for(int j = 0 ; j < G.vexnum; j++){
			if(j != G.vexnum - 1)
				cout << G.vertices[topo[j]].data << " , ";
			else
				cout << G.vertices[topo[j]].data << endl << endl;
		}//for
	}
	else
		cout << "网中存在环，无法进行拓扑排序！" <<endl << endl;
	return OK;
}//main
