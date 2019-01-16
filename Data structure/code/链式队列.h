#include<stdio.h>
#include<malloc.h>
typedef int DataType;
typedef struct node
{
     DataType data;
	 node *next;
}LQnode;

typedef struct
{
	 LQnode *front;
	 LQnode *rear;
}LQueue;

void QueueInitiate(LQueue *p)
{
     p->front=NULL;
	 p->rear=NULL;
}

void QueueAppend(LQueue *p,DataType x)
{
     LQnode *q=(LQnode *)malloc(sizeof(LQnode));
	 q->data=x;
	 q->next=NULL;
	 if(p->rear!=NULL)
		 p->rear->next=q;
	 p->rear=q;
	 if(p->front==NULL)
		 p->front=q;
}

bool QueueDelete(LQueue *p,DataType *x)
{
	 if(p->front==NULL)
	 {
	       printf("队列为空！\n");
		   return false;
	 }
	 LQnode *temp;
	 temp=p->front;
     *x=p->front->data;
	 p->front=p->front->next;
	 free(temp);
	 if(p->front==NULL)
		 p->rear=NULL;
	 return true;
}

bool QueueGet(LQueue *p,DataType *x)
{
     if(p->front==NULL)
	 {
	     printf("队列中没有数据，无法进行取出操作！\n");
		 return false;
	 }
	 *x=p->front->data;
	 return true;
}

bool QueueNotEmpty(LQueue *p)
{
      if(p->front==NULL)
		  return false;
	  return true;
}

void QueueDestroy(LQueue *p)
{
	  LQnode *temp;
      while(p->front!=NULL)
	  {
	         temp=p->front;
			 p->front=p->front->next;
			 free(temp);
	  }
}



