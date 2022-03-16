// const member function #1

// 상수 멤버 함수
// 함수 뒤에 const 붙이는거

#include <iostream>

class Point
{
public:
    int xpos, ypos;
    
    Point(int x, int y)
        :xpos(x), ypos(y)
    {
    }

    void set(int x, int y)
    {
        xpos = x;
        ypos = y;
    }

    void print() const
    {
        std::cout << xpos << ", " << ypos << std::endl;
    }
};

int main()
{
    /*
    Point pt(1, 2);
    pt.xpos = 10;
    pt.set(10, 20);
    pt.print();
    */

    const Point pt(1, 2); // 상수 객체니까 값 변경 불가
    // pt.xpos = 10;      // error
    // pt.set(10, 20);    // error
    // pt.print();        // error ->이건 값을 안바꾸는데 왜 에러가 날까?
    // 컴파일러는 함수의 선언부를 보고 함수 호출여부를 결정한다.
    // 함수의 선언만으로는 멤버의 값을 변경하는지 알 수 없다.
    // 그러므로 상수 객체에서는 무조건 멤버 함 수 못 부르도록 만든다.

    // 해결해보자
    // 상수 멤버 함수
    // (1) 멤버 함수의 괄호() 뒤쪽에 const를 붙이는 문법
    // 선언과 구현 양쪽 모두 붙여야한다.
    // (2) 이 안에서는 절대 멤버의 값을 바꾸지 않겠다는 약속임 -> 상수 멤버 함수 안에서는 모든 멤버는 상수로 취급
    // (3) 상수객체는 상수 멤버함수만 호출할 수 있다.
    pt.print(); // 문제 없이 컴파일 가능해 짐
}

class Rect
{
    int x, y, w, h;
public:
    Rect(int x, int y, int w, int h)
        :x{ x }, y{ y }, w{ w }, h{ h }
    {

    }

    // int getArea() 는 잘못된 코드. const를 붙여야 함
    // get으로 시작하는 함수들은 다 const 해야겠죠?
    int getArea() const // 내부적으로 값을 바꾸지 않을게요
    {
        return w * h;
    }
};

void foo(const Rect& r) // const 참조는 상수 객체이므로 내부 코드(1) 작동 불가
{
    // (1) int area = r.getArea();
    // 상태는 바뀌지 않지만 area는 구해야죠?
    // 그럼 함수 뒤에 const를 붙여봅시다.

    int area = r.getArea(); // error 없이 사용 가능
}

int main()
{
    Rect r(1, 1, 10, 10); // 상수 객체 아님
    int area = r.getArea(); // ok
    foo(r);
}

// 상수 멤버 함수 문법은 선택이 아닌 필수 문법입니다.
// 객체의 상태를 변경하지 않는 모든 멤버 함수는 반드시
// 상수 멤버 함수로 만들어야 합니다.