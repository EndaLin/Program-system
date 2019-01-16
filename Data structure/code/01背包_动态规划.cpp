#include<iostream>
using namespace std;
const int MAXSIZE=10;
const int MAXSIZEWEIGHT=10;
int V[MAXSIZE],W[MAXSIZE];
int value[MAXSIZE][MAXSIZEWEIGHT];

int findMaxValue(int N,int M)
{
    for(int i=1;i<=N;i++)
	{
	      for(int j=1;j<=M;j++)
		  {
		       if(W[i]>j)
				   value[i][j]=value[i-1][j];
			   else
			   {
			       value[i][j]=value[i-1][j]>(value[i-1][j-W[i]]+V[i])?value[i-1][j]:value[i-1][j-W[i]]+V[i];
			   }
		  }
	}
	return value[N][M];
}





int main()
{
     int N,M;
	 cout<<"请输入物品的数量以及背包的容量：";
	 cin>>N>>M;
	 for(int i=1;i<=N;i++)
	 {
	       cout<<"第"<<i+1<<"个物品的价值以及体积:";
		   cin>>V[i]>>W[i];
	 }
	 memset(value,0,sizeof(int));
	 cout<<"所给条件能创建的最大价值为："<<findMaxValue(N,M)<<endl;
	 system("pause");
	 return 0;
}