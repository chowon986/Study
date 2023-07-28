// 성격 유형 검사하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/118666?language=cpp

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    map<char, int> MBTI;
    MBTI.insert(make_pair('R', 0));
    MBTI.insert(make_pair('T', 0));
    MBTI.insert(make_pair('C', 0));
    MBTI.insert(make_pair('F', 0));
    MBTI.insert(make_pair('J', 0));
    MBTI.insert(make_pair('M', 0));
    MBTI.insert(make_pair('A', 0));
    MBTI.insert(make_pair('N', 0));

    int size = survey.size();
    for (int i = 0; i < size; i++)
    {
        if (choices[i] < 4)
        {
            auto it = MBTI.find(survey[i][0]);
            if (it != MBTI.end())
                it->second += (4 - choices[i]);
        }
        else
        {
            auto it = MBTI.find(survey[i][1]);
            if (it != MBTI.end())
                it->second += (choices[i] - 4);
        }
    }

    string answer = "";
    answer += MBTI['R'] >= MBTI['T'] ? 'R' : 'T';
    answer += MBTI['C'] >= MBTI['F'] ? 'C' : 'F';
    answer += MBTI['J'] >= MBTI['M'] ? 'J' : 'M';
    answer += MBTI['A'] >= MBTI['N'] ? 'A' : 'N';

    return answer;
}

int main()
{
    vector<string> survey = { "AN", "CF", "MJ", "RT", "NA" };
    vector<int> choices = { 5,3,2,7,5 };

    solution(survey, choices);
}