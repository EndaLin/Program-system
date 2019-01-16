#include"interface.h"


void Interface::Input()    //批量输入本科生或者研究生的基本信息
{
	   int id;
	   string name;
	   string sex;
	   string major_number;    //专业编号
	   string class_number;    //班级编号
	   string Class1;
	   string major1;
	   string type;
	   int i,n;
	   int flag=1;
	   cout<<"请输入需要录入信息的学生人数：";
	   cin>>n;
	   for(i=0;i<n;i++)
	   {
	        cout<<"请输入第"<<i+1<<"位学生信息"<<endl;
			cout<<"请输入学生姓名：";
			cin>>name;
		    cout<<"请输入学生性别：";
			cin>>sex;
			while(flag){
			     cout<<"请输入专业编号（注意：不能输入不存在的专业编号）：";
			     cin>>major_number;
			     vector<major>::iterator p=maj.begin();   
			     while(p!=maj.end())
				 {
				     if(p->getID()==major_number)
					 {
					        flag=0;
							major1=p->getName();
							break;
					 }
					 else 
						 p++;
				 }
				 if(flag)
			     {
			         cout<<"输入的专业编号不存在！请核实..."<<endl;
			     }
			}
			flag=1;
			while(flag){
			     cout<<"请输入班级编号（注意：不能输入不存在的班级编号）：";
			     cin>>class_number;
			     vector<Class>::iterator p1=Cla.begin();   
			     while(p1!=Cla.end())
				 {
				     if(p1->getID()==class_number)
					 {
					        flag=0;
							Class1=p1->getName();
							break;
					 }
					 else 
						 p1++;
				 }
				 if(flag)
			     {
			         cout<<"输入的班级编号不存在！请核实..."<<endl;
			     }
			}
			flag=1;
			while(1)
			{
				cout<<"请输入学生类别（研究生 or 本科生）：";
				cin>>type;
				if(type!="研究生"&&type!="本科生")
					cout<<"输入的信息有误，请重新输入！"<<endl;
				else 
					break;
			}
			if(type=="本科生")
			{
				count1++;
				id=count1;
				undergraduate s(id,name,sex,major_number,class_number,major1,Class1,0,0,4);
				stu1.push_back(s);
			}
			else 
			{
			    count2++;
				id=count2;
				graduate s(id,name,sex,major_number,class_number,major1,Class1,0,0,3);
				stu2.push_back(s);
			}
			 cout<<"输入成功！";
			 system("pause");
			 system("cls");

	   }
	   cout<<"所有信息录入完成！"<<endl;
	   system("pause");
	   system("cls");
}

