#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;
typedef int DataType;

class HashNode
{
public:
	vector<DataType>node;  
};

class Hash
{
public:
	HashNode *hash;
	int num;   //记录哈希表的大小
	Hash(int num);
	~Hash();
	void Insert(DataType data[],int n);
	bool find(DataType data);
};

Hash::Hash(int num)
{
	this->num=num/0.6;
	hash=new HashNode[this->num];
}

Hash::~Hash()
{
    delete []hash;
}

void Hash::Insert(DataType data[],int n)
{
	 int address;
     for(int i=0;i<n;i++)
	 {
	      address=data[i]%num;
		  hash[address].node.push_back(data[i]);
	 }
}

bool Hash::find(DataType data)
{
     int address=data%num;
	 if(hash[address].node.empty())
		 return false;
	 else {
		 vector<DataType>::iterator p=hash[address].node.begin();
		 while(p!=hash[address].node.end())
		 {
		      if(*p==data)
				  return true;
			  p++;
		 }
		 return false;
	 }
}

void random(DataType data[])
{
    srand(time(NULL));
	for(int i=0;i<500;i++)
	{
	     data[i]=200+rand()%800;
	}
}

void show(DataType data[],int n)
{
    for(int i=0;i<n;i++)
		cout<<data[i]<<" ";
	cout<<endl;
}

bool compare(int a,int b)
{
     return a<b;
}

int main()
{
    DataType data[500];
	Hash hash(500);
	int num;
	random(data);
	sort(data,data+500);
	show(data,500);
	hash.Insert(data,500);
	cout<<"请输入所需要查找的数：";
	cin>>num;
	if(hash.find(num))
		cout<<"存在！"<<endl;
	else
		cout<<"不存在！"<<endl;
	system("pause");
	return 0;
}