// 링크와 스타트

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
vector<int> first;
vector<int> second;
int tc;
int minValue = 1000000;

int check(vector<int>& first, vector<int>& second)
{
	int firstSum = 0;
	int secondSum = 0;
	int firstSize = first.size();
	int secondSize = second.size();

	for (int i = 0; i < firstSize; i++)
	{
		for (int j = 0; j < firstSize; j++)
		{
			if (i == j) continue;
			firstSum += board[first[i]][first[j]];
		}
	}

	for (int i = 0; i < secondSize; i++)
	{
		for (int j = 0; j < secondSize; j++)
		{
			if (i == j) continue;
			secondSum += board[second[i]][second[j]];
		}
	}

	return firstSum > secondSum ? firstSum - secondSum : secondSum - firstSum;
}

void go(int index, vector<int>& first, vector<int>& second)
{
	if (index == tc)
	{
		if (first.size() == 0 || second.size() == 0) return;
		int temp = check(first, second);
		minValue = min(temp, minValue);
	}

	if (index > tc) return;

	first.push_back(index);
	go(index + 1, first, second);
	first.pop_back();
	second.push_back(index);
	go(index + 1, first, second);
	second.pop_back();
}

int main()
{
	cin >> tc;

	board.resize(tc);

	for (int i = 0; i < tc; i++)
	{
		board[i].resize(tc);
		for (int j = 0; j < tc; j++)
		{
			int temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}

	go(0, first, second);

	cout << minValue;
}
