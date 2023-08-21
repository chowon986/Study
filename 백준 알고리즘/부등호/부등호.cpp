// 부등호

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int tc;
vector<char> inequalitySign;
vector<bool> isUsed(10, false);
string maxString = "";
string minString = "";

bool check(string& answer)
{
	for (int i = 0; i < tc; i++)
	{
		if (inequalitySign[i] == '<')
		{
			if (answer[i] > answer[i + 1])
				return false;
		}
		else
		{
			if (answer[i] < answer[i + 1])
				return false;
		}
	}

	return true;
}

void go(int index, string answer)
{
	if (index == tc + 1)
	{
		if (check(answer))
		{
			if (maxString == "") maxString = answer;
			if (minString == "") minString = answer;

			if (maxString < answer) maxString = answer;
			if (minString > answer) minString = answer;
		}
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (isUsed[i]) continue;

		isUsed[i] = true;
		go(index + 1, answer + to_string(i));
		isUsed[i] = false;
	}
}


int main()
{
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		char temp;
		cin >> temp;
		inequalitySign.push_back(temp);
	}

	go(0, "");

	if (minString == maxString)
		cout << minString;
	else
	{
		cout << maxString << '\n';
		cout << minString;
	}
}
