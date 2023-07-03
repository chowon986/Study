#include <iostream>
#include <vector>

using namespace std;

int CheckMaxCandies(vector<vector<char>> C, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

		}
	}
}

int main()
{
	int N;
	cin >> N;

	vector<vector<char>> Candies;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char Temp;
			cin >> Temp;
			Candies[i][j] = Temp;
		}
	}

	for (int i = 0; i < N - 1; i++)
	{
		int Max = -1;
		for (int j = 0; j < N - 1; j++)
		{
			// 오른쪽이랑 비교
			int Temp = j + 1;

			if (Candies[i][j] != Candies[i][Temp])
			{
				swap(Candies[i][j], Candies[i][Temp]);

				int CurCandy = CheckMaxCandies(Candies, N);
				if (Max < CurCandy)
				{
					Max = CurCandy;
				}
			}
		}
	}
}