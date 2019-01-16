#include<iostream>
using namespace std;
const int MAXSIZE=30;
typedef char DataType;
typedef struct
{
	DataType queue[MAXSIZE];
	int front;
	int rear;
	int count;
}LQueue;

void QueueInitiate(LQueue *p)
{
    p->front=0;
	p->rear=0;
	p->count=0;
}

void QueueInset(LQueue *p,DataType x)
{
    if(p->count>0&&p->front==p->rear)
	{
	      cout<<"队列已满，无法插入"<<endl;
		  return;
	}
	p->queue[p->rear]=x;
	p->rear=(p->rear+1)%MAXSIZE;
	p->count++;
}

DataType QueueGet(LQueue *p)
{
    if(p->count==0)
	{
	     cout<<"队列为空，没有数据可取！"<<endl;
		 return 0;
	}
	DataType c=p->queue[p->front];
	p->front=(p->front+1)%MAXSIZE;
	p->count--;
	return c;
}

bool QueueNotEmpty(LQueue *p)
{
     if(p->count==0)
		 return false;
	 return true;
}

int main()
{
     LQueue *p=(LQueue *)malloc(sizeof(LQueue));
	 QueueInitiate(p);
	 DataType c;
	 cout<<"请输入10个字符："<<endl;
	 for(int i=0;i<10;i++)
	 {
	      cin>>c;
		  QueueInset(p,c);
	 }
	 cout<<"队首出列："<<QueueGet(p)<<endl;
	 cout<<"请输入4个字符："<<endl;
	 for(int i=0;i<4;i++)
	 {
	       cin>>c;
		   QueueInset(p,c);
	 }
	 cout<<"出队"<<endl;
	 while(QueueNotEmpty(p))
	 {
		 c=QueueGet(p);
		 cout<<c<<" ";
	 }
	 system("pause");
	 return 0;
}