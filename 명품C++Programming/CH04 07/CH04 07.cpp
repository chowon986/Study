// 3개의 Circle 객체를 가진 배열을 선언하고, 반지름 값을 입력 받고, 면적이 100보다 큰 원의 개수를 출력하라 

#include <iostream>
using namespace std;

class Circle
{
	int radius;
public:
	Circle()
	{
		radius = 1;
	}
	void setRadius(int radius)
	{
		this->radius = radius;
	}
	double getArea()
	{
		return 3.14 * radius * radius;
	}
};

int main()
{
	int a = 0;
	Circle Arr[3];
	int num = 0;
	for (int n = 0; n < 3; n++)
	{
		cout << "원 " << n + 1 << "의 반지름 >> ";
		cin >> a;
		Arr[n].setRadius(a);
		if (Arr[n].getArea() > 100)
		{
			++num;
		}
	}
	cout << "면적이 100보다 큰 원은 " << num << "개 입니다";
}
