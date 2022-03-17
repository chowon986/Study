// 상속

#include <iostream>

// 학사 관리 프로그램 만들기

class Student : public Person
{
	// std::string name; 상속으로 물려받음
	// int age;			 상속으로 물려받음
	int id;
};

class Professor : public Person
{
	// std::string name; 상속으로 물려받음
	// int age;			 상속으로 물려받음
	int major;
};

// 공통의 특징이 있으면 인간이라는 class를 생성하자
// 상속 : 기존 타입을 확장해서 새로운 타입을 설계하는 문법
// 장점 : 코드의 중복을 줄일 수 있고, upcasting, 가상 함수, 다형성, 인터페이스 등
// 다양한 개념을 활용해서 객체지향 설계 기술을 사용할 수 있다.
class Person
{
	std::string name;
	int age;
};

// 상속 그림 표기 시 파생 클래스 -> 기본 클래스
// 화살표 모양 잘 알아두기


class Base
{
private:
	int a;
protected:
	int b;
public:
	int c;
};

class Derived : public Base
{
public:
	void df()
	{
		a = 10; // error : 기본 클래스의 private는 접근 불가 | a를 바꾸고 싶으면 base안의 멤버함수로 바꿔야 함
		b = 10;
		c = 20;
	}
};

int main()
{
	Derived de;
	de.a = 10; // error
	de.b = 10; // error
	de.c = 10;
}

// private : 자신의 멤버 함수와 friend 함수에서 접근 가능 / 파생 클래스는 불가
// protected : 자신의 멤버 함수와 friend 함수 | 파생클래스 멤버 함수와 friend 함수에서 접근 가능 | 멤버가 아닌 함수에서는 접근 안됨
// public : 모든 함수에서 접근 가능