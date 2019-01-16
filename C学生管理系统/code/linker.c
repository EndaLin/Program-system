#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linker.h"
#include "studentshow.h"

#define N 4

extern int maxId;

//函数功能：添加一个结点（newStudent指向的结点）到链表末尾。
//参数说明：headp—二级指针（指向链表头指针的指针）, newStudent—新结点
void addNode(Student ** headp, Student * newStudent)
{
	Student *p = *headp;

	if(*headp == NULL) {//空链表
		*headp = newStudent;
	}else{//非空链表：先找到尾结点，再插入新结点
		p = *headp;
		//找到尾结点
		while(p->next != NULL) p = p->next;
		
		//插入新结点
		p->next = newStudent;
	}
}

//函数功能：根据学号id，删除一个结点。
//参数说明：headp—二级指针（指向链表头指针的指针）, id—学号
//返回值：返回0，表示没有学号为id的学生；返回1，表示成功删除。
int deleteStudentById(Student ** headp, int id)
{
	char ch;
	//注意：headp是指向链表头指针的指针，*headp就是链表的头指针
	if(*headp == NULL)//空链表
		return 0;
	else if((*headp)->id == id){
		show_one_student(*headp);
		printf("已经找到该生信息，是否删除（Y or N）:");
		scanf(" %c",&ch);
		if(ch=='Y'||ch=='y'){//被删除节点是头节点：直接删除
		Student * p = *headp;		//p指向头结点
		*headp = (*headp)->next;	//删除
		free(p);					//释放被删除结点（头结点）的空间
		return 1;
		}
		else return 0;
	}
	else{
		//被删除节点非头节点：先查找，再删除。
		//两个指针变量：p指向被删结点，q指向被删结点的前一个结点。
		//1.设置p、q的初值
		Student * q = *headp, *p = (*headp)->next;
		//2.查找被删结点
		while (p != NULL && p->id != id ){
			q = p;
			p = p->next;
		}
		//3.根据查找结果，做相应处理
		if(p == NULL)	//没有找到id值的员工
			return 0;	//返回0
		else{
			//找到被删除结点：删除p结点，返回1
			show_one_student(p);
			printf("已经找到该生信息，是否删除（Y or N）:");
			scanf(" %c",&ch);
			if(ch=='N'||ch=='n'){
			   return 0;
			}
			else {q->next = p->next;
			   free(p);
			   return 1;
			}
		}
	}
}

//函数功能：交换p、q所指的两个结点的值，但不交换p和q。
//参数说明：p—指向链表结点的指针,q—指向链表结点的指针
void exchangeData(Student * p, Student * q)
{
	Student temp,*pNext,*qNext;

	//记录交换之前结点的指针域
	pNext = p->next;
	qNext = q->next;

	//交换结点的数据域与指针域
	temp = *p;
	*p = *q;
	*q = temp;

	//恢复指针域（不改变链表结点顺序）
	p->next = pNext;
	q->next = qNext;
}