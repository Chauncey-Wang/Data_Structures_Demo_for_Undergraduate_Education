#include"3.23.h"
#include<string.h>

Person dancer[MAXQSIZE];
char name[][20]={"۳ѩ��", "������", "����Դ", "����", "ȽСϪ", "������", "��˼��", 
"������", "�����", "������", "��˼��", "������", "�ܽ���", "������", "����˶", "����",
 "������", "������"};
//  char name[]={'۳ѩ��', '������', '����Դ', '����', 'ȽСϪ', '������', '��˼��', 
// '������', '�����', '������', '��˼��', '������', '�ܽ���', '������', '����˶', '����',
//  '������', '������'};
//  char sex[][2]={"F", "F", "F", "F", "F", "F", "F", "F", "M", "M", "M", "M", "M", 
//  "M", "M", "M", "M", "M"};
 char sex[]={'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'M', 'M', 'M', 'M', 'M', 
 'M', 'M', 'M', 'M', 'M'};

int main() {
	int people_num = 18;
	for(int j=0; j<18 ;j++){
		strcpy(dancer[j].name, name[j]);
		// *dancer[j].name=name[j];
		// dancer[j].sex=*sex[j];
		dancer[j].sex=sex[j];
	}	
	DancePartner(dancer, people_num);
	return 0;
}
