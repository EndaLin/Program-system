#include"interface.h"

/*=======================================专业管理模块==========================================*/


void Interface::creatMajor()  //创建新专业
{
	 //cin.get();   //吸收回车符
     string name,id;
	 char ch;
	 while(1){
	     cout<<"请输入新专业的名称：";
	     cin>>name;
	     cout<<"请输入新专业的专业编号：";
	     cin>>id;
	     major Maj(name,id);
	     maj.push_back(Maj);
		 count4++;
		 cout<<"输入成功！"<<endl;
		 cout<<"是否继续输入（y or n）:";
		 cin>>ch;
		 if(ch=='n'||ch=='N'||ch==50)
			 return;
	 }

}


void Interface::Delete_Major()   //删除某专业以及相关人员
{
	    int flag=0;
        string name,id;
		cout<<"请输入需要删除的专业信息的名称：";
		cin>>name;
		cout<<"请输入专业编号：";
		cin>>id;
		vector<major>::iterator p=maj.begin();
		while(p!=maj.end())
		{
		       if(name==p->getName()&&id==p->getID())
			   {
				    cout<<"已经找到该专业的相关信息(注意：如果删除，则与该专业相关的班级以及人员都会一并删除)"<<endl;
				    cout<<"是否确定删除（y or n）：";
					char ch;
					cin>>ch;
					if(ch=='Y'||ch=='y'){
			            maj.erase(p++);
					    count4--;
					    cout<<"删除成功！"<<endl;
						flag=1;
						break;
					}
					else
					{
					    cout<<"没有删除记录，准备回到菜单页面..."<<endl;
						system("pause");
						return;
					}
			   }
			   else
				   p++;
		}
		if(flag==0)
		{
			   cout<<"没有找到该专业的相关信息，准备回到菜单页面..."<<endl;
			   system("pause");
			   return;
		}
		//删除该专业的所有班级信息
		vector<Class>::iterator p2=Cla.begin();
		while(p2!=Cla.end())
		{
		       if(name==p2->getMajor()&&id==p2->getMajor_number())
			   {
				   p2=Cla.erase(p2);
				   count3--;
			   }
			   else
				   p2++;
		}
		cout<<"已经删除与该专业相关的所有班级信息"<<endl;
		//删除该专业的所有人员信息
		vector<undergraduate>::iterator p3=stu1.begin();
		while(p3!=stu1.end())
		{
		       if(name==p3->getMajor()&&id==p3->getMajorNumber())
			   {
				   p3=stu1.erase(p3);
				   count1--;
			   }
			   else
				   p3++;
		}
		cout<<"已经删除与该专业相关的所有本科生信息"<<endl;
		vector<graduate>::iterator p4=stu2.begin();
		while(p4!=stu2.end())
		{
		       if(name==p4->getMajor()&&id==p4->getMajorNumber())
			   {
			        p4=stu2.erase(p4);
					count2--;
			   }
			   else
				   p4++;
		}
		cout<<"已经删除与该专业相关的所有研究生信息"<<endl;
		cout<<"所有信息已经删除成功，请按任意键回到菜单处..."<<endl;
		system("pause");
}

void Interface::motify1()
{
	   int flag=0;
       string name,id;
	   string name1,id1;
	   cout<<"请输入需要修改信息的专业编号：";
	   cin>>id;
	   cout<<"请输入需要修改信息的专业名称：";
	   cin>>name;
	   vector<major>::iterator p=maj.begin();
	   while(p!=maj.end())
	   {
	        if(name==p->getName()&&id==p->getID())
			{
				  flag=1;
				  cout<<"已经找到该专业的相关信息（注意：如若修改，则会一并修改所有与该专业相关的班级、人员的信息）"<<endl;
				  cout<<"是否确定修改（y or n）：";
				  char ch;
				  cin>>ch;
				  if(ch=='y'||ch=='Y')
				  {
				      cout<<"请输入修改后的专业名称：";
					  cin>>name1;
					  cout<<"请输入修改后的专业编号：";
					  cin>>id1;
					  p->getID()=id1;
					  p->getName()=name1;
					  cout<<"修改该专业的信息成功！"<<endl;
					  break;
				  }
			}
			else p++;
	   }
	   if(flag==0)
	   {
	        cout<<"没有找到与该专业相关的信息，请按任意键回到菜单处..."<<endl;
			system("pause");
			return;
	   }
		//修改该专业的所有班级信息
		vector<Class>::iterator p2=Cla.begin();
		while(p2!=Cla.end())
		{
		       if(name==p2->getMajor()&&id==p2->getMajor_number())
			   {
				   p2->getMajor_number()=id1;
				   p2->getMajor()=name1;
			   }
			   else
				   p2++;
		}
		cout<<"已经修改与该专业相关的所有班级信息"<<endl;
		//修改该专业的所有人员信息
		vector<undergraduate>::iterator p3=stu1.begin();
		while(p3!=stu1.end())
		{
		       if(name==p3->getMajor()&&id==p3->getMajorNumber())
			   {
				   p3->getMajor()=name1;
				   p3->getMajorNumber()=id1;
			   }
			   else
				   p3++;
		}
		cout<<"已经修改与该专业相关的所有本科生信息"<<endl;
		vector<graduate>::iterator p4=stu2.begin();
		while(p4!=stu2.end())
		{
		       if(name==p4->getMajor()&&id==p4->getMajorNumber())
			   {
			        p4->getMajor()=name1;
					p4->getMajorNumber()=id1;
			   }
			   else
				   p4++;
		}
		cout<<"已经修改与该专业相关的所有研究生信息"<<endl;
		cout<<"所有信息已经修改成功，请按任意键回到菜单处..."<<endl;
		system("pause");
}


