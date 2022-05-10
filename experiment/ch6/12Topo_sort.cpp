//�㷨6.12����������

#include <iostream>
using namespace std;

#define MVNum 100                       	//��󶥵���
#define OK 1	
#define ERROR 0 

typedef char VerTexType;

//- - - - -ͼ���ڽӱ�洢��ʾ- - - - - 
typedef struct ArcNode{                		//�߽�� 
    int adjvex;                          	//�ñ���ָ��Ķ����λ�� 
    struct ArcNode *nextarc;          		//ָ����һ���ߵ�ָ�� 
}ArcNode; 

typedef struct VNode{ 
    VerTexType data;                    	//������Ϣ 
    ArcNode *firstarc;                		//ָ���һ�������ö���ıߵ�ָ�� 
}VNode, AdjList[MVNum];               		//AdjList��ʾ�ڽӱ����� 

typedef struct{ 
    AdjList vertices;                 		//�ڽӱ� 
	AdjList converse_vertices;				//���ڽӱ�
    int vexnum, arcnum;              		//ͼ�ĵ�ǰ�������ͱ��� 
}ALGraph;
//- - - - - - - - - - - - - - - -

//- - - - -˳��ջ�Ķ���- - - - -
typedef struct{
	int *base;
	int *top;
	int stacksize;
}spStack;
//- - - - - - - - - - - - - - - -

int indegree[MVNum];						//����indegree��Ÿ���������
spStack S;

//------------ջ����ز���----------------------
void InitStack(spStack &S){
	//��ʼ��ջ
	S.base = new int[MVNum];
	if(!S.base)
		exit(1);
	S.top = S.base;
	S.stacksize = MVNum;
}//InitStack

void Push(spStack &S , int i){
	//��ջ
	if(S.top - S.base == S.stacksize)
		return;
	*S.top++ = i;
}//Push

void Pop(spStack &S , int &i){
	//��ջ
	if(S.top == S.base)
		return;
	i = *--S.top;
}//Pop

bool StackEmpty(spStack S){
	//�ж�ջ�Ƿ�Ϊ��
	if(S.top == S.base)
		return true;
	return false;
}//StackEmpty
//-------------------------------------------------

int LocateVex(ALGraph G , VerTexType v){
	//ȷ����v��G�е�λ��
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vertices[i].data == v)
			return i;
		return -1;
}//LocateVex

int CreateUDG(ALGraph &G){ 
	//��������ͼG���ڽӱ����ڽӱ�
	int i , k;
	
	cout <<"�������ܶ��������ܱ������Կո����:";
	cin >> G.vexnum >> G.arcnum;				//�����ܶ��������ܱ��� 
    cout << endl;
	
	cout << "���������ƣ���a" << endl;
	
	for(i = 0; i < G.vexnum; ++i){          	//������㣬�����ͷ����
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vertices[i].data;           	//���붥��ֵ
		G.converse_vertices[i].data = G.vertices[i].data;
		//��ʼ����ͷ����ָ����ΪNULL 
		G.vertices[i].firstarc=NULL;			
		G.converse_vertices[i].firstarc=NULL;
    }//for
	cout << endl;
	cout << "����������Ķ��㣬��a b" << endl;
	for(k = 0; k < G.arcnum;++k){        		//������ߣ������ڽӱ�
		VerTexType v1 , v2;
		int i , j;
		cout << "�������" << (k + 1) << "���������Ķ���:";
		cin >> v1 >> v2;                		//����һ������������������
		i = LocateVex(G, v1);  j = LocateVex(G, v2);
		//ȷ��v1��v2��G��λ�ã���������G.vertices�е���� 

		ArcNode *p1=new ArcNode;               	//����һ���µı߽��*p1 
		p1->adjvex=j;                   		//�ڽӵ����Ϊj
		p1->nextarc = G.vertices[i].firstarc;  G.vertices[i].firstarc=p1;
		//���½��*p1���붥��vi�ı߱�ͷ��

		ArcNode *p2=new ArcNode;               	//����һ���µı߽��*p1 
		p2->adjvex=i;                   		//���ڽӵ����Ϊi
		p2->nextarc = G.converse_vertices[j].firstarc;  G.converse_vertices[j].firstarc=p2;
		//���½��*p1���붥��vi�ı߱�ͷ��
    }//for 
    return OK; 
}//CreateUDG

