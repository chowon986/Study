// 이차원 배열 대각선 순회하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181829

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k)
{
    int row = board.size();
    int column = 0;
    int answer = 0;

    for (int i = 0; i < row; i++)
    {
        column = board[i].size();

        for (int j = 0; j < column; j++)
        {
            if (i + j > k)
                break;

            answer += board[i][j];
        }
    }

    return answer;
}

int main()
{

}