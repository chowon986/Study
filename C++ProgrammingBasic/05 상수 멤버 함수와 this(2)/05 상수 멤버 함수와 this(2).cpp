// reference return

#include <iostream>

// &로 리턴해야 하는 이유
struct Point
{
    int x;
    int y;
};


void f1(Point p1)
{
    // call by value
    // 객체의 복사본 생성
}

void f2(Point& p2)
{
    // call by reference
    // 그냥 pt를 가리킴
}

int main()
{
    Point pt = { 1, 2 };
    f1(pt);
    f2(pt);
}


// 전역 변수로 pt를 만들었을 때
struct Point
{
    int x;
    int y;
};

Point pt = { 1, 2 };

Point f1(Point p1)
{
    return pt;
}

Point& f2(Point& p2)
{
    return pt;
}

int main()
{
    // f1().x = 10; // 리턴용 임시객체 -> 해당 문장이 끝나면 삭제된다.
                    // 리턴용 임시객체는 대입 불가
    f2().x = 10; // pt.x = 10 -> ok

    // 값 리턴과 참조 리턴
    // 값 리턴 : 리턴용 임시객체가 반환된다.
    // 참조 리턴 : 리턴용 임시객체가 생성되지 않는다.
    // (참고) 지역변수로 만들어진 객체는 절대 참조 반환하면 안된다.
}