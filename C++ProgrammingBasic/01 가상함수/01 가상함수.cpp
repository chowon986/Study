// upcasting

#include <iostream>
#include <string>
using namespace std;

class Animal
{
    string name;
    int age;
public:
    void cry()
    {

    }
};

class Dog : public Animal
{
    int color;
public:
    void setColor(int c)
    {
        color = c;
    }
};
int main()
{
    Dog dog;

    Dog* p1 = &dog; // ok
    int* p2 = &dog; // error
    Animal* p3 = &dog; // ok. 
    // 기반 클래스 포인터로 파생 클래스의 주소를 가리키는 것
    // dog는 name과 age를 상속받았잖아요 p3를 따라가면 animal이 진짜 있잖아요
    // dog 안에 있는 animal을 볼 수 있다는거죠
    p3->cry(); // ok
    p3->setColor(5); // error
    // 기반 클래스 포인터로는 기반 클래스의 멤버만 접근할 수 있다.
    // setColor를 호출하고 싶으면 명시적으로 캐스팅 해야한다.
    static_cast<Dog*>(p3)->setColor(5);
    // p3를 Dog*로 캐스팅 하겠다. 그러면 dog에만 있는 멤버에도 접근 가능
}

// 업캐스팅
// (1) 기반 클래스 포인터로 파생 클래스 객체를 가리킬 수 있다.
// (2) 기반 클래스 포인터로는 기반 클래스의 멤버만 접근할 수 있다.
// (3) 기반 크래스에 없는 멤버에 접근하고 싶다면 캐스팅 해야한다.


class Animal
{
public:
    int age = 0;
};

class Dog : public Animal {};
class Cat : public Animal {};

// void NewYear(Dog* p) // 도그를 인자로 받으면 도그만 가능하니까
void NewYear(Animal* p) // 모든 동물 사용 가능
{
    ++(p->age);
}

int main()
{
    Dog dog;
    NewYear(&dog);

    Cat cat;
    NewYear(&cat);

    std::vector<Dog*> v1; // Dog만 보관하는 vector
    // 모든 동물을 같이 보관하고 싶으면
    std::vector<Animal*> v2; // 모든 동물들을 보관
}

// upcasting 활용
// (1) 동종(동일 기반 클래스부터 파생된 클래스)을 처리하는 함수
// (2) 동종 보관하는 컨테이너