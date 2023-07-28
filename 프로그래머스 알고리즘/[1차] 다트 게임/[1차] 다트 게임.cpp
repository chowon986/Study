// [1차] 다트 게임.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/17682

#include <string>
#include <math.h>
#include <vector>

using namespace std;

int solution(string dartResult)
{
    int size = dartResult.size();
    string tempScore = "";
    int curScore = 0;
    vector<int> scores;

    for (int i = 0; i < size; i++)
    {
        if (dartResult[i] == 'S')
        {
            curScore = stoi(tempScore);
            scores.push_back(pow(curScore, 1));
            tempScore = "";
        }
        else if (dartResult[i] == 'D')
        {
            curScore = stoi(tempScore);
            scores.push_back(pow(curScore, 2));
            tempScore = "";
        }
        else if (dartResult[i] == 'T')
        {
            curScore = stoi(tempScore);
            scores.push_back(pow(curScore, 3));
            tempScore = "";
        }
        else if (dartResult[i] == '*')
        {
            if (scores.size() == 1)
            {
                scores[0] *= 2;
            }
            else
            {
                int lastIdx = scores.size() - 1;
                scores[lastIdx] *= 2;
                scores[lastIdx - 1] *= 2;
            }
        }
        else if (dartResult[i] == '#')
        {
            int lastIdx = scores.size() - 1;
            scores[lastIdx] *= -1;
        }
        else
            tempScore += dartResult[i];
    }

    int answer = 0;

    for (int i : scores)
    {
        answer += i;
    }

    return answer;
}

int main()
{

}