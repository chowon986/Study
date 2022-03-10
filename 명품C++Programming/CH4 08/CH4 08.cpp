// 7번을 수정해보자
// 사용자로부터 원의 개수를 입력받고, 원의 개수만큼 반지름을 입력받아라
// 원의 개수에 따라 동적으로 배열을 할당받아야한다.

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
	int cnt = 0;
	cout << "원의 개수 >> ";
	cin >> cnt;
	Circle* Arr = new Circle[cnt];
	int num = 0;
	for (int n = 0; n < cnt; n++)
	{
		cout << "원 " << n + 1 << "의 반지름 >> ";
		cin >> a;
		Arr[n].setRadius(a);
		if (Arr[n].getArea() > 100)
		{
			++num;
		}
	}
	delete[] Arr;
	cout << "면적이 100보다 큰 원은 " << num << "개 입니다";
}