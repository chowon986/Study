// 4강 실습(2)
#include <iostream>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class myString 
{
	char* str;
	int len;

public:
	myString(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
	myString(const char* s);
	myString(const myString& s);
	~myString();

	void add_string(const myString& s);   // str 뒤에 s 를 붙인다.
	void copy_string(const myString& s);  // str 에 s 를 복사한다.
	int strlen();                       // 문자열 길이 리턴
};

myString::myString(char c, int n)
{
	str = new char[n + 1];
	for (int i = 0; i < n; i++)
	{
		str[i] = c;
	}

	str[n] = '\0';
	len = n;
}

myString::myString(const char* s)
{
	len = 0;
	for (int i = 0; ; i++)
	{
		if (s[i] != '\0')
			++len;
		else
			break;
	}

	str = new char[len + 1];

	for (int i = 0; i < len; i++)
	{
		str[i] = s[i];
	}

	str[len] = '\0';
}

myString::myString(const myString& s)
{
	str = s.str;
	len = s.len;
}

myString::~myString()
{
	if (str != NULL)
		delete[] str;
}

void myString::add_string(const myString& s)
{
	if (str == nullptr)
		return;

	int gap = len;
	len += s.len;

	for (int i = 0; i < len; i++)
	{
		str[gap + i] = s.str[i];
	}
}

void myString::copy_string(const myString& s)
{
	str = s.str;
	len = s.len;
}

int myString::strlen()
{
	return len;
}

int main()
{
	myString a('a', 3);
	myString b("abc");

	a.add_string("string");
	a.copy_string(b);
}

