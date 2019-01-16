#include<stdio.h>
#include"linker.h"

extern Student *head;

void sortAllById()   /*根据id前后进行排序*/
{
    Student *p1=NULL,*p2=NULL,*min=NULL;
	p1=head;
	p2=head;
	while(p2!=NULL){    /*使用选择排序法进行链表排序*/
		min=p2;
		p1=p2;
		while(p1!=NULL){
			if(p1->id<min->id)min=p1;
			p1=p1->next;
		}
		exchangeData(p2,min);
		p2=p2->next;
	}
}