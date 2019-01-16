#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
typedef char DataType;
const int Max=100;
typedef struct node1
{
     DataType stack[Max];
	 int top;
}Stack;

typedef struct node
{
	 int data[Max];
	 int top;
}ans;

void StackInitiate(Stack *p)
{
     p->top=0;
}

void StackPush(Stack *p,DataType x)
{
     p->stack[p->top]=x;
	 p->top++;
}

void StackPop(Stack *p,DataType &x)
{
     p->top--;
	 x=p->stack[p->top];
}

void ansInitiate(ans *p)
{
    p->top=0;
}

void ansPush(ans *p,int x)
{
     p->data[p->top]=x;
	 p->top++;
}

void ansPop(ans *p,int &x)
{
     p->top--;
	 x=p->data[p->top];
}

int caculate(ans *p,DataType c)
{
	 int x,x1,x2;
     ansPop(p,x1);
	 ansPop(p,x2);
	 switch(c){
			      case '+':x=x1+x2;break;
				  case '-':x=x2-x1;break;
				  case '*':x=x2*x1;break;
				  case '/':x=x2/x1;break;
	 }
	 ansPush(p,x);
	 return x;
}

int main()
{
	   string name;
	   cin>>name;
	   name+="#";
       Stack b;
	   ans c;
	   ansInitiate(&c);
	   StackInitiate(&b);
	   StackPush(&b,'#');
	   for(int i=0;name[i]!='#';i++){
	        if(name[i]>=48&&name[i]<=57)
			{
				 int temp=0,j=0;
			     while(name[i]>48&&name[i]<=57)
				 {
				       temp+=(name[i]-48)*pow(10,j);
					   i++;
					   j=1;
				 }
				 ansPush(&c,temp);
				 if(name[i]=='#')
					 break;
			}
			if(name[i]=='+'||name[i]=='-'){
				while(1){
			    	if(b.stack[b.top-1]!='#'&&b.stack[b.top-1]!='('){
				        DataType x;
				    	StackPop(&b,x);
				  	    caculate(&c,x);
			     	}
				    else{
						StackPush(&b,name[i]);
						break;
					}
			    }

			}
			else if(name[i]=='*'||name[i]=='/'){
				if(b.stack[b.top-1]=='*'||b.stack[b.top-1]=='/'){
				    DataType x;
					StackPop(&b,x);
					StackPush(&b,name[i]);
				  	caculate(&c,x);
				}
				else
					StackPush(&b,name[i]);
			}
			else if(name[i]=='(')
				 StackPush(&b,name[i]);
			else if(name[i]==')'){
			     while(1){
				         DataType x;
						 StackPop(&b,x);
				  	     caculate(&c,x);
						 if(b.stack[b.top-1]=='('){
						      StackPop(&b,x);
							  break;
						 }
				}
		    }
	   }
	   while(b.top!=1){
	        DataType x;
			StackPop(&b,x);
			caculate(&c,x);
	   }
	   /*for(int i=0;i<a.length();i++)
	   {
		   cout<<a[i];
	   }*/
	   
	   //开始进行后缀表达式的计算
	  /* a+='#';
	   char *p=new char[sizeof(char)*a.length()];
	   //a+='\0';
	   strcpy(p,a.c_str());
	   cout<<ans(p)<<endl;*/
	   int a;
	   ansPop(&c,a);
	   cout<<a<<endl;
	   return 0;
}