/*=======================================班级管理模块========================================*/

void Interface::creatClass()
{
       string name,id;   //班级名称，班级编号
	   string majorName,number;     //专业名称，专业编号
	   cout<<"请输入新班级的名称：";
	   cin>>name;
	   cout<<"请输入新班级的编号：";
	   cin>>id;
	   int flag=0;
	   while(!flag)
	   {
	        cout<<"请输入该班级的专业编号（注意：不能输入不存在的专业编号）：";
			cin>>number;
			cout<<"请输入该班级的专业名称（注意：不能输入不存在的专业名称）：";
			cin>>majorName;
			vector<major>::iterator p=maj.begin();
			while(p!=maj.end())
			{
			      if(p->getID()==number&&p->getName()==majorName)
				  {
				       flag=1;
					   break;
				  }
				  else 
					   p++;
			}
			if(!flag)
			{
			     cout<<"输入的专业信息不存在，请重新输入！"<<endl;
			}
	   }
	   Class class1(number,majorName,name,id);
	   Cla.push_back(class1);
	   count3++;
	   cout<<"添加成功！"<<endl;
	   system("pause");
}

void Interface::Delete_Class()
{
       string id;
	   string number;
	   int flag=1;
	   cout<<"请输入对应的班级编号：";
	   cin>>id;
	   cout<<"请输入对应的专业编号：";
	   cin>>number;
	   vector<Class>::iterator p=Cla.begin();
	   while(p!=Cla.end())
	   {
	          if(p->getID()==id&&p->getMajor_number()==number)
			  {
			        Cla.erase(p++);
					cout<<"该班级信息删除成功！"<<endl;
					flag=0;
					break;
			  }
			  else 
				    p++;
	   }
	   if(flag)
	   {
	         cout<<"没有找到相关的班级信息，请核对相关信息是否有误！"<<endl;
			 system("pause");
			 return;
	   }
	   //删除该班级的所有学生信息
	   vector<undergraduate>::iterator p2=stu1.begin();
	   while(p2!=stu1.end())
	   {
		   if(p2->getClassNumber()==id&&p2->getMajorNumber()==number)
		   {
			        p2=stu1.erase(p2);
		   }
		   else 
			  p2++;
	   }
	   vector<graduate>::iterator p3=stu2.begin();
	   while(p3!=stu2.end())
	   {
		   if(p3->getClassNumber()==id&&p3->getMajorNumber()==number)
			  {
			        p3=stu2.erase(p3);
			  }
		   else 
			  p3++;
	   }
	   cout<<"该班级的的所有人员信息均已全部删除！请按任意键继续..."<<endl;
	   system("pause");
}

void Interface::motify2()
{
	   int flag=0;
	   string name1,id1;
       string name,id,number;
	   cout<<"请输入需要修改信息的班级编号：";
	   cin>>id;
	   cout<<"请输入对应的班级名称：";
	   cin>>name;
	   cout<<"请输入对应的专业编号：";
	   cin>>number;
	   vector<Class>::iterator p=Cla.begin();
	   while(p!=Cla.end())
	   {
		   if(p->getID()==id&&p->getMajor_number()==number&&p->getName()==name)
		   {
				  flag=1;
				  cout<<"已经找到该班级的相关信息（注意：如若修改，则会一并修改所有与该班级相关的人员的信息）"<<endl;
				  cout<<"是否确定修改（y or n）：";
				  char ch;
				  cin>>ch;
				  if(ch=='y'||ch=='Y')
				  {
				      cout<<"请输入修改后的班级名称：";
					  cin>>name1;
					  cout<<"请输入修改后的班级编号：";
					  cin>>id1;
					  p->getID()=id1;
					  p->getName()=name1;
					  cout<<"修改该班级的信息成功！"<<endl;
					  break;
			       }
		   }
		   p++;
	   }
	   //修改与该班级信息相关的本科生信息和研究生信息
	   vector<undergraduate>::iterator p2=stu1.begin();
	   while(p2!=stu1.end())
	   {
	         if(p2->getClassNumber()==id&&p2->getClass()==name&&p2->getMajorNumber()==number)
			 {
			          p2->getClass()=name1;
					  p2->getClassNumber()=id1;
			 }
			 else 
				      p2++;
	   }
	   vector<graduate>::iterator p3=stu2.begin();
	   while(p3!=stu2.end())
	   {
	         if(p3->getClassNumber()==id&&p3->getClass()==name&&p3->getMajorNumber()==number)
			 {
			          p3->getClass()=name1;
					  p3->getClassNumber()=id1;
			 }
			 else 
				      p3++;
	   }
	   cout<<"与该班级相关的人员信息已全部修改成功！"<<endl;
	   system("pause");
}
