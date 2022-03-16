// this

#include <iostream>

class Point
{
    int x{ 0 };
    int y{ 0 };
public:
    void set(int a, int b)
    {
        x = a; // 여기서 x가 pt1의 x인지 pt2의 x인지 어떻게 알겠는가?
        y = b;
    }
};

int main()
{
    Point pt1;
    Point pt2;

    pt1.set(10, 20);
    pt2.set(10, 20);

    // 10하고, 20만 전달되면 pt1인지 pt2인지 알 수 없다.
    // int a, int b만 보내는 것 같지만
    // void set(Point* this, int a, int b)
    // {
    //   this->x = a;
    //   this->y = b;
    // }
    // 멤버 함수 호출 시 객체의 주소가 같이 전달된다.
    // this call이라고 한다.
    // 의미상 이렇지만 set(&pt1, 10, 20); 이런식으로 보낼 수는 없다.
    // 객체 주소가 전달되는 방식에 약간의 차이가 있기 때문에
}

// this
// 멤버 함수 안에서 사용 가능한 키워드
// 해당 멤버 함수를 호출할 때 사용한 객체의 주소
// static에서는 사용 불가하다. (static은 객체 없이 부를 수 있으니까)

class Counter
{
    int count{ 0 };
public:
    // this가 사용되는 경우
    // (1) 멤버 데이터 임을 명확히 하고 싶을 때
    void reset(int count = 0)
    {
        this->count = count;
        // 멤버 카운터  // 인자 카운터
    }

    // 멤버 함수가 this 또는 *this를 반환하면 멤버 함수를 연속적으로 호출 할 수 있다.
    Counter* increment()
    {
        ++count;
        return this; 
    }

    Counter& decrement()
    {
        --count;
        return *this; // 이렇게 반환할 때는 Counter&를 써야한다. Counter로 하면 버그의 원인이 된다.
    }
};

int main()
{
    Counter c;
    c.increment()->increment()->increment();
    c.decrement().decrement().decrement();
    // this를 반환하면 연속 호출 가능
}