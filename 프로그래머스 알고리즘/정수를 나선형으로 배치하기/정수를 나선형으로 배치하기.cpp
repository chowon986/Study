// 정수를 나선형으로 배치하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181832

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;
    answer.resize(n);
    int num = 1;

    for (int i = 0; i < n; i++)
        answer[i].resize(n);

    int i = 0;
    int j = 0;
    int count = n;
    int turn = 0;

    while (count > 0)
    {
        ++turn;

        if (turn % 2 == 0)
            --count;

        int tempCount = count;

        if (turn % 4 == 1)
        {
            if (tempCount != n)
                j += 1;

            while (tempCount-- > 0)
            {
                answer[i][j++] = num++;
            }

            j -= 1;
        }
        else if (turn % 4 == 2)
        {
            while (tempCount-- > 0)
                answer[++i][j] = num++;
        }
        else if (turn % 4 == 3)
        {
            while (tempCount-- > 0)
                answer[i][--j] = num++;

            i -= 1;
        }
        else
        {
            while (tempCount-- > 0)
                answer[i--][j] = num++;

            i += 1;
        }
    }

    return answer;
}

int main()
{
    solution(4);
}