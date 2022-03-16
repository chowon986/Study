// 객체의 복사 방법 #2

#include <iostream>
using namespace std;

// 얕은 복사 문제를 해결하기 위해 지난 시간에 배웠던 기법들
// (1) 깊은 복사
// (2) 참조 계수

// 다른 방법들
// (1) 복사 금지
// (2) 자원을 직접 관리하지 말자
// (3) 소유권 이전(move) : 초급에서 다루기엔 어려움 -> 중급과정 참고

class Person
{
	char* name;
	int   age;
public:
	Person(const char* n, int a)
		: age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Person()
	{
		delete[] name;
	}

	Person(const Person& p) = delete; // (1) 복사 생성자 삭제
};

int main()
{
	Person p1("kim", 20);
	// Person p2 = p1; 컴파일 에러 발생 -> 아예 사용하지 못하게 만들어 버림
}

#include <string>

//(2) 문자열이 필요하면 STL의 string 클래스를 사용하자
// 동적 메모리 할당을 할 필요 없다.
// string이 내부적으로 자원을 관리해준다.
// int 변수처럼 사용하면 된다.

class Person
{
	string name;
	int   age;
public:
	Person(string n, int a)
		: name(n), age(a)
};

int main()
{
	Person p1("kim", 20);
	Person p2 = p1;
}