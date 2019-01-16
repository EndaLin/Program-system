#include<iostream>
#include<malloc.h>
#include<math.h>
using namespace std;
typedef struct node
{
      int x;  //系数
	  int n;  //指数
	  int symbol;   //将每条多项式视为一个整体，若该整体为减数时，symbio为1，否则为被减数时为-1;
	  node *next;
}LNode;

void ListInitiate(LNode **head)             //链表初始化
{
      (*head)=(LNode *)malloc(sizeof(LNode));
	  (*head)->next=NULL;
	  (*head)->symbol=1;
}

void ListInset(LNode *head,int x,int n)     //插入新数据,插入时排序，x为新节点的系数，n为新节点的指数
{
      LNode *temp=(LNode *)malloc(sizeof(LNode)),*p=head,*q=NULL;
	  temp->x=x;
	  temp->n=n;
	  temp->symbol=1;
	  while(p->next!=NULL&&p->n<n)     //选择合适位置，插入新节点
	  {
		     q=p;
	         p=p->next;
	  }
	  if(p->next==NULL&&p->n<n)      //找到合适位置后，进行插入操作
	  {
	         p->next=temp;
			 temp->next=NULL;
	  }
	  else
	  {
	         q->next=temp;
			 temp->next=p;
	  }
}

LNode *ListApp(LNode *head1,LNode *head2)    //两条链表相加
{
      LNode *head,*p=head1->next,*q=head2->next,*temp,*s;
	  ListInitiate(&head);
	  s=head;
	  while(p!=NULL&&q!=NULL)     //此处先将链表进行合并排序操作，为了方便后面的相减操作能够同时进行，所以此处会建立一条新链表来储存合并后的多项式
	  {
	          if(p->n<=q->n)      //此处的排序的时间复杂度为O（n）;
			  {
			       temp=(LNode *)malloc(sizeof(LNode));
				   temp->x=p->x;
				   temp->n=p->n;
				   temp->symbol=1;
				   p=p->next;
			  }
			  else
			  {
			       temp=(LNode *)malloc(sizeof(LNode));
				   temp->x=q->x;
				   temp->n=q->n;
				   temp->symbol=1;
				   q=q->next;
			  }
			  s->next=temp;
			  temp->next=NULL;
			  s=temp;
	  }
	  while(p!=NULL)       //此处将排序后剩下的还没有排序的一部分链表直接连接上新链表里
	  {
		  temp=(LNode *)malloc(sizeof(LNode));
		  temp->x=p->x;
		  temp->n=p->n;
		  temp->symbol=p->symbol;
		  temp->next=NULL;
		  s->next=temp;
		  s=temp;
		  p=p->next;
	  }
	  while(q!=NULL)
	  {
		  temp=(LNode *)malloc(sizeof(LNode));
		  temp->x=q->x;
		  temp->n=q->n;
		  temp->symbol=q->symbol;
		  temp->next=NULL;
		  s->next=temp;
		  s=temp;
		  q=q->next;
	  }
	  s=head->next;
	  if(s==NULL)
		  return head;
	  while(s->next!=NULL)   //排序结束后，指数相同的相加
	  {
	        if(s->n==s->next->n)     //指数相同的进行相加操作，并把二者之和赋值到前一个节点处，后一个节点则删除
			{
			       s->x*=s->symbol;
				   s->next->x*=s->next->symbol;
				   s->x+=s->next->x;
				   LNode *temp=s->next;
				   s->next=s->next->next;
				   free(temp);
			}
			else 
			{
				   s->x*=s->symbol;
				   s=s->next;
			}
			if(s==NULL)
				break;
	  }
	  return head;     //放回新链表的头指针
}

