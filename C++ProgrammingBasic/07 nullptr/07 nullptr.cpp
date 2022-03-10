#include <iostream>

#ifdef __cplusplus
#define NULL 0
#else
#define NULL (void*)0
#endif

void foo(int n)
{
	std::cout << "int " << std::endl;
}

void foo(void* p)
{
	std::cout << "void* " << std::endl;
}

void goo(char* p)
{
	std::cout << "char* " << std::endl;
}

int main()
{
	// 0
	// 정수(int) 형 literal
	// -> 포인터 변수 초기화에 사용될 수 있다.
	// (포인터로 암시적 형 변환)
	// (1) 0이 아닌 다른 정수형 literal은 포인터로 암시적 변환될 수 없다.
	// (2)0을 가진 정수형 변수도 포인터로 암시적 변환될 수 없다.

	int n1 = 0;
	int* p1 = 0;

	// int* p2 = 10; // error (1)
	// int* p3 = n1; // error(2)

	// nullptr
	// C++11 에서 도입
	// -> null pointer를 나타내는 literal, keyword
	// 모든 종류(타입)의 포인터 변수를 초기화 하는데 사용 가능
	// (3) 정수(실수) 초기화에 사용될 수는 없다.

	int* p4 = nullptr;
	void(*p5)() = nullptr;

	// int n2 = nullptr; // error (3)
	// - - -

	// #define NULL (void*)0;

	foo(0);
	// foo(int n)과 foo(void* p) 둘 다 가능하지만 0은 정수이므로 foo(int n)이 작동된다.
	
	foo((void*)0);
	// foo(void* p) void*로 0을 캐스팅 한 후 함수 적용

	// foo(NULL);
	// 경고가 나오지만 실행됨 (매크로 재정의)


	goo(0); // ok
	// goo(NULL); // error. void* -> char* 필요 

	goo(NULL); // error. void* -> char* 필요 
}

