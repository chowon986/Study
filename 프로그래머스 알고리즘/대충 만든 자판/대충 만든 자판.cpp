// 대충 만든 자판.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/160586

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;

    int size = targets.size();
    int minIdx = 101;

    for (int i = 0; i < size; i++)
    {
        int stringSize = targets[i].size();

        for (int j = 0; j < stringSize; j++)
        {
            char targetWord = targets[i][j];

            int keymapSize = keymap.size();
            for (int k = 0; k < keymapSize; k++)
            {
                int keymapStringSize = keymap[k].size();
                for (int q = 0; q < keymapStringSize; q++)
                {
                    if (keymap[k][q] == targetWord &&
                        q < minIdx)
                    {
                        minIdx = q + 1;
                    }

                }
            }

            if (minIdx == 101)
                answer.push_back(-1);
            else
                answer.push_back(minIdx);
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