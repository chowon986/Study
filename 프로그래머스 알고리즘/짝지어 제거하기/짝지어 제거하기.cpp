// 짝지어 제거하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/12973

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = -1;
    vector<char> words;

    int size = s.size();

    for (int i = 0; i < size; i++)
    {
        if (words.size() > 0)
        {
            if (words.back() == s[i])
                words.pop_back();
            else
                words.push_back(s[i]);
        }
        else
            words.push_back(s[i]);
    }


    return words.size() > 0 ? 0 : 1;
}

int main()
{

}