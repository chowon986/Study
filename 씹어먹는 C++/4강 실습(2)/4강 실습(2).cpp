// 4강 실습(2)
#include <iostream>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class myString 
{
	char* str;
	int len;
	int memory_capacity;

public:
	myString(char c);  // 문자  하나로 생성
	myString(const char* s);
	myString(const myString& s);
	~myString();

	void add_string(const myString& s);   // str 뒤에 s 를 붙인다.
	void copy_string(const myString& s);  // str 에 s 를 복사한다.
	int length() const;                   // 문자열 길이 리턴
	int strlen(const char* s);            // 문자열 길이 리턴
	int strlen(const string& s);   
	int capacity();
	int compare(const myString& s) const;
	void print();
	void assign(const char* s);
	void assign(const myString& s);
	void reserve(int size);
	char at(int i) const;
	myString& insert(int loc, const myString& s);
	myString& insert(int loc, const char* s);
	myString& insert(int loc, char c);

	myString& erase(int loc, int num);

	int find(int find_from, myString* s) const;
	int find(int find_from, const char* s) const;
	int find(int find_from, char c) const;
};

myString::myString(char c)
{
	str = new char[1];
	str[0] = c;
	len = 1;
	memory_capacity = 1;
}

myString::myString(const char* s)
{
	len = strlen(s);
	memory_capacity = len;
	str = new char[len];

	for (int i = 0; i < len; i++)
		str[i] = s[i];
}

myString::myString(const myString& s)
{
	str = new char[s.len];
	len = s.len;
	memory_capacity = len;
	for (int i = 0; i < len; i++)
		str[i] = s.str[i];
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

	if (memory_capacity < s.len)
	{
		int tempSize = len + s.len;
		delete[] str;

		str = new char[tempSize];
		memory_capacity = tempSize;
	}

	len = gap + s.len;
	
	for (int i = 0; i < len; i++)
	{
		str[gap + i] = s.str[i];

	}
}

void myString::copy_string(const myString& s)
{
	if (memory_capacity < s.len)
	{
		delete[] str;

		str = new char[s.len];
		memory_capacity = s.len;
	}

	len = s.len;

	for (int i = 0; i < len; i++)
		str[i] = s.str[i];
}

int myString::length() const
{
	return len;
}

int myString::strlen(const char* s)
{
	int len = 0;
	for (int i = 0; ; i++)
	{
		if (s[i] == '\0')
		{
			return len;
		}
		else
			++len;
	}

	return len;
}

int myString::strlen(const string& s)
{
	return s.length();
}

int myString::capacity()
{
	return memory_capacity;
}

int myString::compare(const myString& s) const
{
	for (int i = 0; i < min(len, s.len); i++)
	{
		if (str[i] > s.str[i]) return 1;
		else if (str[i] < s.str[i]) return -1;
	}

	if (len == s.len) return 0;

	return len > s.len ? 1 : -1;
}

void myString::print()
{
	for (int i = 0; i < len; i++)
		cout << str[i];

	cout << '\n';
}

void myString::assign(const char* s)
{
	if (memory_capacity > strlen(s))
	{
		delete[] str;

		str = new char[strlen(s)];
	}

	len = strlen(s);

	for (int i = 0; i < len; i++)
		str[i] = s[i];
}

void myString::assign(const myString& s)
{
	if (memory_capacity > s.len)
	{
		delete[] str;

		str = new char[s.len];
	}

	len = s.len;

	for (int i = 0; i < len; i++)
		str[i] = s.str[i];
}

void myString::reserve(int size)
{
	if (memory_capacity < size)
	{
		char* prev_string = str;
		int stringLength = len;
		str = new char[size];
		memory_capacity = size;

		for (int i = 0; i < stringLength; i++)
		{
			str[i] = prev_string[i];
		}
		delete[] prev_string;
	}
}

char myString::at(int i) const
{
	if (i >= len || i < 0) return NULL;

	return str[i];
}

