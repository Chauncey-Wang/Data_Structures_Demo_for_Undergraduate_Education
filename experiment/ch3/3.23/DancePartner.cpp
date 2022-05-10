#include"3.23.h"
#include<string.h>

Person dancer[MAXQSIZE];
char name[][20]={"鄢雪棱", "高欣雅", "张甜源", "许丹丹", "冉小溪", "周如意", "胡思琪", 
"蒋雅琪", "金城武", "吴彦祖", "王思聪", "古天乐", "周杰伦", "李敏镐", "李钟硕", "马云",
 "张智霖", "王力宏"};
//  char name[]={'鄢雪棱', '高欣雅', '张甜源', '许丹丹', '冉小溪', '周如意', '胡思琪', 
// '蒋雅琪', '金城武', '吴彦祖', '王思聪', '古天乐', '周杰伦', '李敏镐', '李钟硕', '马云',
//  '张智霖', '王力宏'};
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
