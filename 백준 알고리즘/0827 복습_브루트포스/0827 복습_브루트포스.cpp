// 복습_브루트포스

// NM과 K (1)

// NM과 K (1) : https://www.acmicpc.net/problem/18290
//#include <iostream>
//using namespace std;
//
//int a[10][10];
//bool c[10][10];
//int n, m, k;
//int ans = -2147483647;
//int dx[] = { 0, 0, 1, -1 };
//int dy[] = { 1, -1, 0, 0 };
//
//void go(int cnt, int sum)
//{
//	if (cnt == k)
//	{
//		if (ans < sum) ans = sum;
//		return;
//	}
//	
//	for (int x = 0; x < n; x++)
//	{
//		for (int y = 0; y < m; y++)
//		{
//			if (c[x][y]) continue;
//			bool ok = true;
//			for (int i = 0; i < 4; i++)
//			{
//				int nx = x + dx[i];
//				int ny = y + dy[i];
//				if (0 <= nx && nx < n && 0 <= ny && ny < m)
//				{
//					// 격자판 범위 안에 있고,
//					if (c[nx][ny]) // 선택한 적이 있다면 선택할 수 없음
//						ok = false;
//				}
//			}
//
//			if (ok)
//			{
//				c[x][y] = true;
//				go(cnt + 1, sum + a[x][y]);
//				c[x][y] = false;
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m >> k;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			int temp;
//			cin >> temp;
//
//			a[i][j] = temp;
//		}
//	}
//
//	go(0, 0);
//
//	cout << ans;
//}


// 리모컨 : https://www.acmicpc.net/problem/1107

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int target, count;
//	cin >> target >> count;
//
//	bool brokenNumbers[10] = { false, };
//
//	for (int i = 0; i < count; i++)
//	{
//		int temp;
//		cin >> temp;
//		brokenNumbers[temp] = true;
//	}
//
//	int curChannel = 100;
//	int moveCount = curChannel > target ? curChannel - target : target - curChannel;
//
//	int ChannelA = target;
//	int copyChannel = ChannelA;
//
//	while (copyChannel > 0)
//	{
//		if (brokenNumbers[copyChannel % 10])
//		{
//			// 고장난 채널이면
//			--ChannelA;
//			copyChannel = ChannelA;
//		}
//		else
//		{
//			copyChannel /= 10;
//		}
//	}
//
//
//	if (ChannelA == 0)
//	{
//		if (brokenNumbers[0]) ChannelA = -1000000;
//		else ChannelA = 0;
//	}
//
//	int tempNum = to_string(ChannelA).size();
//	tempNum += target - ChannelA;
//
//	moveCount = min(tempNum, moveCount);
//
//	int ChannelB = target;
//	copyChannel = ChannelB;
//
//	while (copyChannel >= 0 && copyChannel < 1000000)
//	{
//		if (brokenNumbers[copyChannel % 10])
//		{
//			// 고장난 채널이면
//			++ChannelB;
//			copyChannel = ChannelB;
//		}
//		else
//		{
//			copyChannel /= 10;
//			if (copyChannel == 0)
//				break;
//		}
//	}
//
//	tempNum = to_string(ChannelB).size();
//	tempNum += ChannelB - target;
//
//	moveCount = min(tempNum, moveCount);
//
//	cout << moveCount;
//}

// 반례 모음집 : https://www.acmicpc.net/board/view/109610
/*
0
0
답:1

0
2
0 1
답:3
*/

// N과 M (1) : https://www.acmicpc.net/problem/15649

//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> numbers(10);
//vector<bool> isUsed(10, false);
//
//void go(int index, int count, int maxNum)
//{
//	if (index == count)
//	{
//		for (int i = 0; i < index; i++)
//			cout << numbers[i] << ' ';
//
//		cout << '\n';
//		return;
//	}
//
//	for (int i = 1; i <= maxNum; i++)
//	{
//		if (isUsed[i]) continue;
//
//		numbers[index] = i;
//		isUsed[i] = true;
//		go(index + 1, count, maxNum);
//		isUsed[i] = false;
//	}
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	go(0, m, n);
//}

