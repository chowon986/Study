// static member function

#include <iostream>

class Car
{
	int speed{ 0 };
	static int count;
public:
	Car()
	{
		++count;
	}
	~Car()
	{
		--count;
	}

	//**

	static int get_count()
	{
		return count;
	}
};

int Car::count{ 0 }; // static member 초기화

int main()
{
	// *** 여기서 Car 객체의 개수를 알고 싶다.
	// 객체 없이 private 멤버인 Car::count에 접근 할 수 없을까?
	// 객체 없이 호출 가능한 멤버 함수가 필요하다.
	// int get_count() 함수 앞에 static을 붙인다. **
	std::cout << Car::get_count() << std::endl; // 0이 나옴
	// 가독성을 위해 클래스 이름을 통해 호출하는 것이 좋다.

	Car c1;
	Car c2;
	std::cout << c1.get_count() << std::endl; // 2라고 잘 나옴 그런데 객체 만들기 전에 호출하면? ***
}

// static member data vs global

int global{ 0 };

class Object
{
	int idata{ 0 };
	static int sdata;
public:
	void ifunc()
	{

	}

	static void sfunc()
	{

	}
};
int Object::sdata{ 0 };

void gfunc()
{

}

int main()
{
	gfunc();
	Object::sfunc();

	Object obj;
	obj.ifunc();
}

// (공통점 1) 메모리는 프로그램 처음 실행 시 할당된다.
// (차이점 1) 전역함수는 접근지정자를 사용할 수 없다.
// (차이점 2) static은 객체 없이 호출 가능 (private 접근 가능)

class Object
{
	int idata;
	static int sdata;
public:
	void ifunc()
	{
		idata = 10; // ok
		sdata = 10; // ok
		sfunc();    // ok
	}

	static void sfunc()
	{
		// idata = 10; 에러 -> 객체 없이 사용 불가
		sdata = 10; // ok
		// ifunc(); 에러 -> 객체 없이 사용 불가

		// static 멤버 함수에서는 static 멤버(데이터, 함수)만 접근 가능
	}
};
int Object::sdata{ 0 };

int main()
{
	Object::sfunc();
	Object obj;
	obj.ifunc();
}

// 선언과 구현의 분리
// static member data 외부 정의(초기화)는 구현에서 한다.
// 선언부 함수에는 static을 붙이지만 구현부 함수에서는 static을 안 붙인다.