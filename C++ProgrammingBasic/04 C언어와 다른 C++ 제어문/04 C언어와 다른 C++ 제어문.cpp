
#include <iostream>

int foo()
{
	return 0;
}

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++)
	{
		std::cout << x[i] << ", ";
	}
	std::cout << std::endl;
	// 이 방법은 배열의 크기가 바뀌면 for 문 안의 범위도 수정이 필요하다


	// 해결 방법 (1) size()
	// std:: size()
	// 배열 크기를 구하는 C++ 표준 함수 (C++17부터 지원)
	// 배열 뿐만 아니라 C++ 표준 라이브러리(STL)의 다양한 컨테이너(list, vector 등)의 크기도 구할 수 있다.

	for (int i = 0; i < std::size(x); i++)
	{
		std::cout << x[i] << ", ";
	}
	std::cout << std::endl;

	// 해결 방법 (2) range-for 문
	for (int e : x) // for (auto e : x)
	{
		std::cout << e << ", ";
	}
	std::cout << std::endl;

	// range-for 문 사용시 모든 요소를 거꾸로 출력할 수 없을까?
	// C++20부터 제공되는 Ranges Library를 사용하면 된다.
	// <ranges> 헤더
	// "std::views" namespace 안에 다양한 함수 제공

	// #include <ranges>

	/*
	for (auto e : std::views::reverse(x)); 거꾸로 출력
	for (auto e : std::views::take(x, 3)); 0부터 3개만 출력
	for (auto e : std::views::reverse(std::views::take(x, 3))); 0부터 3개를 거꾸로 출력
	for (auto e : std::views::dro(x, 3)) 0부터 3개 버리겠다.
	for (auto e : std::views::filter(x, 함수)) 차례대로 함수로 보내서 결과값 출력
	for (auto e : std::views::filter(x, [](int n) { return n % 2 == 1;)) 람다 함수
	*/
	
	int ret = foo();
	if (ret == 0)
	{

	}
	// C++ 17부터 위 코드를 아래처럼 한줄로 입력 가능
	/* 
	if (int ret = foo(); ret == 0)
	{

	}

	switch (int n = foo(); n)
	{
	case 1: break;
	}
	*/

	// C++ 20부터는 range-for도 가능
	/* for (int y[3] = {1,2,3}; auto n:x)
	{
	}
	*/

	// while문은 불가
}