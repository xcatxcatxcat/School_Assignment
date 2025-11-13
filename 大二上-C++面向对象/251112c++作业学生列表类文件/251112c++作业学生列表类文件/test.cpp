#include "StudentList.h"
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    CStudentList list1;
    list1.StudentAdd(CStudent("Alice", 101, 95.5));
    list1.StudentAdd(CStudent("Bob", 102, 88.0));
    list1.StudentAdd(CStudent("Charlie", 103, 92.3));
    list1.display_all();

    //文本文件 test
    //写入文本文件
    ofstream ofs("students.txt");
    if (list1.write_text(ofs)) cout << "写入文本文件成功" << endl;
    //读出文本文件
    ofs.close();
    ifstream ifs("students.txt");
    CStudentList list2;
    list2.StudentAdd(CStudent("A", 1, 9.5));
    list2.StudentAdd(CStudent("B", 2, 8.0));
    list2.StudentAdd(CStudent("C", 3, 9.3));
    if (list2.read_text(ifs)) cout << "读取文本文件成功" << endl;
    list2.display_all();
    ifs.close();

    //二进制文件 test
    //写入二进制文件
    ofs.open("students.bin");
    if (list1.write_binary(ofs)) cout << "写入二进制文件成功" << endl;
    //读出二进制文件
    ofs.close();
    ifs.open("students.bin");
    CStudentList list3;
    list3.StudentAdd(CStudent("A", 1, 9.5));
    list3.StudentAdd(CStudent("B", 2, 8.0));
    list3.StudentAdd(CStudent("C", 3, 9.3));
    if(list3.read_binary(ifs)) cout<<"读取二进制文件成功"<<endl;
    list3.display_all();

    //转换十六进制
    ifs.clear();
    ifs.seekg(0);
    cout << hex << setfill('0');
    unsigned char byte;
    while (ifs.read((char*)&byte,sizeof(char)))
    {

        cout <<setw(2)<< (unsigned int)byte << " ";
    }
    ifs.close();

    return 0;
}