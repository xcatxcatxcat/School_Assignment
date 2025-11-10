#include "Association.h"
#include <iostream>
using namespace std;

int main()
{
    CStudentList L;
    L.StudentAdd(CStudent("李四", 102, 88.0));
    L.StudentAdd(CStudent("王五", 103, 92.0));
    L.StudentAdd(CStudent("张三", 101, 95.5));
    Association A("club",L);
    //下标取
    cout << A[0].get_name() << endl;
    //排序前
    L.display_all();
    L.SortById();
    //排序后
    L.display_all();
    return 0;
}