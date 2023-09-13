// [큐와 그래프] 연결 요소의 개수

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
vector<bool> isVisited;
bool isComponent;
int n, m;
void dfs(int x)
{
	isVisited[x] = true;

	for (int i = 1; i <= n; i++)
	{
		if (board[x][i] == 1 && isVisited[i] == false)
		{
			isComponent = true;
			dfs(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	board.resize(n + 1, vector<int>(n + 1));
	isVisited.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
		board[b][a] = 1;
	}

	int count = 0;
	
	// 이어지는 정점의 개수가 없는 경우
	for (int i = 1; i <= n; i++)
	{
		bool hasComponent = false;
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == 1) 
			{
				hasComponent = true;
				break;
			}
		}

		if (hasComponent == false)
			++count;
	}
	
	for (int i = 1; i <= n; i++)
	{
		isComponent = false;
		dfs(i);

		if (isComponent == true)
			++count;
	}

	cout << count;
}