#pragma once
#include "StudentList.h"

class Association
{
private:
	Mystring name;
	CStudentList& L;

public:
	//析构、默认构造和移动，默认实现就可以

	//复制不允许实现，因为同一个社团不能有多个
	Association(const Association& other) = delete;
	Association& operator=(const Association& other) = delete;

	//转型构造
	inline Association(Mystring s, CStudentList& other) :L(other), name(s) {};

	//添加社团成员
	inline bool AddStudent(const CStudent& NEW)
	{
		return L.StudentAdd(NEW);
	}

	//按学号删除社团成员
	inline bool DeleteStudent(int id)
	{
		return L.StudentDelete_FromId(id);
	}

	//显示社团成员
	void Show();

	//下标运算符
	inline CStudent& operator[](size_t idx)
	{
		if (idx >= L.get_size()) throw "out of range";
		else return L[idx];
	}
	inline const CStudent& operator[](size_t idx) const
	{
		if (idx >= L.get_size()) throw "out of range";
		else return L[idx];
	}
};