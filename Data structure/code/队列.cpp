#include"链式队列.h"
#include<iostream>

int main()
{
	 DataType x;
     LQueue p;
	 QueueInitiate(&p);
	 for(int i=0;i<6;i++)
	 {
	      scanf("%d",&x);
		  QueueAppend(&p,x);
	 }
	 QueueDelete(&p,&x);
	 printf("被删除的元素是：%d\n",x);
	 for(int i=0;i<6;i++)
	 {
	        if(QueueDelete(&p,&x))
			     printf("%d\n",x);
	 }
	 system("pause");
	 return 0;
}