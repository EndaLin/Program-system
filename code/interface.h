#pragma once
//#ifdef INTERFACE
//#define INTERFACE
#include<cstdio>
#include<algorithm>
#include<fstream>
#include<vector>
#include"Data.h"

class Interface
{
private:
	vector<undergraduate>stu1;    //本科生
	vector<graduate>stu2;         //研究生
	vector<Class>Cla;             //班级
	vector<major>maj;             //专业
	static int count1;    //记录本科生总人数
	static int count2;    //记录研究生总人数
	static int count3;    //记录班级的总数
	static int count4;    //记录专业的总数
public:
	Interface();          //打开文件并且读取文件数据
	void menu();          //主菜单函数
	void menu1();         //管理员菜单函数
	void menu2();         //老师管理菜单函数
	void menu3();
	void menu4();
	void menu5();
	void menu6();
	void menu7(int n);
	void menu8();
	void run();                //启动函数
	void save();               //关闭程序并保存数据
	void Administrator();      //专业/班级管理函数
	void Teacher();          //专业、班级人员管理函数
	void creatMajor();         //创建专业
	void Delete_Major();       //删除专业以及相关人员的信息
	void motify1();            //修改专业信息
	void creatClass();         //创建一个新的班级
	void Delete_Class();       //删除一个班级的信息
	void motify2();          //修改班级信息
	template<class T>void getPage(int page,T begin,T end);   //获取当前页数的所有信息
	template<class T>void Display(int n,int count,T begin,T end);       //显示所有专业、班级以及所有学生的相关信息
    void Input();    //增加本科生或者研究生的基本个人信息
	void InputScore();       //批量输入本科生或者研究生成绩
	void motify3();          //根据学号修改学生相关信息
	void motify4();          //根据姓名修改学生相关信息
	void Delete_student();   //根据学号删除学生信息
	void DisplayByClass();   //输出本班级的学生信息
	void DisplayByMajor();   //输出本专业的学生信息
	void DisplayByName();    //根据姓名输出学生信息
	void DisplayByID();      //根据学号查询个人信息
	void DisplayFailStudent();  //查询某班级、某科目不及格的名单
	static bool comparing1(undergraduate s1,undergraduate s2);  //比较二者总成绩大小
	static bool comparing2(graduate s1,graduate s2);  //比较二者总成绩大小
	static bool comparing3(undergraduate s1,undergraduate s2);  //比较二者学号
	static bool comparing4(graduate s1,graduate s2);  //比较学号
	void sortUndergraduate();   //排序全部本科生
	void sortGraduate();        //排序全部研究生
	void sortByClass_undergraduate();        //排序本科生班级
	void sortByClass_graduate();      //排序研究生班级
	void statistic1();                //统计某班级平均分、最高分和最低分
	void statistic2();                //统计某班级超过平均分的人数以及名单
	void statistic3();                //统计某班级某科目不及格的人数和名单
	void statistic4();                //统计某班级某科目不同等级的学生人数
	void motify5();                   //修改个人专业编号
	void motify6();                   //修改个人班级编号
};

//#endif

template<class T>     //类模板：获取当前页数
void Interface::getPage(int page,T begin,T end)
{
	  T p=begin;
      int count=0,page1,page2;
	  page1=(page-1)*10;
	  page2=(page)*10;
	  while(p!=end)
	  {
	       count++;
		   if(count>page1)
			   break;
		   p++;
	  }
	  while(p!=end&&count<=page2)
	  {
	       p->Display();
		   count++;
		   p++;
	  }
}

template<class T>     //类模板：显示所有学生的信息
void Interface::Display(int n,int count,T begin,T end)    //  n为显示类型
{
       int page=1,allpage;
	   int choose;
	   if(count<=10&&count>0)
	   {
	       allpage=1;
	   }
	   else if(count==0)
	   {
	       allpage=0;
		   cout<<"没有相关学生信息！请按任意键继续..."<<endl;
		   system("pause");
		   system("pause");
		   return;
	   }
	   else if(count%10)
	   {
	       allpage=count/10+1;
	   }
	   else
	   {
	       allpage=count/10;
	   }
	   do{
		if(page==1&&allpage==1){
		     printf("======================================================================\n");
			 menu7(n);
			 printf("----------------------------------------------------------------------\n");
			 getPage(page,begin,end);
			 printf("----------------------------------------------------------------------\n");
			 printf("             当前页为第%d页  总页数为%d页 【0】返回\n",page,allpage);
			 printf("======================================================================\n");
			 do{
			   printf("请选择>>");
			   scanf("%d",&choose);
			   if(choose!=0)
				   printf("输入有误，请重新选择...\n");
			   else break;
			 }while(1);
		}
		else if(page==1&&allpage>1){
			 printf("=============================================================================\n");
			 menu7(n);
			 getPage(page,begin,end);
			 printf("-----------------------------------------------------------------------------\n");
			 printf("  当前页为第%d页  总页数为%d页 【2】下一页 【4】尾页 【0】退出\n",page,allpage);
			 printf("==============================================================================\n");
			 do{
			   printf("请选择>>");
			   scanf("%d",&choose);
			   if(choose!=0&&choose!=2&&choose!=4)
				   printf("输入有误，请重新选择...\n");
			   else break;
			 }while(1);
		}
		else if(page>1&&page!=allpage){
		     printf("================================================================================================\n");
			 menu7(n);
			 getPage(page,begin,end);
			 printf("------------------------------------------------------------------------------------------------\n");
			 printf("  当前页为第%d页  总页数为%d页 【1】上一页 【2】下一页 【3】首页 【4】尾页 【0】退出\n",page,allpage);
			 printf("================================================================================================\n");
			 do{
			   printf("请选择>>");
			   scanf("%d",&choose);
			   if(choose!=0&&choose!=2&&choose!=4&&choose!=1&&choose!=3)
				   printf("输入有误，请重新选择...\n");
			   else break;
			 }while(1);
		}
		else if(page==allpage){
			 printf("=============================================================================\n");
			 menu7(n);
			 getPage(page,begin,end);
			 printf("-----------------------------------------------------------------------------\n");
			 printf("  当前页为第%d页  总页数为%d页 【1】上一页 【3】首页【0】退出\n",page,allpage);
			 printf("=============================================================================\n");
			 do{
			   printf("请选择>>");
			   scanf("%d",&choose);
			   if(choose!=0&&choose!=1&&choose!=3)
				   printf("输入有误，请重新选择...\n");
			   else break;
			 }while(1);
		}
		  if(choose==1)
			  page--;
		  if (choose==2)
			 page++;
		  if(choose==3)
			  page=1;
		  if(choose==4)
			  page=allpage;
		  if(choose==0)break;
		      system("cls");
	    }while(1);
	    cout<<"查询结束，请按任意键结束..."<<endl;
		system("pause");
		system("cls");
}



