#pragma once
#include"linker.h"

void show_one_student(Student *p);  /*函数功能：显示某位学生的信息*/

void getPage(int page,enum studentcategory category);  /*函数功能：显示当前页的学生信息*/

void getPageByClasses(enum studentcategory category,char *specialty,char *classes,int page);  /*函数功能：显示指定班级当前页的学生信息*/

void getPageFailByClassCourse(char *specialty,char *classes,int course,int page);   /*函数功能：显示某门科目某班级不及格的学生信息*/