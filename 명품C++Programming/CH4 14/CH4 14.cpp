#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Player
{
private:
	string name;
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
private:
	Player* p = new Player[2];
public:
	GamblingGame()
	{
		cout << "***** 겜블링 게임을 시작합니다. *****" << endl;
		srand((unsigned)time(0));
	}

	~GamblingGame()
	{
		delete[] p;
	}

	void setGame()
	{
		string name;
		cout << "첫번째 선수 이름>>";
		cin >> name;
		p[0].setName(name);
		cout << "두번째 선수 이름>>";
		cin >> name;
		p[1].setName(name);
	}

	void playGame()
	{
		while (1)
		{
			char a[1] = {0};
			for (int i = 0; i < 2; i++)
			{
				cout << p[i].getName() << ": <Enter>" << endl;
				cin.getline(a, 2, '\n');
				int r[3];
				cout << "\t\t";
				for (int j = 0; j < 3; j++)
				{
					r[j] = rand() % 3;
					cout << r[j] << '\t';
				}
				if (r[0] == r[1] && r[1] == r[2])
				{
					cout << p[i].getName() << "님 승리!!" << endl;
					return;
				}
				else
				{
					cout << "아쉽군요!" << endl;;
				}
			}
		}
	}
};

int main()
{
	GamblingGame a;
	a.setGame();
	a.playGame();
}