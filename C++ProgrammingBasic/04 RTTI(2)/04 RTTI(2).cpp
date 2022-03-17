// dynamic_cast

#include <iostream>
#include <typeinfo>

class Animal {};
class Dog : public Animal
{
public:
    int color;
};

void foo(Animal* p)
{
    // p가 dog라면 색을 바꾸고싶다
    p->color = 10;

}

int main()
{
    Animal a;
    foo(&a);
    Dog d;
    foo(&d);
}

// (1) 함수가 인자로 기반 클래스의 포인터를 받으면
// 기반 클래스 뿐 아니라 모든 파생 클래스를 전달 받을 수 있다.
// (2) 기반 클래스 포인터로 파생 클래스의 고유 멤버에 접근할 수 없다.
// 파생클래스의 고유 멤버에 접근하려면 파생 클래스 타입으로 캐스팅 해야한다.

#include <iostream>
#include <typeinfo>

class Animal 
{
public:
    virtual ~Animal();
};
class Dog : public Animal
{
public:
    int color;
};

void foo(Animal* p)
{
    // p가 dog라면 색을 바꾸고싶다
    const type_info& t = typeid(*p); // p가 가리키는 타입이 모냐
   cout << t.name() << endl; // animal -> 가상함수가 없어서 | 가상함수 하나 만들기
   // 가상함수를 따로 만들 필요는 없고 기본 클래스의 소멸자를 가상 함수로 매번 하니까 그렇게 하면 됨

   if (typeid(*p) == typeid(Dog))
   {
       Dog* pDog = static_cast<Dog*>(p);
       pDog->color = 10;;
       std::cout << "Dog" << std::endl;
   }
}

int main()
{
    Animal a;
    foo(&a);
    Dog d;
    foo(&d);
}

// typeid
// 가상함수가 없는 객체(non polymorphic type) : 컴파일 시간에 포인터 타입으로 조사
// 가상함수가 있는 객체(polymorphic type) : 실행시간 타입 조사(가상함수 테이블 등을 사용)


// downcasting
// 기반 클래스 포인터를 파생클래스 타입으로 캐스팅 하는것
// 안전하지 않을수도 있다.

// 다운캐스팅과 캐스팅 연산자 (기본클래스에 가상함수가 하나 이상은 있어야한다)
// (1) static_cast
// 잘못된 downcasting을 조사할 수 없다.
// 단, 컴파일 시간에 캐스팅을 수행하므로 오버헤드가 없다.
 
// (2) dynamic_cast 
// 잘못된 downcasting을 하면 0을 반환한다.
// 실행시간에 캐스팅을 수행하므로 약간의 오버헤드가 있다.

Dog* pDog = dynamic_cast<Dog*>(p);
