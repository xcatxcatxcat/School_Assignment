#pragma once
#include "Mystring.h"

class CStudent
{
private:
	Mystring name;
	int id;
	double score;
public:
	//析构
	~CStudent() = default;

	//默认构造
	CStudent() = default;

	//转型构造，不复杂，类中实现
	inline CStudent(Mystring other_name, int other_id, double other_score) :
		name(other_name), id(other_id), score(other_score) {
	}

	//复制构造
	CStudent(const CStudent& other) = default;
	//复制赋值运算符
	CStudent& operator=(const CStudent& other) = default;

	//移动构造
	CStudent(CStudent&& other) noexcept = default;
	//移动赋值运算符
	CStudent& operator=(CStudent&& other) noexcept = default;

	//获取id，不复杂，类中实现
	inline int get_id() const
	{
		return id;
	}

	//修改名字
	inline void set_name(const char* other_name)
	{
		name = other_name;//转型再移动
	}

	//修改分数
	inline void set_score(double other_score)
	{
		score = other_score;
	}

	//获取name
	inline const char* get_name() const
	{
		return name.get_string();
	}

	//获取score
	inline double get_score() const
	{
		return score;
	}
};