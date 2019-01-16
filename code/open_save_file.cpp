#include"interface.h"

Interface::Interface()
{
      /*ofstream s1("undergraduate");
	  if(!s1)
	  {
	       cout<<"can not creat file1"<<endl;
		   return ;
	  }
	  ofstream s2("graduate");
	  if(!s2)
	  {
	       cout<<"can not creat file2"<<endl;
		   return ;
	  }
	  ofstream m("major");
	  if(!m)
	  {
	       cout<<"can not creat file3"<<endl;
		   return ;
	  }
	  ofstream C("Class");
	  if(!s1)
	  {
	       cout<<"can not creat file4"<<endl;
		   return ;
	  }
	  s1.close();
	  s2.close();
	  m.close();
	  C.close();   //此处为创建文件,创建完成后删除   */
	  ifstream student1("undergraduate");
	  if(!student1)
	  {
	       cout<<"can not open the file1 !"<<endl;
		   return;
	  }
	  ifstream student2("graduate");
	  if(!student2)
	  {
	       cout<<"can not open the file2 !"<<endl;
		   return ;
	  }
	  ifstream Major("major");
	  if(!Major)
	  {
	       cout<<"can not open the file3 !"<<endl;
		   return ;
	  }
	  ifstream cla("Class");
	  if(!cla)
	  {
	       cout<<"can not open the file4 !"<<endl;
		   return ;
	  }
	  int id;
	  string id1;
	  string name1;
	  string sex1;
	  string major_number1;
	  string class_number1;
	  string major1;
	  string Class1;
	  int gradeRanking1;
	  int classRanking1;
      //读取本科生文件中的数据
	  vector<int>score(4,0);
	  student1>>id>>name1>>sex1>>major_number1>>class_number1>>major1>>Class1>>gradeRanking1>>classRanking1>>score[0]>>score[1]>>score[2]>>score[3];
	  while(!student1.eof())
	  {
	       undergraduate student(id,name1,sex1,major_number1,class_number1,major1,Class1,gradeRanking1,classRanking1,score.begin(),score.end());
	       stu1.push_back(student);
		   count1++;   //记录本科生总人数
		   student1>>id>>name1>>sex1>>major_number1>>class_number1>>major1>>Class1>>gradeRanking1>>classRanking1>>score[0]>>score[1]>>score[2]>>score[3];
	  }
	  //读取研究生文件中的数据
	  score.clear();
	  score.resize(3);
	  student2>>id>>name1>>sex1>>major_number1>>class_number1>>major1>>Class1>>gradeRanking1>>classRanking1>>score[0]>>score[1]>>score[2];
	  while(!student2.eof())
	  {
		  graduate student(id,name1,sex1,major_number1,class_number1,major1,Class1,gradeRanking1,classRanking1,score.begin(),score.end());
		  stu2.push_back(student);
		  count2++;    //记录研究生总人数
	  	  student2>>id>>name1>>sex1>>major_number1>>class_number1>>major1>>Class1>>gradeRanking1>>classRanking1>>score[0]>>score[1]>>score[2];

	  }
	  //读取班级信息文件中的数据
	  string major_number;
	  cla>>major_number>>major1>>name1>>id1;
	  while(!cla.eof())
	  {
	       Class class1(major_number,major1,name1,id1);
		   Cla.push_back(class1);
		   count3++;     //记录班级总数
		   cla>>major_number>>major1>>name1>>id1;
	  }
	  //读取专业信息文件中的数据
	  Major>>name1>>id1;
	  while(!Major.eof())
	  {
	        major maj1(name1,id1);
			maj.push_back(maj1);
			count4++;    //记录专业总数
			Major>>name1>>id1;
	  }
	  //读取完毕，关闭文件
	  student1.close();
	  student2.close();
	  Major.close();
	  cla.close();
}

void Interface::save()    //保存文件
{
     ofstream out1("undergraduate");
	 if(!out1)
	 {
	      cout<<"打开文件1失败，无法保存数据"<<endl;
		  return ;
	 }
	 ofstream out2("graduate");
	 if(!out2)
	 {
	      cout<<"打开文件2失败，无法保存数据"<<endl;
		  return ;
	 }
	 ofstream out3("major");
	 if(!out3)
	 {
	      cout<<"打开文件3失败，无法保存数据"<<endl;
		  return ;
	 }
	 ofstream out4("Class");
	 if(!out4)
	 {
	      cout<<"打开文件4失败，无法保存数据"<<endl;
		  return ;
	 }
	 //存储本科生信息
	 vector<undergraduate>::iterator p=stu1.begin();
	 while(p!=stu1.end())
	 {
	       out1<<p->getID()<<" "<<p->getName()<<" "<<p->getSex()<<" "<<p->getMajorNumber()<<" "<<p->getClassNumber()<<" "<<p->getMajor()<<" "<<p->getClass()<<" "<<p->getRanking1()<<" "<<p->getranking2()<<" "<<p->getScore(0)<<" "<<p->getScore(1)<<" "<<p->getScore(2)<<" "<<p->getScore(3)<<endl;
		   p++;
	 }
	 printf("成功存储%d位本科生的信息！\n",count1);
	 out1.close();
	 //存储研究生信息
	 vector<graduate>::iterator p2=stu2.begin();
	 while(p2!=stu2.end())
	 {
	       out2<<p2->getID()<<" "<<p2->getName()<<" "<<p2->getSex()<<" "<<p2->getMajorNumber()<<" "<<p2->getClassNumber()<<" "<<p2->getMajor()<<" "<<p2->getClass()<<" "<<p2->getRanking1()<<" "<<p2->getranking2()<<" "<<p2->getScore(0)<<" "<<p2->getScore(1)<<" "<<p2->getScore(2)<<endl;
		   p2++;
	 }
	 out2.close();
	 printf("成功存储%d位研究生的信息！\n",count2);
	 //存储专业信息
	 vector<major>::iterator p3=maj.begin();
	 while(p3!=maj.end())
	 {
	      out3<<p3->getName()<<" "<<p3->getID()<<endl;
		  p3++;
	 }
	 out3.close();
	 printf("成功存储%d个专业信息！\n",count4);
	 //存储班级信息
	 vector<Class>::iterator p4=Cla.begin();
	 while(p4!=Cla.end())
	 {
		   out4<<p4->getMajor_number()<<" "<<p4->getMajor()<<" "<<p4->getName()<<" "<<p4->getID()<<endl;
		   p4++;
	 }
	 out4.close();
	 printf("成功存储%d个班级信息！\n",count3);
}