// 객체의 복사 방법 #1

#include <iostream>
#include <string>

class Person
{
	char* name;
	int age;
public:
	Person(const char* n, int a)
		:age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	~Person()
	{
		delete[] name;
	}

	Person(const Person& p)
		:age(p.age)
	{
		// name = p.name; 이렇게하면 포인터 복사되니까
		// 포인터는 복사하지 말고, 새롭게 메모리 할당
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}
};

int main()
{
	Person p1("kim", 20);
	Person p2 = p1; 
}

// 객체의 복사 방법

// 깊은 복사(Deep Copy)
// 클래스 안에 포인터 멤버가 있을 때
// 메모리 주소를 복사하지 말고 메모리 자체의 복사본을 만드는 기술
// (단점)
// 객체를 여러번 복사하면 동일한 자원(이름)이 메모리에 여러번 놓이게 된다.
// 자원의 크기가 큰 경우 메모리 낭비가 발생

// 참조 계수(reference counting)
// 여러 객체가 하나의 자원을 공유하게 한다.
// 단, 몇명의 객체가 자원을 사용하는지 개수를 관리한다.
// 얕은 복사를 하고, *ref 개수를 지정해서 개수를 빼자

class Person
{
	char* name;
	int	  age;
	//// 참조 계수를 가리키는 포인터 변수 하나 만들기
	int*  ref;
	////
public:
	Person(const char* n, int a)
		:age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		//// 참조 계수를 관리하기 위한 동적 메모리 생성
		ref = new int(1);
		//*ref = 1; 이 코드를 안적어도 위에(1) 하면 (1)로 초기화 하라는 뜻임
		////
	}

	~Person()
	{
		////
		if (--(ref) == 0) // ref를 한 개 뺀게 0이 되면
		{
			delete[] name; // 동적 생성 삭제하라
			delete ref;
		}
		////
	}

	Person(const Person& p)
	//// 다 복사하는데 ref는 증가하게끔
		:name(p.name), age(p.age), ref(p.ref)
	{
		++(ref);
	}
	////
};

int main()
{
	// 복사생성자를 안만들면 카운터는 증가하지 못하겠죠?
	// 복사생성자 ref 증가하게끔 생성
	// 소멸자도 바뀌어야 합니다.

	// 참조계수에서 좀 더 생각해야 할 점
	// p1 객체가 자신의 이름을 변경하게 되면? (자원이 바뀌면?)
	// p2의 이름은 변경되면 안되므로 공유 했던 자원은 분리되어야 한다.
	// 멀티 스레드 환경에서는 동기화의 오버헤드가 추가된다.
}