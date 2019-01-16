#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linker.h"
#include"studentshow.h"
#include"studentManage.h"

extern Student *head;
extern int maxId;

void addStudent()  /*添加学生基本信息*/
{
	char name[80],sex[80];
    Student *p=NULL;
	int i,n,category;
	printf("请输入需要添加信息的学生人数：");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		fflush(stdin);   /*清空键盘缓存区*/
		printf("请输入第%d位学生信息：\n",i);
		if((p=(Student *)malloc(sizeof(Student)))==NULL){
		     printf("不能成功分配存储块\n");
			 exit(0);
		}
		p->next=NULL;
		do{
		     printf("请输入学生姓名：");
			 gets(name);
			 if(strlen(name)>=10){
			     printf("输入有误，名字长度不能超出十位，请重新输入...\n");
			 }
			 else break;
		}while(1);
		strcpy(p->name,name);
		fflush(stdin);
		do{
		    printf("请输入学生的性别（男或女）：");
			scanf("%s",sex);
			if(strcmp(sex,"男")!=0&&strcmp(sex,"女")!=0){
			     printf("输入有误，只能输入 男 或者 女，请重新输入...\n");
			}
			else break;
		}while(1);   
		strcpy(p->sex,sex);
		fflush(stdin);
		printf("请输入学生专业名称：");
		gets(p->specialty);
		printf("请输入班别：");
		gets(p->classes);
		printf("请输入学生类型（本科生-0，研究生-1）：");
		do{
		     scanf("%d",&category);
			 if(category!=1&&category!=0){
			      printf("输入有误，只能输入0或1，请重新输入...");
			 }
			 else break;
		}while(1);
		p->category=(enum studentcategory)category;
		p->math=-1;
		p->english=-1;
		p->clanguage=-1;
		p->comprehensive=-1;
		p->thesis=-1;
		p->totalscore=-1;
		p->classrank=-1;
		p->schoolrank=-1;
		maxId++;
		p->id=maxId;
		addNode(&head,p);
		system("cls");
	}
	printf("本次输入成功，请按任意键继续...");
	getchar();
	getchar();
	system("cls");
}

void modifyStudent()   /*根据学号修改学生基本信息和成绩信息*/
{
   Student *p=head;
   int id,choose,category;
   printf("请输入所要修改信息的学生学号：");
   scanf("%d",&id);
   while(p!=NULL){      /*寻找符合该信息的学生*/
      if(p->id==id)break;
	  p=p->next;
   }
   if(p==NULL){
      printf("没有找到该生信息...\n");
   }
   else {
      printf("已找到该生信息\n");
	  while(1){
         show_one_student(p);    /*显示该生个人信息*/
	     printf(" [ 0 ] 退出\n");
	     printf("请输入您的修改项(1-8)：");
		 scanf("%d",&choose);
		 if(choose==0)break;
		 else {
			 switch(choose){
			     case 1:printf("请输入该生姓名：");getchar();gets(p->name);break;
				 case 2:printf("请输入该生性别：");getchar();gets(p->sex);break;
				 case 3:printf("请输入该生专业名称：");getchar();gets(p->specialty);break;
				 case 4:printf("请输入班级信息：");getchar();gets(p->classes);break;
				 case 5:printf("请输入学生类型（本科生-0，研究生-1）：");scanf("%d",&category);p->category=(enum studentcategory)category;break;
				 case 6:case 7:case 8:printf("请输入正确的成绩信息：");
					 if(p->category==UNDERGRADUATE){
						 if(choose==6)scanf("%d",&p->math);
						 if(choose==7)scanf("%d",&p->english);
						 if(choose==8)scanf("%d",&p->clanguage);
						 if(p->math!=-1&&p->english!=-1&&p->clanguage!=-1)p->totalscore=p->math+p->english+p->clanguage;
					 }
					 else {
					     if(choose==6)scanf("%d",&p->comprehensive);
						 if(choose==7)scanf("%d",&p->thesis);
						 if(p->comprehensive!=-1&&p->thesis!=-1)p->totalscore=p->comprehensive+p->thesis;
					 }
			 }
		 }
		 system("cls");
	  }
	  printf("修改成功，请按任意键继续...\n");
	  getchar();
	  system("cls");   /*清屏*/
   }
}

