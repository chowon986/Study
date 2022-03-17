// 인터페이스(interface)

#include <iostream>
using namespace std;
// 인터페이스 개념

class Camera
{
public:
    void take()
    {
        cout << "take picture" << endl;
    }
};

class HDCamera
{
public:
    void take()
    {
        cout << "take picture HD" << endl;
    }
};

class People
{
public:
    void useCamera(Camera* p)
    {
        p->take();
    }

    void useCamera(HDCamera* p)
    {
        p->take();
    }
};
int main()
{
    People p;
    Camera c1;
    p.useCamera(&c1);

    HDCamera hd;
    p.useCamera(&hd);
}

// 개방 폐쇄의 법칙(OCP - open close principle)
// 기능 확장(모듈, 클래스, 함수 추가)에 열려 있고,
// 수정(기존 코드 수정)에는 닫혀 있어야 한다는 원칙
// 새로운 카메라 클래스가 추가되어도 기존 클래스의 코드를 수정하지 않도록 만들어야한다.

// People이 Camera를 사용하기 위해 Camera* p를 쓰고 있다.
// HDCamera를 쓰려면 코드를 바꿔야 한다
// -> 강한 결합
// 객체와 다른 객체와의 관계가 강하게 연결되어 있는 것
// 교체 불가능하고 확장성이 없다.





// 계약에 의한 설계
// (1) 사람과 카메라 제작자 사이에 지켜야하는 규칙을 먼저 설계한다.
// 규칙은 추상 클래스를 사용해서 설계한다.

class ICamera
{
public:
    virtual void take() = 0;
};

// (2)규칙
// 모든 카메라는 ICamera로 부터 파생되어야 한다.
// 사람과 카메라가 지켜야하는 규칙들을 보통 인터페이스라고 한다.
// 인터페이스는 규칙만 만들기 때문에 추상클래스로 만든다.
// 인터페이스는 함수들을 public으로 써야 하기 때문에
// 접근 지정 제한자를 public:으로 넣거나 클래스가 아닌 struct로 생성한다.

// (3) 카메라 사용자
// 규칙대로만 사용하면 된다.
class People
{
public:
    void useCamera(ICamera* p)
    {
        p->take();
    }

};

// (4) 모든 카메라 제작자
// 반드시 규칙을 지켜야 한다.
class Camera : public ICamera
{
public:
    void take()
    {
        cout << "take picture" << endl;
    }
};

class HDCamera : public ICamera
{
public:
    void take()
    {
        cout << "take picture HD" << endl;
    }
};

int main()
{
    People p;
    Camera c1;
    p.useCamera(&c1);

    HDCamera c2;
    p.useCamera(&c2);
}

// 약한 결합
// People과 camera 또는 hdcamera는 
// 객체와 다른 객체와의 관계가 약하게 연결되어 있는 것
// (인터페이스를 사용해서 통신)
// 교체 가능하고 확장성이 좋다.