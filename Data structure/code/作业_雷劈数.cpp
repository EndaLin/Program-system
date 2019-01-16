#include<iostream>
#include<cmath>
using namespace std;

int main()
{
      int count=0,temp,right,left;
	  for(int i=9;i<=10000;i++){
		     count=0;
		     temp=i*i;
			 while(temp){
			       temp/=10;
				   count++;
			 }
			 for(int j=1;j<count;j++){
			       left=pow(i,2)/int(pow(10,j));
				   right=(i*i)%int(pow(10,j));
				   if(pow(left+right,2)==i*i){
				           cout<<i*i<<endl;
						   break;
				   }
			 }
	  }
	  system("pause");
	  return 0;
}