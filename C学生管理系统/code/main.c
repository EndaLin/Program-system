#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linker.h"			//链表操作：函数原型声明
#include "fileOperate.h"	//文件操作：函数原型声明
#include "tools.h"			//辅助工具：函数原型声明
#include "studentManage.h"	//学生管理：函数原型声明
#include "sortAllyById.h"   //链表排序
#include "studentshow.h"    //显示功能
#include "searchMenu.h"	//查询管理：函数原型声明
#include "sort.h"			//排序管理：函数原型声明
#include "statistic.h"		//统计管理：函数原型声明   

int maxId=0;									//当前最大学生学号
int change = 1, peopleNumber;					//修改标志、学生总人数
int minTotalscore,maxTotalscore,avgTotalscore;	//最低总分、最高总分、平均总分
const char fileFullPath[40] = "student.dat";	//学生数据文件
Student * head = NULL;							//学生链表头指针

//二级菜单： 
//1.学生管理（增删改）菜单
void StudentManagerMenu();
//2.查询管理菜单
void searchMenu();
//3.排序管理菜单
void sortMenu();
//4.统计管理菜单
void statisticMenu();

void main(void)
{
	int menuItem;
	FILE *fp;

	if((fp = fopen(fileFullPath, "rb")) == NULL){  //建立文件,测试程序所用
		printf("无法打开数据文件! \n");
		exit(0);
	}
	fclose(fp);
	if (readFromFile()==-1){	//函数调用：从文件中读取数据到链表
		return;
	}	

	//主菜单：一级菜单
	while(1)
	{
		do
		{
			fflush(stdin);//清空键盘缓冲区
			printf("\n                 主菜单\n");
			printf("===========================================\n");
			printf("|   1—学生管理             2—查询管理   |\n");
			printf("|   3—排序管理             4—统计管理   |\n");
			printf("|                 5—退出                 |\n");
			printf("===========================================\n");
			printf("          请输入菜单编号（1-5）：");
			scanf("%d",&menuItem);
			if(menuItem<1||menuItem>5)printf("菜单编号输入错误，请输入菜单编号（1-5）：\n\n");
			else break;
		}while(1);

		switch(menuItem){
		    case 1: StudentManagerMenu();    /*学生管理菜单*/
					break;
			case 2: searchMenu();
					break; 
			case 3: sortMenu();
					break;
			case 4: statisticMenu();
					break;   
			case 5: sortAllById();		//函数调用：将链表按学号id从小到大排序
					saveToFile();		//函数调用：将链表存入文件    
			default:break;
		}
		if(menuItem==5){
		    printf("========================================\n");
			printf("   您已退出学生管理系统，欢迎再次使用！ \n");
			printf("========================================\n");
			break;
		}
	}
}

//二级菜单：1.学生管理（增删改）菜单
void StudentManagerMenu()
{
	int menuItem;
	enum studentcategory category;	

	while(1)
	{
		do
		{
			fflush(stdin);//清空键盘缓冲区
			printf("\n             二级菜单—学生管理\n");
			printf("============================================\n");
			printf("|   1—添加学生基本信息                    |\n");
			printf("|   2—根据学号修改学生基本信息            |\n");
			printf("|   3—根据学号修改学生成绩信息            |\n");
			printf("|   4—根据学号删除学生                    |\n");
			printf("|   5—批量输入本科生成绩并计算总成绩      |\n");
			printf("|   6—批量输入研究生成绩并计算总成绩      |\n");
			printf("|   7—本科生成绩排名                      |\n");
			printf("|   8—研究生成绩排名                      |\n");
			printf("|   9—退回上级菜单                        |\n");
			printf("============================================\n");
			printf("          请输入菜单编号（1-9）：");
			scanf("%d", &menuItem);
			if(menuItem<1||menuItem>9)printf("菜单编号输入错误，请输入菜单编号（1-9）!\n\n");
			else break;
		}while(1);

		switch(menuItem){
			case 1: addStudent(); break;     /*添加学生信息*/
			case 2:case 3: modifyStudent(); break;  /*修改学生信息*/
			case 4: deleteStudent();  break;        /*删除学生信息*/
			case 5: undergraduateScore(); break;    /*批量输入本科生成绩*/
			case 6: postgraduateScore(); break;     /*批量输入研究生成绩*/
			case 7:
			case 8:
					if(menuItem==7) category=UNDERGRADUATE;    /*对本科生或者研究生进行校级排名*/
					else category=POSTGRADUATE;
					sortAllByCategory(category);//排序
		            sortAllById();    //复原链表
					break;    
			case 9: system("cls");return;
		}
	}
}

