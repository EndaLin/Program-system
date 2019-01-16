#pragma once

void showAllByCategory(enum studentcategory category);    /*函数功能：显示全部本科生或者研究生的学生信息*/

void showByClass(enum studentcategory category,char *specialty,char *classes);   /*函数功能：显示本班学生的个人信息*/

void showById(int id);    /*函数功能：根据id显示个人信息*/

void showByName(char *name);    /*函数功能：根据名字显示个人信息*/

void showFailByClassCourse(char *specialty,char *classes,int course); /*函数功能：显示某班级某门科目不及格的名单*/