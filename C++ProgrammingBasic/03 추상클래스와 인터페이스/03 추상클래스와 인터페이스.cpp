// 추상클래스
#include <iostream>

class Shape
{
public:
    virtual void Draw() = 0;
};

class Rect : public Shape
{
    virtual void Draw() {}
};

int main()
{
    Shape s; // error (1)
    Shape* p; // ok   (2)
    Rect r; // 특정 멤버 함수를 구현하면 객체 생성 가능 
}

// 순수 가상 함수
// 함수의 구현부가 없고, 선언부가 =0으로 끝나는 가상함수

// 추상 클래스
// 순수 가상 함수가 한개 이상 있는 클래스
// 객체를 생성할 수 없다. (1)
// 포인터 변수는 만들 수 있다. (2)

// Rect는 추상 클래스인 기본클래스로부터 파생된 것이므로
// 기반 클래스의 순수 가상함수의 구현부를 제공하지 않으면 역시 추상 클래스이다.

// 추상 클래스의 설계 의도
// 파생 클래스에게 특정 멤버 함수를 반드시 만들어야한다고 지시하는 것