// N과 M (7) : https://www.acmicpc.net/problem/15656

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> numbers;
//vector<int> answer;
//
//void go(int index, int count)
//{
//	if (index == count)
//	{
//		for (int i = 0; i < index; i++)
//		{
//			cout << answer[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//
//	for (int i = 0; i < numbers.size(); i++)
//	{
//		answer[index] = numbers[i];
//		go(index + 1, count);
//	}
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		numbers.push_back(temp);
//	}
//
//	sort(numbers.begin(), numbers.end());
//
//	answer.resize(m + 1);
//	go(0, m);
//}

// 일곱 난쟁이 : https://www.acmicpc.net/problem/2309

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> talls;
//vector<bool> isTrue(10, true);
//
//int main()
//{
//	int sumTall = 0;
//	for (int i = 0; i < 9; i++)
//	{
//		int temp;
//		cin >> temp;
//		talls.push_back(temp);
//		sumTall += temp;
//	}
//
//	sort(talls.begin(), talls.end());
//
//	for (int i = 0; i < 9; i++)
//	{
//		int totalTalls = sumTall;
//		for (int j = 0; j < 9; j++)
//		{
//			if (i == j) continue;
//			// 9명 중 2명의 난쟁이를 빼면 7난쟁이가 됨
//			if (100 == totalTalls - (talls[i] + talls[j]))
//			{
//				isTrue[i] = isTrue[j] = false;
//
//				for (int k = 0; k < 9; k++)
//				{
//					if (isTrue[k])
//						cout << talls[k] << '\n';
//				}
//				return 0;
//			}
//		}
//	}
//}

// 사탕 게임 : https://www.acmicpc.net/problem/3085

#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board;
int n;

int check()
{
	// 가로 최대 체크
	int maxValue = 0;
	for (int i = 0; i < n; i++)
	{
		char prevWord = board[i][0];
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (prevWord == board[i][j])
				++count;
			else
			{
				prevWord = board[i][j];
				maxValue = max(count, maxValue);
				count = 1;
			}
		}

		maxValue = max(count, maxValue);
	}

	// 세로 최대 체크
	for (int i = 0; i < n; i++)
	{
		char prevWord = board[0][i];
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (prevWord == board[j][i])
				++count;
			else
			{
				prevWord = board[j][i];
				maxValue = max(count, maxValue);
				count = 1;
			}
		}

		maxValue = max(count, maxValue);
	}

	return maxValue;
}

int main()
{
	int Maximum = 0;
	cin >> n;

	board.resize(n);

	for (int i = 0; i < n; i++)
	{
		board[i].resize(n);

		for (int j = 0; j < n; j++)
		{
			char temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;

			if (j == n - 1) // 맨 오른쪽이고
			{
				if (i != n - 1) // 맨 밑이 아니면
				{
					// 아래쪽 체크 가능
					swap(board[i][j], board[i + 1][j]);
					Maximum = max(Maximum, check());
					swap(board[i][j], board[i + 1][j]);
				}
			}

			else if (i == n - 1) // 맨 밑이면 
			{
				// 오른쪽 체크 가능
				swap(board[i][j], board[i][j + 1]);
				Maximum = max(Maximum, check());
				swap(board[i][j], board[i][j + 1]);
			}
			else
			{
				// 아래쪽 체크 가능
				swap(board[i][j], board[i + 1][j]);
				Maximum = max(Maximum, check());
				swap(board[i][j], board[i + 1][j]);

				// 오른쪽 체크 가능
				swap(board[i][j], board[i][j + 1]);
				Maximum = max(Maximum, check());
				swap(board[i][j], board[i][j + 1]);
			}
		}
	}

	cout << Maximum;
}

// 날짜 계산 : https://www.acmicpc.net/problem/1476

// 테트로미노 : https://www.acmicpc.net/problem/14500

// 카잉 달력 : https://www.acmicpc.net/problem/6064

// 수 이어 쓰기1 : https://www.acmicpc.net/problem/1748
