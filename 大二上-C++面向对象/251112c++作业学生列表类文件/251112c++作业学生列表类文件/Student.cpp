#include "Student.h"

//写入文本文件
bool CStudent::write_text(std::ostream & os) const
{
	if (!name.write_text(os)) return false;
	os << id << " " << score << "\n";
	return true;
}
//读取文本文件
bool CStudent::read_text(std::istream& is)
{
	if (!name.read_text(is)) return false;
	is >> id;
	if (!is.get()) return false;
	is >> score;
	if (!is.get()) return false;
	return true;
}

//写入二进制文件
bool CStudent::write_binary(std::ostream& os) const
{
	if (!name.write_binary(os)) return false;
	os.write((char*)&id, sizeof(int));
	os.write((char*)&score, sizeof(double));
	return true;
}
//读取二进制文件
bool CStudent::read_binary(std::istream& is)
{
	if (!name.read_binary(is)) return false;
	if(!is.read((char*)&id, sizeof(int))) return false;
	if(!is.read((char*)&score, sizeof(double))) return false;
	return true;
}