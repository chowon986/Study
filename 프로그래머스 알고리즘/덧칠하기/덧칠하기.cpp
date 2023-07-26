// 덧칠하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/161989

#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int size = section.size();
    vector<bool> walls;
    walls.resize(n + 1, true);
    int count = 0;

    for (int i : section)
    {
        walls[i] = false;
    }

    int i = 1;
    while (i <= n)
    {
        if (walls[i] == false)
        {
            for (int j = 0; j < m; j++)
            {
                walls[i] = true;
                if (i < n)
                    ++i;
            }

            ++count;
        }
        else
            ++i;
    }

    return count;
}

int main()
{
    solution(5, 2, { 1,2,5 });
}