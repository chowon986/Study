// 괄호 회전하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/76502

#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int size = s.size();
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        vector<char> curWord;
        for (int j = i; j < i + size; j++)
        {
            if (curWord.size() == 0)
                curWord.push_back(s[j]);
            else
            {
                if (curWord.back() == '(')
                {
                    if (s[j] == ')')
                        curWord.pop_back();
                    else
                        curWord.push_back(s[j]);
                }
                else if (curWord.back() == '[')
                {
                    if (s[j] == ']')
                        curWord.pop_back();
                    else
                        curWord.push_back(s[j]);
                }
                else if (curWord.back() == '{')
                {
                    if (s[j] == '}')
                        curWord.pop_back();
                    else
                        curWord.push_back(s[j]);
                }
                else
                    curWord.push_back(s[j]);
            }
        }

        if (curWord.size() == 0)
            ++count;

        s += s[i];
    }

    return count;
}

int main()
{
    solution("[)(]");
}