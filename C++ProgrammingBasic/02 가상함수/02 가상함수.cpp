// 가상함수 #2

#include <iostream>
using namespace std;

// 가상함수를 만들 때는 함수 앞에 virtual을 붙인다.
// 가상함수를 재정의 할 때는 virtual을 붙여도 되고 붙이지 않아도 된다.
// -> 가독성을 위해서는 붙이는 것이 좋다.
// 가상 함수 재정의 시 함수 이름 등에 오타가 있어도 에러가 발생하지 않는다.
// 컴파일러는 새로운 함수를 추가 했다고 생각한다.

// override 의미 (C++ 11)
// 새로운거 만드는게 아니라 기반 클래스거를 재정의 하는 거니까 기반 클래스에 없으면
// 오류를 내달라
// 가상함수를 재정의 할 때 반드시 붙이지는 않아도 되는 이유는 그 이전 버전도 지원해야하므로
// override를 붙여도 안붙여도 된다.

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}
	~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived()" << endl;
	}
	~Derived()
	{
		cout << "~Derived()" << endl;
	}
};
int main()
{
	Base* p = new Derived;
	delete p;
	// 이렇게하면 Derived의 소멸자가 발생되지 않는다.
	// 왜 이런현상이 발생되는가
	// Base* p -> Derived
	// Base* p = new Derived;
	// delete p; p가 가리키는 곳이 파괴 되므로 소멸자를 호출해야 하는데
	// p의 타입이 Base*이르모 Base 소멸자만 호출된다.

	// 해결 방법
	// 소멸자 호출시 포인터 타입이 아닌 p가 가리키는 메모리를 조사 후 호출해야한다.
	// 기반 클래스의 소멸자를 가상함수로 한다.
}

// object slicing
// 값에 의한 복사로 가상함수 복사할 때 모든 멤버가 아닌 내가 가진 멤버만 복사되는것

// virtual과 override는 클래스 내부에서만 가능
// virtual과 override는 선언부에만 적고 구현부에서는 빼라

// static const virtual override일때 각각 달라지는 점에 주목 