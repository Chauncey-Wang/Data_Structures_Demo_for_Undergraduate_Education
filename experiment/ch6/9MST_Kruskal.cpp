//算法6.9　克鲁斯卡尔算法

#include <iostream>
using namespace std;

typedef char VerTexType;              		//假设顶点的数据类型为字符型 
typedef int ArcType;   
#define MVNum 100                       	//最大顶点数
#define MaxInt 32767                    	//表示极大值，即∞

//----------------图的邻接矩阵---------------------
// typedef struct{ 
// 	VerTexType vexs[MVNum];            		//顶点表 
// 	ArcType arcs[MVNum][MVNum];      		//邻接矩阵 
// 	int vexnum,arcnum;                		//图的当前点数和边数 
// }AMGraph;

typedef struct{ 
	VerTexType vexs[7]={'0','1','2','3','4','5','6'};            		//顶点表 
	ArcType arcs[7][7]={
		{MaxInt,    28,MaxInt,MaxInt,MaxInt,    10,MaxInt},
		{    28,MaxInt,    16,MaxInt,MaxInt,MaxInt,    14},
		{MaxInt,    16,MaxInt,    12,MaxInt,MaxInt,MaxInt},
		{MaxInt,MaxInt,    12,MaxInt,    22,MaxInt,    18},
		{MaxInt,MaxInt,MaxInt,    22,MaxInt,    25,    24},
		{    10,MaxInt,MaxInt,MaxInt,    25,MaxInt,MaxInt},
		{MaxInt,    14,MaxInt,    18,    24,MaxInt,MaxInt}
		};      		//邻接矩阵 
	int vexnum=7,arcnum=9;                		//图的当前点数和边数 
}AMGraph;

//辅助数组Edges的定义
struct{
	VerTexType Head;						//边的始点
	VerTexType Tail;						//边的终点
	ArcType lowcost;						//边上的权值
}Edge[(MVNum * (MVNum - 1)) / 2];


// var1.a='a';

int Vexset[MVNum];							//辅助数组Vexset的定义

int LocateVex(AMGraph G , VerTexType v){
	//确定点v在G中的位置
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
		return -1;
}//LocateVex

void CreateUDN(AMGraph &G){ 
    //采用邻接矩阵表示法，创建无向网G 
	int i , j , k;
	cout <<"请输入总顶点数，总边数，以空格隔开:";
    cin >> G.vexnum >> G.arcnum;						//输入总顶点数，总边数
	cout << endl;
	
	cout << "输入点的名称，如a" << endl;

    for(i = 0; i < G.vexnum; ++i){   
		cout << "请输入第" << (i+1) << "个点的名称:";
		cin >> G.vexs[i];                        		//依次输入点的信息 
	}
	cout << endl;
	for(i = 0; i < G.vexnum; ++i)                		//初始化邻接矩阵，边的权值均置为极大值MaxInt 
		for(j = 0; j < G.vexnum; ++j) 
			G.arcs[i][j] = MaxInt; 
	cout << "输入边依附的顶点及权值，如a b 6" << endl;
	for(k = 0; k < G.arcnum;++k){						//构造邻接矩阵 
		VerTexType v1 , v2;
		ArcType w;
		cout << "请输入第" << (k + 1) << "条边依附的顶点及权值:";
		cin >> v1 >> v2 >> w;                           //输入一条边依附的顶点及权值
		i = LocateVex(G, v1);  j = LocateVex(G, v2);	//确定v1和v2在G中的位置，即顶点数组的下标 
		G.arcs[i][j] = w;								//边<v1, v2>的权值置为w 
		G.arcs[j][i] = G.arcs[i][j];					//置<v1, v2>的对称边<v2, v1>的权值为w 
		Edge[k].lowcost = w;
		Edge[k].Head = v1;
		Edge[k].Tail = v2;
		
	}//for
}//CreateUDN 

