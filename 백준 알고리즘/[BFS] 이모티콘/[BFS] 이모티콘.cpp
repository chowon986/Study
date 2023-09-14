// [BFS] 이모티콘

// 화면에 있는 이모티콘은 1개
// 연산의 종류
// 1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장
// 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기
// 3. 화면에 있는 이모티콘 중 하나를 삭제

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
vector<vector<int>> d(1001, vector<int>(1001, -1));

int main() 
{
    int n;
    cin >> n;

    queue<pair<int, int>> q;

    q.push({ 1, 0 });

    d[1][0] = 0; // 화면의 이모티콘 개수, 클립보드에 있는 이모티콘 개수

    while (!q.empty()) 
    {
        int s, c;
        s = q.front().first;
        c = q.front().second;

        q.pop();

        // 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
        if (d[s][s] == -1) 
        {
            d[s][s] = d[s][c] + 1;
            q.push({ s, s });
        }

        // 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
        // 화면 + 클립보드에 있는 이모티콘의 수가 결과보다 같거나 작은 경우 수행
        if (s + c <= n && d[s + c][c] == -1)
        {
            d[s + c][c] = d[s][c] + 1;
            q.push({ s + c, c });
        }

        // 화면에 있는 이모티콘에서 1개를 뺀 값이 0보다 같거나 클 때
        if (s - 1 >= 0 && d[s - 1][c] == -1) 
        {
            d[s - 1][c] = d[s][c] + 1;
            q.push({ s - 1, c });
        }
    }

    int ans = -1;

    // 최소값 구하기
    for (int i = 0; i <= n; i++) 
    {
        if (d[n][i] != -1) 
        {
            if (ans == -1 || ans > d[n][i]) 
            {
                ans = d[n][i];
            }
        }
    }

    cout << ans << '\n';
    return 0;
}