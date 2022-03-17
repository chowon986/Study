#include <iostream>
#include <string>
using namespace std;

class WordGame
{
	int num{0};
	string name{"김"};
	string word1{"아버지"};
	string word2{"입력"};
public:
	void Start()
	{
		cout << "끝말 잇기 게임을 시작합니다" << endl << "게임에 참가하는 인원은 몇명입니까?";
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cout << "참가자의 이름을 입력하세요. 빈칸 없이>>";
			cin >> name[i];
		}
		cout << "시작하는 단어는 " << word1 << "입니다" << endl;
		while (1)
		{
			for (int i = 0; i < num; i++)
			{
				cout << name[i] << ">>";
				cin >> word2;
				int j = (int)word1.size();
				if (word1.at(j - 2) == word2.at(0) && word1.at(j - 1) == word2.at(1))
				{
					word1 = word2;
				}
				else
				{
					cout << name[i] << " 탈락!!!";
					return;
				}
			}
		}
	}
};

int main()
{
	WordGame a;
	a.Start();
}