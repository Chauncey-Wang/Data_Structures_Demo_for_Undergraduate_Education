//�㷨6.13���ؼ�·���㷨

#include <iostream>
using namespace std;

#define MVNum 100                       	//��󶥵���
#define BDNum MVNum * (MVNum - 1)			//������
#define OK 1	
#define ERROR 0 

typedef char VerTexType;

//- - - - -ͼ���ڽӱ�洢��ʾ- - - - - 
typedef struct ArcNode{                		//�߽�� 
    int adjvex;                          	//�ñ���ָ��Ķ����λ��
	int weight;								//Ȩֵ
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
int ve[BDNum];								//�¼�vi�����緢��ʱ��
int vl[BDNum];								//�¼�vi����ٷ���ʱ��
int topo[MVNum];							//��¼�������еĶ������
spStack S;

//----------------ջ�Ĳ���--------------------
void InitStack(spStack &S){
	//ջ�ĳ�ʼ��
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
//---------------------------------------

int LocateVex(ALGraph G , VerTexType v){
	//ȷ����v��G�е�λ��
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vertices[i].data == v)
			return i;
		return -1;
}//LocateVex

// int CreateUDG(ALGraph &G){ 
// 	//��������ͼG���ڽӱ����ڽӱ�
// 	int i , k;
	
// 	cout <<"�������ܶ��������ܱ������Կո����:";
// 	cin >> G.vexnum >> G.arcnum;				//�����ܶ��������ܱ��� 
//     cout << endl;

// 	cout << "���������ƣ���a" << endl;
	
// 	for(i = 0; i < G.vexnum; ++i){          		//������㣬�����ͷ����
// 		cout << "�������" << (i+1) << "���������:";
// 		cin >> G.vertices[i].data;           		//���붥��ֵ
// 		G.converse_vertices[i].data = G.vertices[i].data;
// 		//��ʼ����ͷ����ָ����ΪNULL 
// 		G.vertices[i].firstarc=NULL;			
// 		G.converse_vertices[i].firstarc=NULL;
//     }//for
// 	cout << endl;

// 	cout << "����������Ķ��㼰��Ȩֵ����a b 3" << endl;

// 	for(k = 0; k < G.arcnum;++k){        			//������ߣ������ڽӱ�
// 		VerTexType v1 , v2;
// 		int i , j , w;
// 		cout << "�������" << (k + 1) << "���������Ķ��㼰��Ȩֵ:";
// 		cin >> v1 >> v2 >> w;                		//����һ������������������
// 		i = LocateVex(G, v1);  j = LocateVex(G, v2);
// 		//ȷ��v1��v2��G��λ�ã���������G.vertices�е���� 

// 		ArcNode *p1=new ArcNode;               		//����һ���µı߽��*p1 
// 		p1->adjvex=j;                   			//�ڽӵ����Ϊj
// 		p1->nextarc = G.vertices[i].firstarc;  G.vertices[i].firstarc=p1;
// 		p1->weight = w;
// 		//���½��*p1���붥��vi�ı߱�ͷ��

// 		ArcNode *p2=new ArcNode;               		//����һ���µı߽��*p1 
// 		p2->adjvex=i;                   			//���ڽӵ����Ϊi
// 		p2->nextarc = G.converse_vertices[j].firstarc;  G.converse_vertices[j].firstarc=p2;
// 		p2->weight = w;
// 		//���½��*p1���붥��vi�ı߱�ͷ��
//     }//for 
//     return OK; 
// }//CreateUDG


int CreateUDG_Manual(ALGraph &G){ 
	//��������ͼG���ڽӱ����ڽӱ�
	int i , k;

	G.vexnum = 6;
	G.arcnum = 10;

	G.converse_vertices[0].data=G.vertices[0].data='1';
	G.converse_vertices[1].data=G.vertices[1].data='2';
	G.converse_vertices[2].data=G.vertices[2].data='3';
	G.converse_vertices[3].data=G.vertices[3].data='4';
	G.converse_vertices[4].data=G.vertices[4].data='5';
	G.converse_vertices[5].data=G.vertices[5].data='6';
	
	cout << "���������ƣ���a" << endl;
	
	for(i = 0; i < G.vexnum; ++i){          	//������㣬�����ͷ����
		G.vertices[i].firstarc=NULL;			
		G.converse_vertices[i].firstarc=NULL;
    }//for

	ArcNode *p1=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p2=new ArcNode; 
	p1->adjvex=1;                   		//�ڽӵ����Ϊj  1 2
	p1->nextarc = G.vertices[0].firstarc;  G.vertices[0].firstarc=p1;
	p2->adjvex=0;                   		//���ڽӵ����Ϊi
	p2->nextarc = G.converse_vertices[1].firstarc;  G.converse_vertices[1].firstarc=p2;
	p1->weight=p2->weight=1;

	ArcNode *p3=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p4=new ArcNode; 
	p3->adjvex=2;                   		//�ڽӵ����Ϊj  1 3
	p3->nextarc = G.vertices[0].firstarc;  G.vertices[0].firstarc=p3;
	p4->adjvex=0;                   		//���ڽӵ����Ϊi
	p4->nextarc = G.converse_vertices[2].firstarc;  G.converse_vertices[2].firstarc=p4;
	p3->weight=3;
	p4->weight=3;


	ArcNode *p5=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p6=new ArcNode; 
	p5->adjvex=3;                   		//�ڽӵ����Ϊj  1 4
	p5->nextarc = G.vertices[0].firstarc;  G.vertices[0].firstarc=p5;
	p6->adjvex=0;                   		//���ڽӵ����Ϊi
	p6->nextarc = G.converse_vertices[3].firstarc;  G.converse_vertices[3].firstarc=p6;
	p5->weight=p6->weight=5;


	ArcNode *p7=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p8=new ArcNode; 
	p7->adjvex=2;                   		//�ڽӵ����Ϊj  2 3
	p7->nextarc = G.vertices[1].firstarc;  G.vertices[1].firstarc=p7;
	p8->adjvex=1;                   		//���ڽӵ����Ϊi
	p8->nextarc = G.converse_vertices[2].firstarc;  G.converse_vertices[2].firstarc=p8;
	p7->weight=p8->weight=1;

	ArcNode *p9=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p10=new ArcNode; 
	p9->adjvex=4;                   		//�ڽӵ����Ϊj  2 5
	p9->nextarc = G.vertices[1].firstarc;  G.vertices[1].firstarc=p9;
	p10->adjvex=1;                   		//���ڽӵ����Ϊi
	p10->nextarc = G.converse_vertices[4].firstarc;  G.converse_vertices[4].firstarc=p10;
	p9->weight=p10->weight=2;

	ArcNode *p11=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p12=new ArcNode; 
	p11->adjvex=3;                   		//�ڽӵ����Ϊj  3 4
	p11->nextarc = G.vertices[2].firstarc;  G.vertices[2].firstarc=p11;
	p12->adjvex=2;                   		//���ڽӵ����Ϊi
	p12->nextarc = G.converse_vertices[3].firstarc;  G.converse_vertices[3].firstarc=p12;
	p11->weight=p12->weight=1;

	ArcNode *p13=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p14=new ArcNode; 
	p13->adjvex=5;                   		//�ڽӵ����Ϊj  3 6
	p13->nextarc = G.vertices[2].firstarc;  G.vertices[2].firstarc=p13;
	p14->adjvex=2;                   		//���ڽӵ����Ϊi
	p14->nextarc = G.converse_vertices[5].firstarc;  G.converse_vertices[5].firstarc=p14;
	p13->weight=p14->weight=2;

	ArcNode *p15=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p16=new ArcNode; 
	p15->adjvex=4;                   		//�ڽӵ����Ϊj  4 5
	p15->nextarc = G.vertices[3].firstarc;  G.vertices[3].firstarc=p15;
	p16->adjvex=3;                   		//���ڽӵ����Ϊi
	p16->nextarc = G.converse_vertices[4].firstarc;  G.converse_vertices[4].firstarc=p16;
    p15->weight=p16->weight=1;

	ArcNode *p17=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p18=new ArcNode; 
	p17->adjvex=5;                   		//�ڽӵ����Ϊj  4 6
	p17->nextarc = G.vertices[3].firstarc;  G.vertices[3].firstarc=p17;
	p18->adjvex=3;                   		//���ڽӵ����Ϊi
	p18->nextarc = G.converse_vertices[5].firstarc;  G.converse_vertices[5].firstarc=p18;
	p17->weight=p18->weight=2;

	ArcNode *p19=new ArcNode;               	//����һ���µı߽��*p1 
	ArcNode *p20=new ArcNode; 
	p19->adjvex=5;                   		//�ڽӵ����Ϊj  5 6
	p19->nextarc = G.vertices[4].firstarc;  G.vertices[4].firstarc=p19;
	p20->adjvex=4;                   		//���ڽӵ����Ϊi
	p20->nextarc = G.converse_vertices[5].firstarc;  G.converse_vertices[5].firstarc=p20;
	p19->weight=p20->weight=2;
	
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
		}//if
		indegree[i] = count;
	}//for
}//FindInDegree

