// 외판원 순회

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<int> numbers;
int n;
int sum = 2147483647;

void check()
{
	int temp = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (board[numbers[i]][numbers[i + 1]] == 0)
			return;
		else
			temp += board[numbers[i]][numbers[i + 1]];
	}

	if (board[numbers[n - 1]][numbers[0]] == 0)
		return;

	temp += board[numbers[n - 1]][numbers[0]];

	sum = min(temp, sum);
}

int main()
{
	cin >> n;

	board.resize(n);

	for (int i = 0; i < n; i++)
	{
		board[i].resize(n);

		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}


	numbers.resize(n);

	for (int i = 0; i < n; i++)
	{
		numbers[i] = i;
	}

	do
	{
		check();
	} while (next_permutation(numbers.begin(), numbers.end()));

	cout << sum;
}
