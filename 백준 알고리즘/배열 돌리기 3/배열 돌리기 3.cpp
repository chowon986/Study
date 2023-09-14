//// 배열 돌리기 3 : https://www.acmicpc.net/problem/16935

// 이전 풀이
 

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n, m, r;
//
//void MovePos(vector<vector<int>>& b, string direction)
//{
//	vector<vector<int>> newBoard(n);
//	for (int i = 0; i < n; i++)
//	{
//		newBoard[i].resize(m);
//	}
//
//	if (direction == "right")
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				if (i < n / 2 && j < m / 2 )
//				{
//					newBoard[i][j + m / 2] = b[i][j];
//				}
//				else if (i < n / 2 && j >= m / 2)
//				{
//					newBoard[i + n / 2][j] = b[i][j];
//				}
//				else if (i >= n / 2 && j >= m / 2)
//				{
//					newBoard[i][j - m / 2] = b[i][j];
//				}
//				else if (i >= n / 2 && j < m / 2)
//				{
//					newBoard[i - n/2][j] = b[i][j];
//				}
//			}
//		}
//	}
//	else if (direction == "left")
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				if (i < n / 2 && j < m / 2)
//				{
//					newBoard[i + n / 2][j] = b[i][j];
//				}
//				else if (i >= n / 2 && j < m / 2) // 왼쪽 아래
//				{
//					newBoard[i][j + m/2] = b[i][j];
//				}
//				else if (i >= n / 2 && j >= m / 2) // 오른쪽 아래
//				{
//					newBoard[i - n/2][j] = b[i][j];
//				}
//				else if (i < n / 2 && j >= m / 2) // 오른쪽 위
//				{
//					newBoard[i][j - m/2] = b[i][j];
//				}
//			}
//		}
//	}
//
//	b = newBoard;
//}
//
//void Rotation(vector<vector<int>>& b, string direction)
//{
//	vector <vector<int>> newBoard(m);
//	for (int i = 0; i < m; i++)
//	{
//		newBoard[i].resize(n);
//	}
//
//	if (direction == "right")
//	{
//		for (int i = 0; i < n; i++) 
//		{
//			for (int j = 0; j < m; j++)
//			{
//				newBoard[j][n - i - 1] = b[i][j];
//			}
//		}
//	}
//	else if (direction == "left")
//	{
//		for (int i = 0; i < n; i++) 
//		{
//			for (int j = 0; j < m; j++) 
//			{
//				newBoard[m - j - 1][i] = b[i][j];
//			}
//		}
//	}
//
//	int temp = m;
//	m = n;
//	n = temp;
//
//	b = newBoard;
//}
//
//void SwitchArray(vector<vector<int>>& b, string direction)
//{
//	if (direction == "horizontal")
//	{
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j * 2 < n; j++)
//			{
//				swap(b[j][i], b[n - j - 1][i]);
//			}
//		}
//	}
//	else if (direction == "vertical")
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j * 2 < m; j++)
//			{
//				swap(b[i][j], b[i][m - j - 1]);
//			}
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m >> r;
//
//	vector<vector<int>> board;
//
//	board.resize(n);
//
//	for (int i = 0; i < n; i++)
//	{
//		board[i].resize(m);
//		for (int j = 0; j < m; j++)
//		{
//			int temp;
//			cin >> temp;
//
//			board[i][j] = temp;
//		}
//	}
//
//	int calNum;
//	for (int i = 0; i < r; i++)
//	{
//		cin >> calNum;
//
//		switch (calNum)
//		{
//		case 1:
//		{
//			SwitchArray(board, "horizontal");
//			break;
//		}
//		case 2:
//		{
//			SwitchArray(board, "vertical");
//			break;
//		}
//		case 3:
//		{
//			Rotation(board, "right");
//			break;
//		}
//		case 4:
//		{
//			Rotation(board, "left");
//			break;
//		}
//		case 5:
//			MovePos(board, "right");
//			break;
//		case 6:
//			MovePos(board, "left");
//			break;
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << board[i][j] << ' ';
//		}
//
//		cout << '\n';
//	}
//}
//

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

deque<deque<int>> q;
int n, m, r;

void go(int num)
{
	deque<deque<int>> cq;

	if (num == 1)
	{
		while (!q.empty())
		{
			cq.push_back(q.back());
			q.pop_back();
		}
	}
	else if (num == 2)
	{
		while (!q.empty())
		{
			reverse(q.front().begin(), q.front().end());
			cq.push_back(q.front());
			q.pop_front();
		}
	}
	else if (num == 3)
	{
		int size = q[0].size();

		cq.resize(size);

		for (int j = 0; j < size; j++)
		{
			for (int i = q.size() - 1; i >= 0; i--)
			{
				cq[j].push_back(q[i].front());
				q[i].pop_front();
			}
		}
	}
	else if (num == 4)
	{
		int size = q[0].size();

		cq.resize(size);

		for (int j = 0; j < size; j++)
		{
			for (int i = q.size() - 1; i >= 0; i--)
			{
				cq[j].push_front(q[i].back());
				q[i].pop_back();
			}
		}
	}
	else if (num == 5)
	{
		cq.resize(q.size(), deque<int>(q[0].size()));
		int nn = q.size();
		int nm = q[0].size();

		int hn = nn / 2;
		int hm = nm / 2;

		for (int i = 0; i < nn; i++)
		{
			for (int j = 0; j < nm; j++)
			{
				if (i < hn && j < hm)
				{
					cq[i][j + hm] = q[i][j];
				}
				else if (i < hn && j >= hm)
				{
					cq[i + hn][j] = q[i][j];
				}
				else if (i >= hn && j < hm)
				{
					cq[i - hn][j] = q[i][j];
				}
				else if (i >= hn && j >= hm)
				{
					cq[i][j - hm] = q[i][j];
				}
			}
		}
	}
	else if (num == 6)
	{
		cq.resize(q.size(), deque<int>(q[0].size()));
		int nn = q.size();
		int nm = q[0].size();

		int hn = nn / 2;
		int hm = nm / 2;

		for (int i = 0; i < nn; i++)
		{
			for (int j = 0; j < nm; j++)
			{
				if (i < hn && j < hm)
				{
					cq[i + hn][j] = q[i][j];
				}
				else if (i < hn && j >= hm)
				{
					cq[i][j - hm] = q[i][j];
				}
				else if (i >= hn && j < hm)
				{
					cq[i][j + hm] = q[i][j];
				}
				else if (i >= hn && j >= hm)
				{
					cq[i - hn][j] = q[i][j];
				}
			}
		}
	}

	q = cq;
}

int main()
{
	cin >> n >> m >> r;

	q.resize(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			q[i].push_back(temp);
		}
	}

	int num;
	for (int i = 0; i < r; i++)
	{
		cin >> num;
		go(num);
	}

	for (int i = 0; i < q.size(); i++)
	{
		for (int j = 0; j < q[0].size(); j++)
		{
			cout << q[i][j] << ' ';
		}

		cout << '\n';
	}
}