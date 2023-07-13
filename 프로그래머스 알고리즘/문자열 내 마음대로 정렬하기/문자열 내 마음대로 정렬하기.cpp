// 문자열 내 마음대로 정렬하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/12915

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) 
{
    int size = strings.size();

    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (strings[j][n] < strings[j - 1][n])
                swap(strings[j], strings[j - 1]);
            else if (strings[j][n]
                == strings[j - 1][n])
                sort(strings.begin() + j - 1, strings.begin() + j + 1);
        }

    }

    return strings;
}

int main()
{
    vector<string> strings = { "abce", "abcd", "cdx" };
    solution(strings, 1);
}