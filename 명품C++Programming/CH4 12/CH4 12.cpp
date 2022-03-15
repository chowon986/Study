#include <iostream>
#include <string>
using namespace std;

class Circle
{
	int radius;
	string name;
public:
	Circle()
	{
		radius = 1;
		name = "초기화";
	}
	void setCircle(string name, int radius)
	{
		this->radius = radius;
		this->name = name;
	}
	double getArea()
	{
		return 3.14 * radius * radius;
	}
	string getName() 
	{
		return name;
	}
};

class CircleManager
{
	Circle* p;
	int size;
public:
	CircleManager(int size)
	{
		this->size = size;
		Circle* b = new Circle[size];
		int radius;
		int num = 1;
		string name;
		for (int i = 0; i < size; i++)
		{
			cout << "원" << num << "의 이름과 반지름 >>";
			cin >> name >> radius;
			b[i].setCircle(name, radius);
			++num;
		}
		p = b;
	}
	~CircleManager()
	{
		delete p;
	}

	void searchByName()
	{
		string name2;
		cin >> name2;
		for (int i = 0; i < size; i++)
		{
			if (name2.compare(p[i].getName()) == 0)
			{
				cout << p[i].getArea();
			}
		}
	}

	void searchByArea()
	{
		int a;
		cin >> a;
		cout << a << "보다 큰 원을 검색합니다." << endl;

		for (int i = 0; i < size; i++)
		{
			if (a < p[i].getArea())
			{
				cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ',';
			}
		}
	}
};

int main()
{
	int num = 0;
	cout << "원의 개수 >>";
	cin >> num;
	CircleManager a(num);
	cout << "검색하고자 하는 원의 이름 >>";
	a.searchByName();
	cout << endl << "최소 면적을 정수로 입력하세요 >>";
	a.searchByArea();
}
