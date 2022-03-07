#include <iostream>

void inc1(int n) { ++n; }
void inc2(int* p) { ++(*p); }
void inc3(int& r) { ++r; }

void f1(int* p)
{
	if (p != 0)
	{

	}
}

void f2(int& r)
{

}

void swap(int p1, int p2)
{
	int temp = p1;
	p1 = p2;
	p2 = temp;
}

void swap2(int& r1, int& r2)
{
	int temp = r1;
	r1 = r2;
	r2 = temp;
}

/*
template<class T>
inline void swap3(T& k1, T& k2)
{
	T temp = k1;
	k1 = k2;
	k2 = temp;
}
*/

int main()
{
	int n = 10;
	int* p = &n;
	int& r = n; // n에 r이라는 이름을 붙이겠다.

	r = 20;

	std::cout << n << std::endl;
	std::cout << &n << std::endl;
	std::cout << &r << std::endl;

	// 레퍼런스 (reference, 참조)
	// 이미 존재하는 변수(메모리)에 대한 추가적인 별칭을 부여하는 문법

	// & 연산자
	// (1) 변수의 주소를 구할 때 사용
	// int n = 0; // 변수 선언 후
	// int* p = &n; // 변수의 주소를 구할 때

	// (2) 레퍼런스 변수를 선언할 때 사용
	// int& r = n;

	int a = 10, b = 10, c = 10;

	inc1(a);
	inc2(&b);
	inc3(c);

	std::cout << a << std::endl; // 11이 아닌 10이 나온다. call by value
	std::cout << b << std::endl; // 11이 나온다. call by pointer
	std::cout << c << std::endl; // 11이 나온다. call by reference

	// 함수 인자로 reference를 사용하면
	// 포인터와 유사하게 전달된 인자의 값을 수정할 수 있다.
	// 포인터보다 간결하고 안전하게 코드를 작성할 수 있다.

	// int* p = 0; // 널포인터는 있다.
	// int& r; // 널 참조는 없다.

	// scanf 는 call by pointer
	// cout은 call by reference

	int x = 10, y = 20;
	//  swap(&x, &y); C 방식
	swap(x, y);
	std::swap(x, y);
}
