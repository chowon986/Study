// 디폴트 복사 생성자 문제점

#include <iostream>
using namespace std;

class Point
{
public:
    int x;
    int y;

    Point(int a, int b)
        :x(a), y(b)
    {

    }
};

int main()
{
    Point p1(1, 2); // ok
    Point p2(p1);   // ok
    cout << p2.x << endl; // 1
    cout << p2.y << endl; // 2

}

// 복사 생성자는 모든 멤버를 복사하기 때문에 편하지만 이로 인한 문제점이 있다.
class Person
{
    char* name;
    int age;

public:
    Person(const char* n, int a)
        : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    ~Person()
    {
        delete[] name;
    }
};

int main()
{
    Person p1("kim", 20);
    // Person p2 = p1; 실행 시 오류 발생
    // 소멸자가 kim과 p2를 지워버림

    // (1) 얕은 복사(Shallow Copy)
    // 클래스 안에 포인터 멤버가 있을 때 디폴트 복사 생성자가
    // 메모리 자체를 복사하지 않고 주소만 복사하는 현상
    // -> 해결 방법 : 개발자가 직접 복사 생성자를 만들어야 한다.
    // 복사하는 방법은?
}