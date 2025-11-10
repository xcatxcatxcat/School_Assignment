#include "CStudentList.h"
#include <iostream>
using namespace std;

int main()
{
	Mystring  str2("sdf");

	Mystring str(move(str2));
	//str = str2;

	//默认构造
	CStudentList L; 

	L.display_all();

	//增加学生
	L.StudentAdd(CStudent("xcatxcat", 24281225, 90.5));
	L.StudentAdd(CStudent("lopan", 24281111, 99.0));
	L.StudentAdd(CStudent("a", 24281112, 98.0));
	L.StudentAdd(CStudent("b", 24281113, 97.0));
	L.StudentAdd(CStudent("c", 24281114, 96.0));

	L.display_all();

	//按学号删除
	L.StudentDelete_FromId(24281111);
	
	L.display_all();

	//按学号修改学生信息
	L.StudentRevise_FromId(24281225, "lopan", 99.0);

	L.display_all();

	//显示学生信息
	L.display(24281112);
	L.display(96.0);

	return 0;
}