#include"interface.h"

void Interface::statistic1()
{
     string major_number;
	 string class_number;
	 cout<<"请输入需要统计信息相关班级信息"<<endl;
     cout<<"请输入该班级的年级编号：";
	 cin>>major_number;
	 cout<<"请输入该班级的班级编号：";
	 cin>>class_number;
	 vector<major>::iterator p=maj.begin();
	 while(p!=maj.end())
	 {
	       if(p->getID()==major_number)
			   break;
		   else
			   p++;
	 }
	 if(p==maj.end())
	 {
	       cout<<"没有相关的专业信息，请核对后输入"<<endl;
		   system("pause");
		   system("cls");
		   return;
	 }
	 vector<Class>::iterator p2=Cla.begin();
	 while(p2!=Cla.end())
	 {
	       if(p2->getID()==class_number)
			   break;
		   else
			   p2++;
	 }
	 if(p2==Cla.end())
	 {
	       cout<<"没有相关的班级信息，请核对后输入"<<endl;
		   system("pause");
		   system("cls");
		   return;	 
	 }
	 int choose;
	 cout<<"请输入学生类型（本科生-1 or 研究生-2）：";
	 cin>>choose;
	 if(choose==1)
	 {
		   if(!count1)
		   {
		        cout<<"没有相关学生的信息！"<<endl;
				system("pause");
				system("cls");
				return;
		   }
	       vector<undergraduate>::iterator p=stu1.begin();
		   int count=0,sum=0;
		   double average;
		   int max=p->getScore(3),min=p->getScore(3);
		   while(p!=stu1.end())
		   {
			   if(p->getMajorNumber()==major_number&&p->getClassNumber()==class_number&&p->getScore(3)!=0)
			   {
				   count++;
		           if(p->getScore(3)>max)
					     max=p->getScore(3);
				   if(p->getScore(3)<min)
					     min=p->getScore(3);
				   sum+=p->getScore(3);
			   }
			   p++;
		   }
		   average=sum/count;
		   cout<<"统计完成！"<<endl;
		   cout<<"该班级的平均分是："<<average<<endl;	 
		   cout<<"该班级的最高分是："<<max<<endl;
		   cout<<"该班级的最低分是："<<min<<endl;
		   system("pause");
		   system("cls");
		   return;
	 }
	 else if(choose==2)
	 {
		   if(!count2)
		   {
		        cout<<"没有相关学生的信息！"<<endl;
				system("pause");
				system("cls");
				return;
		   }
	       vector<graduate>::iterator p=stu2.begin();
		   int count=0,sum=0;
		   double average;
		   int max=p->getScore(2),min=p->getScore(2);
		   while(p!=stu2.end())
		   {
			   if(p->getMajorNumber()==major_number&&p->getClassNumber()==class_number&&p->getScore(2)!=0)
			   {
				   count++;
		           if(p->getScore(2)>max)
					     max=p->getScore(2);
				   if(p->getScore(2)<min)
					     min=p->getScore(2);
				   sum+=p->getScore(2);
			   }
			   p++;
		   }
		   average=sum/count;
		   cout<<"统计完成！"<<endl;
		   cout<<"该班级的平均分是："<<average<<endl;	 
		   cout<<"该班级的最高分是："<<max<<endl;
		   cout<<"该班级的最低分是："<<min<<endl;
		   system("pause");
		   system("cls");
		   return;	 
	 }
	 cout<<"请输入的学生类型有误，请核对后输入..."<<endl;
	 system("pause");
	 system("cls");
	 return;
}

