#include <iostream>
#include <string>

// 초기화 리스트 #1

class Chowon
{
	std::string name/*{s}*/; // 여기서 바로 초기화도 가능
	int age/*{a}*/; 
public:
	Chowon(const std::string& s, int a)
		/*(1)*/ : name{s}, age{a} // 초기화 -> 객체를 생성하면서 초기값을 전달하는 것
								  // 즉, 한번의 함수 호출로 초기화
								  // (2) : name(s), age(a)도 가능
	{
		//(3) name = s; sge = a;  // 대입
								  // 즉, 2번의 함수 호출 발생
	}
};
// 1, 2번 방법이 3번에 비해 더 효율적이다.

// 멤버 초기화 리스트를 반드시 사용해야 하는 경우
// (1) 멤버 데이터로 상수나 참조 멤버 데이터로 있는 경우
class Object
{
	const int c;
	int& r;
public:
	Object(int n, int& x) // 상수는 값 변경 불가하니까 함수 구현에서 대입 불가
		: c{ n }, r{ x }   // 이렇게 해야함
	{
		// c = n; 
		// r = x; 
	}
};

// (2) 디폴트 생성자가 없는 타입이 멤버로 있는 경우
class Point
{
	int x;
	int y;
public:
	/*Point()
	{

	}
	*/
	Point(int a, int b) : x{ a }, y{ b }
	{

	}
};

class Rect
{
	Point leftTop;
	Point rightBottom;
public:
	Rect(int x1, int y1, int x2, int y2)
	{

	}
};

// 초기화 리스트의 주의 사항
// (1)
class p
{
public:
	int x;
	int y;

	p() : y{ 10 }, x{ y }
	{
		// 실행은 멤버 데이터 x부터 실행되기 때문에 잘못된 동작을 한다.
		// 초기화 리스트의 코드를 작성할 때는 멤버 데이터가 선언된 순서대로 초기화 코드를 작성하는 것이 좋다.
	}
};

// (2) 선언과 구현 파일로 나누어 클래스를 작성할 때
// 멤버 초기화 리스트는 구현 파일에 작성
// 멤버 초기화 리스트 코드에서는 this가 필요없다. (컴파일러가 알아서 처리 해 줌)
Point::Point(int x, int y) : x{ x }, y{ y }
{

}


// 디폴트 멤버 이니셜 라이저
// class d의 멤버 변수 초기화는 어떻게 될까?
class d
{
public:
	int x{ 0 };
	int y{ 0 };

	d() {}
	d(int a) : x{ a }  {}
	d(int a, int b) : x{ a }, y{ b } {}
};

// 위 코드는 아래와 같이 바뀐다.
/*
	int x;
	int y;

	d() {} : x{0}, y{0} {}
	d(int a) : x{ a }  y{0} {}
	d(int a, int b) : x{ a }, y{ b } {}
*/


int main()
{
	// (1)
	int num = 10;
	Object obj(10, num);

	// (2)
	Rect r(1, 1, 10, 10); // 객체를 생성하면 leftTop, rightBottom도 생겨야 하는데
						  // 디폴트 생성자가 없으므로 안된다.
}