//二级菜单：2.查询管理菜单
void searchMenu()
{
	int menuItem;
	char classes[80],specialty[80],category1;
	int id;
	char name[80];
	int course;			//课程：1—高数，2—英语，3—C语言，4—课程综合，5—论文
	enum studentcategory category,category2;	

	while(1) 
	{
		do
		{
			fflush(stdin);//清空键盘缓冲区
			printf("\n             二级菜单—查询管理\n");
			printf("======================================================\n");
			printf("|  1—查询全部本科生     2—查询全部研究生           |\n");
			printf("|  3—按班级查询         4—按学号查询               |\n");
			printf("|  5—按姓名查询         6—查询某班级、某课程不及格 |\n");
			printf("|  7—退回上级菜单                                   |\n");
			printf("======================================================\n");
			printf("          请输入菜单编号（1-7）：");
			scanf("%d", &menuItem);
			if(menuItem<1||menuItem>7)printf("菜单编号输入错误，请输入菜单编号（1-7）!\n\n");
			else break;
		}while(1);
		
		switch(menuItem){
			case 1:
			case 2:
					if(menuItem==1) category=UNDERGRADUATE;
					else category=POSTGRADUATE;
					//调用函数：显示
					showAllByCategory(category);//显示
					break;
			case 3: //1.输入待查询的班级
					do{
						fflush(stdin);//清空键盘缓冲区
						printf("输入提示：班级、专业，学生类型不能为空!\n");
						printf("请输入学生类型（本科生-0，研究生-1）：");
						scanf("%d",&category1);
						if(category1==0||category==1)
							category2=(enum studentcategory)category1;
						getchar();
						printf("请输入专业名称：");
						scanf("%s",specialty);
						printf("请输入要查询的班级：");
						scanf("%s",classes);
						if(strlen(classes)<=0)printf("班级不能为空！\n");
						else if(strlen(specialty)<=0)printf("专业名称不能为空!\n");
						else if(category1!=0&&category!=1)printf("学生类型输入有误！\n");
						else break;
					}while(1);
					//2.函数调用：按班级查询
					showByClass(category2,specialty,classes); 
					break;
			case 4: //1.输入待查询的学号id
					do{
						fflush(stdin);//清空键盘缓冲区
						printf("输入提示：学号不能为负!\n");
						printf("请输入要查询的学号：");
						scanf("%d",&id);
						if(id<=0)printf("学号id不能为负数！\n");
						else break;
					}while(1);

					//2.函数调用：按学号id查询
					showById(id);
					break;
			case 5: //1.输入待查询的姓名
					do{
						fflush(stdin);//清空键盘缓冲区
						printf("输入提示：姓名不能为空!\n");
						printf("请输入要查询的姓名：");
						scanf("%s",name);
						if(strlen(name)<=0)printf("姓名不能为空！\n");
						else break;
					}while(1);

					//2.函数调用：按姓名name查询
					showByName(name); 
					break;
			case 6: //1.输入待查询的班级和课程
					do{
						fflush(stdin);//清空键盘缓冲区
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
					break;  
			case 7: system("cls");return;     
		}
	}
}

//二级菜单：3.排序管理菜单
void sortMenu()
{
	int menuItem,category1;
	char classes[80],specialty[80];
	enum studentcategory category;

	while(1) 
	{
		do
		{
			fflush(stdin);//清空键盘缓冲区
			printf("\n             二级菜单—排序管理\n");
			printf("            （按总成绩从高到低）\n");
			printf("==============================================\n");
			printf("|  1—排序全部本科生      2—排序全部研究生  |\n");
			printf("|  3—排序某班级学生      4—退回上级菜单    |\n");
			printf("==============================================\n");
			printf("          请输入菜单编号（1-4）：");
			scanf("%d", &menuItem);
			if(menuItem<1||menuItem>4)printf("菜单编号输入错误，请输入菜单编号（1-4）!\n\n");
			else break;
		}while(1);

		switch(menuItem){
			case 1:
			case 2:
					if(menuItem==1) category=UNDERGRADUATE;
					else category=POSTGRADUATE;
					//调用函数：排序、显示
					sortAllByCategory(category);//排序
					showAllByCategory(category);//显示
					sortAllById();  //复原链表
					break;
			case 3:
					//1.输入待排序的班级
					do{
						fflush(stdin);//清空键盘缓冲区
						printf("输入提示：班级、专业和学生类型不能为空!\n");
						printf("请输入专业名称：");
						scanf("%s",specialty);
						printf("请输入要排序的班级：");
						scanf("%s",classes);
						printf("请输入学生类型(本科生-0，研究生-1)：");
						scanf("%d",&category1);
						if(category1==1||category1==0)
							category=(enum studentcategory)category1;
						if(strlen(classes)<=0)printf("班级不能为空！\n");
						else if(category1!=1&&category1!=0)printf("学生类型输入错误\n");
						else break;
					}while(1);

					//2.调用函数：排序、显示
 					sortAllByClass(category,specialty,classes);//排序
					showByClass(category,specialty,classes);	//显示
					sortAllById();    //复原链表
					break;
			case 4:	system("cls");return;   
		}
	}
}

//二级菜单：4.统计管理菜单
void statisticMenu()
{
	int menuItem;

	while(1) 
	{
		do
		{
			fflush(stdin);//清空键盘缓冲区
			printf("\n                二级菜单—统计管理\n");
			printf("=========================================================\n");
			printf("|  1—统计某班级某课程的平均成绩、最高成绩、最低成绩    |\n");
			printf("|  2—统计某班级某课程超过课程平均成绩的学生名单及人数  |\n");
			printf("|  3—统计某班级某课程不及格的学生名单及人数            |\n");
			printf("|  4—统计某班级某课程不同等级的学生人数                |\n");
			printf("|  5—退回上级菜单                                      |\n");
			printf("=========================================================\n");
			printf("             请输入菜单编号（1-4）：");
			scanf("%d", &menuItem);
			if(menuItem<1||menuItem>5)printf("菜单编号输入错误，请输入菜单编号（1-5）!\n\n");
			else break;
		}while(1);

		switch(menuItem){
			case 1:statistic1(); break;
			case 2:statistic2(); break;
			case 3:statistic3(); break;
			case 4:statistic4(); break;  
			case 5:system("cls");return;  
		}
	}
}