// Guess

#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board;
vector<int> numbers;
vector<int> answer;
vector<bool> isUsed(20, false);
int tc;

bool check(int index)
{
	for (int i = 0; i <= index; i++)
	{
		int sum = 0;
		sum += numbers[i];

		if (numbers[i] > 0)
		{
			if (board[i][i] != '+') return false;

		}
		else if (numbers[i] == 0)
		{
			if (board[i][i] != '0') return false;
		}
		else
		{
			if (board[i][i] != '-') return false;
		}

		for (int j = i + 1; j <= index; j++)
		{
			sum += numbers[j];

			if (sum > 0)
			{
				if (board[i][j] != '+') return false;

			}
			else if (sum == 0)
			{
				if (board[i][j] != '0') return false;
			}
			else
			{
				if (board[i][j] != '-') return false;
			}
		}
	}

	return true;
}

void go(int index, int count)
{
	if (answer.size() > 0) return;

	if (index > tc) return;

	if (index == tc)
	{
		for (int i = 0; i < index; i++)
		{
			answer.push_back(numbers[i]);
		}

		return;
	}

	for (int i = -10; i <= 10; i++)
	{
		numbers[index] = i;
		if (!check(index)) continue;
		go(index + 1, count);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> tc;
	board.resize(tc);

	for (int i = 0; i < tc; i++)
	{
		board[i].resize(tc);
		for (int j = i; j < tc; j++)
		{
			char temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}

	numbers.resize(tc);

	go(0, tc);

	for (int i = 0; i < tc; i++)
	{
		cout << answer[i] << ' ';
	}
}