void deleteStudent()  /*删除学生信息*/
{
    int id,result;
	printf("请输入需要删除学生信息的学生id:");
	scanf("%d",&id);
	result=deleteStudentById(&head,id);
	if(result==0){
	   printf("并无删除记录...\n");
	}
	else printf("删除成功,请按任意键继续...\n");
	getchar();
	getchar();
	system("cls");
}

void undergraduateScore()   /*批量输入本科学生成绩信息*/
{
	Student *p=head;
	int choose,flag=0;
    char specialty[80],classes[80];
	getchar();
	printf("请需要输入成绩信息的专业名称：");
	gets(specialty);
	printf("请输入班别信息：");
	gets(classes);
	printf("请输入所需要输入的成绩科目（高数-1，英语-2，C语言-3）：");
	scanf("%d",&choose);
	if(p==NULL){
	    printf("没有学生信息，请按任意键继续...\n");
		getchar();
		system("cls");
	}
	while(p!=NULL){
		if(strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&p->category==UNDERGRADUATE){
		   flag=1;
		   printf("学生学号：%d\n",p->id);
		   printf("学生姓名：%s\n",p->name);
		   if(choose==1){
		       printf("请输入该生的高数成绩：");
			   scanf("%d",&p->math);
		   }
		   else if(choose==2){
		   	   printf("请输入该生的英语成绩：");
			   scanf("%d",&p->english);
		   }
		   else if(choose==3){
		   	   printf("请输入该生的C语言成绩：");
			   scanf("%d",&p->clanguage);
		   }
		   else printf("输入有误，请按任意键继续...\n");
		}
		if(p->math!=-1&&p->english!=-1&&p->clanguage!=-1)
			p->totalscore=p->math+p->english+p->clanguage;
		p=p->next;
	}
	if(flag==0){
	       printf("并无该类学生信息，请按任意键继续...\n");
		   getchar();
		   system("cls");
	}
	else printf("输入成功，请按任意键继续...\n");
	getchar();
	getchar();
	system("cls");
}

void postgraduateScore()  /*批量输入研究生成绩信息*/
{
	Student *p=head;
	int choose,flag=0;
    char specialty[80],classes[80];
	getchar();
	printf("请需要输入成绩信息的专业名称：");
	gets(specialty);
	printf("请输入班别信息：");
	gets(classes);
	printf("请输入所需要输入的成绩科目（课程设计成绩-1，论文成绩-2）：");
	scanf("%d",&choose);
	if(p==NULL){
	    printf("没有学生信息，请按任意键继续...\n");
		getchar();
		system("cls");
	}
	while(p!=NULL){
		if(strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&p->category==POSTGRADUATE){
		   flag=1;
		   printf("学生学号：%d\n",p->id);
		   printf("学生姓名：%s\n",p->name);
		   if(choose==1){
		       printf("请输入该生的课程设计成绩：");
			   scanf("%d",&p->comprehensive);
		   }
		   else if(choose==2){
		   	   printf("请输入该生的论文成绩：");
			   scanf("%d",&p->thesis);
		   }
		   else printf("输入的科目信息有误，请按任意键继续...\n");
		}
		if(p->comprehensive!=-1&&p->thesis!=-1)
			p->totalscore=p->comprehensive+p->thesis;
		p=p->next;
	}
	if(flag==0){
	       printf("并无该类学生信息，请按任意键继续...\n");
		   getchar();
		   getchar();
		   system("cls");
	}
	else printf("输入成功，请按任意键继续...\n");
	getchar();
	getchar();
	system("cls");
}


