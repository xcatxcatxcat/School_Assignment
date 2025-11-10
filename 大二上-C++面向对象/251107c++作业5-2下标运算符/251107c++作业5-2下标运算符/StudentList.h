#pragma once
#include "Student.h"

class CStudentList
{
private:
	CStudent* students;
	size_t size;
	size_t capacity;
	void resize();
public:
	//析构
	~CStudentList();

	//默认构造
	CStudentList();

	//不应该实现复制，因为同一份列表不能有多个，否则学生会重复，析构时还会出问题
		////复制构造，应该实现深复制
		//CStudentList(const CStudentList& other);
		////复制赋值运算符，应该实现深复制
		//CStudentList& operator=(const CStudentList& other);
	CStudentList(const CStudentList& other) = delete;
	CStudentList& operator=(const CStudentList& other) = delete;

	//移动构造
	CStudentList(CStudentList&& other) noexcept;
	//移动赋值运算符
	CStudentList& operator=(CStudentList&& other) noexcept;

	//增加学生
	bool StudentAdd(const CStudent& NEW);

	//按学号删除
	bool StudentDelete_FromId(int id);

	//按学号修改学生信息
	bool StudentRevise_FromId(int id, const char* NewName, double score);

	//显示学生信息
	bool display(int id) const;
	bool display(double score) const;

	//按学号查找学生是否存在
	bool IsExist(int id) const;

	//显示所有学生
	void display_all() const;

	//下标运算符
	inline CStudent& operator[] (size_t idx)
	{
		if (idx >= size)
		{
			throw "out of range";
		}
		else return students[idx];
	}
	inline const CStudent& operator[](size_t idx) const
	{
		if (idx > size)
		{
			throw "out of range";
		}
		else return students[idx];
	}

	//按学号排序
	void SortById();

	//返回人数
	inline size_t get_size()
	{
		return size;
	}
};