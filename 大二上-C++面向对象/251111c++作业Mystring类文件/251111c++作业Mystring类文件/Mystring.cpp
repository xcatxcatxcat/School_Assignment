#include "Mystring.h"
#include <iostream>
#include <iomanip>
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

//比较c字符串
int str_cmp(const char* s1, const char* s2)
{
	size_t len1 = get_clen(s1);
	size_t len2 = get_clen(s2);
	size_t len = min(len1, len2);
	for (size_t i = 0; i < len; ++i)
	{
		if (s1[i] == s2[i]) continue;
		else if (s1[i] > s2[i]) return 1;
		else return -1;
	}
	if (len1 == len2) return 0;
	if (len1 > len2) return 1;
	if (len1 > len2) return -1;
}

//析构
Mystring::~Mystring()
{
	//cout << "MyString类的析构函数被调用，当前字符串为：" << str << endl;
	delete[] str;
	str = nullptr;
}

//默认构造
Mystring::Mystring() :len(0), str(nullptr)
{
	//cout << "Mystring类的默认构造函数被调用" << endl;
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
	//cout << "Mystring类的有参构造函数被调用，当前字符串为：" << str << endl;
}

//复制构造
Mystring::Mystring(const Mystring& s)
{
	len = s.len;
	str = new char[len + 1];
	for (size_t i = 0; i < len; ++i)
	{
		str[i] = s.str[i];
	}
	str[len] = '\0';
	//cout << "MyString类的复制构造函数被调用，当前字符串为：" << str << endl;
}

//复制赋值运算符
Mystring& Mystring::operator=(const Mystring& s)
{
	//cout << "MyString类的赋值运算符被调用，当前字符串为：" << s.str << endl;
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
	//cout << "MyString类的移动构造函数被调用，当前字符串为：" << str << endl;
	s.len = 0;
	s.str = nullptr;
}

//移动赋值运算符
Mystring& Mystring::operator=(Mystring&& s) noexcept
{
	//cout << "MyString类的移动赋值运算符函数被调用，当前字符串为：" << s.str << endl;
	if (this == &s)
	{
		return *this;
	}
	else
	{
		len = s.len;
		str = s.str;
		s.len = 0;
		s.str = nullptr;
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

//转型赋值运算符
Mystring& Mystring::operator= (const char* s)
{
	if (s == nullptr)
	{
		char* NEW = new char[0];
		NEW[0] = '\0';
		len = 0;
		delete[] str;
		str = NEW;
	}
	else
	{
		size_t LEN = get_clen(s);
		char* NEW = new char[LEN + 1];
		for (size_t i = 0; i < LEN; ++i)
		{
			NEW[i] = s[i];
		}
		NEW[LEN] = '\0';
		len = LEN;
		delete[] str;
		str = NEW;
	}
	return *this;
}

//加法运算符
Mystring Mystring::operator+(const Mystring& other) const
{
	char* NEW = new char[len + other.len + 1];
	for (size_t i = 0; i < len; ++i)
	{
		NEW[i] = str[i];
	}
	for (size_t i = 0; i < other.len; ++i)
	{
		NEW[len + i] = other.str[i];
	}
	NEW[len + other.len] = '\0';
	Mystring S(NEW);
	delete[] NEW;
	return S;
}
Mystring Mystring::operator+(const char* s) const
{
	if (s == nullptr)
	{
		return *this;
	}
	else
	{
		size_t LEN = get_clen(s);
		char* NEW = new char[len + LEN + 1];
		for (size_t i = 0; i < len; ++i)
		{
			NEW[i] = str[i];
		}
		for (size_t i = 0; i < LEN; ++i)
		{
			NEW[len + i] = s[i];
		}
		NEW[len + LEN] = '\0';
		Mystring S(NEW);
		delete[] NEW;
		return S;
	}
}

//下标运算符
char& Mystring::operator[](size_t idx)
{
	if (idx >= len)
	{
		throw "out of range";
	}
	else
	{
		return str[idx];
	}
}
const char& Mystring::operator[](size_t idx) const
{
	if (idx >= len)
	{
		throw "out of range";
	}
	else
	{
		return str[idx];
	}
}

//函数调用运算符
void Mystring::operator()(const char* s)
{
	*this = s;
}

//字面量运算符
inline Mystring operator"" _s(const char* s, size_t l)
{
	return Mystring(s);
}

//比较运算符
bool Mystring::operator< (const Mystring& other) const
{
	if (str_cmp(str, other.str) == -1) return true;
	else return false;
}
bool Mystring::operator<=(const Mystring& other) const
{
	if (str_cmp(str, other.str) <= 0) return true;
	else return false;
}
bool Mystring::operator>(const Mystring& other) const
{
	if (str_cmp(str, other.str) == 1) return true;
	else return false;
}
bool Mystring::operator>=(const Mystring& other) const
{
	if (str_cmp(str, other.str) >= 0) return true;
	else return false;
}

//重载提取符
std::istream& operator >>(std::istream& is, Mystring& s)
{
	char tmp[1024];
	is >>setw(1024)>> tmp;
	if(is) s = tmp;
	return is;
}
//重载插入符
std::ostream& operator <<(std::ostream& os,const Mystring& s)
{
	os << s.get_string();
	return os;
}