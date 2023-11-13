// N-Queen.cpp

#include <iostream>
#include <vector>
using namespace std;

vector<int> board(15);
vector<bool> isUsed(15, false);
int n;
int sum;

bool test(int x, int y)
{
	if (x == 0) return true;

	for (int i = 0; i < x; i++)
	{
		if (board[i] == y)
			return false;

		if (abs(y - board[i]) == abs( x - i)) return false;
	}

	return true;
}

void check(int depth)
{
	if (depth == n)
	{
		sum += 1;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!test(depth, i)) continue;

		board[depth] = i;
		check(depth + 1);
	}
}

int main()
{
	cin >> n;

	check(0);

	cout << sum;
}