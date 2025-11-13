#pragma once
#include <iostream>
class Mystring
{
private:
	size_t len;
	char* str;
public:
	//析构
	~Mystring();

	//默认构造
	Mystring();

	//转型构造
	Mystring(const char* s);

	//复制构造
	Mystring(const Mystring& s);

	//复制赋值运算符
	Mystring& operator=(const Mystring& s);

	//移动构造
	Mystring(Mystring&& s) noexcept;

	//移动赋值运算符
	Mystring& operator=(Mystring&& s) noexcept;

	//设置字符串
	void set_string(const char* s);

	//获取字符串长度，不复杂，内部实现，内联函数
	inline size_t get_length(void) const
	{
		return len;
	}

	//获取字符串，不复杂，内部实现，内联函数
	inline const char* get_string(void) const
	{
		return str;
	}

	//追加c语言字符串
	void append(const char* s);
	//追加类字符串
	void append(const Mystring& s);

	//转型赋值运算符
	Mystring& operator=(const char* s);

	//加法运算符
	Mystring operator+(const Mystring& other) const;
	Mystring operator+(const char* s) const;

	//下标运算符
	char& operator[](size_t idx);
	const char& operator[](size_t idx) const;

	//函数调用运算符
	void operator() (const char* s);

	//字面量运算符，外部函数
	friend Mystring operator"" _s(const char* s, size_t l);

	//比较运算符
	bool operator<(const Mystring& ohter) const;
	bool operator<=(const Mystring& other) const;
	bool operator>(const Mystring& other) const;
	bool operator>=(const Mystring& other) const;

	//自动类型转换
	inline operator const char* () const
	{
		return str;
	}

	//重载提取符
	friend std::istream& operator >> (std::istream& is, Mystring& s);
	//重载插入符
	friend std::ostream& operator <<(std::ostream& os, const Mystring& s);

	//写入文本文件
	bool write_text(std::ostream& os) const;
	//读出文本文件
	bool read_text(std::istream& is);

	//写入二进制文件
	bool write_binary(std::ostream& os) const;
	//读出文本文件
	bool read_binary(std::istream& is);
};
