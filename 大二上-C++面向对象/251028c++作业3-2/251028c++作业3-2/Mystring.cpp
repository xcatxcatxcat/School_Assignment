#include "Mystring.h"
#include <iostream>
using namespace std;

//求c字符串长度
size_t get_clen(const char* s)
{
	size_t len = 0;
	while (s[len])
	{
		len++;
	}
	return len;
}

//析构
Mystring::~Mystring()
{
	cout << "MyString类的析构函数被调用，当前字符串为：" << str << endl;
	delete[] str;
	str = nullptr;
}

//默认构造
Mystring::Mystring() :len(0), str(nullptr)
{
	cout << "Mystring类的默认构造函数被调用" << endl;
	str = new char[1];
	str[0] = '\0';
}

//转型构造
Mystring::Mystring(const char* s) :len(0), str(nullptr)
{
	if (s == nullptr)
	{
		len = 0;
		str = new char[1];
		str[0] = '\0';
	}
	else
	{
		len = get_clen(s);
		str = new char[len + 1];
		for (size_t i = 0; i < len; ++i)
		{
			str[i] = s[i];
		}
		str[len] = '\0';
	}
	cout << "Mystring类的有参构造函数被调用，当前字符串为：" << str << endl;
}

//复制构造
Mystring::Mystring(const Mystring& s):len(s.len),str(nullptr)
{
	str = new char[len + 1];
	for (size_t i = 0; i < len; ++i)
	{
		str[i] = s.str[i];
	}
	str[len] = '\0';
	cout << "MyString类的复制构造函数被调用，当前字符串为：" << str << endl;
}

//复制赋值运算符
Mystring& Mystring::operator=(const Mystring& s)
{
	cout << "MyString类的赋值运算符被调用，当前字符串为：" << s.str << endl;
	if (this == &s)
	{
		return *this;
	}
	else
	{
		delete[] str;
		len = s.len;
		str = new char[len + 1];
		for (size_t i = 0; i < len; ++i)
		{
			str[i] = s.str[i];
		}
		str[len] = '\0';
		return *this;
	}
}

//移动构造
Mystring::Mystring(Mystring&& s) noexcept :len(s.len), str(s.str)
{
	cout << "MyString类的移动构造函数被调用，当前字符串为：" << str << endl;
	s.len = 0;
	s.str = nullptr;// new char[1];
	//s.str[0] = '\0';
}

//移动赋值运算符
Mystring& Mystring::operator=(Mystring&& s) noexcept
{
	cout << "MyString类的移动赋值运算符函数被调用，当前字符串为：" << s.str << endl;
	if (this == &s)
	{
		return *this;
	}
	else
	{
		len = s.len;
		str = s.str;
		s.len = 0;
		s.str = new char[1];
		s.str[0] = '\0';
		return *this;
	}
}

//设置字符串
void Mystring::set_string(const char* s)
{
	delete[] str;
	if (s == nullptr)
	{
		len = 0;
		str = new char[1];
		str[0] = '\0';
	}
	else
	{
		len = get_clen(s);
		str = new char[len + 1];
		for (size_t i = 0; i < len; ++i)
		{
			str[i] = s[i];
		}
		str[len] = '\0';
	}
	return;
}

//追加c语言字符串
void Mystring::append(const char* s)
{
	size_t l = get_clen(s);
	char* NEW = new char[len + l + 1];
	for (size_t i = 0; i < len; ++i)
	{
		NEW[i] = str[i];
	}
	for (size_t i = 0; i < l; ++i)
	{
		NEW[len + i] = s[i];
	}
	NEW[len + l] = '\0';
	delete[] str;
	str = NEW;
	len = len + l;
	return;
}
//追加类字符串
void Mystring::append(const Mystring& s)
{
	this->append(s.str);
}