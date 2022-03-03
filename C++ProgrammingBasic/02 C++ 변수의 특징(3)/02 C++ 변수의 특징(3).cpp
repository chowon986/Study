#include <iostream>

struct Point
{
	int x;
	int y;
};

int main()
{
	// 일관된 초기화 (uniform initialization)
	// (c++11 이전)
	//  일반 변수, 구조체, 배열, 클래스에 따라 초기화 방법이 다르다.
	// (c++11)
	// uniform initialization 문법
	// 모든 종류의 변수를 한가지 방법으로 초기화 할 수 있다.
	// 중괄호 초기화라고도 부름

	int n1 = 0;
	Point p1 = { 0, 0 };
	int x1[3] = { 1, 2, 3 };
	
	// 일관된 초기화 중 "복사 초기화" ('=' 이 있음)
	// copy initialization
	int n2 = { 0 };
	Point p2 = { 0, 0 };
	int x2[3] = {1, 2, 3};

	// 일관된 초기화 중 "직접 초기화" ('=' 이 없음)
	// direct initialization
	int n3{ 0 };
	Point p3{ 0, 0 };
	int x3[3]{ 1, 2, 3 };



	// <prevent narrow>
	// int k1 = 3.4; // warining
	// int k2{ 3.4 }; // error
	// int k3 = { 3.4 }; // eroor
	// char c{ 500 }; // error
}