int TopologicalOrder(ALGraph G , int topo[]){ 
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
}//TopologicalOrder

int CriticalPath(ALGraph G){ 
    //GΪ�ڽӱ�洢�������������G�ĸ���ؼ��
	int n , i , k , j , e , l;
    if (!TopologicalOrder(G, topo))  return ERROR; 
    //�������������㷨��ʹ�������б�����topo�У�������ʧ�ܣ���������򻷣�����ERROR 
    n = G.vexnum;                  				//nΪ������� 
	cout << "����������";
	for(int x=0;x<n;x++)
		cout << topo[x]<< " ";
	cout << endl;

    for(i = 0; i < n; i++)               		//��ÿ���¼������緢��ʱ���ó�ֵ0 
		ve[i] = 0; 

    /*�D�D�D�D�D�D�D�D�D�D�����˴�����ÿ���¼������緢��ʱ�䣭�D�D�D�D���D�D�D�D�D*/ 
    for(i = 0;i < n; i++){                 
		k = topo[i];                   			//ȡ�����������еĶ������k             
		ArcNode *p = G.vertices[k].firstarc;    //pָ��k�ĵ�һ���ڽӶ���  
		while(p != NULL){            			//���θ���k�������ڽӶ�������緢��ʱ��   
			j = p->adjvex;               		//jΪ�ڽӶ�������    
			// cout<<j <<" "<<k<<" "<< ve[j]<<endl;               
			if(ve[j] < ve[k] + p->weight)    	//���¶���j�����緢��ʱ��ve[j] 
				ve[j] = ve[k] + p->weight;  
			// cout << ve[j]<<endl;   
			p = p->nextarc;              		//pָ��k����һ���ڽӶ���  
		} //while 
    } //for 

    for(i=0;i<n;i++)                 			//��ÿ���¼�����ٷ���ʱ���ó�ֵve[n-1] 
		vl[i]=ve[n-1];
	
    /*�D�D�D�D�D�D�D�D�D�D�������˴�����ÿ���¼�����ٷ���ʱ�䣭�D�D�D�D���D�D�D�D�D*/ 
    for(i = n - 1;i >= 0; i--){               
		k = topo[i];                   			//ȡ�����������еĶ������k      
		// cout << k << endl;      
		ArcNode *p = G.vertices[k].firstarc;    //pָ��k�ĵ�һ���ڽӶ���  
		while(p != NULL){            			//����k���ڽӵ㣬����k����ٷ���ʱ��   
			j = p->adjvex;              		//jΪ�ڽӶ������� 
			// cout <<"j"<< j<< endl;                  
			if(vl[k] > vl[j] - p->weight)    	//���¶���k����ٷ���ʱ��vl[k] 
				vl[k] = vl[j] - p->weight;       
			p = p->nextarc;              		//pָ��k����һ���ڽӶ���  
		}//while 
    }//for 

    /*�D�D�D�D�D�D�D�D�D�D�D�D�ж�ÿһ��Ƿ�Ϊ�ؼ�����D�D�D�D�D�D���D�D�D�D�D*/
	cout << endl;
	cout << "�ؼ��·��Ϊ:";
    for(i = 0;i < n; i++){                		//ÿ��ѭ�����viΪ���ʼ������л 
        ArcNode *p = G.vertices[i].firstarc;    //pָ��i�ĵ�һ���ڽӶ���  
        while(p != NULL) {    
			j = p->adjvex;             			//jΪi���ڽӶ�������    
			e = ve[i];                 			//����<vi, vj>�����翪ʼʱ�� 
			l = vl[j] - p->weight;      		//����<vi, vj>����ٿ�ʼʱ�� (ֻ��Ϊ�˷����ӡj����ѡ�õĺ�һ����)
			if(e == l)               			//��Ϊ�ؼ���������<vi, vj> 
				cout << G.vertices[i].data << "-->" << G.vertices[j].data << " ";
			p = p->nextarc;              		//pָ��i����һ���ڽӶ���  
		} //while 
	} //for  
	return OK;
}//CriticalPath

int main(){
	cout << "************�㷨6.13���ؼ�·���㷨**************" << endl << endl;
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
	int *topo = new int [G.vexnum];
	
	cout << endl;
	cout << "����ͼ�������!" << endl << endl;
	
	if(!CriticalPath(G))
		cout << "���д��ڻ����޷�������������" <<endl << endl;
	cout << endl;
	return OK;
}//main

