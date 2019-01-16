#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linker.h"
#include"studentshow.h"

extern Student *head;

void show_one_student(Student *p)
{
    printf(" [ 0 ] 学号：%d\n",p->id);
	printf(" [ 1 ] 姓名：%s\n",p->name);
	printf(" [ 2 ] 性别：%s\n",p->sex);
	printf(" [ 3 ] 专业：%s\n",p->specialty);
	printf(" [ 4 ] 班级：%s\n",p->classes);
	switch(p->category){
	    case UNDERGRADUATE:printf(" [ 5 ] 学生类型：本科生\n");break;
		case POSTGRADUATE:printf(" [ 5 ] 学生类型：研究生\n");break;
	}
	if(p->category==UNDERGRADUATE){
	     printf(" [ 6 ] 高数成绩：%d\n",p->math);
		 printf(" [ 7 ] 英语成绩：%d\n",p->english);
		 printf(" [ 8 ] C语言成绩：%d\n",p->clanguage);
		 printf(" [ A ] 总成绩：%d\n",p->totalscore);
	}
	else {
	     printf(" [ 6 ] 课程综合成绩：%d\n",p->comprehensive);
		 printf(" [ 7 ] 论文成绩：%d\n",p->thesis);
		 printf(" [ A ] 总成绩：%d\n",p->totalscore);
	}
    printf(" [ B ] 班级排名：%d\n",p->classrank);
	printf(" [ C ] 校级排名：%d\n",p->schoolrank);
}

void getPage(int page,enum studentcategory category)  /*显示当前页学生信息*/
{
  int count=0,page1,page2;
  Student *p1=head;
  if(p1==NULL){
      printf("没有学生记录，请按任意键继续...\n");
	  getchar();
	  system("cls");
	  return;
  }
  page1=(page-1)*10;
  page2=page*10;
  if(category==UNDERGRADUATE)
	  printf("学号  姓名  性别     专业     班级  学生类型  高数成绩  英语成绩  C语言成绩  总成绩  班级排名  校级排名\n");
  else printf("学号  姓名  性别     专业     班级  学生类型  课程设计成绩  论文成绩  总成绩  班级排名  校级排名\n");
  while(p1!=NULL){
	  if(p1->category==category&&category==UNDERGRADUATE){
	        count++;
			if(count>=page1&&count<=page2)
				printf("%2d%8s%5s%13s%4s     本科生  %6d%10d%10d%10d%10d%10d\n",p1->id,p1->name,p1->sex,p1->specialty,p1->classes,p1->math,p1->english,p1->clanguage,p1->totalscore,p1->classrank,p1->schoolrank);
	  }
	  if(p1->category==category&&category==POSTGRADUATE){
	        count++;
			if(count>=page1&&count<=page2)
				printf("%2d%8s%5s%13s%4s     研究生  %8d%12d%10d%10d%10d\n",p1->id,p1->name,p1->sex,p1->specialty,p1->classes,p1->comprehensive,p1->thesis,p1->totalscore,p1->classrank,p1->schoolrank);
	  }
	  if(count>page2)break;
	  p1=p1->next;
  }
}

void getPageByClasses(enum studentcategory category,char *specialty,char *classes,int page)
{
  int count=0,page1,page2;
  Student *p1=head;
  if(p1==NULL){
      printf("没有学生记录，请按任意键继续...\n");
	  getchar();
	  system("cls");
	  return;
  }
  page1=(page-1)*10;
  page2=page*10;
  if(category==UNDERGRADUATE)
	  printf("学号  姓名  性别     专业     班级  学生类型  高数成绩  英语成绩  C语言成绩  总成绩  班级排名  校级排名\n");
  else printf("学号  姓名  性别     专业     班级  学生类型  课程设计成绩  论文成绩  总成绩  班级排名  校级排名\n");
  while(p1!=NULL){
	  if(p1->category==category&&category==UNDERGRADUATE&&strcmp(p1->classes,classes)==0&&strcmp(p1->specialty,specialty)==0){
	        count++;
			if(count>=page1&&count<=page2)
				printf("%2d%8s%5s%13s%4s     本科生  %6d%10d%10d%10d%10d%10d\n",p1->id,p1->name,p1->sex,p1->specialty,p1->classes,p1->math,p1->english,p1->clanguage,p1->totalscore,p1->classrank,p1->schoolrank);
	  }
	  if(p1->category==category&&category==POSTGRADUATE&&strcmp(p1->classes,classes)==0&&strcmp(p1->specialty,specialty)==0){
	        count++;
			if(count>=page1&&count<=page2)
				printf("%2d%8s%5s%13s%4s     研究生  %8d%12d%10d%10d%10d\n",p1->id,p1->name,p1->sex,p1->specialty,p1->classes,p1->comprehensive,p1->thesis,p1->totalscore,p1->classrank,p1->schoolrank);
	  }
	  if(count>page2)break;
	  p1=p1->next;
  }
}