int CreateUDG_Manual(ALGraph &G){ 
	//��������ͼG���ڽӱ����ڽӱ�
	int i , k;

	G.vexnum = 6;
	G.arcnum = 8;

	G.converse_vertices[0].data=G.vertices[0].data='0';
	G.converse_vertices[1].data=G.vertices[1].data='1';
	G.converse_vertices[2].data=G.vertices[2].data='2';
	G.converse_vertices[3].data=G.vertices[3].data='3';
	G.converse_vertices[4].data=G.vertices[4].data='4';
	G.converse_vertices[5].data=G.vertices[5].data='5';
	
	cout << "���������ƣ���a" << endl;
	
	for(i = 0; i < G.vexnum; ++i){          	//������㣬�����ͷ����
		G.vertices[i].firstarc=NULL;			
		G.converse_vertices[i].firstarc=NULL;
    }//for

	ArcNode *p1=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p2=new ArcNode; 
	p1->adjvex=1;                   		//�ڽӵ����Ϊj  0 1
	p1->nextarc = G.vertices[0].firstarc;  G.vertices[0].firstarc=p1;
	p2->adjvex=0;                   		//���ڽӵ����Ϊi
	p2->nextarc = G.converse_vertices[1].firstarc;  G.converse_vertices[1].firstarc=p2;
	delete [] p1;
	delete  p1;
	// p1=NULL;

	ArcNode *p3=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p4=new ArcNode; 
	p3->adjvex=3;                   		//�ڽӵ����Ϊj  0 3
	p3->nextarc = G.vertices[0].firstarc;  G.vertices[0].firstarc=p3;
	p4->adjvex=0;                   		//���ڽӵ����Ϊi
	p4->nextarc = G.converse_vertices[3].firstarc;  G.converse_vertices[3].firstarc=p4;

	ArcNode *p5=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p6=new ArcNode; 
	p5->adjvex=5;                   		//�ڽӵ����Ϊj  1 5
	p5->nextarc = G.vertices[1].firstarc;  G.vertices[1].firstarc=p5;
	p6->adjvex=1;                   		//���ڽӵ����Ϊi
	p6->nextarc = G.converse_vertices[5].firstarc;  G.converse_vertices[5].firstarc=p6;

	ArcNode *p7=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p8=new ArcNode; 
	p7->adjvex=1;                   		//�ڽӵ����Ϊj  2 1
	p7->nextarc = G.vertices[2].firstarc;  G.vertices[2].firstarc=p7;
	p8->adjvex=2;                   		//���ڽӵ����Ϊi
	p8->nextarc = G.converse_vertices[1].firstarc;  G.converse_vertices[1].firstarc=p8;

	ArcNode *p9=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p10=new ArcNode; 
	p9->adjvex=5;                   		//�ڽӵ����Ϊj  2 5
	p9->nextarc = G.vertices[2].firstarc;  G.vertices[2].firstarc=p9;
	p10->adjvex=2;                   		//���ڽӵ����Ϊi
	p10->nextarc = G.converse_vertices[5].firstarc;  G.converse_vertices[5].firstarc=p10;

	ArcNode *p11=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p12=new ArcNode; 
	p11->adjvex=0;                   		//�ڽӵ����Ϊj  4 0
	p11->nextarc = G.vertices[4].firstarc;  G.vertices[4].firstarc=p11;
	p12->adjvex=4;                   		//���ڽӵ����Ϊi
	p12->nextarc = G.converse_vertices[0].firstarc;  G.converse_vertices[0].firstarc=p12;

	ArcNode *p13=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p14=new ArcNode; 
	p13->adjvex=1;                   		//�ڽӵ����Ϊj  4 1
	p13->nextarc = G.vertices[4].firstarc;  G.vertices[4].firstarc=p13;
	p14->adjvex=4;                   		//���ڽӵ����Ϊi
	p14->nextarc = G.converse_vertices[1].firstarc;  G.converse_vertices[1].firstarc=p14;

	ArcNode *p15=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p16=new ArcNode; 
	p15->adjvex=5;                   		//�ڽӵ����Ϊj  4 5
	p15->nextarc = G.vertices[4].firstarc;  G.vertices[4].firstarc=p15;
	p16->adjvex=4;                   		//���ڽӵ����Ϊi
	p16->nextarc = G.converse_vertices[5].firstarc;  G.converse_vertices[5].firstarc=p16;
    return OK; 
}//CreateUDG


void FindInDegree(ALGraph G){
	//������������ȴ�������indegree�� 
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
    //����ͼG�����ڽӱ�洢�ṹ 
    //��G�޻�·��������G��һ����������topo[]������OK������ERROR 
	int i , m;
    FindInDegree(G);              				//������������ȴ�������indegree�� 
    InitStack(S);                          		//ջS��ʼ��Ϊ�� 
    for(i = 0; i < G.vexnum; ++i)
		if(!indegree[i]) Push(S, i);     		//���Ϊ0�߽�ջ 
	m = 0;                               		//����������������ʼΪ0 
	while(!StackEmpty(S)){                		//ջS�ǿ� 
		Pop(S, i);                          	//��ջ������vi��ջ
		topo[m]=i;                         		//��vi������������������topo�� 
		++m;                             		//������������ 
		ArcNode *p = G.vertices[i].firstarc;    //pָ��vi�ĵ�һ���ڽӵ� 
		while(p){
			int k = p->adjvex;					//vkΪvi���ڽӵ�   
			--indegree[k];                   	//vi��ÿ���ڽӵ����ȼ�1 
			if(indegree[k] ==0)  Push(S, k);	//����ȼ�Ϊ0������ջ 
			p = p->nextarc;                		//pָ�򶥵�vi��һ���ڽӽ�� 
		}//while 
	}//while
	
	if(m < G.vexnum)  return ERROR;    			//������ͼ�л�· 
	else return OK;
}//TopologicalSort 

int main(){
	cout << "************�㷨6.12����������**************" << endl << endl;
	ALGraph G;
	// CreateUDG(G);
	CreateUDG_Manual(G);

	cout << "��ӡ�����޻�ͼ�ĳ���" << endl;
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
	cout << "��ӡ�����޻�ͼ�����" << endl;
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
	cout << "����ͼ���ڽӱ����ڽӱ������!" << endl << endl;

	if(TopologicalSort(G , topo)){
		cout << "������ͼ��������������Ϊ��";
		for(int j = 0 ; j < G.vexnum; j++){
			if(j != G.vexnum - 1)
				cout << G.vertices[topo[j]].data << " , ";
			else
				cout << G.vertices[topo[j]].data << endl << endl;
		}//for
	}
	else
		cout << "���д��ڻ����޷�������������" <<endl << endl;
	return OK;
}//main