myString& myString::insert(int loc, const myString& s)
{
	if (loc < 0 || loc > memory_capacity) return *this;

	myString prev_string(str);

	if (memory_capacity < len + s.len)
	{
		str = new char[len + s.len];
	}

	for (int i = 0; i < loc; i++)
	{
		str[i] = prev_string.str[i];
	}

	for (int i = loc; i < loc + s.len; i++)
	{
		str[i] = s.str[i - loc]; // 새로운 문자열을 넣는다.
	}

	int j = 0;
	for (int i = loc + s.len; i < len + s.len; i++)
	{
		str[i] = prev_string.str[loc + j];
		j++;
	}

	memory_capacity = memory_capacity * 2 < len + s.len ? len + s.len : memory_capacity * 2;
	len = len + s.len;

	return *this;
}

myString& myString::insert(int loc, const char* s)
{
	myString temp(s);

	return insert(loc, temp);
}

myString& myString::insert(int loc, char c)
{
	myString temp(c);

	return insert(loc, temp);
}

myString& myString::erase(int loc, int num)
{
	if (num < 0 || loc < 0 || loc > len) return *this;

	if (num > len) return *this;

	for (int i = loc + num; i < len; i++)
		str[i - num] = str[i];

	len -= num;

	return* this;
}

int myString::find(int find_from, myString* s) const
{
	if (len == 0) return -1;
	for (int i = find_from; i < len; i++)
	{
		for (int j = 0; j < s->len; j++)
		{
			if (str[i + j] != s->str[j])
				break;
			if (j == s->len - 1) // 끝까지 같으면
			{
				return i;
			}
		}
	}

	return -1;
}

int myString::find(int find_from, const char* s) const
{
	myString temp(s);

	return find(find_from, &temp);
}

int myString::find(int find_from, char c) const
{
	myString temp(c);

	return find(find_from, &temp);
}

int main()
{
	//myString str1("hello world!");
	//myString str2(str1);

	//str1.print();
	//str2.print();

	//a.add_string("string");
	//a.copy_string(b);

	//myString str1("very very very long string");
	//str1.reserve(30);

	//std::cout << "Capacity : " << str1.capacity() << std::endl;
	//std::cout << "String length : " << str1.length() << std::endl;
	//str1.print();

	//cout << str1.at(0);
	//cout << str1.at(1);
	//cout << str1.at(2);
	//cout << str1.at(3);

	//myString str1("very long string");
	//myString str2("<some string inserted between>");
	//str1.reserve(30);

	//std::cout << "Capacity : " << str1.capacity() << std::endl;
	//std::cout << "String length : " << str1.length() << std::endl;
	//str1.print();

	//str1.insert(5, 'a');
	//str1.insert(5, 'a');
	//str1.insert(5, 'a');
	//str1.insert(5, 'a');
	//str1.insert(5, 'a');
	//str1.print();

	//myString str1("hello world!");
	//myString str2(str1);

	//str1.print();
	//str2.print();

	//myString str1("very long string");
	//myString  str2("<some string inserted between>");
	//str1.reserve(30);

	//std::cout << "Capacity : " << str1.capacity() << std::endl;
	//std::cout << "String length : " << str1.length() << std::endl;
	//str1.print();

	//str1.insert(5, str2);
	//str1.print();

	//std::cout << "Capacity : " << str1.capacity() << std::endl;
	//std::cout << "String length : " << str1.length() << std::endl;
	//str1.print();

	//str1.erase(5, 3);
	//str1.print();

	//myString str1("this is a very very long string");
	//std::cout << "Location of first <very> in the string : " << str1.find(0, "very")
	//	<< std::endl;
	//std::cout << "Location of second <very> in the string : "
	//	<< str1.find(str1.find(0, "very") + 1, "very") << std::endl;

	myString str1("abcdef");
	myString str2("abcde");

	std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;

}

