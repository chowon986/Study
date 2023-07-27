// 크레인 인형뽑기 게임.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/64061

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int size = board.size();
    int moveCount = moves.size();
    vector<int> dolls;
    int answer = 0;

    for (int i = 0; i < moveCount; i++)
    {
        int idx = moves[i] - 1;

        for (int j = 0; j < size; j++)
        {
            if (board[j][idx] != 0)
            {
                if (dolls.size() == 0 || dolls.back() != board[j][idx])
                {
                    dolls.push_back(board[j][idx]);
                    board[j][idx] = 0;
                    break;
                }
                else if (dolls.back() == board[j][idx])
                {
                    dolls.pop_back();
                    board[j][idx] = 0;
                    ++answer;
                    break;
                }
            }
        }
    }

    return answer * 2;
}