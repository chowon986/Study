// 문자열 묶기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181855


#include <string>
#include <vector>

using namespace std;

int solution(vector<string> strArr)
{
    int strSizeArr[31];
    int size = strArr.size();

    for (int i = 0; i < size; i++)
    {
        ++strSizeArr[strArr[i].size()];
    }

    int max = -1;

    for (int i = 0; i < 31; i++)
    {
        if (strSizeArr[i] > max)
            max = strSizeArr[i];
    }

    return max;
}

int main()
{
    vector<string> strArr = { "a","bc","d","efg","hi" };
    solution(strArr);
}