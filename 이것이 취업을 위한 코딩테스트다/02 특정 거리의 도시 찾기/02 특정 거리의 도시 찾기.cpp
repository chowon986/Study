// 02 특정 거리의 도시 찾기

// 메모리 초과 풀이(인접행렬)

//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//vector<vector<int>> board;
//vector<int> d;
//vector<bool> isVisited;
//
//int n, m, k, x;
//
//void bfs(int start)
//{
//	queue<int> q;
//	q.push(start);
//	isVisited[start] = true;
//	d[start] = 0;
//
//	while (!q.empty())
//	{
//		int now = q.front();
//		q.pop();
//
//		for (int i = 1; i <= n; i++)
//		{
//			if (board[now][i] == 1 && isVisited[i] == false)
//			{
//				isVisited[i] = true;
//				d[i] = d[now] + 1;
//				q.push(i);
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m >> k >> x;
//
//	board.resize(n + 1, vector<int>(n + 1));
//	isVisited.resize(n + 1, false);
//	d.resize(n + 1);
//
//	for (int i = 0; i < m; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		board[a][b] = 1;
//	}
//
//	bfs(x);
//	
//	bool match = false;
//
//	for (int i = 1; i < d.size(); i++)
//	{
//		if (d[i] == k)
//		{
//			cout << i << '\n';
//			match = true;
//		}
//	}
//
//	if (!match)
//		cout << -1;
//}


//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//vector<vector<int>> board;
//vector<int> dis;
//vector<bool> isVisited;
//
//int n, m, k, x;
//
//void bfs(int start)
//{
//    queue<int> q;
//    q.push(start);
//    dis[start] = 0;
//    q.pop();
//
//    while (!q.empty())
//    {
//        int now = q.front();
//
//        for (int i = 1; i <= n; i++)
//        {
//            if (board[now][i] == 1 && isVisited[i] == false)
//            {
//                isVisited[i] = true;
//                q.push(i);
//                dis[i] = dis[now] + 1;
//            }
//        }
//    }
//}
//
//int main()
//{
//    cin.tie(NULL);
//    ios::sync_with_stdio(false);
//
//    cin >> n >> m >> k >> x;
//
//    board.resize(n + 1, vector<int>(n + 1));
//    dis.resize(n + 1);
//    isVisited.resize(n + 1, false);
//
//    for (int i = 0; i < m; i++)
//    {
//        int a, b;
//        cin >> a >> b;
//        board[a][b] = 1;
//    }
//
//    bfs(x);
//
//    bool isMatched = false;
//    for (int i = 1; i <= n + 1; i++)
//    {
//        if (dis[i] == k)
//        {
//            cout << i << '\n';
//            isMatched = true;
//        }
//    }
//
//    if (!isMatched) cout << -1;
//}

// 리스트 형식으로 넣어서 풀기

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> board;
vector<int> dis;
vector<bool> isVisited;

int n, m, k, x;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    dis[start] = 0;
    isVisited[start] = true;

    while (!q.empty())
    {
        int now = q.front();
		q.pop();

        for (int i = 0; i < board[now].size(); i++)
        {
            if (isVisited[board[now][i]] == false)
            {
                isVisited[board[now][i]] = true;
                q.push(board[now][i]);
                dis[board[now][i]] = dis[now] + 1;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k >> x;

    board.resize(n + 1);
    dis.resize(n + 1);
    isVisited.resize(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
    }

    bfs(x);

    bool isMatched = false;
    for (int i = 1; i < n + 1; i++)
    {
        if (dis[i] == k)
        {
            cout << i << '\n';
            isMatched = true;
        }
    }

    if (!isMatched) cout << -1;
}
