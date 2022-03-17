// 예제로 배우는 상속 문법

#include <iostream>
#include <vector>
using namespace std;

// 도형 편집기로 배우는 객체지향 프로그래밍

class Shape
{
public:
	virtual void Draw()
	{

	}
};

class Rect : public Shape
{
public:
	virtual void Draw() override;
};

void Rect::Draw() // override  구현 선언 나눌때 구현부에는 override 붙일 필요 없다.
{
		cout << "Rect::Draw" << endl;
}


class Circle : public Shape
{
public:
	virtual void Draw()
	{
		cout << "Circle::Draw" << endl;
	}
};

int main()
{
	// vector<Rect*> v; // 이렇게 만들면 사각형만 보관 가능. 원은 보관 불가
	vector<Shape*> v; // 이렇게 하면 모든 도형 가능

	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v) // v는 shape* 타입
			{
				p->Draw(); // static 바인딩되면 shape만 작동하겠죠
				// 가상 함수로 바꾸기 위해 draw함수를 virtual로 바꿔볼게요
				// 다형성
			}
		}
	}
}
// (1) 모든 도형을 타입으로 만들자
// (2) 모든 도형을 하나의 컨테이너에 넣어서 관리할 수 없을까? -> 모든 도형의 공통된 기반 클래스를 만들다.
// (3) 모든 도형의 공통의 특징은 반드시 기반 클래스인 shape에 있어야한다.
// -> draw 함수를 shape* 타입으로 호출하려면 draw 함수는 shape에 있어야한다.
// (4) 파생 클래스가 재정의 하게 되는 멤버 함수는 반드시 가상함수로 만들어야한다.


// 다형성
// 동일한 코드 표현(함수 호출)이 "상황에 따라 다르게 동작" 하는 것
// 개방 폐쇄의 원칙 (OCP)
// 기능 확장에 열려 있고, 코드 수정에는 닫혀 있어야 한다는 이론
// 다형성은 OCP를 만족하는 좋은 코드 스타일이다.
// (기능이 추가되어도, 코드는 수정되면 안된다)