void getPageFailByClassCourse(char *specialty,char *classes,int course,int page)
{
  int count=0,page1,page2;
  Student *p1=head;
  if(p1==NULL){
      printf("没有学生记录，请按任意键继续...\n");
	  getchar();
	  system("cls");
	  return;
  }
  page1=(page-1)*10;
  page2=page*10;
  if(course==1||course==2||course==3)
	  printf("学号  姓名  性别     专业     班级  学生类型  高数成绩  英语成绩  C语言成绩  总成绩  班级排名  校级排名\n");
  else printf("学号  姓名  性别     专业     班级  学生类型  课程设计成绩  论文成绩  总成绩  班级排名  校级排名\n");
  while(p1!=NULL){
	  if(strcmp(p1->classes,classes)==0&&strcmp(p1->specialty,specialty)==0&&course==1&&p1->math>=0&&p1->math<60){
	        count++;
			if(count>=page1&&count<=page2)
				printf("%2d%8s%5s%13s%4s     本科生  %6d%10d%10d%10d%10d%10d\n",p1->id,p1->name,p1->sex,p1->specialty,p1->classes,p1->math,p1->english,p1->clanguage,p1->totalscore,p1->classrank,p1->schoolrank);
	  }
	  if(strcmp(p1->classes,classes)==0&&strcmp(p1->specialty,specialty)==0&&course==2&&p1->english>=0&&p1->english<60){
	        count++;
			if(count>=page1&&count<=page2)
				printf("%2d%8s%5s%13s%4s     本科生  %6d%10d%10d%10d%10d%10d\n",p1->id,p1->name,p1->sex,p1->specialty,p1->classes,p1->math,p1->english,p1->clanguage,p1->totalscore,p1->classrank,p1->schoolrank);
	  }
	  if(strcmp(p1->classes,classes)==0&&strcmp(p1->specialty,specialty)==0&&course==3&&p1->clanguage>=0&&p1->clanguage<60){
	        count++;
			if(count>=page1&&count<=page2)
				printf("%2d%8s%5s%13s%4s     本科生  %6d%10d%10d%10d%10d%10d\n",p1->id,p1->name,p1->sex,p1->specialty,p1->classes,p1->math,p1->english,p1->clanguage,p1->totalscore,p1->classrank,p1->schoolrank);
	  }
	  if(strcmp(p1->classes,classes)==0&&strcmp(p1->specialty,specialty)==0&&course==4&&p1->thesis>=0&&p1->thesis<60){
	        count++;
			if(count>=page1&&count<=page2)
				printf("%2d%8s%5s%13s%4s     研究生  %8d%12d%10d%10d%10d\n",p1->id,p1->name,p1->sex,p1->specialty,p1->classes,p1->comprehensive,p1->thesis,p1->totalscore,p1->classrank,p1->schoolrank);
	  }
	  if(strcmp(p1->classes,classes)==0&&strcmp(p1->specialty,specialty)==0&&course==5&&p1->comprehensive>=0&&p1->comprehensive<60){
	        count++;
			if(count>=page1&&count<=page2)
				printf("%2d%8s%5s%13s%4s     研究生  %8d%12d%10d%10d%10d\n",p1->id,p1->name,p1->sex,p1->specialty,p1->classes,p1->comprehensive,p1->thesis,p1->totalscore,p1->classrank,p1->schoolrank);
	  }
	  if(count>page2)break;
	  p1=p1->next;
  }
}