LNode *ListSubstract(LNode *head1,LNode *head2)    //两天链表相减
{
      LNode *head,*p=head1->next,*q=head2->next,*temp,*s;
	  ListInitiate(&head);
	  s=head;
	  q->symbol=-1;
	  while(p!=NULL&&q!=NULL)
	  {
	          if(p->n<=q->n)
			  {
			       temp=(LNode *)malloc(sizeof(LNode));
				   temp->x=p->x;
				   temp->n=p->n;
				   temp->symbol=1;
				   p=p->next;
			  }
			  else
			  {
			       temp=(LNode *)malloc(sizeof(LNode));
				   temp->x=q->x*-1;
				   temp->n=q->n;
				   temp->symbol=-1;
				   q=q->next;
			  }
			  s->next=temp;
			  temp->next=NULL;
			  s=temp;
	  }
	  while(p!=NULL)
	  {
		  temp=(LNode *)malloc(sizeof(LNode));
		  temp->x=p->x;
		  temp->n=p->n;
		  temp->symbol=1;
		  temp->next=NULL;
		  s->next=temp;
		  s=temp;
		  p=p->next;
	  }
	  while(q!=NULL)
	  {
		  temp=(LNode *)malloc(sizeof(LNode));
		  temp->x=q->x*-1;
		  temp->n=q->n;
		  temp->symbol=-1;
		  temp->next=NULL;
		  s->next=temp;
		  s=temp;
		  q=q->next;
	  }
	  //相减操作
	  s=head->next;
	  if(s==NULL)
		  return head;
	  while(s->next!=NULL)   //指数相同的相减
	  {
	        if(s->n==s->next->n)
			{
				   s->x+=s->next->x;
				   LNode *temp=s->next;
				   s->next=s->next->next;
				   free(temp);
			}
			else
			{
			       s=s->next;
			}
			if(s==NULL)
				break;
	  }
	  return head;       
}

void ListOutput(LNode *head)    //输出
{
     LNode *p=head->next;
	 while(p->x==0)    //检测第一个系数不为0的节点位置
		 p=p->next;
	 if(p->n!=0)       //输出多项式的第一项
		 cout<<p->x<<"X^"<<p->n;
	 else 
		 cout<<p->x;
	 p=p->next;
	 while(p!=NULL)
	 {
		 if(p->x==0)    //如果多项式系数为0，则不输出
		 {
		       p=p->next;
			   continue;
		 }
		 if(p->x>0)    //判断多项式的符号
			 cout<<"+";
		 else if(p->x<0) 
			 cout<<"-";
		 if(p->n!=0)  
			 cout<<abs(p->x)<<"X"<<"^"<<p->n;
		 else
			 cout<<abs(p->x);
		 p=p->next;
	 }
}

void ListDestroy(LNode *head)
{
     LNode *p=head;
	 while(head!=NULL)
	 {
	      head=head->next;
		  free(p);
		  p=head;
	 }
}

int main()
{
	int x=1,n;
    LNode *head1,*head2,*head3=NULL,*head4=NULL;
	ListInitiate(&head1);
	ListInitiate(&head2);
	cout<<"请分别输入两条一元多项式每一项的系数和指数，系数输入0时退出"<<endl;
	cout<<"请输入第一条一元多项式："<<endl;
    while(x!=0)
   {
	    cin>>x;
		if(x==0)
			break;
		cin>>n;
		ListInset(head1,x,n);
   }
	cout<<"请输入第二条一元多项式:"<<endl;
	x=1;
	while(x!=0)
   {
	    cin>>x;
		if(x==0)
			break;
		cin>>n;
		ListInset(head2,x,n);
   }
   head3=ListApp(head1,head2);
   cout<<"两式子分别为："<<endl;
   ListOutput(head1);
   cout<<endl;
   ListOutput(head2);
   cout<<endl;
   cout<<"两式相加：";
   ListOutput(head3);
   cout<<endl;
   head4=ListSubstract(head1,head2);
   cout<<"两式相减：";
   ListOutput(head4);
   cout<<endl;
   ListDestroy(head1);
   ListDestroy(head2);
   ListDestroy(head3);
   ListDestroy(head4);
   system("pause");
   return 0;
}