//----------冒泡排序-------------------
void Sort(AMGraph G){
	for(int x=0; x<9; x++){
		cout << Edge[x].lowcost << " ";
	}
	cout << endl;
	int m = G.arcnum - 2;
	int flag = 1;
	while((m >= 0) && flag == 1){
		flag = 0;
		for(int j = 0 ; j <= m ; j++){
			if(Edge[j].lowcost > Edge[j+ 1].lowcost){
				flag = 1;

				VerTexType temp_Head = Edge[j].Head;
				Edge[j].Head = Edge[j+ 1].Head;
				Edge[j + 1].Head = temp_Head;
				

				VerTexType temp_Tail = Edge[j].Tail;
				Edge[j].Tail = Edge[j+ 1].Tail;
				Edge[j + 1].Tail = temp_Tail;
				
				ArcType temp_lowcost = Edge[j].lowcost;
				Edge[j].lowcost = Edge[j+ 1].lowcost;
				Edge[j + 1].lowcost = temp_lowcost;
			}//if
		}//for
		--m;
	}//while

	for(int x=0; x<9; x++){
		cout << Edge[x].lowcost << " ";
	}
	cout << endl;
}//Sort

void MiniSpanTree_Kruskal(AMGraph G){ 
    //无向网G以邻接矩阵形式存储，构造G的最小生成树T，输出T的各条边     
    int i , j , v1 , v2 , vs1 , vs2;
	Sort(G);                 							//将数组Edge中的元素按权值从小到大排序 
	for(i = 0; i < G.vexnum; ++i)     					//辅助数组，表示各顶点自成一个连通分量 
        Vexset[i] = i;
    for(i = 0; i < G.arcnum; ++i){      
		//依次查看排好序的数组Edge中的边是否在同一连通分量上     
		v1 =LocateVex(G, Edge[i].Head);     			//v1为边的始点Head的下标 
		v2 =LocateVex(G, Edge[i].Tail);     			//v2为边的终点Tail的下标 
		vs1 = Vexset[v1];       						//获取边Edge[i]的始点所在的连通分量vs1 
		vs2 = Vexset[v2];       						//获取边Edge[i]的终点所在的连通分量vs2 
		if(vs1 != vs2){         						//边的两个顶点分属不同的连通分量 
			cout << Edge[i].Head << "-->" << Edge[i].Tail << endl;		//输出此边 
			for(j = 0; j < G.vexnum; ++j)      			//合并vs1和vs2两个分量，即两个集合统一编号 
				if(Vexset[j] == vs2) Vexset[j] = vs1;	//集合编号为vs2的都改为vs1 
		}//if 
    }//for 
}//MiniSpanTree_Kruskal

int main(){
	Edge[0].Head='0'; Edge[0].Tail='1'; Edge[0].lowcost=28;
	Edge[1].Head='1'; Edge[1].Tail='2'; Edge[1].lowcost=16;
	Edge[2].Head='1'; Edge[2].Tail='6'; Edge[2].lowcost=14;
	Edge[3].Head='2'; Edge[3].Tail='3'; Edge[3].lowcost=12;
	Edge[4].Head='3'; Edge[4].Tail='4'; Edge[4].lowcost=22;
	Edge[5].Head='3'; Edge[5].Tail='6'; Edge[5].lowcost=18;
	Edge[6].Head='4'; Edge[6].Tail='5'; Edge[6].lowcost=25;
	Edge[7].Head='4'; Edge[7].Tail='6'; Edge[7].lowcost=24;
	Edge[8].Head='5'; Edge[8].Tail='0'; Edge[8].lowcost=10;
	cout << "************算法6.9　克鲁斯卡尔算法**************" << endl << endl;
	AMGraph G;
	// CreateUDN(G);
	
	cout <<endl;
	cout << "*****无向网G创建完成！*****" << endl;

	cout <<endl;
	MiniSpanTree_Kruskal(G);

	return 0;
}///main


/*

请输入总顶点数，总边数，以空格隔开:7 9

输入点的名称，如a
请输入第1个点的名称:0
请输入第2个点的名称:1
请输入第3个点的名称:2
请输入第4个点的名称:3
请输入第5个点的名称:4
请输入第6个点的名称:5
请输入第7个点的名称:6

输入边依附的顶点及权值，如a b 6
请输入第1条边依附的顶点及权值:0 1 28
请输入第2条边依附的顶点及权值:1 2 16
请输入第3条边依附的顶点及权值:1 6 14
请输入第4条边依附的顶点及权值:2 3 12
请输入第5条边依附的顶点及权值:3 4 22
请输入第6条边依附的顶点及权值:3 6 18
请输入第7条边依附的顶点及权值:4 5 25
请输入第8条边依附的顶点及权值:4 6 24
请输入第9条边依附的顶点及权值:5 0 10

*****无向网G创建完成！*****

2-->3
5-->0
1-->6
1-->2
3-->4
4-->5

*/