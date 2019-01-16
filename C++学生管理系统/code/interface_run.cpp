#include "interface.h"

void Interface::run()
{
	 int choose=1;
	 while(choose){
	     while(1){
		 menu();
		 cin>>choose;
	     if(choose==1||choose==2||choose==0){
			 break;
		 }
		 else
			 cout<<"输入有误，请重新输入！"<<endl;
	     }
		 system("cls");
	     if(choose==1)
			 Administrator();
		 else if(choose==2)
	         Teacher();
		 else 
			  break;
		 system("cls");
	 }
	 save();
	 cout<<"您已经退出师生管理系统，欢迎再次使用！"<<endl;
}

void Interface::Administrator()
{
    cout<<"         您已经成功进入管理员系统！        "<<endl;
	int choose,choose1=1;

	while(choose1){
	  while(1)
	  {
		 menu1();
		 cin>>choose;
	     if(!choose){
			 cout<<"您已经退出管理员系统"<<endl;
			 system("pause");
			 system("cls");
			 return ;
		 }
		 else if(choose!=1&&choose!=2)
			 cout<<"输入有误，请重新输入"<<endl;
		 else break;
	   }
	   system("cls");
	   if(choose==1){
		 while(choose1){ 
			cout<<endl;
			cout<<"        专业管理菜单     "<<endl; 
	        cout<<"========================="<<endl;
		    cout<<"       【1】添加专业     "<<endl;
		    cout<<"       【2】删除专业     "<<endl;
		    cout<<"       【3】查询专业     "<<endl;
		    cout<<"       【4】修改专业     "<<endl;
		    cout<<"       【0】 退 出       "<<endl;
		    cout<<"========================="<<endl;
		    cout<<"      请输入您的选择：";
		    cin>>choose1;
		    switch(choose1){
		         case 1:creatMajor();break;
		         case 2:Delete_Major();break;
		         case 3:Display(1,count4,maj.begin(),maj.end());break;
		         case 4:motify1();break;
			     case 0:break;
		    }    
			system("cls");
		  }
	   }
	   else {
		    while(choose1){
			   cout<<"        班级管理菜单     "<<endl;
	           cout<<"========================="<<endl;
		       cout<<"       【1】添加班级     "<<endl;
		       cout<<"       【2】删除班级     "<<endl;
		       cout<<"       【3】查询班级     "<<endl;
		       cout<<"       【4】修改班级     "<<endl;
		       cout<<"       【0】 退 出       "<<endl;
		       cout<<"========================="<<endl;
		       cout<<"      请输入您的选择：";
		       cin>>choose1;
		       switch(choose1){
		            case 1:creatClass();break;
		            case 2:Delete_Class();break;
		            case 3:Display(2,count3,Cla.begin(),Cla.end());break;
		            case 4:motify2();break;
			        case 0:break;
		       }    
			   system("cls");
		      }	
	    }
		cout<<"您已经退出管理员系统！"<<endl;
		system("pause");
		system("cls");
	}
}

void Interface::Teacher()
{   
     cout<<"         您已经进入人员管理系统        "<<endl;
	 int choose,choose1=1;
	 menu2();
	 cin>>choose;
	 system("cls");
	 while(choose==1&&choose1)  //学生信息管理模块
	 {
	      menu3();
		  cin>>choose1;
		  switch(choose1){
		             case 1:Input();break;
		             case 2:motify3();break;
					 case 3:motify4();break;
					 case 4:DisplayByID();break;
		             case 5:Delete_student();break;
					 case 6:InputScore();break;
		             case 0:break;
		   }
		  system("cls");
	 }
	while(choose==2&&choose1)
	 {
	       menu4();
		   cin>>choose1;
		   switch(choose1)
		   {
		   case 1:Display(3,count1,stu1.begin(),stu1.end());break;
		   case 2:Display(4,count2,stu2.begin(),stu2.end());break;
		   case 3:DisplayByClass();break;
		   case 4:DisplayByMajor();break;
		   case 5:DisplayByName();break;
		   case 6:DisplayByID();break;
		   case 7:DisplayFailStudent();break;
		   }
		   
	 }
	 while(choose==3&&choose1)
	 {
	       menu5();
		   cin>>choose1;
		   switch(choose1)
		   {
		   case 1:sortUndergraduate();
				  break;
		   case 2:sortGraduate();
				  break;
		   case 3:sortByClass_undergraduate();
			      break;
		   case 4:sortByClass_graduate();
			      break;
		   }
	 }
	 while(choose==4&&choose1)
	 {
	       menu6();
		   cin>>choose1;
		   switch(choose1)
		   {
		   case 1:statistic1();break;
		   case 2:statistic2();break;
		   case 3:statistic3();break;
		   case 4:statistic4();break;
		   }
	 }
	 return;
}
