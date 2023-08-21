// 스타트와 링크

#include <iostream>
#include <vector>

using namespace std;

vector<int> first;
vector<int> second;

vector<vector<int>> board;
int minValue = 1000000;
int tc;

int check(vector<int>& first, vector<int>& second)
{
	int firstSum = 0;
	int secondSum = 0;
	int lastIdx = tc / 2;

	for (int i = 0; i < lastIdx; i++)
	{
		for (int j = 0; j < lastIdx; j++)
		{
			if (i == j) continue;

			firstSum += board[first[i]][first[j]];
			//firstSum += board[first[j]][first[i]];
			//secondSum += board[second[i]][second[j]];
			secondSum += board[second[j]][second[i]];
		}
	}

	return firstSum > secondSum ? (firstSum - secondSum) : (secondSum - firstSum);
}

void go(int index, vector<int>& first, vector<int>& second)
{
	if (index == tc)
	{
		if (first.size() != tc / 2) return;
		if (second.size() != tc / 2) return;

		int temp = check(first, second);
		minValue = min(temp, minValue);
		return;
	}

	if (index >= tc) return;

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