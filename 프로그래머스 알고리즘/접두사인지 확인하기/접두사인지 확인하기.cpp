// 접두사인지 확인하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181906

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string is_prefix)
{
    int size = my_string.size();
    string tempString = "";
    vector<string> allPrefixs;

    for (int i = 0; i < size; i++)
    {
        tempString += my_string[i];
        allPrefixs.push_back(tempString);
    }

    for (string word : allPrefixs)
    {
        if (word == is_prefix)
            return 1;
    }

    return 0;
}

int main()
{
    \
}