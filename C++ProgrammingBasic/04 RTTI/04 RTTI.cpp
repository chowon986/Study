// RTTI(Run Time Type Information)

#include <iostream>
#include <typeinfo>
using namespace std;
// RTTI 개념


int main()
{
	int n1 = 10;
	auto n2 = n1; // n2의 타입은 우항을 보고 결정하니까 int

	// 근데 정말 int일까?
	// RTTI
	// 실행 시간에 타입의 정보를 얻을 때 사용하는 기술
	// 사용하려면
	// (1) <typeinfo> 헤더를 포함한다.
	// (2) typeid 연산자를 사용한다.

	const std::type_info& t1 = typeid(n2);
	// n2의 타입이름을 알려줘

	cout << t1.name() << endl; // 실행결과 : int
}

int main()
{
	// typeid
	// 타입에 대한 정보를 얻을 때 사용하는 연산자
	// 다양한 형태로 사용할 수 있다. (1)(2)(3)
	auto n1 = 10;
	typeid(n1); // 변수 (1)
	typeid(int); // 타입 (2)
	typeid(3 + 4.2); // 표현식 (3)

	const type_info& t = typeid(3 + 4.2);

	// std::type_info
	// 타입의 정보를 담고 있는 클래스
	// 사용자가 직접 객체를 만들 수는 없고,
	// typeid() 연산자를 통해서만 얻을 수 있다.
	// 멤버 함수인 name을 통해서 타입의 이름을 얻을 수 있다.
}

int main()
{
	// 타입을 출력하는 것이 아니라 조사하고 싶다면?
	auto n1 = 10;
	const type_info& t1 = typeid(n1);
	const type_info& t2 = typeid(int);

	// 두개를 구한 후 비교해도 되지만
	if (t1 == t2)
	{
		cout << "n1은 int" << endl;
	}
	
	// 이렇게 해도 된다.
	if (typeid(n1) == typeid(int))
	{

	}

}