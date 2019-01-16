#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int sum[3000];

string Reverse(string num)
{
	 string temp;
     for(int i=num.length()-1;i>=0;i--)
	     temp+=num[i];
	 return temp;
}

int main()
{
   int i,num=0;
   string num1,num2;
   memset(sum,0,sizeof(sum));
   cin>>num1>>num2;
   num1=Reverse(num1);
   num2=Reverse(num2);
   num=num1.length()<num2.length()?num1.length():num2.length();
   for(i=0;i<num;i++)
   {
        sum[i]+=num1[i]+num2[i]-48*2;
		if(sum[i]>=10)
		{
		      sum[i+1]=sum[i]/10;
			  sum[i]%=10;
		}
   }
   for(;i<abs(int(num1.length()-num2.length()))+num;i++)
   {
        if(num1.length()>num2.length())
		{
		      sum[i]+=num1[i]-48;
		      if(sum[i]>=10)
		      {
		      sum[i+1]=sum[i]/10;
		  	  sum[i]%=10;
		      }
		}
		else
		{
		      sum[i]+=num2[i]-48;
		      if(sum[i]>=10)
		      {
		      sum[i+1]=sum[i]/10;
		  	  sum[i]%=10;
		      }		
		}
   }
   if(sum[int(num1.length()>num2.length()?num1.length():num2.length())])
	   cout<<sum[i];
   for(i=int(num1.length()>num2.length()?num1.length():num2.length())-1;i>=0;i--)
	   cout<<sum[i];
   cout<<endl;
   system("pause");
   return 0;
}

