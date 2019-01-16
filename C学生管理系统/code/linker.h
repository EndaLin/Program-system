#pragma once

//枚举型学生类别：本科生、研究生
enum studentcategory { UNDERGRADUATE,POSTGRADUATE };

//学生类型
typedef struct node {
	int  id;						//学号
	char name[80];					//姓名
	char sex[80];					//性别：男或女
	char specialty[80];				//专业
	char classes[80];				//班级 
	enum studentcategory category;	//枚举型学生类别；本科生、研究生
	int  math;						//高数
	int  english;					//英语
	int  clanguage;					//C语言
	int  comprehensive;				//课程综合
	int  thesis;					//毕业论文
	int  totalscore;				//总成绩
	int  classrank;					//班级排名
	int  schoolrank;				//校级排名
	struct node * next;				
} Student;

//函数功能：添加一个结点（newStudent指向的结点）到链表末尾。
//参数说明：headp—二级指针（指向链表头指针的指针）, newStudent—新结点
void addNode(Student ** headp, Student * newStudent);

//函数功能：根据学号id，删除一个结点。
//参数说明：headp—二级指针（指向链表头指针的指针）, id—学号
//返回值：返回0，表示没有学号为id的学生；返回1，表示成功删除。
int deleteStudentById(Student ** headp, int id);

//函数功能：交换p、q所指的两个结点的值，但不交换p和q。
//参数说明：p—指向链表结点的指针,q—指向链表结点的指针
void exchangeData(Student * p, Student * q);