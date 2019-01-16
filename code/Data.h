#pragma once
//#ifdef _DATA
//#define _DATA
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

class score  //成绩类
{
private:
	vector<int>sco;
public:
	score(vector<int>::const_iterator begin,vector<int>::const_iterator end)  //构造函数
	{
	    while(begin!=end)
		{
		      sco.push_back(*begin);
			  begin++;
		}
	}
	score(int n)                    //构造函数
	{
	     sco.resize(n);
		 vector<int>::iterator p=sco.begin();
		 while(p!=sco.end()){
			 *p=-1;
			 p++;
		 }
	}
	void print() const      //为了显示所有人的信息而用
	{
	    vector<int>::const_iterator p=sco.begin();
		for(;p!=sco.end();p++)
			cout<<*p<<setw(3);
		
	}

	int getTotalScore() const   //提供总成绩，为了排序而用
	{
		vector<int>::const_iterator p=sco.end()-1;
		return *p;
	}

    int &getScore(int n)   //为了返回各科成绩而用
	{
	    return sco[n];
	}

	void calculation()   //为了计算总成绩
	{
		unsigned i;
		int sum;
		for(i=0;i<sco.size()-1;i++)  //检测是否所有成绩都均已输入
		{
		       if(sco[i]==-1)
				   return;
		}
		for(i=0,sum=0;i<sco.size()-1;i++)     //计算总成绩
		{
		       sum+=sco[i];
		}
		sco[i]=sum;
	}
};

class Person    //Person类
{
protected:
	int id;                 //学号
	string name;            //姓名
	string sex;             //性别
	string major_number;    //专业编号
	string class_number;    //班级编号
	string major;           //专业名称
	string Class;           //班级名称
	string type;            //学生类型
	int gradeRanking;       //年级排名
	int classRanking;       //班级排名
	score sco;
public:
	Person(int i,string na,string se,string num1,string num2,string maj,string cla,int rank1,int rank2,vector<int>::const_iterator begin,vector<int>::const_iterator end):id(i),name(na),sex(se),major_number(num1),class_number(num2),major(maj),Class(cla),gradeRanking(rank1),classRanking(rank2),sco(begin,end)  //初始化列表
	{}
	Person(int i,string na,string se,string num1,string num2,string maj,string cla,int rank1,int rank2,int n):id(i),name(na),sex(se),major_number(num1),class_number(num2),major(maj),Class(cla),gradeRanking(rank1),classRanking(rank2),sco(n)  //初始化列表
	{}
	virtual void motify(int n);            //为了修改个人信息而用
	int &getID();            //以下获取信息的放回值均设置为引用是用以左值为了方便修改
	string &getName();       //获取姓名
	string &getSex();        //获取性别
	string &getMajorNumber();//获取专业编号
	string &getClassNumber();//获取班级编号
	string &getMajor();      //获取专业名称
	string &getClass();      //获取班级名称
	int &getRanking1();      //获取年级排名
	int &getranking2();      //获取班级排名
	int &getScore(int n);    //获取各科成绩
};

class undergraduate:virtual public Person   //本科生类
{
public:
	undergraduate(int i,string na,string se,string num1,string num2,string major,string Class,int rank1,int rank2,vector<int>::const_iterator begin,vector<int>::const_iterator end):Person(i,na,se,num1,num2,major,Class,rank1,rank2,begin,end)
	{}
	undergraduate(int i,string na,string se,string num1,string num2,string major,string Class,int rank1,int rank2,int n):Person(i,na,se,num1,num2,major,Class,rank1,rank2,n)
	{}
	virtual void Display();      //显示所有人信息
	virtual void print();        //显示个人信息
	virtual void motify(int n);  //修改个人信息
}; 

class graduate:virtual public Person     //研究生类
{
public:
	graduate(int i,string na,string se,string num1,string num2,string major,string Class,int rank1,int rank2,vector<int>::const_iterator begin,vector<int>::const_iterator end):Person(i,na,se,num1,num2,major,Class,rank1,rank2,begin,end)
	{}
	graduate(int i,string na,string se,string num1,string num2,string major,string Class,int rank1,int rank2,int n):Person(i,na,se,num1,num2,major,Class,rank1,rank2,n)
	{}
	virtual void Display();      //显示所有人信息
	virtual void print();        //显示个人信息
	virtual void motify(int n);  //修改个人信息
};

class Class   //班级类
{
private:
	string major_number;  //专业编号
	string major;         //专业名称
	string name;          //班级名称
	string id;            //班级编号
public:
	Class(string number,string maj,string na,string i):major_number(number),major(maj),name(na),id(i)
	{}
	void Display() const;           //显示所有的班级名称
	string &getMajor_number();      //获取专业编号  
	string &getMajor();             //获取专业名称
	string &getName();              //获取班级名称
	string &getID();                //获取班级编号
};

class major  //专业类
{
private:
	string name;        //专业名称
	string id;          //专业编号
public:
	major(string na,string i):name(na),id(i)      //构造函数
	{}
	void Display() const;                         //显示函数
	string &getName();                            //获取专业名称
	string &getID();                              //获取专业编号
};

//#endif




