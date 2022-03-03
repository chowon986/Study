#include <iostream>

struct Point
{
	int x = 1; // 구조체 멤버에 디폴트 초기값을 지정할 수 있다.
	int y{ 2 };
};

Point foo()
{
	Point p = { 1,2 };
	return p;
}
int main()
{
	struct Point pt1; // C에서는 구조체로 변수 만들 때 struct 붙여야 했으나
	Point pt2 = { 3,4 }; // C++은 struct 없이도 가능
	
	// int x = pt2.x;
	// int y = pt2.y;

	// 위 두 줄의 코드를 한줄로 표현 가능
	// auto [x, y] = pt2;
	
	// Structure Binding (c++17)
	// 구조체 또는 배열의 모든 요소의 값을 한 줄 꺼내는 문법
	// 타입은 반드시 auto를 사용해야 한다.
	// 요소의 개수와 선언된 변수의 개수가 동일해야 한다.

	int arr[3] = { 1,2,3 };
	int a = arr[0];
	int b = arr[1];
	int c = arr[2];
	// auto [a, b, c] = arr; // 개수 통일, auto 사용 OK
	// arr에 있는 변수를 a, b, c에 담겠다.

	auto ret = foo(); // Point ret = foo();
	// auto [x1, y1] = foo(); 각 요소를 분리해서 받겠다.
}

