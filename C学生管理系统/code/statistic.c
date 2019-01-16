#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linker.h"
#include"searchMenu.h"

extern Student *head;

void statistic1()
{
    Student *p=head;
	int max=0,min=200,category1,subject,count=0,sum=0;
	double average;
	char specialty[80],classes[80];
	enum studentcategory category;

	do{
		printf("请输入学生类型(本科生-0，研究生-1)：");
	    scanf("%d",&category1);
		if(category1!=1&&category1!=0)
			printf("输入有误，请重新输入");
		else break;
	}while(1);
	category=(enum studentcategory)category1;
	printf("请输入专业名称：");
	scanf("%s",specialty);
	printf("请输入班级信息：");
	scanf("%s",classes);
	if(category==UNDERGRADUATE){
		do{
			printf("请选择查询科目（高数-1，英语-2，C语言-3）：");
		    scanf("%d",&subject);
			if(subject!=1&&subject!=2&&subject!=3)
				printf("输入有误，请重新输入...\n");
			else break;
		}while(1);
	}
	else {
		do{
			printf("请选择查询科目（课程设计-4，论文成绩-5）：");
		    scanf("%d",&subject);
			if(subject!=4&&subject!=5)
				printf("输入有误，请重新输入...\n");
			else break;
		}while(1);
	}

	while(p!=NULL){
	      if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0)
			  break;
		  p=p->next;
	}
	if(p==NULL){
	    printf("没有找到该类学生的基本信息，请按任意键继续...\n");
		getchar();
		system("cls");
		return;
	}
	else {
		while(p!=NULL){
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==1&&p->math!=-1){
				 if(p->math>max)
					 max=p->math;
				 if(p->math<min)
					 min=p->math;
			     count++;
				 sum+=p->math;
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==2&&p->english!=-1){
				 if(p->english>max)
					 max=p->english;
				 if(p->english<min)
					 min=p->english;
			     count++;
				 sum+=p->english;
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==3&&p->clanguage!=-1){
				 if(p->clanguage>max)
					 max=p->clanguage;
				 if(p->clanguage<min)
					 min=p->clanguage;
			     count++;
				 sum+=p->clanguage;
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==4&&p->comprehensive!=-1){
				if(p->comprehensive>max)
					 max=p->comprehensive;
				 if(p->comprehensive<min)
					 min=p->comprehensive;
			     count++;
				 sum+=p->comprehensive;
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==5&&p->thesis!=-1){
				if(p->thesis>max)
					 max=p->thesis;
				 if(p->thesis<min)
					 min=p->thesis;
			     count++;
				 sum+=p->thesis;
			}
			p=p->next;
		}
	}
	average=sum/count*1.0;
	printf("查询成功！\n");
	printf("该班级本门科目的平均分为%.3lf,最高分为%d,最低分为%d\n",average,max,min);
	printf("请按任意键继续...\n");
	getchar();
	getchar();
	system("cls");
}

void statistic2()
{
	Student *p=head,*p1=NULL;
	int category1,subject,count=0,sum=0,count1=0;
	double average;
	char specialty[80],classes[80];
	enum studentcategory category;

	do{
		printf("请输入学生类型(本科生-0，研究生-1)：");
	    scanf("%d",&category1);
		if(category1!=1&&category1!=0)
			printf("输入有误，请重新输入");
		else break;
	}while(1);
	category=(enum studentcategory)category1;
	printf("请输入专业名称：");
	scanf("%s",specialty);
	printf("请输入班级信息：");
	scanf("%s",classes);
	if(category==UNDERGRADUATE){
		do{
			printf("请选择查询科目（高数-1，英语-2，C语言-3）：");
		    scanf("%d",&subject);
			if(subject!=1&&subject!=2&&subject!=3)
				printf("输入有误，请重新输入...\n");
			else break;
		}while(1);
	}
	else {
		do{
			printf("请选择查询科目（课程设计-4，论文成绩-5）：");
		    scanf("%d",&subject);
			if(subject!=4&&subject!=5)
				printf("输入有误，请重新输入...\n");
			else break;
		}while(1);
	}

	while(p!=NULL){
	      if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0)
			  break;
		  p=p->next;
	}
	if(p==NULL){
	    printf("没有找到该类学生的基本信息，请按任意键继续...\n");
		getchar();
		system("cls");
		return;
	}
	else {
		p1=p;
		while(p!=NULL){
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==1&&p->math!=-1){
			     count++;
				 sum+=p->math;
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==2&&p->english!=-1){
			     count++;
				 sum+=p->english;
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==3&&p->clanguage!=-1){
			     count++;
				 sum+=p->clanguage;
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==4&&p->comprehensive!=-1){
			     count++;
				 sum+=p->comprehensive;
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==5&&p->thesis!=-1){
			     count++;
				 sum+=p->thesis;
			}
			p=p->next;
		}
	}
		average=sum/count*1.0;
		if(category==UNDERGRADUATE)
	         printf("学号  姓名  性别     专业     班级  学生类型  高数成绩  英语成绩  C语言成绩  总成绩  班级排名  校级排名\n");
        else printf("学号  姓名  性别     专业     班级  学生类型  课程设计成绩  论文成绩  总成绩  班级排名  校级排名\n");
		p=p1;
		while(p!=NULL){
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==1&&p->math!=-1){
				if(p->math>=average){
				     count1++;
					 printf("%2d%8s%5s%13s%4s     本科生  %6d%10d%10d%10d%10d%10d\n",p->id,p->name,p->sex,p->specialty,p->classes,p->math,p->english,p->clanguage,p->totalscore,p->classrank,p->schoolrank);
				}
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==2&&p->english!=-1){
				if(p->english>=average){
				     count1++;
					 printf("%2d%8s%5s%13s%4s     本科生  %6d%10d%10d%10d%10d%10d\n",p->id,p->name,p->sex,p->specialty,p->classes,p->math,p->english,p->clanguage,p->totalscore,p->classrank,p->schoolrank);
				}
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==3&&p->clanguage!=-1){
				if(p->clanguage>=average){
				     count1++;
					 printf("%2d%8s%5s%13s%4s     本科生  %6d%10d%10d%10d%10d%10d\n",p->id,p->name,p->sex,p->specialty,p->classes,p->math,p->english,p->clanguage,p->totalscore,p->classrank,p->schoolrank);
				}
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==4&&p->comprehensive!=-1){
				if(p->comprehensive>=average){
				     count1++;
					 printf("%2d%8s%5s%13s%4s     研究生  %8d%12d%10d%10d%10d\n",p->id,p->name,p->sex,p->specialty,p->classes,p->comprehensive,p->thesis,p->totalscore,p->classrank,p->schoolrank);
				}
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==5&&p->thesis!=-1){
				if(p->thesis>=average){
				     count1++;
					 printf("%2d%8s%5s%13s%4s     研究生  %8d%12d%10d%10d%10d\n",p->id,p->name,p->sex,p->specialty,p->classes,p->comprehensive,p->thesis,p->totalscore,p->classrank,p->schoolrank);
				}
			}
			p=p->next;
		}
	printf("查询成功！\n");
	printf("该班级本门科目的平均分为%.3lf\n",average);
	printf("超过平均成绩的人数总共为%d个\n",count1);
	printf("请按任意键继续...\n");
	getchar();
	getchar();
	system("cls");
}

