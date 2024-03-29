﻿// [BFS] 숨바꼭질 3

#include <iostream>
#include <deque>

using namespace std;

bool isVisited[1000000];
int d[1000000];
int MAX = 1000000;

int main() 
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    isVisited[n] = true;
    d[n] = 0;

    deque<int> q;
    q.push_back(n);

    while (!q.empty()) 
    {
        int now = q.front();
        q.pop_front();
        if (now * 2 < MAX) 
        {
            if (isVisited[now * 2] == false) 
            {
                q.push_front(now * 2);
                isVisited[now * 2] = true;
                d[now * 2] = d[now];
            }
        }
        if (now - 1 >= 0) 
        {
            if (isVisited[now - 1] == false) 
            {
                q.push_back(now - 1);
                isVisited[now - 1] = true;
                d[now - 1] = d[now] + 1;
            }
        }
        if (now + 1 < MAX) 
        {
            if (isVisited[now + 1] == false) 
            {
                q.push_back(now + 1);
                isVisited[now + 1] = true;
                d[now + 1] = d[now] + 1;
            }
        }
    }

    cout << d[m] << '\n';
    return 0;
}