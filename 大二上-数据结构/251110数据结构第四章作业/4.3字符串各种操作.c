#include <stdio.h>
#include <stdlib.h>

//求字符串长度
int StrLength(const char *s)
{
	if (s == NULL) return -1;
	int len = 0;
	while (s[len]) ++len;
	return len;
}

//求字子串，从idx开始取len位（idx从1开数）
char* SubString(const char *s, size_t idx, size_t len)
{
	int length = StrLength(s);
	if (idx > length) return NULL;
	int rlen = length - idx;
	if (rlen > len) rlen = len;
	char* sub = (char*)malloc(sizeof(char) * (rlen+1));
	//0 1 2 3 4 5 |3 2|-> 2 3
	for (size_t i = 0; i < rlen; ++i)
	{
		sub[i] = s[i + idx - 1];
	}
	sub[rlen] = '\0';
	return sub;
}

//找第一个对应索引
int Index(const char *s, char c)
{
	if (s == NULL) return -1;
	size_t i = 0;
	while (s[i])
	{
		if (s[i] == c) return i;
		++i;
	}
	return -1;
}

//从当前指针找特定字符串
const char* StrStr(const char* s, const char* target)
{
	if (!s || !target) return NULL;
	if (*target == "\0") return s;
	char* p = s;
	while (*p)
	{
		char* ps = p;
		char* pt = target;
		while (*ps && *pt && (*ps == *pt))
		{
			++ps;
			++pt;
		}
		if (*pt == '\0') return p;
		++p;
	}
	return NULL;
}

//找第一个对应索引，子串版
int IndexStr(const char* s, const char* target)
{
	char* p = StrStr(s, target);
	if (!p) return -1;
	return (p - s);
}

//用q替代s中特定字符串
char* Replace(const char *s, const char* target, const char *q)
{
	if (!s || !target || !q) return NULL;
	//找s中有几个特定字符串
	size_t len = StrLength(target);
	size_t cnt = 0;
	char* p = s;
	p = StrStr(p, target);
	while (p!=NULL)
	{
		++cnt;
		p += len;
		p = StrStr(p, target);
	}
	//替换
	size_t slen = StrLength(s);
	if (cnt == 0)
	{
		char* NEW = (char*)malloc(sizeof(char) * (slen + 1));
		for (size_t i = 0; i < slen; ++i)
		{
			NEW[i] = s[i];
		}
		NEW[slen] = '\0';
		return NEW;
	}
	else
	{
		size_t qlen = StrLength(q);
		char* NEW = (char*)malloc(sizeof(char) * (slen - len * cnt + qlen * cnt + 1));
		p = s;
		char* pN = NEW;
		while (*p)
		{
			//遇到该替换的
			if (p == StrStr(p, target))
			{
				char* pq = q;
				while (*pq)
				{
					*pN = *pq;
					++pN;
					++pq;
				}
				p += len;
			}
			//不该替换的
			else
			{
				*pN = *p;
				++pN;
				++p;
			}
		}
		*pN = '\0';
		return NEW;
	}
}\

//连接
char* Concat(const char* s1, const char* s2)
{
	if (!s1 || *s1 == '\0') return s2;
	if (!s2 || *s2 == '\0') return s1;
	size_t s1_len = StrLength(s1);
	size_t s2_len = StrLength(s2);
	char* NEW = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1));
	for (size_t i = 0; i < s1_len; ++i)
	{
		NEW[i] = s1[i];
	}
	for (size_t i = 0; i < s2_len; ++i)
	{
		NEW[s1_len + i] = s2[i];
	}
	NEW[s1_len + s2_len] = '\0';
	return NEW;
}

int main()
{
	const char* s = "I AM A STUDENT";
	const char* t = "GOOD";
	const char* q = "WORKER";
	printf("StrLength(s):%d\n", StrLength(s));
	printf("StrLength(t):%d\n", StrLength(t));
	printf("SubString(s,8,7):%s\n", SubString(s, 8, 7));
	printf("SubString(t,2,1):%s\n", SubString(t, 2, 1));
	printf("Index(s,'A'):%d\n", Index(s, 'A'));
	printf("IndexStr(s,t):%d\n", IndexStr(s, t));
	printf("Replace(s,\"STUDENT\",q):%s\n", Replace(s, "STUDENT", q));
	printf("Concat(SubString(s,6,2),Concat(t,SubString(s,7,8))):%s\n", Concat(SubString(s, 6, 2), Concat(t, SubString(s, 7, 8))));
	return 0;
}