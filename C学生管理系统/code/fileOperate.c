#include <stdio.h>
#include <stdlib.h>
#include "linker.h"

extern const char fileFullPath[40];
extern Student* head;
extern int maxId;

//函数功能：从文件中读取学生数据到链表
int readFromFile()
{
	FILE *fp;
	int nodeNumber = 0;

	if((fp = fopen(fileFullPath, "rb")) == NULL){//读方式打开二进制文件，允许读数据，文件必须存在。
		printf("无法打开数据文件! \n");
		return -1;
	}
	
	printf("正在从文件中读取学生数据到链表，请稍候...... \n");
	do{
		Student * newStudent = (Student *)malloc(sizeof(Student));		
		if(fread(newStudent, sizeof(Student), 1, fp) == 1) {//读取数据成功！
			newStudent->next = NULL;	//新结点作为尾结点插入
			if(maxId < newStudent->id) maxId = newStudent->id;

			//将新结点添加到链表尾部
			addNode(&head, newStudent);//注意：多次调用addNode方式—代码效率高，运行效率低（每次要从前往后遍历整个链表，大家可以自己写效率更高的代码：指针总是指向链表尾结点，从文件中读一个结点，就插入链表尾。）
			nodeNumber++;		       //读取结点数加1
		}else{
			if(feof(fp)){//读取数据完毕
				fclose(fp);
				printf("读取结束，共读取了%d名学生数据! \n", nodeNumber);
				system("pause");
				system("cls");
				return 1;
			}
		}
	}while(1);
	fclose(fp);
}

//函数功能：将学生链表结点数据写入到文件，便于数据长久保存
void saveToFile() 
{
	FILE *fp;
	int nodeNumber = 0;
	Student *p = head;

	if((fp = fopen(fileFullPath, "wb+")) == NULL){//w+ 打开可读写文件，若文件存在则文件长度清为零，即该文件内容会消失。若文件不存在则建立该文件。
		printf("无法打开数据文件! \n");
		return ;
	}

	printf("正在将链表中的数据保存到文件，请稍候...... \n");
	while(p!=NULL){
		if(fwrite(p, sizeof(Student), 1, fp) == 1)
			nodeNumber++;
		else
			printf("学号为：%d，姓名为：%s 的学生数据保存文件失败 \n",p->id,p->name);		
		p = p->next;
	}

	fclose(fp);
	printf("保存结束，共保存了%d名学生数据! \n", nodeNumber);
}