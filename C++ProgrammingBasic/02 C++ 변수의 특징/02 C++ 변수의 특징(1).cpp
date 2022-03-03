#include <iostream>

int main()
{
	int x[5] = { 1, 2, 3, 4, 5 };
	auto n = x[0]; // int n = 1;
	// auto
	// 변수 선언 시, 우변의 표현식을 조사해서 컴파일러가 타입을 결정
	// 컴파일 할 때 타입을 결정, 실행 시 오버헤드는 없다.
	// 단점 : 해당 줄(6번)만 봤을 때는 가독성이 떨어진다.

	// 배열과 auto
	// int x[5] = {1, 2, 3, 4, 5}; 일 때
	// auto a = x;
	// (1) int a[5] = x; // 컴파일 에러
	// (2) int* a = x;

	decltype(n) n1 = 2; // int n1 = 2;
	decltype(x) n2 = { 1,2,3,4,5 }; // int n2[5] = {1, 2, 3, 4, 5};
 	// decltype()
	// () 안의 표현식으로 타입을 결정
	// 함수(클래스) 템플릿 등을 만들 때 주로 사용

	// 배열과 decltype
	// int x[5] = {1, 2, 3, 4, 5}; 일 때
	// decltype(x) d; // int d[5];
	//decltype(x) d1 = x; // error

	// type deduction(inference, 추론, 연역)
	// 주어진 표현식을 보고 컴파일러가 타입을 결정하는 과정
	// 생각보다 복잡한 과정을 통해서 타입을 결정

}
