#include <iostream>
#include <fstream>
#include <iomanip>
#include "Mystring.h"
using namespace std;

//测试文本文件
bool TestTextFile()
{
	Mystring s1("xcatxcat");
	Mystring s2("lo pan");
	Mystring s3("123");
	ofstream ofs("test.txt");
	if (!ofs) return false;
	//写入文本文件，需要保存字符串长度，空白符相隔，否则当字符串中有空白符时，读入会出错
	ofs << s1.get_length() << " " << s1<<'\n';
	ofs << s2.get_length() << " " << s2<<'\n';
	ofs << s3.get_length() << " " << s3<<'\n';
	ofs.close();
	//读取文本文件
	ifstream ifs("test.txt");
	for (size_t i = 0; i < 3; ++i)
	{
		if (!ifs) return false;
		size_t len;
		ifs >> len;
		ifs.get();
		if (len == 0) cout << "" << endl;
		else
		{
			char* s = new char[len + 1];
			ifs.read(s, len);
			s[len] = '\0';
			cout << s << endl;
			delete[] s;
			ifs.get();
		}
	}
	return true;
}

//测试二进制文件
bool TestBinaryFile()
{
	Mystring s1("xcatxcat");
	Mystring s2("lo pan");
	Mystring s3("123");
	ofstream ofs("test.bin", ios::binary);
	if (!ofs) return false;
	//写入二进制文件
	size_t len = s1.get_length();
	ofs.write((char*)&len, sizeof(size_t));
	ofs.write(s1, len);
	len = s2.get_length();
	ofs.write((char*)&len, sizeof(size_t));
	ofs.write(s2, len);
	len = s3.get_length();
	ofs.write((char*)&len, sizeof(size_t));
	ofs.write(s3, len);
	ofs.close();
	//读取二进制文件
	ifstream ifs("test.bin", ios::binary);
	if (!ifs) return false;
	size_t len2;
	while (ifs.read((char*)&len2, sizeof(size_t)))
	{
		char* s = new char[len2 + 1];
		ifs.read(s, sizeof(char) * len2);
		s[len2] = '\0';
		cout << s << endl;
		delete[] s;
	}
	//十六进制输出
	ifs.clear();
	ifs.seekg(0);
	cout << hex << setfill('0');
	char byte;
	while (ifs.get(byte))
	{
		cout << setw(2) << (unsigned int)byte << " ";
	}
	return true;
}

int main()
{
	TestTextFile();
	TestBinaryFile();
	return 0;
}