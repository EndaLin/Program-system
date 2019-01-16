#include<iostream>
using namespace std;
const int MAXSIZE=12;
static int num;
int a[MAXSIZE][MAXSIZE] =

{{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},     

{ 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0,-1},     

{-1, 0,-1,-1,-1,-1,-1, 0, 0, 0, 0,-1},    

{-1, 0, 0, 0,-1, 0,-1, 0, 0, 0,-1,-1},    

{-1,-1,-1, 0,-1,-1,-1, 0,-1,-1, 0,-1},    

{-1, 0,-1, 0, 0, 0,-1, 0,-1, 0, 0,-1},

{-1, 0,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1},

{-1, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1},

{-1, 0,-1,-1,-1,-1, 0,-1,-1,-1, 0,-1},

{-1, 0,-1,-1, 0, 0, 0, 0, 0, 0, 0,-1},

{-1, 0, 0, 0, 0,-1,-1, 0,-1, 0, 0, 0},

{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};

void print()     //输出迷宫路线
{
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
	       if(a[i][j]==-1)
			   cout<<"= ";
		   else if(a[i][j]==0)
			   cout<<"  ";
		   else
			   cout<<"* ";
		}
		cout<<endl;
	}
	cout<<endl<<endl<<endl;
}

void find(int i,int j)
{
	a[i][j]=1;            //标记当前结点
	if(i==10&&j==11){
	       num++;
		   print();
		   a[i][j]=0;
		   return;
	}
	if(i-1>-1&&a[i-1][j]==0){
	       find(i-1,j);   //向上寻找
	}
	if(i+1<MAXSIZE&&a[i+1][j]==0){
	       find(i+1,j);  //向下寻找
	}
	if(j-1>-1&&a[i][j-1]==0){
	       find(i,j-1);  //向左寻找
	}
	if(j+1<MAXSIZE&&a[i][j+1]==0){
	       find(i,j+1); //向右寻找      
	}
	{
        a[i][j]=0;   
        return;
	}

}

int main()
{
	  cout<<"输出迷宫形状"<<endl;
	  print();
	  cout<<"输出出口路线"<<endl;
      find(1,0);     //传入口位置参数4
	  cout<<"一共"<<num<<"种答案"<<endl;
	  system("pause");    
	  return 0;
}
