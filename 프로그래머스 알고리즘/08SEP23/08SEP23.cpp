// 08SEP23

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    // 0은 벽이 있는 자리, 1은 벽이 없는 자리
    int n = maps.size();
    int m = maps[0].size();
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    int cx = 1;
    int cy = 1;

    vector<vector<bool>> isVisited(n + 1, vector<bool>(m + 1, false));
    vector<vector<int>> visitCount(n + 1, vector<int>(m + 1));
    queue<pair<int, int>> q;

    q.push({ cx, cy });
    isVisited[cx][cy] = true;
    visitCount[cx][cy] = 0;

    while (!q.empty())
    {
        cx = q.front().first;
        cy = q.front().second;

        if (cx == n && cy == m)
        {
            return visitCount[cx][cy];
        }

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
            if (isVisited[nx][ny] == true) continue;
            if (maps[nx - 1][ny - 1] == 0) continue;

            isVisited[nx][ny] = true;
            visitCount[nx][ny] = visitCount[cx][cy] + 1;
            q.push({ nx, ny });
        }
    }

    return -1;
}

int main()
{
    vector<vector<int>> maps({ { 1,0,1,1,1 }, { 1,0,1,0,1 }, { 1,0,1,1,1 }, { 1,1,1,0,1 }, { 0,0,0,0,1 } });

    solution(maps);
}