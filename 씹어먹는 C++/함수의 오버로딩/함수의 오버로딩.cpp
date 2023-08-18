﻿// 함수의 오버로딩

// char를 인자로 받는 print 함수는 없지만 오류가 발생하지 않음
//#include <iostream>
//
//void print(int x) { std::cout << "int : " << x << std::endl; }
//void print(double x) { std::cout << "double : " << x << std::endl; }
//
//int main() 
//{
//	int a = 1;
//	char b = 'c';
//	double c = 3.2f;
//
//	print(a);
//	print(b);
//	print(c);
//
//	return 0;
//}
//

#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }

int main() 
{
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	print(b);
	//print(c); 오류 발생

	return 0;
}

