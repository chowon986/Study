// 암호 만들기

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<char> alpha;

bool check(string password)
{
	int a = 0; int b = 0;
	for (int i = 0; i < password.size(); i++)
	{
		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u')
			++a;

		else ++b;
	}

	return (a >= 1 && b >= 2);
}

void go(int n, vector<char>& alpha, string password, int i)
{
	if (password.length() == n)
	{
		if (check(password))
		{
			cout << password << '\n';
		}
		return;
	}

	if (i >= alpha.size()) return;
	go(n, alpha, password + alpha[i], i + 1);
	go(n, alpha, password, i + 1);
}

int main()
{
	// n 만들어야 하는 암호의 길이
	// alpha 사용할 수 있는 알파벳
	// password 현재까지 만든 암호
	// i 사용할지 말지 결정해야 하는 알파벳의 인덱스
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		char character;
		cin >> character;
		alpha.push_back(character);
	}

	sort(alpha.begin(), alpha.end());

	go(n, alpha, "", 0);
}