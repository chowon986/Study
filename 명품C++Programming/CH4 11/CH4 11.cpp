#include <iostream>
using namespace std;

class CoffeeVendingMachine
{
private:
	Container tong[3];

	void fill()
	{
	}
	void selectEspresso()
	{
		for (int i = 0; i < 3; i++)
		{
			if (tong[i].getSize() == 0)
			{
				cout << "원료가 부족합니다.\n";
				run();
			}
		}
		tong[0].consume();
		tong[1].consume();
	}

	void selectAmericano()
	{
		for (int i = 0; i < 3; i++)
		{
			if (tong[i].getSize() == 0)
			{
				cout << "원료가 부족합니다.\n";
				run();
			}
		}
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
	}

	void selectSugarCoffee()
	{
		for (int i = 0; i < 3; i++)
		{
			if (tong[i].getSize() == 0)
			{
				cout << "원료가 부족합니다.\n";
				run();
			}
		}
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		tong[2].consume();
	}

	void show()
	{
		cout << "커피 " << tong[0].getSize();
		cout << ", 물 " << tong[1].getSize();
		cout << ", 설탕" << tong[2].getSize() << endl;
	}
public:
	void run()
	{
		int start = 0;
		int num;
		if (start == 0)
		{
			cout << "***** 커피 자판기를 작동합니다. *****\n";
		}
		++start;
		while (1)
		{
			cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>>";
			cin >> num;
			switch (num)
			{
			case 1:
				selectEspresso();
				break;
			case 2:
				selectAmericano();
				break;
			case 3:
				selectSugarCoffee();
				break;
			case 4:
				show();
			case 5:
				fill();
				break;
			}
		}
	}
};

class Container
{
	int size;
public:
	Container()
	{
		size = 10;
	}

	void fill()
	{
		size = 10;
	}

	void consume()
	{
		size -= 1;
	}

	int getSize()
	{
		return size;
	}
};

int main()
{	
	CoffeeVendingMachine* coffee = new CoffeeVendingMachine;
	coffee->run();
	delete coffee;
}
