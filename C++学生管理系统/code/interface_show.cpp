#include"interface.h"

void Interface::DisplayByClass()
{
     string id1;
	 string id2;
	 int count=0;
	 int choose;
	 cout<<"请输入您所需要查询的专业编号：";
	 cin>>id1;
	 cout<<"请输入您所需要查询的班级编号：";
	 cin>>id2;
	 cout<<"请输入学生类型（本科生-1 or 研究生-2）：";
	 cin>>choose;
	 if(choose==1){
		 vector<undergraduate>::iterator p=stu1.begin();
		 vector<undergraduate> student;
		 while(p!=stu1.end())
		 {
		      if(p->getMajorNumber()==id1&&p->getClassNumber()==id2)
			  {
				    student.push_back(*p++);
					count++;
			  }
			  else 
				      p++;
		 }
		 Display(3,count,student.begin(),student.end());
		 return;
	 }
	 else if(choose==2){
		 vector<graduate>::iterator p=stu2.begin();
		 vector<graduate> student;
		 while(p!=stu2.end())
		 {
		      if(p->getMajorNumber()==id2&&p->getClassNumber()==id1)
			  {
				    student.push_back(*p++);
					count++;
			  }
			  else 
				      p++;
		 }
		 Display(4,count,student.begin(),student.end());
		 return;
	 }
	 else
	 {
	     cout<<"输入有误，正在返回菜单..."<<endl;
		 system("pause");
		 return;
	 }
}

void Interface::DisplayByMajor()
{
    string id;
	cout<<"请输入需要查询的专业编号：";
	cin>>id;
	int choose;
	int count=0;
	cout<<"请输入学生类型（本科生-1 or 研究生-2）：";
	cin>>choose;
	if(choose==1)
	{
		 vector<undergraduate>::iterator p=stu1.begin();
		 vector<undergraduate> student;
		 while(p!=stu1.end())
		 {
		      if(p->getMajorNumber()==id)
			  {
				    student.push_back(*p++);
					count++;
			  }
			  else 
				      p++;
		 }
		 Display(3,count,student.begin(),student.end());
		 return;
	 }
	 else if(choose==2){
		 vector<graduate>::iterator p=stu2.begin();
		 vector<graduate> student;
		 while(p!=stu2.end())
		 {
		      if(p->getMajorNumber()==id)
			  {
				    student.push_back(*p++);
					count++;
			  }
			  else 
				      p++;
		 }
		 Display(4,count,student.begin(),student.end());
		 return;
	 }
	 else
	 {
	     cout<<"输入有误，正在返回菜单..."<<endl;
		 system("pause");
		 system("cls");
		 return;
	 }  
}

void Interface::DisplayByName()
{
      string name;
	  cout<<"请输入该生姓名：";
	  cin>>name;
	  int type;
	  cout<<"请输入学生类型（本科生-1 or 研究生-2）：";
	  cin>>type;
	if(type==1)
	{
		 vector<undergraduate>::iterator p=stu1.begin();
		 while(p!=stu1.end())
		 {
		      if(p->getName()==name)
			  {
				  cout<<"已找到该生信息！"<<endl;
				  p->print();
				  system("pause");
				  system("cls");
				  return;
			  }
			  else 
				      p++;
		 }
		 cout<<"没有相关学生的信息，请核对信息！"<<endl;
		 system("pause");
		 return;
	 }
	else if(type==2)
	{
		 vector<graduate>::iterator p=stu2.begin();
		 while(p!=stu2.end())
		 {
		      if(p->getName()==name)
			  {
				  cout<<"已找到该生信息！"<<endl;
				  p->print();
				  system("pause");
				  system("cls");
				  return;
			  }
			  else 
				      p++;
		 }
		 cout<<"没有相关学生的信息，请核对信息！"<<endl;
		 system("pause");
		 return;
	}
	 else
	 {
	     cout<<"输入有误，正在返回菜单..."<<endl;
		 system("pause");
		 return;
	 }  
}

void Interface::DisplayByID()
{
     int id;
	 int type;
	 cout<<"请输入学生学号：";
	 cin>>id;
	 cout<<"请输入学生类型（本科生-1 or 研究生-2）：";
	 cin>>type;
	 if(type==1)
	 {
		 vector<undergraduate>::iterator p=stu1.begin();
		 while(p!=stu1.end())
		 {
		      if(p->getID()==id)
			  {
				  cout<<"已找到该生信息！"<<endl;
				  p->print();
				  system("pause");
				  system("cls");
				  return;
			  }
			  else 
				      p++;
		 }
		 cout<<"没有相关学生的信息，请核对信息！"<<endl;
		 system("pause");
		 return;
	 }
	 else if(type==2)
	 {
		 vector<graduate>::iterator p=stu2.begin();
		 while(p!=stu2.end())
		 {
		      if(p->getID()==id)
			  {
				  cout<<"已找到该生信息！"<<endl;
				  p->print();
				  system("pause");
				  system("cls");
				  return;
			  }
			  else 
				      p++;
		 }
		 cout<<"没有相关学生的信息，请核对信息！"<<endl;
		 system("pause");
		 return;
	 }
	 else
	 {
	     cout<<"输入有误，正在返回菜单..."<<endl;
		 system("pause");
		 return;
	 }  
}

void Interface::DisplayFailStudent()
{
     string id1;   //年级编号
	 string id2;   //班级编号
	 cout<<"请输入年级编号：";
	 cin>>id1;
	 cout<<"请输入班级编号：";
	 cin>>id2;
	 int type;
	 cout<<"请输入学生类型（本科生-1 or 研究生-2）：";
	 cin>>type;
	 int choose;
	 int count=0;
	 if(type==1)
	 {
		  cout<<"请输入需要统计信息的科目（C语言-1，高数—2，英语—3）：";
		  cin>>choose;
	      vector<undergraduate>::iterator p=stu1.begin();
		  vector<undergraduate> student;
		  while(p!=stu1.end())
		  {
		       if(p->getMajorNumber()==id1&&p->getClassNumber()==id2&&p->getScore(choose-1)<60)
			   {
			           student.push_back(*p++);
					   count++;
			   }
			   else 
				       p++;
		  }
		  if(!count)
		  {
		      cout<<"该班级在该科目中不及格人数为0！"<<endl;
			  system("pause");
			  system("cls");
			  return;
		  }
		  else
			  Display(3,count,student.begin(),student.end());
	 }
	 else if(type==2)
	 {
		  cout<<"请输入需要统计信息的科目（课程设计-1，论文成绩-2）：";
		  cin>>choose;
	      vector<graduate>::iterator p=stu2.begin();
		  vector<graduate> student;
		  while(p!=stu2.end())
		  {
		       if(p->getMajorNumber()==id1&&p->getClassNumber()==id2&&p->getScore(choose-1)<60)
			   {
			           student.push_back(*p++);
					   count++;
			   }
			   else 
				       p++;
		  }
		  if(!count)
		  {
		      cout<<"该班级在该科目中不及格人数为0！"<<endl;
			  system("pause");
			  system("cls");
			  return;
		  }
		  else
			  Display(4,count,student.begin(),student.end());
	 }
	 else
	 {
	      cout<<"输入的学生类型有误！请核对..."<<endl;
		  system("pause");
		  return;
	 }
}
