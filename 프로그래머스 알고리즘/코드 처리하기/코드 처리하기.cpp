// 코드 처리하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181932

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string code)
{
    bool mode = false;
    int lastIndex = size(code);
    string answer = "";

    for (int i = 0; i < lastIndex; i++)
    {
        if (mode == false)
        {
            if (code[i] != '1' && i % 2 == 0)
            {
                answer += code[i];
            }
            else if (code[i] == '1')
            {
                mode = !mode;
            }
        }
        else
        {
            if (code[i] != '1' && i % 2 != 0)
            {
                answer += code[i];
            }
            else if (code[i] == '1')
            {
                mode = !mode;
            }
        }
    }

    if (answer.size() == 0)
        return "EMPTY";

    return answer;
}

int main()
{
    solution("abc1abc1abc");
}