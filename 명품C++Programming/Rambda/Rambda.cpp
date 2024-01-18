// Rambda

#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int CalLam(int _numA, int _numB, /*int(*Func)(int, int)*/ function<int(int, int)> f)
{
	return f(_numA, _numB);
}

int main()
{
	// 람다 식
	// 무명 함수
	/* 일반함수 vs 람다
	   함수 실행 위치 밖의 변수에 접근할 수 있는가?
	   일반 함수는 불가하지만 람다는 가능

	   함수 밖에 있는 데이터를 어떻게 접근하는가?
	   (1) 매개 변수
	   (2) 전역 변수
	*/

	int cnt = 0;

	//auto lamFunc = [&]()
	//{
	//	std::cout << "람다";
	//	cnt++;
	//};

	auto TestLam = [&](int a, int b)
	{
		cnt++;
		cout << "cnt :" << cnt << endl;
		return a + b;
	};
	
	CalLam(10, 10, TestLam);

	cout << cnt << endl;

	//lamFunc();

	[](int a)
	{
		cout << "매개변수 : " << a << endl;
		return a;
	}(10);
	
	[](int a /*= 10*/)
	{
		cout << "매개변수 : " << a << endl;
	}(3);

	cout << CalLam(3, 5, [](int a, int b) {return a + b; }) << endl;

}