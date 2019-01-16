#include<iostream>
#include<string>
using namespace std;

int main()
{
	long long num;
	char ch;
	string ans;
	cin>>num;
	while(num!=0){
	    if(num%16<=9)
			ch=char(num%16+48);
		else 
			ch=char(num%16+55);
		num/=16;
		ans+=ch;
	}
	for(int i=ans.length()-1;i>=0;i--)
		cout<<ans[i];
	return 0;
}