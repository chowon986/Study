// 수 조작하기2.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181925

#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog)
{
    int size = numLog.size();
    string answer = "";

    for (int i = 1; i < size; i++)
    {
        int prevValue = numLog[i - 1] - '0';
        int curValue = numLog[i] - '0';

        if (curValue - prevValue == 1)
            answer += 'w';
        else if (curValue - prevValue == -1)
            answer += 's';
        else if (curValue - prevValue == 10)
            answer += 'd';
        else
            answer += 'a';
    }

    return answer;
}

int main()
{

}