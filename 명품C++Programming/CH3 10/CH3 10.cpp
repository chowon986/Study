// 다수의 클래스를 선언하고 활용하는 간단한 문제이다.
// 더하기(+), 빼기(-), 곱하기(*), 나누기(/)를 수행하는 4개의 클래스 Add, Sub, Mul, Div를 만들고자 한다.
// 이들은 모두 공통으로 다음 멤버를 가진다.
/*  - int 타입 변수 a, b : 피연산자
	- void setValue(int x, int y) 함수 : 매개 변수 x, y를 멤버 a, b에 복사
	- int calculate() 함수 : 연산을 실행하고 결과 리턴
*/
// main() 함수는 Add, Sub, Mul, Div 클래스 타입의 객체 a, s, m, d를 생성하고,
// a, s, m, d 객체 중에서 연산을 처리할 객체의 setValue() 함수를 호출한 후,
// calculate()를 호출하여 결과를 화면에 출력한다.
// 프로그램은 무한 루프를 돈다.

#include <iostream>
using namespace std;
#include "Calculator.h"

int main()
{
	int x =0;
	int y=0;
	char z = 'a';

	Add a;
	Sub s;
	Mul m;
	Div d;

	while (1)
	{
		cout << "두 정수와 연산자를 입력하세요>>";
		cin >> x >> y >> z;
		if (z == '*')
		{
			m.setValue(x, y);
			m.calculate();
		}

		else if (z == '+')
		{
			a.setValue(x, y);
			a.calculate();
		}

		else if (z == '-')
		{
			s.setValue(x, y);
			s.calculate();
		}

		else if (z == '/')
		{
			d.setValue(x, y);
			d.calculate();
		}
	}
}
