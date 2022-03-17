// 상속과 생성자

#include <iostream>
using namespace std;

class Base
{
	int data1;
public:
	Base()
		: data1(0)
	{
		cout << "Base()" << endl;
	}

	Base(int a)
		:data1(a)
	{
		cout << "Base(int)" << endl;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
	int data2;
public:
	Derived()
		:data2(0)
	{
		cout << "Derived()" << endl;
	}

	Derived(int a)
		:data2(a)
	{
		cout << "Derived(int)" << endl;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}
};

int main()
{
	Derived d1;
	Derived d2(5);
}

// Derived 타입의 객체 d1(또는 d2)를 생성할 때
// Base의 생성자도 호출될까? -> Base 생성자도 호출된다.

// Base와 Derived 생성자 중 어느 것이 먼저 실행될까?
// Base 생성자가 먼저 실행된다.
// 소멸은 반대로!

// 파생 생성자의 객체를 생성할 경우
// 항상 기본생성자는 인자가 없는 디폴트 생성자가 호출된다.
// -> 다른 버전의 생성자를 호출하려면, 
// 기반 클래스 다른 버전의 생성자를 호출하는 코드를 직접 작성해야한다.

class Base
{
	int data1;
public:
	//Base() : data1(0) {}
	// 생성자가 하나라도 있으면 디폴트 생성자는 생성 안된다.

	Base(int a)
		:data1(a) { }

	~Base() {}
};

class Derived : public Base
{
	int data2;
public:
	Derived()
		:Base(0), data2(0) { }

	Derived(int a)
		:data2(a) {	}

	~Derived() { }
};

// 기반 클래스에 디폴트 생성자가 없다면 사용자가 명시적으로 넣어줘야한다.
// 파생 클래스의 생성자에서 기반 클래스 생성자를 호출하는 코드를 반드시 작성해야 한다.

// 기반 클래스 생성자 호출을 멤버 초기화 리스트 가장 앞쪽에 넣는 것이 관례
// 순서가 바껴도 기반 클래스가 먼저 호출됨 -> 가독성을 위해 앞쪽에 넣을 것

class Person
{
	std::string name;
	int age;

public:
	//Person(){ }
	Person(const std::string& n, int a)
		: name(n), age(a)
	{

	}
};

class Student : public Person
{
	int id;
public:
	/* 중요 */Student(const std::string& n, int a, int id) : Person(n, a), id(id)
	// 세가지 인자를 받는데 두개는 기본 클래스에서 생성할 때 넣고, 하나는 파생 클래스 생성할 때 넣어줘
	{

	}
};

int main()
{
	// Person p; // 모든 사람은 이름과 나이가 있어야하므로 디폴트 생성자를 없애자

	Student s("kim", 20, 33); // 이걸 빌드하면 age가 없어 -> 이름과 나이를 같이 받아야지

}

// 정리
// 상속받으면 디폴트 생성자 발동
// 디폴트 생성자 말고 다른 생성자 발동을 원하면 명시적 표기 필요