void Interface::motify3()    //根据学号修改学生个人信息
{
	  int id;
      int choose,flag=1;
	  cout<<"请输入学生学号：";
	  cin>>id;
	  cout<<"请输入选择学生类别（本科生-1  or   研究生-2）"<<endl;
	  cout<<"请选择：";
	  cin>>choose;
	  if(choose==1)
	  {
	       vector<undergraduate>::iterator p=stu1.begin();
		   while(p!=stu1.end())
		   {
		        if(p->getID()==id)
				{
				      cout<<"已经找到该生信息！"<<endl;
					  flag=0;
					  break;
				}
				else
					  p++;
		   }
		   if(flag)
		   {
		        cout<<"该生信息不存在，请核对您的输入..."<<endl;
				system("pause");
				return;
		   }
		   int choose1=1;
		   while(choose1)
		   {
			    p->print();
			    cout<<"【0】退出"<<endl;
		        cout<<"请输入您要修改的项目（0-7）：";
				cin>>choose1;
				if(choose1!=3&&choose1!=4)
				      p->motify(choose1);
				else if(choose1==3)
				{
					  string id;
				      cout<<"请输入修改后的专业编号（注意：不能输入不存在的专业编号）：";
					  cin>>id;
					  vector<major>::iterator p2=maj.begin();
					  while(p2!=maj.end())
					  {
					       if(p2->getID()==id)
						   {
							   p->getMajorNumber()=id;
							   p->getMajor()=p2->getName();
							   break;
						   }
						   else
							   p2++;
					  }
					  if(p2==maj.end())
					  {
					      cout<<"请输入的编号不存在，请核对后重新输入！"<<endl;
						  system("pause");
					  }
				}
				else if(choose1==4)
				{
					  string id;
				      cout<<"请输入修改后的班级编号（注意：不能输入不存在的班级编号）：";
					  cin>>id;
					  vector<Class>::iterator p2=Cla.begin();
					  while(p2!=Cla.end())
					  {
					       if(p2->getID()==id)
						   {
							   p->getClassNumber()=id;
							   p->getClass()=p2->getName();
							   break;
						   }
						   else
							   p2++;
					  }
					  if(p2==Cla.end())
					  {
					      cout<<"请输入的编号不存在，请核对后重新输入！"<<endl;
						  system("pause");
					  }				      
				}
				system("cls");
		   }
	  }
	  else
	  {
	       vector<graduate>::iterator p=stu2.begin();
		   while(p!=stu2.end())
		   {
		        if(p->getID()==id)
				{
				      cout<<"已经找到该生信息！"<<endl;
					  flag=0;
					  break;
				}
				else
					  p++;
		   }
		   if(flag)
		   {
		        cout<<"该生信息不存在，请核对您的输入..."<<endl;
				system("pause");
				return;
		   }
		   int choose1=1;
		   while(choose1)
		   {
			    p->print();
			    cout<<"【0】退出"<<endl;
		        cout<<"请输入您要修改的项目（0-6）：";
				cin>>choose1;
				if(choose1!=3&&choose1!=4)
				      p->motify(choose1);
				else if(choose1==3)
				{
					  string id;
				      cout<<"请输入修改后的专业编号（注意：不能输入不存在的专业编号）：";
					  cin>>id;
					  vector<major>::iterator p2=maj.begin();
					  while(p2!=maj.end())
					  {
					       if(p2->getID()==id)
						   {
							   p->getMajorNumber()=id;
							   p->getMajor()=p2->getName();
							   break;
						   }
						   else
							   p2++;
					  }
					  if(p2==maj.end())
					  {
					      cout<<"请输入的编号不存在，请核对后重新输入！"<<endl;
						  system("pause");
					  }
				}
				else if(choose1==4)
				{
					  string id;
				      cout<<"请输入修改后的班级编号（注意：不能输入不存在的班级编号）：";
					  cin>>id;
					  vector<Class>::iterator p2=Cla.begin();
					  while(p2!=Cla.end())
					  {
					       if(p2->getID()==id)
						   {
							   p->getClassNumber()=id;
							   p->getClass()=p2->getName();
							   break;
						   }
						   else
							   p2++;
					  }
					  if(p2==Cla.end())
					  {
					      cout<<"请输入的编号不存在，请核对后重新输入！"<<endl;
						  system("pause");
					  }				      
				}
				system("cls");
		   }
	  }
}

void Interface::InputScore()
{
      string major_number;
	  string class_number;
	  string type;
	  int flag=1;
	  while(flag)
	  {
	      cout<<"请输入专业编号（注意：不能输入不存在的专业编号）：";
		  cin>>major_number;
		  vector<major>::iterator p=maj.begin();
		  while(p!=maj.end())
		  {
		         if(p->getID()==major_number)
				 {
				       flag=0;
					   break;
				 }
				 else 
					   p++;
		  }
		  if(flag)
		  {
		         cout<<"该专业编号不存在，请核实后再输入..."<<endl;
		  }
	  }
	  flag=1;
	  while(flag)
	  {
	      cout<<"请输入班级编号（注意：不能输入不存在的班级编号）：";
		  cin>>class_number;
		  vector<Class>::iterator p1=Cla.begin();
		  while(p1!=Cla.end())
		  {
		         if(p1->getID()==class_number)
				 {
				       flag=0;
					   break;
				 }
				 else 
					   p1++;
		  }
		  if(flag)
		  {
		         cout<<"该班级编号不存在，请核实后再输入..."<<endl;
		  }
	  }
	  cout<<"请输入学生类型(本科生 or 研究生)：";
	  cin>>type;
	  if(type=="本科生")
	  {
		   int choose;
		   int flag=1;    //检测该班级中是否有学生信息
		   int score;
		   cout<<"请输入需要输入成绩的课科目（C语言-1，高数-2，英语-3）：";
		   cin>>choose;
	       vector<undergraduate>::iterator p=stu1.begin();
		   while(p!=stu1.end())
		   {
			   if(p->getClassNumber()==class_number&&p->getMajorNumber()==major_number)
			   {
				         flag=0;
			             cout<<"姓名："<<p->getName()<<endl;
						 switch(choose)
						 {
						 case 1:cout<<"请输入该生的C语言成绩：";break;
						 case 2:cout<<"请输入该生的高数成绩：";break;
						 case 3:cout<<"请输入该生的英语成绩：";break;
						 default:cout<<"输入有误！终止输入..."<<endl;return;
						 }
						 cin>>score;
						 p->getScore(choose-1)=score;
						 p++;
			   }
			   else 
				   p++;
		   }
		   if(flag)
		   {
		           cout<<"该班级中没有学生的基本信息！请按任意键继续..."<<endl;
				   system("pause");
				   return;
		   }
		   cout<<"该班信息输入成功，请按任意键继续..."<<endl;
		   system("pause");
	  }
	  else if(type=="研究生")
	  {
		   int choose;
		   int flag=1;    //检测该班级中是否有学生信息
		   int score;
		   cout<<"请输入需要输入成绩的课科目（课程设计-1，论文成绩-2）：";
		   cin>>choose;
	       vector<graduate>::iterator p=stu2.begin();
		   while(p!=stu2.end())
		   {
			   if(p->getClassNumber()==class_number&&p->getMajorNumber()==major_number)
			   {
				         flag=0;
			             cout<<"姓名："<<p->getName()<<endl;
						 switch(choose)
						 {
						 case 1:cout<<"请输入该生的课程设计成绩：";break;
						 case 2:cout<<"请输入该生的论文成绩：";break;
						 default:cout<<"输入有误！终止输入..."<<endl;return;
						 }
						 cin>>score;
						 p->getScore(choose-1)=score;
						 p++;
			   }
			   else 
				   p++;
		   }
		   if(flag)
		   {
		           cout<<"该班级中没有学生的基本信息！请按任意键继续..."<<endl;
				   system("pause");
				   return;
		   }
		   cout<<"该班信息输入成功，请按任意键继续..."<<endl;
		   system("pause");
	  }
	  else
	  {
	       cout<<"该学生类别不存在，请按任意键继续..."<<endl;
		   system("pause");
	  }
}

