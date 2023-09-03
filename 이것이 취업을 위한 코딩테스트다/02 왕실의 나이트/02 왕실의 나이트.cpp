// 02 왕실의 나이트

#include <iostream>
#include <string>
using namespace std;

int b[9][9];
int dx[] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int dy[] = { -1, 1, -1, 1, 2, 2, -2, -2 };

bool check(int x, int y)
{
	if (x <= 0 || y <= 0 || x > 8 || y > 8) return false;

	return true;
}

int main()
{
	string temp;
	cin >> temp;

	// 시작 위치
	int cx = temp[0] - 'a' + 1;
	int cy = temp[1] - '0';
	int count = 0;

	for (int i = 0; i < 8; i++)
	{
		if (check(cx + dx[i], cy + dy[i]))
			++count;
	}

	cout << count;
}