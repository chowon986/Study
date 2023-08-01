// 영어 끝말잇기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/12981

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    vector<string> allWords;

    int curPeopleNum = 1;
    int idx = 0;
    int turn = 1;
    while (true)
    {
        if (curPeopleNum == n + 1)
        {
            curPeopleNum = 1;
            ++turn;
        }
        if (idx >= words.size())
            break;

        if (allWords.size() >= 1)
        {
            string curWord = allWords.back();
            int lastIdx = curWord.size() - 1;
            if (curWord[lastIdx] == words[idx].front())
            {
                if (find(allWords.begin(), allWords.end(), words[idx]) == allWords.end())
                {
                    allWords.push_back(words[idx]);
                    ++idx;
                    ++curPeopleNum;
                }
                else
                {
                    answer.push_back(curPeopleNum);
                    answer.push_back(turn);
                    return answer;
                }
            }
            else
            {
                answer.push_back(curPeopleNum);
                answer.push_back(turn);
                return answer;
            }
        }
        else
        {
            allWords.push_back(words[idx]);
            ++idx;
            ++curPeopleNum;
        }
    }

    answer.push_back(0);
    answer.push_back(0);

    return answer;
}

int main()
{

}