void statistic3()
{
	 int course;
	 char specialty[80],classes[80];
	 do{
		printf("输入提示：班级不能为空!\n");
		printf("课程：1—高数，2—英语，3—C语言，4—课程综合，5—论文\n");
		printf("请输入所需要查询的课程：");
		scanf("%d",&course);
		printf("请输入专业名称：");
		scanf("%s",specialty);
		printf("请输入要查询的班级：");
		scanf("%s",classes);
		if(strlen(classes)<=0)
					printf("班级不能为空！\n");
		else if(course<1 &&course>5)
				printf("课程编号只能1-5！\n");
		else break;
		}while(1);
						
		//2.函数调用：查询某班级、某课程不及格学生
		showFailByClassCourse(specialty,classes,course);
}

void statistic4()
{
	Student *p=head;
	int category1,subject,count=0,sum=0,num[5],i;
	char specialty[80],classes[80];
	enum studentcategory category;

	do{
		printf("请输入学生类型(本科生-0，研究生-1)：");
	    scanf("%d",&category1);
		if(category1!=1&&category1!=0)
			printf("输入有误，请重新输入");
		else break;
	}while(1);
	category=(enum studentcategory)category1;
	printf("请输入专业名称：");
	scanf("%s",specialty);
	printf("请输入班级信息：");
	scanf("%s",classes);
	if(category==UNDERGRADUATE){
		do{
			printf("请选择查询科目（高数-1，英语-2，C语言-3）：");
		    scanf("%d",&subject);
			if(subject!=1&&subject!=2&&subject!=3)
				printf("输入有误，请重新输入...\n");
			else break;
		}while(1);
	}
	else {
		do{
			printf("请选择查询科目（课程设计-4，论文成绩-5）：");
		    scanf("%d",&subject);
			if(subject!=4&&subject!=5)
				printf("输入有误，请重新输入...\n");
			else break;
		}while(1);
	}

	for(i=0;i<5;i++)num[i]=0;

	while(p!=NULL){
	      if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0)
			  break;
		  p=p->next;
	}
	if(p==NULL){
	    printf("没有找到该类学生的基本信息，请按任意键继续...\n");
		getchar();
		system("cls");
		return;
	}
	else {
		while(p!=NULL){
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==1&&p->math!=-1){
				   num[p->math/10-5]++;
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==2&&p->english!=-1){
				   num[p->math/10-5]++;
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==3&&p->clanguage!=-1){
				   num[p->math/10-5]++;
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==4&&p->comprehensive!=-1){
				   num[p->math/10-5]++;
			}
			if(p->category==category&&strcmp(p->specialty,specialty)==0&&strcmp(p->classes,classes)==0&&subject==5&&p->thesis!=-1){
				   num[p->math/10-5]++;
			}
			p=p->next;
		}
	}
	printf("查询成功！\n");
	printf(">>等级为A的人数为%d位\n",num[4]);
	printf(">>等级为B的人数为%d位\n",num[3]);
	printf(">>等级为C的人数为%d位\n",num[2]);
	printf(">>等级为D的人数为%d位\n",num[1]);
	printf(">>等级为E的人数为%d位\n",num[0]);
	printf("请按任意键继续...\n");
	getchar();
	getchar();
	system("cls");
}