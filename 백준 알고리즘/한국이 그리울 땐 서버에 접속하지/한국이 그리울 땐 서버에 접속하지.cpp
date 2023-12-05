// 한국이 그리울 땐 서버에 접속하지

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int tc;
	cin >> tc;

	string name;
	cin >> name;

	int idx = name.find('*');
	string originFront = name.substr(0, idx);
	string originEnd = name.substr(idx + 1, name.size());

	for (int i = 0; i < tc; i++)
	{
		string temp;
		cin >> temp;

		if (temp.size() >= name.size() - 1)
		{
			string front = temp.substr(0, idx);
			string end = temp.substr(temp.size() - originEnd.size(), temp.size());

			if (originFront == front && originEnd == end)
				cout << "DA" << '\n';
			else
				cout << "NE" << '\n';
		}
		else
			cout << "NE" << '\n';
	}
}