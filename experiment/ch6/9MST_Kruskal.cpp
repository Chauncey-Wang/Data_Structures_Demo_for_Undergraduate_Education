//�㷨6.9����³˹�����㷨

#include <iostream>
using namespace std;

typedef char VerTexType;              		//���趥�����������Ϊ�ַ��� 
typedef int ArcType;   
#define MVNum 100                       	//��󶥵���
#define MaxInt 32767                    	//��ʾ����ֵ������

//----------------ͼ���ڽӾ���---------------------
// typedef struct{ 
// 	VerTexType vexs[MVNum];            		//����� 
// 	ArcType arcs[MVNum][MVNum];      		//�ڽӾ��� 
// 	int vexnum,arcnum;                		//ͼ�ĵ�ǰ�����ͱ��� 
// }AMGraph;

typedef struct{ 
	VerTexType vexs[7]={'0','1','2','3','4','5','6'};            		//����� 
	ArcType arcs[7][7]={
		{MaxInt,    28,MaxInt,MaxInt,MaxInt,    10,MaxInt},
		{    28,MaxInt,    16,MaxInt,MaxInt,MaxInt,    14},
		{MaxInt,    16,MaxInt,    12,MaxInt,MaxInt,MaxInt},
		{MaxInt,MaxInt,    12,MaxInt,    22,MaxInt,    18},
		{MaxInt,MaxInt,MaxInt,    22,MaxInt,    25,    24},
		{    10,MaxInt,MaxInt,MaxInt,    25,MaxInt,MaxInt},
		{MaxInt,    14,MaxInt,    18,    24,MaxInt,MaxInt}
		};      		//�ڽӾ��� 
	int vexnum=7,arcnum=9;                		//ͼ�ĵ�ǰ�����ͱ��� 
}AMGraph;

//��������Edges�Ķ���
struct{
	VerTexType Head;						//�ߵ�ʼ��
	VerTexType Tail;						//�ߵ��յ�
	ArcType lowcost;						//���ϵ�Ȩֵ
}Edge[(MVNum * (MVNum - 1)) / 2];


// var1.a='a';

int Vexset[MVNum];							//��������Vexset�Ķ���

int LocateVex(AMGraph G , VerTexType v){
	//ȷ����v��G�е�λ��
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
		return -1;
}//LocateVex

void CreateUDN(AMGraph &G){ 
    //�����ڽӾ����ʾ��������������G 
	int i , j , k;
	cout <<"�������ܶ��������ܱ������Կո����:";
    cin >> G.vexnum >> G.arcnum;						//�����ܶ��������ܱ���
	cout << endl;
	
	cout << "���������ƣ���a" << endl;

    for(i = 0; i < G.vexnum; ++i){   
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vexs[i];                        		//������������Ϣ 
	}
	cout << endl;
	for(i = 0; i < G.vexnum; ++i)                		//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt 
		for(j = 0; j < G.vexnum; ++j) 
			G.arcs[i][j] = MaxInt; 
	cout << "����������Ķ��㼰Ȩֵ����a b 6" << endl;
	for(k = 0; k < G.arcnum;++k){						//�����ڽӾ��� 
		VerTexType v1 , v2;
		ArcType w;
		cout << "�������" << (k + 1) << "���������Ķ��㼰Ȩֵ:";
		cin >> v1 >> v2 >> w;                           //����һ���������Ķ��㼰Ȩֵ
		i = LocateVex(G, v1);  j = LocateVex(G, v2);	//ȷ��v1��v2��G�е�λ�ã�������������±� 
		G.arcs[i][j] = w;								//��<v1, v2>��Ȩֵ��Ϊw 
		G.arcs[j][i] = G.arcs[i][j];					//��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw 
		Edge[k].lowcost = w;
		Edge[k].Head = v1;
		Edge[k].Tail = v2;
		
	}//for
}//CreateUDN 

//----------ð������-------------------
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
    //������G���ڽӾ�����ʽ�洢������G����С������T�����T�ĸ�����     
    int i , j , v1 , v2 , vs1 , vs2;
	Sort(G);                 							//������Edge�е�Ԫ�ذ�Ȩֵ��С�������� 
	for(i = 0; i < G.vexnum; ++i)     					//�������飬��ʾ�������Գ�һ����ͨ���� 
        Vexset[i] = i;
    for(i = 0; i < G.arcnum; ++i){      
		//���β鿴�ź��������Edge�еı��Ƿ���ͬһ��ͨ������     
		v1 =LocateVex(G, Edge[i].Head);     			//v1Ϊ�ߵ�ʼ��Head���±� 
		v2 =LocateVex(G, Edge[i].Tail);     			//v2Ϊ�ߵ��յ�Tail���±� 
		vs1 = Vexset[v1];       						//��ȡ��Edge[i]��ʼ�����ڵ���ͨ����vs1 
		vs2 = Vexset[v2];       						//��ȡ��Edge[i]���յ����ڵ���ͨ����vs2 
		if(vs1 != vs2){         						//�ߵ��������������ͬ����ͨ���� 
			cout << Edge[i].Head << "-->" << Edge[i].Tail << endl;		//����˱� 
			for(j = 0; j < G.vexnum; ++j)      			//�ϲ�vs1��vs2��������������������ͳһ��� 
				if(Vexset[j] == vs2) Vexset[j] = vs1;	//���ϱ��Ϊvs2�Ķ���Ϊvs1 
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
	cout << "************�㷨6.9����³˹�����㷨**************" << endl << endl;
	AMGraph G;
	// CreateUDN(G);
	
	cout <<endl;
	cout << "*****������G������ɣ�*****" << endl;

	cout <<endl;
	MiniSpanTree_Kruskal(G);

	return 0;
}///main


/*

�������ܶ��������ܱ������Կո����:7 9

���������ƣ���a
�������1���������:0
�������2���������:1
�������3���������:2
�������4���������:3
�������5���������:4
�������6���������:5
�������7���������:6

����������Ķ��㼰Ȩֵ����a b 6
�������1���������Ķ��㼰Ȩֵ:0 1 28
�������2���������Ķ��㼰Ȩֵ:1 2 16
�������3���������Ķ��㼰Ȩֵ:1 6 14
�������4���������Ķ��㼰Ȩֵ:2 3 12
�������5���������Ķ��㼰Ȩֵ:3 4 22
�������6���������Ķ��㼰Ȩֵ:3 6 18
�������7���������Ķ��㼰Ȩֵ:4 5 25
�������8���������Ķ��㼰Ȩֵ:4 6 24
�������9���������Ķ��㼰Ȩֵ:5 0 10

*****������G������ɣ�*****

2-->3
5-->0
1-->6
1-->2
3-->4
4-->5

*/