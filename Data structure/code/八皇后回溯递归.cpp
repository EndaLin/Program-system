#include<iostream>
#include<cmath>
using namespace std;
const int MAX=8;
int a[MAX];   //只需继续每行皇后所在的列数即可,非列数下标
static int num;

bool place(int k){
     int i;
	 for(i=0;i<k;i++)
		 if(a[i]==a[k]||abs(a[i]-a[k])==abs(i-k))   //检测该位置是否合适放皇后
			 return true;
	 return false;
}

void print()
{
    for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
		      if(a[i]-1==j)
				  cout<<1<<" ";
			  else
				  cout<<0<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl<<endl;
}

int find(int n)    //n为行数下标
{
	 if(n<0)
	 	    return 0;
	 else if(a[n]!=MAX)
	       a[n]++;
	 else{
		    a[n]=0;
     		return find(n-1);
	 }
	 while(a[n]<=MAX&&place(n))
		    a[n]++;
	 if(a[n]<=MAX&&n==MAX-1){
	       num++;
		   print();
		   a[n]=0;
		   return find(n-1);
	 }
	 else if(a[n]<=MAX&&n<MAX-1){
	       return find(n+1);
	 }
	 else{
	       a[n]=0;
		   return find(n-1);
	 }
}

int main()
{
	memset(a,0,sizeof(a));
    find(0);
	cout<<"一共"<<num<<"种结果"<<endl;
	system("pause");
	return 0;
}

