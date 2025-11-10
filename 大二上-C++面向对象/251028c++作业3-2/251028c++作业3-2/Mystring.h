#pragma once
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
};
