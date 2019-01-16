#include<stdio.h>
#include<malloc.h>
const int MaxQueueSize=6;
typedef int DataType;

typedef struct
{
     DataType queue[MaxQueueSize];
	 int real;      //队尾
	 int front;     //队首
	 int count;     //总个数
}SeqQueue;

void QueueInitiate(SeqQueue *p)
{
      p->real=0;
	  p->front=0;
	  p->count=0;
}

void QueueAppend(SeqQueue *p,DataType x)
{
      if(p->count>=MaxQueueSize)
	  {
	        printf("队列已满，无法进行插入！");
			return;
	  }
	  p->queue[p->real]=x;
	  p->real=(p->real+1)%MaxQueueSize;
	  p->count++;
}

bool QueueDelete(SeqQueue *p,DataType *x)
{
      if(p->count<=0)
	  {
	         printf("队列为空，无法进行删除操作！");
			 return false;
	  }
	  *x=p->queue[p->front];
	  p->front=(p->front+1)%MaxQueueSize;
	  p->count--;
}
bool QueueGet(SeqQueue *p,DataType *x)
{
      if(p->count<=0)
	  {
	        printf("队列为空，无法进行取出操作！");
			return false;
	  }
	  *x=p->queue[p->front];
}

bool QueueNotEmpty(SeqQueue *p)
{
      if(p->count)
		  return true;
	  else
		  return false;
}

