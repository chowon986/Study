#include <iostream>
#include <string>
using namespace std;
#include <stdlib.h>
#include <time.h>

class Player
{
	string name;

	Player()
	{
	}

public:
	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}
};

class GamblingGame
{
	Player* p;
public:
	void Game()
	{
		string name;
		cout << "***** 겜블링 게임을 시작합니다. *****" << endl << "첫번째 선수 이름>>";
		cin >> name;

		for (int i = 0; i < 2; i++)
		{
			cin >> name;
			p[i].setName(name);
		}

		char a[1];
		while (true)
		{
			for (int i = 0; i < 2; i++)
			{
				cout << p[i].getName() << ":";
				cin.get(a, 1, '\n');
				int a = 0;
				int b = 2;
				int n = rand() % (b - a + 1) + a;
				int Random[3] = { n, n, n };

				for (int i = 0; i < 3; i++)
				{
					cout << Random[i];
				}
				if (Random[i] == Random[i + 1] && Random[i + 1] == Random[i + 2])
				{
					cout << p[i].getName() << "님 승리!!" << endl;
				}
				else
				{
					cout << "아쉽군요!";
				}
			}
		}
	}

};

int main()
{
	srand((unsigned)time(0));
	GamblingGame a;
	a.Game();
}
