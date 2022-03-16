#include <iostream>

class Point
{
public:
    int x;
    int y;

    Point()
        :x(0), y(0)
    {

    }
    Point(int a, int b)
        :x(a), y(b)
    {

    }

   /* 복사 생성자 Point(const Point& p)
        :x(p.x), y(p.y)
    {

    }
    */
};

int main()
{
    Point p1;
    Point p2(1, 2);
    // Point p3(1); 없어서 에러
    Point p4(p2); // 만들지 않았는데도 이용 가능
}

// 복사 생성자
// 자신과 동일한 타입 한개를 인자로 가지는 생성자
// 사용자가 복사 생성자를 만들지 않으면
// -> 컴파일러가 제공
// -> 디폴트 복사 생성자
// -> 모든 멤버를 복사한다
// 생성자가 하나도 없으면 생기는게 아니라 복사 생성자가 없다면 만들어준다.

// 호출되는 경우
// (1) 자신과 동일한 타입의 객체로 초기화될때
// (2) 함수 인자를 call by value로 받을 때 
// (3) 함수가 객체를 값으로 반환 할 때


// (2) call by value
void foo(Point pt)
{

}

// call by value 말고 아래와 같이 쓰세요
void foo(const Point& pt)
{

}

// (3)
Point p;

Point foo()
{
    return p;
}

int main()
{
    foo(); // return 값을 받기 위한 임시 객체
}

// 임시 객체를 만들지 말고 바로 반환해줘 -> 참조 리턴 넣기
// -> 단, 지역변수는 참조로 반환하면 안된다. (함수 끝나면 사라지니까)
Point& foo()
{
    return q;
}