void Interface::Delete_student()
{
      string major_number;
	  string class_number;
	  int id;
	  string type;
	  int flag=1;
	  while(flag)
	  {
	      cout<<"请输入专业编号（注意：不能输入不存在的专业编号）：";
		  cin>>major_number;
		  vector<major>::iterator p=maj.begin();
		  while(p!=maj.end())
		  {
		         if(p->getID()==major_number)
				 {
				       flag=0;
					   break;
				 }
				 else 
					   p++;
		  }
		  if(flag)
		  {
		         cout<<"该专业编号不存在，请核实后再输入..."<<endl;
		  }
	  }
	  flag=1;
	  while(flag)
	  {
	      cout<<"请输入班级编号（注意：不能输入不存在的班级编号）：";
		  cin>>class_number;
		  vector<Class>::iterator p1=Cla.begin();
		  while(p1!=Cla.end())
		  {
		         if(p1->getID()==class_number)
				 {
				       flag=0;
					   break;
				 }
				 else 
					   p1++;
		  }
		  if(flag)
		  {
		         cout<<"该班级编号不存在，请核实后再输入..."<<endl;
		  }
	  }
	  cout<<"请输入学生的ID：";
	  cin>>id;
	  cout<<"请输入学生类别（研究生 or 本科生）：";
	  cin>>type;
	  if(type=="本科生")
	  {
	       vector<undergraduate>::iterator p=stu1.begin();
		   while(p!=stu1.end())
		   {
			   if(p->getClassNumber()==class_number&&p->getMajorNumber()==major_number&&p->getID()==id)
			   {
				         cout<<"已成功找到该生信息！"<<endl;
						 p->print();
						 char ch;
						 cout<<"是否确定删除（y or n）：";
						 cin>>ch;
						 if(ch=='y'||ch=='Y')
						 {
						          stu1.erase(p++);
								  cout<<"删除成功！请按任意键继续..."<<endl;
								  system("pause");
								  return;
						 }
						 else
						 {
						          cout<<"请按任意键回到菜单处..."<<endl;
								  system("pause");
								  return;
						 }
			   }
			   else 
				   p++;
		   }
	  }
	  else if(type=="研究生")
	  {
	       vector<graduate>::iterator p=stu2.begin();
		   while(p!=stu2.end())
		   {
			   if(p->getClassNumber()==class_number&&p->getMajorNumber()==major_number&&p->getID()==id)
			   {
				         cout<<"已成功找到该生信息！"<<endl;
						 p->print();
						 char ch;
						 cout<<"是否确定删除（y or n）：";
						 if(ch=='y'||ch=='Y')
						 {
						          stu2.erase(p++);
								  cout<<"删除成功！请按任意键继续..."<<endl;
								  system("pause");
								  return;
						 }
						 else
						 {
						          cout<<"请按任意键回到菜单处..."<<endl;
								  system("pause");
								  return;
						 }
			   }
			   else 
				   p++;
		   }
	  }
	  else
	  {
	          cout<<"该学生类别不存在，请核实后输入..."<<endl;
			  system("pause");
			  return;
	  }
	  cout<<"不存在该生信息，请核实..."<<endl;
	  system("pause");
}

