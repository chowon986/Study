// 대충 만든 자판.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/160586

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;
    int minIdx;
    int size = targets.size();
    answer.resize(size);


    for (int i = 0; i < size; i++)
    {
        int stringSize = targets[i].size();

        for (int j = 0; j < stringSize; j++)
        {
            minIdx = 101;
            char targetWord = targets[i][j];

            int keymapSize = keymap.size();
            for (int k = 0; k < keymapSize; k++)
            {
                int keymapStringSize = keymap[k].size();
                for (int q = 0; q < keymapStringSize; q++)
                {
                    if (keymap[k][q] == targetWord && q < minIdx)
                        minIdx = q + 1;
                }
            }

            if (minIdx == 101)
            {
                answer[i] = -1;
                break;
            }
            else
                answer[i] += minIdx;
        }
    }

    return answer;
}

int main()
{
    vector<string> keymap = { "ABACD", "BCEFD" };
    vector<string> targets = { "ABCD","AABB" };
    solution(keymap, targets);
}