void Interface::statistic2()
{
     string major_number;
	 string class_number;
	 cout<<"请输入需要统计信息相关班级信息"<<endl;
     cout<<"请输入该班级的年级编号：";
	 cin>>major_number;
	 cout<<"请输入该班级的班级编号：";
	 cin>>class_number;
	 vector<major>::iterator p=maj.begin();
	 while(p!=maj.end())
	 {
	       if(p->getID()==major_number)
			   break;
		   else
			   p++;
	 }
	 if(p==maj.end())
	 {
	       cout<<"没有相关的专业信息，请核对后输入"<<endl;
		   system("pause");
		   system("cls");
		   return;
	 }
	 vector<Class>::iterator p2=Cla.begin();
	 while(p2!=Cla.end())
	 {
	       if(p2->getID()==class_number)
			   break;
		   else
			   p2++;
	 }
	 if(p2==Cla.end())
	 {
	       cout<<"没有相关的班级信息，请核对后输入"<<endl;
		   system("pause");
		   system("cls");
		   return;	 
	 }
	 int choose;
	 cout<<"请输入学生类型（本科生-1 or 研究生-2）：";
	 cin>>choose;
	 if(choose==1)
	 {
		   if(!count1)
		   {
		        cout<<"没有相关学生的信息！"<<endl;
				system("pause");
				system("cls");
				return;
		   }
	       vector<undergraduate>::iterator p=stu1.begin();
		   int count=0,sum=0;
		   double average;
		   while(p!=stu1.end())
		   {
			   if(p->getMajorNumber()==major_number&&p->getClassNumber()==class_number&&p->getScore(3)!=0)
			   {
				   count++;
				   sum+=p->getScore(3);
			   }
			   p++;
		   }
		   if(!count)
		   {
		       cout<<"没有找到该班级的相关成绩信息！"<<endl;
			   system("pause");
			   system("cls");
			   return;
		   }
		   average=sum/count;
		   p=stu1.begin();
		   int count2=0;      //统计超过平均分的人数
		   vector<undergraduate>student;
		   while(p!=stu1.end())
		   {
		        if(p->getMajorNumber()==major_number&&p->getClassNumber()==class_number&&p->getScore(3)>=average)
				{
					student.push_back(*p);
					count2++;
				}
				p++;
		   }
		   cout<<"统计结束！"<<endl;
		   Display(3,count2,student.begin(),student.end());
		   return;
	 }
	 else if(choose==2)
	 {
		   if(!count2)
		   {
		        cout<<"没有相关学生的信息！"<<endl;
				system("pause");
				system("cls");
				return;
		   }
	       vector<graduate>::iterator p=stu2.begin();
		   int count=0,sum=0;
		   double average;
		   while(p!=stu2.end())
		   {
			   if(p->getMajorNumber()==major_number&&p->getClassNumber()==class_number&&p->getScore(2)>=average)
			   {
				   count++;
				   sum+=p->getScore(2);
			   }
			   p++;
		   }
		   if(!count)
		   {
		       cout<<"没有找到该班级的相关成绩信息！"<<endl;
			   system("pause");
			   system("cls");
			   return;
		   }
		   average=sum/count;
		   p=stu2.begin();
		   int count2=0;      //统计超过平均分的人数
		   vector<graduate>student;
		   while(p!=stu2.end())
		   {
		        if(p->getMajorNumber()==major_number&&p->getClassNumber()==class_number&&p->getScore(2)>=average)
				{
					student.push_back(*p);
					count2++;
				}
				p++;
		   }
		   cout<<"统计结束！"<<endl;
		   Display(4,count2,student.begin(),student.end());
		   return;	 }
	 cout<<"请输入的学生类型有误，请核对后输入..."<<endl;
	 system("pause");
	 system("cls");
	 return;
}

void Interface::statistic3()
{
     string major_number;
	 string class_number;
	 cout<<"请输入需要统计分数的班级信息"<<endl;
	 cout<<"请输入专业编号：";
	 cin>>major_number;
	 cout<<"请输入班级编号：";
	 cin>>class_number;
	 vector<major>::iterator p=maj.begin();
	 while(p!=maj.end())
	 {
	       if(p->getID()==major_number)
			   break;
		   else
			   p++;
	 }
	 if(p==maj.end())
	 {
	       cout<<"没有相关的专业信息，请核对后输入"<<endl;
		   system("pause");
		   system("cls");
		   return;
	 }
	 vector<Class>::iterator p2=Cla.begin();
	 while(p2!=Cla.end())
	 {
	       if(p2->getID()==class_number)
			   break;
		   else
			   p2++;
	 }
	 if(p2==Cla.end())
	 {
	       cout<<"没有相关的班级信息，请核对后输入"<<endl;
		   system("pause");
		   system("cls");
		   return;	 
	 }
	 int choose,subject;
	 cout<<"请输入学生类型（本科生-1 or 研究生-2）：";
	 cin>>choose;
	 if(choose==1)
	 {
		  while(1)
	      {
	              cout<<"请输入您需要统计信息的科目（C语言-1，高数-2，英语-3）：";
		          cin>>subject;
		          if(subject==1||subject==2||subject==3)
			            break;
		          else
			            cout<<"输入有误，请重新输入！"<<endl;
	       }
	       vector<undergraduate>::iterator p=stu1.begin();
		   vector<undergraduate>student;
		   int count=0;   //统计不及格人数
		   while(p!=stu1.end())
		   {
		        if(p->getMajorNumber()==major_number&&p->getClassNumber()==class_number&&p->getScore(subject-1)<=60)
				{
				        student.push_back(*p);
						count++;
				}
				p++;
		   }
		   if(!count)
		   {
		       cout<<"该班级没有不及格名单！"<<endl;
			   system("pause");
			   system("cls");
			   return;
		   }
		   Display(3,count,student.begin(),student.end());
	 }
	 else if(choose==2)
	 {
		  while(1)
	      {
	              cout<<"请输入您需要统计信息的科目（课程设计-1，论文成绩-2）：";
		          cin>>subject;
		          if(subject==1||subject==2)
			            break;
		          else
			            cout<<"输入有误，请重新输入！"<<endl;
	       }
	       vector<graduate>::iterator p=stu2.begin();
		   vector<graduate>student;
		   int count=0;   //统计不及格人数
		   while(p!=stu2.end())
		   {
		        if(p->getMajorNumber()==major_number&&p->getClassNumber()==class_number&&p->getScore(subject-1)<=60)
				{
				        student.push_back(*p);
						count++;
				}
				p++;
		   }
		   if(!count)
		   {
		       cout<<"该班级没有不及格名单！"<<endl;
			   system("pause");
			   system("cls");
			   return;
		   }
		   Display(4,count,student.begin(),student.end());	 
	 }
	 else
	 {
	      cout<<"输入的学生类型有误，请核对后输入！"<<endl;
		  system("pause");
		  system("cls");
		  return;
	 }
}