void Interface::motify4()   //根据姓名修改学生信息
{
	  string name;
      int choose,flag=1;
	  cout<<"请输入学生姓名：";
	  cin>>name;
	  cout<<"请输入选择学生类别（本科生-1  or   研究生-2）"<<endl;
	  cout<<"请选择：";
	  cin>>choose;
	  if(choose==1)
	  {
	       vector<undergraduate>::iterator p=stu1.begin();
		   while(p!=stu1.end())
		   {
		        if(p->getName()==name)
				{
				      cout<<"已经找到该生信息！"<<endl;
					  flag=0;
					  break;
				}
				else
					  p++;
		   }
		   if(flag)
		   {
		        cout<<"该生信息不存在，请核对您的输入..."<<endl;
				system("pause");
				return;
		   }
		   int choose1=1;
		   while(choose1)
		   {
			    p->print();
			    cout<<"【0】退出"<<endl;
		        cout<<"请输入您要修改的项目（0-7）：";
				cin>>choose1;
				if(choose1!=3&&choose1!=4)
				      p->motify(choose1);
				else if(choose1==3)
				{
					  string id;
				      cout<<"请输入修改后的专业编号（注意：不能输入不存在的专业编号）：";
					  cin>>id;
					  vector<major>::iterator p2=maj.begin();
					  while(p2!=maj.end())
					  {
					       if(p2->getID()==id)
						   {
							   p->getMajorNumber()=id;
							   p->getMajor()=p2->getName();
							   break;
						   }
						   else
							   p2++;
					  }
					  if(p2==maj.end())
					  {
					      cout<<"请输入的编号不存在，请核对后重新输入！"<<endl;
						  system("pause");
					  }
				}
				else if(choose1==4)
				{
					  string id;
				      cout<<"请输入修改后的班级编号（注意：不能输入不存在的班级编号）：";
					  cin>>id;
					  vector<Class>::iterator p2=Cla.begin();
					  while(p2!=Cla.end())
					  {
					       if(p2->getID()==id)
						   {
							   p->getClassNumber()=id;
							   p->getClass()=p2->getName();
							   break;
						   }
						   else
							   p2++;
					  }
					  if(p2==Cla.end())
					  {
					      cout<<"请输入的编号不存在，请核对后重新输入！"<<endl;
						  system("pause");
					  }				      
				}
				system("cls");
		   }
	  }
	  else
	  {
	       vector<graduate>::iterator p=stu2.begin();
		   while(p!=stu2.end())
		   {
		        if(p->getName()==name)
				{
				      cout<<"已经找到该生信息！"<<endl;
					  flag=0;
					  break;
				}
				else
					  p++;
		   }
		   if(flag)
		   {
		        cout<<"该生信息不存在，请核对您的输入..."<<endl;
				system("pause");
				return;
		   }
		   int choose1=1;
		   while(choose1)
		   {
			    p->print();
			    cout<<"【0】退出"<<endl;
		        cout<<"请输入您要修改的项目（0-6）：";
				cin>>choose1;
				if(choose1!=3&&choose1!=4)
				      p->motify(choose1);
				else if(choose1==3)
				{
					  string id;
				      cout<<"请输入修改后的专业编号（注意：不能输入不存在的专业编号）：";
					  cin>>id;
					  vector<major>::iterator p2=maj.begin();
					  while(p2!=maj.end())
					  {
					       if(p2->getID()==id)
						   {
							   p->getMajorNumber()=id;
							   p->getMajor()=p2->getName();
							   break;
						   }
						   else
							   p2++;
					  }
					  if(p2==maj.end())
					  {
					      cout<<"请输入的编号不存在，请核对后重新输入！"<<endl;
						  system("pause");
					  }
				}
				else if(choose1==4)
				{
					  string id;
				      cout<<"请输入修改后的班级编号（注意：不能输入不存在的班级编号）：";
					  cin>>id;
					  vector<Class>::iterator p2=Cla.begin();
					  while(p2!=Cla.end())
					  {
					       if(p2->getID()==id)
						   {
							   p->getClassNumber()=id;
							   p->getClass()=p2->getName();
							   break;
						   }
						   else
							   p2++;
					  }
					  if(p2==Cla.end())
					  {
					      cout<<"请输入的编号不存在，请核对后重新输入！"<<endl;
						  system("pause");
					  }				      
				}
				system("cls");
		   }
	  }
}
