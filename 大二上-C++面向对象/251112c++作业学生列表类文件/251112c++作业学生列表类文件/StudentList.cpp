#include "StudentList.h"
//#include <iostream>
#include <algorithm>
using namespace std;

//私有扩容函数
void CStudentList::resize()
{
	capacity *= 2;
	CStudent* NEW = new CStudent[capacity];
	for (size_t i = 0; i < size; ++i)
	{
		NEW[i] = students[i];
	}
	delete[] students;
	students = NEW;
	return;
}

//析构
CStudentList::~CStudentList()
{
	delete[] students;
	students = nullptr;
}

//默认构造
CStudentList::CStudentList() :size(0), capacity(4), students(nullptr)
{
	students = new CStudent[4];
}

////复制构造
//CStudentList::CStudentList(const CStudentList& other) :
//	size(other.size), capacity(other.capacity), students(nullptr)
//{
//	students = new CStudent[capacity];
//	for (size_t i = 0; i < size; ++i)
//	{
//		students[i] = other.students[i];
//	}
//}
//
////复制赋值运算符
//CStudentList& CStudentList::operator=(const CStudentList& other)
//{
//	if (this == &other)
//	{
//		return *this;
//	}
//	else
//	{
//		size = other.size;
//		capacity = other.capacity;
//		CStudent* NEW = new CStudent[capacity];
//		for (size_t i = 0; i < size; ++i)
//		{
//			NEW[i] = other.students[i];
//		}
//		delete[] students;
//		students = NEW;
//		return *this;
//	}
//}

//移动构造
CStudentList::CStudentList(CStudentList&& other) noexcept :
	size(other.size), capacity(other.capacity), students(other.students)
{
	other.students = nullptr;
	other.capacity = 0;
	other.size = 0;
}

//移动赋值运算符
CStudentList& CStudentList::operator=(CStudentList&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}
	else
	{
		size = other.size;
		capacity = other.capacity;
		students = other.students;
		return *this;
	}
}

//按学号查找学生是否存在
bool CStudentList::IsExist(int id) const
{
	size_t i = 0;
	for (; i < size; ++i)
	{
		if (students[i].get_id() == id)
		{
			break;
		}
	}
	if (i < size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//增加学生
bool CStudentList::StudentAdd(const CStudent& NEW)
{
	if (IsExist(NEW.get_id()))
	{
		return false;
	}
	if (size >= capacity)
	{
		resize();
	}
	students[size] = NEW;
	size++;
	return true;
}

//按学号删除学生
bool CStudentList::StudentDelete_FromId(int id)
{
	size_t i = 0;
	for (; i < size; ++i)
	{
		if (students[i].get_id() == id)
		{
			break;
		}
	}
	if (i == size)
	{
		return false;
	}
	else
	{
		students[i] = move(students[size - 1]);
		size--;
		return true;
	}
}

//按学号修改学生信息
bool CStudentList::StudentRevise_FromId(int id, const char* name, double score)
{
	size_t i = 0;
	for (; i < size; ++i)
	{
		if (students[i].get_id() == id)
		{
			break;
		}
	}
	if (i == size)
	{
		return false;
	}
	else
	{
		students[i].set_name(name);
		students[i].set_score(score);
		return true;
	}
}

//显示学生信息
bool CStudentList::display(int id) const
{
	size_t i = 0;
	for (; i < size; ++i)
	{
		if (students[i].get_id() == id)
		{
			break;
		}
	}
	if (i == size)
	{
		return false;
	}
	else
	{
		cout << id << "\t" << students[i].get_name() << "\t" << students[i].get_score() << endl;
		return true;
	}
}
bool CStudentList::display(double score) const
{
	size_t i = 0;
	for (; i < size; ++i)
	{
		if (students[i].get_score() == score)
		{
			break;
		}
	}
	if (i == size)
	{
		return false;
	}
	else
	{
		cout << students[i].get_id() << "\t" << students[i].get_name() << "\t" << score << endl;
		return true;
	}
}

//显示所有学生
void CStudentList::display_all() const
{
	cout << "All students:" << endl;
	for (size_t i = 0; i < size; ++i)
	{
		cout << students[i].get_id() << "\t"
			<< students[i].get_name() << "\t"
			<< students[i].get_score() << endl;
	}
	return;
}

//按学号排序
void CStudentList::SortById()
{
	sort(students, students + size,
		[](const CStudent& a, const CStudent& b) {
			return a.get_id() < b.get_id();
		});
}

//全部写入文本文件
bool CStudentList::write_text(std::ostream& os) const
{
	for (size_t i = 0; i < size; ++i)
	{
		if(!students[i].write_text(os)) return false;
	}
	return true;
}
//全部读出文本文件
bool CStudentList::read_text(std::istream& is)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (!students[i].read_text(is)) return false;
	}
	return true;
}

//全部写入二进制文件
bool CStudentList::write_binary(std::ostream& os)const
{
	for (size_t i = 0; i < size; ++i)
	{
		if (!students[i].write_binary(os)) return false;
	}
	return true;
}
//全部读出二进制文件
bool CStudentList::read_binary(std::istream& is)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (!students[i].read_binary(is)) return false;
	}
	return true;
}