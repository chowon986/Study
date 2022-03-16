#include <iostream>

// 정적 멤버(static member) 데이터

class Car
{
	int speed;		// 멤버 데이터
	static int cnt; // static member data

public:
	void Go()
	{

	}

	void Stop()
	{

	}

	static int getCount() // 데이터 뿐만 아니라 함수에도 적용 가능
	{
		return cnt;
	}
};

int Car::cnt = 0; // static member를 쓰려면 이걸 해줘야 한다.

int main()
{

}

// 방법 (1) 멤버변수 count 사용
class Car
{
	int speed{ 0 };
public:
	int count{ 0 };

public:
	Car()
	{
		++count;
	}
	~Car()
	{
		--count;
	}
};

int main()
{
	Car c1;
	Car c2;

	std::cout << c1.count; // 2가 나올까?
	// c1을 만들면 count가 1, c2를 만들면 count 1 (각자의 카운터가 1씩 올라감)
}
// 멤버 데이터는 객체당 한 개가 생성된다.
// 각 객체가 독립적인 자신의 count 멤버 변수를 사용하므로 실패



// 방법 (2) 전역변수 count 사용
int count{ 0 };
class Car
{
	int speed{ 0 };

public:
	Car()
	{
		++count;
	}
	~Car()
	{
		--count;
	}
};

int main()
{
	Car c1;
	Car c2;

	std::cout << count; // 2가 나온다.
}

// 전역변수 특징
// 전역변수는 모든 객체가 공유할 수 있다.
// 객체의 개수를 구하는데 성공
// (문제점 1) 전역변수는 어디서나 접근 할 수 있으므로 안전하지 않다.
// 다른곳에서 쉽게 바꿔버릴 수 있다. (접근 지정자 같은걸로 보호할 수 없을까?)
// (문제점 2) Car 외에 다른 타입에도 동일한 기능( count 라는 이름)을 다시 사용할 수 없으므로 다른 이름을 사용해야 한다.


// (3) static member data
class Car
{
	int speed{ 0 };
public:
	static int count; // 멤버 데이터 앞에 static을 붙여서 만든다.
				      // 여기서 초기화 불가. 반드시 클래스 외부에서 선언(정의) 되어야 한다. ***
public:
	Car()
	{
		++count;
	}
	~Car()
	{
		--count;
	}
};

int Car::count{ 0 }; // ***초기화는 이렇게

// (1) 프로그램이 처음 시작될 때 객체를 생성하지 않아도 메모리에 놓이게 된다.
// (2) static member data는 객체의 메모리에는 포함되지 않는다.
// (3) 결국 모든 Car 객체가 Car::count를 공유하게 된다.
// (4) static 멤버 데이터는 클래스이름::static멤버이름으로 접근(public일때)

int main()
{
	Car c1; // speed만 가지고 있음 (객체의 메모리에는 포함되지 않음)
	Car c2;
	std::cout << Car::count; // public이면 접근 가능
}

// static member data와 instance member data의 차이점
// static은 클래스 당 1개 (동일 타입의 모든 객체 공유)
// instance는 객체 당 1개