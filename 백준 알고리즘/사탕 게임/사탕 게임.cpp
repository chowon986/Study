//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int CheckMaxCandies(vector<vector<char>> C, int N)
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//
//		}
//	}
//
//	return 1;
//}
//
//int main()
//{
//	int N;
//	cin >> N;
//
//	vector<vector<char>> Candies;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			char Temp;
//			cin >> Temp;
//			Candies[i][j] = Temp;
//		}
//	}
//
//	for (int i = 0; i < N - 1; i++)
//	{
//		int Max = -1;
//		for (int j = 0; j < N - 1; j++)
//		{
//			// 오른쪽이랑 비교
//			int Temp = j + 1;
//
//			if (Candies[i][j] != Candies[i][Temp])
//			{
//				swap(Candies[i][j], Candies[i][Temp]);
//
//				int CurCandy = CheckMaxCandies(Candies, N);
//				if (Max < CurCandy)
//				{
//					Max = CurCandy;
//				}
//			}
//		}
//	}
//}

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> board;

int checkBoard(int boardSize)
{
	// 가로 체크
	int max = -1;
	char prevWord;
	for (int i = 0; i < boardSize; i++)
	{
		prevWord = board[i][0];
		int count = 0;
		for (int j = 0; j < boardSize; j++)
		{
			if (prevWord == board[i][j])
				++count;
			else
			{
				if (count > max) max = count;
				count = 1;
				prevWord = board[i][j];
			}
		}

		if (count > max) max = count;
	}

	for (int i = 0; i < boardSize; i++)
	{
		prevWord = board[i][0];
		int count = 0;
		for (int j = 0; j < boardSize; j++)
		{
			if (prevWord == board[j][i])
				++count;
			else
			{
				if (count > max) max = count;
				count = 1;
				prevWord = board[j][i];
			}
		}

		if (count > max) max = count;
	}

	return max;
}

int main()
{
	int boardSize;
	cin >> boardSize;

	board.resize(boardSize);

	for (int i = 0; i < boardSize; i++)
	{
		board[i].resize(boardSize);
	}

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			char temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}

	int maxCandy = -1;

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			if (j != boardSize - 1)
			{
				if (board[i][j] != board[i][j + 1])
				{
					swap(board[i][j], board[i][j + 1]);
					maxCandy = checkBoard(boardSize) > maxCandy ? checkBoard(boardSize) : maxCandy;
					swap(board[i][j], board[i][j + 1]);
				}
			}

			if (i != boardSize - 1)
			{
				if (board[i][j] != board[i + 1][j])
				{
					swap(board[i][j], board[i + 1][j]);
					maxCandy = checkBoard(boardSize) > maxCandy ? checkBoard(boardSize) : maxCandy;
					swap(board[i][j], board[i + 1][j]);
				}
			}
		}
	}

	cout << maxCandy;
}