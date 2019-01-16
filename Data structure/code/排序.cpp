#include<iostream>
#include<ctime>
using namespace std;

void random(int num[],int n,int max)
{
    srand(time(NULL));
	for(int i=0;i<n;i++)
	{
	      num[i]=200+rand()%(max-200);
	}
}

void shellSort(int num[],int n)
{
	int span[]={5,3,1};
	for(int i=0;i<3;i++)
	{
	     for(int j=0;j<span[i];j++)
		 {
		      for(int k=j;k<n-span[i];k+=span[i])
			  {
			        int temp=num[k+span[i]];
					int m=k;
					while(m>-1&&temp<num[m])
					{
					      num[m+span[i]]=num[m];
						  m-=span[i];
					}
					num[m+span[i]]=temp;
			  }
		 }
	}
}

void QuickSort(int num[],int low,int high)
{
   int i=low,j=high;
   int temp=num[low];
   while(i<j)
   {
        while(i<j&&temp<=num[j])j--;
		if(i<j)
		{
		     num[i]=num[j];
			 i++;
		}
		while(i<j&&num[i]<temp)i++;
		if(i<j)
		{
		     num[j]=num[i];
			 j--;
		}
   }
   num[i]=temp;
   if(low<i)
	   QuickSort(num,low,i-1);
   if(i<high)
	   QuickSort(num,j+1,high);
}

void CreatHeap(int num[],int n,int h)
{
    int temp=num[h];
	int i=h;
	int j=2*i+1;
	int flag=0;
	while(j<n&&flag!=1)
	{
	       if(j<n-1&&num[j]<num[j-1])j++;
		   if(temp>num[j])
			   flag=1;
		   else
		   {
		       num[i]=num[j];
			   i=j;
			   j=2*i+1;
		   }
	}
	num[i]=temp;
}

void InitiateHeap(int num[],int n)
{
    for(int i=(n-2)/2;i>-1;i--)
		CreatHeap(num,n,i);
}

void HeapSort(int num[],int n)
{
    InitiateHeap(num,n);
	for(int i=n-1;i>-1;i--)
	{
	       int temp=num[i];
		   num[i]=num[0];
		   num[0]=temp;
		   CreatHeap(num,i,0);
	}
}


void show(int num[],int n)
{
    for(int i=0;i<n;i++){
		cout<<num[i];
		if(i%20==0&&i!=0)
			cout<<endl;
		else
			cout<<" ";
	}
}


int main()
{
     int num_1[100],num_2[200],num_3[500];
	 random(num_1,100,1000);
	 cout<<"Ï£¶ûÅÅÐò"<<endl;
	 shellSort(num_1,100);
	 show(num_1,100);
	 random(num_2,200,10000);
	 cout<<endl<<"¿ìËÙÅÅÐò"<<endl;
	 QuickSort(num_2,0,199);
	 show(num_2,200);
	 random(num_3,500,10000);
	 cout<<endl<<"¶ÑÅÅÐò"<<endl;
	 HeapSort(num_3,500);
	 show(num_3,500);
	 system("pause");
	 return 0;
}