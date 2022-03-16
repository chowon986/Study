// const member function #2

#include <iostream>

class Rect
{
    int x, y, w, h;
    mutable int cnt = 0;
public:
    Rect(int x, int y, int w, int h)
        : x{ x }, y{ y }, w{ w }, h{ h } {}

    int getArea() const
    {
        // 디버깅 등의 목적으로 객체당 getArea()가 몇 번 호출되었는지 알고싶다.
        // static int cnt = 0; 이렇게 하지말고 멤버 데이터로 넣어야한다.
        // 객체당 따로 생성되도록
        // 문제는 const 때문에 ++cnt가 불가하다.
        // 이럴때 멤버 데이터 앞에 mutable을 붙이면 된다.
        // 상수 멤버에서도 값을 바꿀 수 있게 만든다.
        ++cnt;
        std::cout << cnt << std::endl;
        return w * h;
    }
};

int main()
{
    Rect r1(1, 1, 10, 10);
    Rect r2(1, 1, 10, 10);
    
    r1.getArea(); // 1
    r2.getArea(); // 1
    r2.getArea(); // 2
}

class Number
{
    int value;
public:
    Number(int n)
        :value(n) {}

    int& get()
    {
        return value;
    }
    
    int get() const
    {
        return value;
    }
};

int main()
{
    Number num(10);
    const Number cnum(10);

    cnum.get(); // 2번만 호출 가능
    num.get(); // 1번 호출, 없다면 2번 호출

    num.get() = 20;   // &는 등호(=)의 왼쪽에 올 수 있다.
    // cnum.get() = 20;  // 등호의 왼쪽에 올 수 없다. error
}

// 선언과 구현의 분리
// const는 선언과 구현에 모두 붙여야한다.
// 동일한 함수 이름으로 const 있는 것과 없는 것 둘 다 만들 수 있기 때문에
// 컴파일러의 정확한 함수 구분을 위해서 꼭 붙여야한다.