// 1-2.cpp : 첫 C++ 프로그램 분석하기

// 헤더 참조
// iostream은 C++에서 표준 입출력에 필요한 내용을 포함함
// std::cout, std::endl 등
#include <iostream>

// namespace : 어떤 정의된 객체에 대해 어디 소속인지 지정해주는 것
// 서울 사는 철수, 부산 사는 철수와 같이 소속된 이름 공간이 다르면 다르게 취급됨
// std::cout은 std란 namespace에 있는 cout 함수를 의미
namespace header1 
{
	int foo() { return 0; }
	void bar();

	int func()
	{
		foo();			// header1의 foo가 호출됨, 즉 자기 자신이 포함되어 있는 이름 공간 안에서는
						// 이름 공간을 명시하지 않고 자유롭게 부를 수 있음
		//header2::foo(); // namespace를 이용하면 소속되지 않은 함수도 호출 가능
		
		return 0;
	}
}

namespace header2
{
	int foo() { return 0; }
	void bar() {}
}

// 매번 header1::을 붙이기 귀찮은 경우 using 키워드를 통해 해결 가능
// (1) using header1::foo; -> 이 이후에 foo(); 만 호출해도 header1의 foo가 호출됨
// (2) using namespace header1; 
// 하지만 표준 라이브러리는 매우 크고 업데이트 되는 사항이므로 using namespace std;와 같이 사용하면
// 추후 프로젝트의 함수와 겹치는 등 문제가 발생될 수 있으므로 std::와 같이 명시적으로 사용하는 것을 권장함

// 이름 없는 이름 공간
namespace 
{
	// static int OnlyThisFile()과 동일하게 사용됨
	int OnlyInThisFile() {}

}

// main 함수
// 프로그램이 실행될 때 가장 먼저 실행되는 함수
int main()
{
	std::cout << "Hello, World!!" << std::endl;

	return 0;
}