void Interface::statistic4()
{
     string major_number;
	 string class_number;
	 cout<<"请输入需要统计分数的班级信息"<<endl;
	 cout<<"请输入专业编号：";
	 cin>>major_number;
	 cout<<"请输入班级编号：";
	 cin>>class_number;
	 vector<major>::iterator p=maj.begin();
	 while(p!=maj.end())
	 {
	       if(p->getID()==major_number)
			   break;
		   else
			   p++;
	 }
	 if(p==maj.end())
	 {
	       cout<<"没有相关的专业信息，请核对后输入"<<endl;
		   system("pause");
		   system("cls");
		   return;
	 }
	 vector<Class>::iterator p2=Cla.begin();
	 while(p2!=Cla.end())
	 {
	       if(p2->getID()==class_number)
			   break;
		   else
			   p2++;
	 }
	 if(p2==Cla.end())
	 {
	       cout<<"没有相关的班级信息，请核对后输入"<<endl;
		   system("pause");
		   system("cls");
		   return;	 
	 }
	 int choose,subject;
	 cout<<"请输入学生类型（本科生-1 or 研究生-2）：";
	 cin>>choose;
	 if(choose==1)
	 {
		  while(1)
	      {
	              cout<<"请输入您需要统计信息的科目（C语言-1，高数-2，英语-3）：";
		          cin>>subject;
		          if(subject==1||subject==2||subject==3)
			            break;
		          else
			            cout<<"输入有误，请重新输入！"<<endl;
	       }
		  vector<undergraduate>::iterator p=stu1.begin();
		  static int count[5];
		  while(p!=stu1.end())
		  {
		          if(p->getMajorNumber()==major_number&&p->getClassNumber()==class_number&&p->getMajorNumber()==major_number&&p->getClassNumber()==class_number)
				  {
				        if(p->getScore(subject-1)==100)
							count[4]++;
						else if(p->getScore(subject-1)<60)
							count[0]++;
						else
							count[subject-1]++;
				  }
				  p++;
		  }
		  cout<<"统计完成，信息如下"<<endl;
		  cout<<"优秀人数为： "<<count[4]<<"位"<<endl;
		  cout<<"良好人数为： "<<count[3]<<"位"<<endl;
		  cout<<"中等人数为： "<<count[2]<<"位"<<endl;
		  cout<<"及格人数为： "<<count[1]<<"位"<<endl;
		  cout<<"不及格人数为： "<<count[0]<<"位"<<endl;
		  system("pause");
		  system("cls");
		  return;
	 }
	 else if(choose==2)
	 {
		  while(1)
	      {
	              cout<<"请输入您需要统计信息的科目（课程设计-1，论文成绩-2）：";
		          cin>>subject;
		          if(subject==1||subject==2)
			            break;
		          else
			            cout<<"输入有误，请重新输入！"<<endl;
	       }
		  vector<graduate>::iterator p=stu2.begin();
		  static int count[5];
		  while(p!=stu2.end())
		  {
		          if(p->getMajorNumber()==major_number&&p->getClassNumber()==class_number&&p->getMajorNumber()==major_number&&p->getClassNumber()==class_number)
				  {
				        if(p->getScore(subject-1)==100)
							count[4]++;
						else if(p->getScore(subject-1)<60)
							count[0]++;
						else
							count[subject-1]++;
				  }
				  p++;
		  }
		  cout<<"统计完成，信息如下"<<endl;
		  cout<<"优秀人数为： "<<count[4]<<"位"<<endl;
		  cout<<"良好人数为： "<<count[3]<<"位"<<endl;
		  cout<<"中等人数为： "<<count[2]<<"位"<<endl;
		  cout<<"及格人数为： "<<count[1]<<"位"<<endl;
		  cout<<"不及格人数为： "<<count[0]<<"位"<<endl;
		  system("pause");
		  system("cls");
		  return;	 
	 }
}
