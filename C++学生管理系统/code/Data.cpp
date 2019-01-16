#include"Data.h"
#include"interface.h"


//Person类函数实现

int &Person::getID()
{
     return id;
}

string &Person::getName()
{
     return name;
}

string &Person::getSex()
{
     return sex;
}

string &Person::getMajorNumber()
{
     return major_number;
}

string &Person::getClassNumber()
{
      return class_number;
}

string &Person::getMajor()
{
      return major;
}

string &Person::getClass()
{
      return Class;
}

int &Person::getScore(int n)
{
      return sco.getScore(n);
}


void Person::motify(int n)
{
      int temp;
	  switch(n){
	  case 1:cout<<"请输入正确的名字：";cin>>temp;name=temp;break;
	  case 2:cout<<"请输入正确的性别：";cin>>temp;sex=temp;break;
	  }
}

int &Person::getRanking1()
{
      return gradeRanking;
}

int &Person::getranking2()
{
      return classRanking;
}

//本科生类函数实现

void undergraduate::Display()
{
	  cout<<setw(7)<<id<<setw(7)<<name<<setw(5)<<sex<<setw(11)<<major_number<<setw(7)<<class_number<<setw(11)<<major<<setw(12)<<Class<<setw(7)<<sco.getScore(0)<<setw(10)<<sco.getScore(1)<<setw(10)<<sco.getScore(2)<<setw(10)<<sco.getScore(3)<<setw(10)<<classRanking<<setw(10)<<gradeRanking<<endl;
}

void undergraduate::print()
{
      cout<<"【A】ID： "<<id<<endl;
	  cout<<"【1】名字： "<<name<<endl;
	  cout<<"【2】性别： "<<sex<<endl;
	  cout<<"【3】专业编号："<<major_number<<endl;
	  cout<<"【B】专业名称："<<major<<endl;
	  cout<<"【4】班级编号： "<<class_number<<endl;
	  cout<<"【C】班级名称："<<Class<<endl;
	  cout<<"【5】C语言成绩： "<<sco.getScore(0)<<endl;
	  cout<<"【6】高数成绩： "<<sco.getScore(1)<<endl;
	  cout<<"【7】英语成绩： "<<sco.getScore(2)<<endl;
	  cout<<"【D】总成绩： "<<sco.getScore(3)<<endl;
	  cout<<"【E】班级排名： "<<gradeRanking<<endl;
	  cout<<"【F】年级排名： "<<classRanking<<endl;
}

void undergraduate::motify(int n)
{
	  if(n<=4)
	  {
	      Person &p=*this;
		  p.Person::motify(n);
	  }
	  else
	  {
		  string temp;
		  int score;
		  switch(n)
		  {
		       case 5:cout<<"请输入正确的C语言成绩：";cin>>score;sco.getScore(0)=score;break;
		       case 6:cout<<"请输入正确的高数成绩：";cin>>score;sco.getScore(1)=score;break;
		       case 7:cout<<"请输入正确的英语成绩：";cin>>score;sco.getScore(2)=score;break;
			   case 0:cout<<"修改结束，请按任意键回到菜单处！"<<endl;break;
		  }
	      sco.calculation();  //计算总成绩
	  }
	  cout<<"修改成功！"<<endl;
}


//研究生类函数实现

void graduate::Display()
{
   cout<<setw(7)<<id<<setw(7)<<name<<setw(5)<<sex<<setw(11)<<major_number<<setw(7)<<class_number<<setw(11)<<major<<setw(12)<<Class<<setw(9)<<sco.getScore(0)<<setw(12)<<sco.getScore(1)<<setw(10)<<sco.getScore(2)<<setw(7)<<classRanking<<setw(10)<<gradeRanking<<endl;
}

void graduate::print()
{
      cout<<"【A】ID： "<<id<<endl;
	  cout<<"【1】名字： "<<name<<endl;
	  cout<<"【2】性别： "<<sex<<endl;
	  cout<<"【3】专业编号："<<major_number<<endl;
	  cout<<"【B】专业名称： "<<major<<endl;
	  cout<<"【4】班级编号： "<<class_number<<endl;
	  cout<<"【C】班级名称： "<<Class<<endl;
	  cout<<"【5】课程综合成绩： "<<sco.getScore(0)<<endl;
	  cout<<"【6】论文成绩： "<<sco.getScore(1)<<endl;
	  cout<<"【D】总成绩： "<<sco.getScore(2)<<endl;
	  cout<<"【E】班级排名： "<<gradeRanking<<endl;
	  cout<<"【F】年级排名： "<<classRanking<<endl;
}

void graduate::motify(int n)
{
      if(n<=4)
	  {
	      Person &p=*this;
		  p.Person::motify(n);
	  }
	  else
	  {
		  int score;
 		  switch(n)
		  {
		     case 5:cout<<"请输入正确的课程设计成绩：";cin>>score;sco.getScore(0)=score;break;
		     case 6:cout<<"请输入正确的论文成绩：";cin>>score;sco.getScore(1)=score;break;
			 case 0:cout<<"修改结束，请按任意键回到菜单处！"<<endl;break;
		  }
		  sco.calculation();
	  }
}

//班级类函数实现

void Class::Display() const
{
	 cout<<setw(15)<<major_number<<setw(11)<<major<<setw(17)<<id<<setw(17)<<name<<endl;
}

string &Class::getMajor_number()
{
    return major_number;
}

string &Class::getMajor()
{
    return major;
}

string &Class::getName()
{
    return name;
}

string &Class::getID()
{
    return id;
}

//年级类函数实现

void major::Display() const
{
	  cout<<setw(14)<<id<<setw(12)<<name<<endl;
}

string &major::getName()
{
       return name;
}

string &major::getID()
{
       return id;
}
