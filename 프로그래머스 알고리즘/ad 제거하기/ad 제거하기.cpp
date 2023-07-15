// ad 제거하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181870

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strArr)
{
    vector<string> answer;

    for (string str : strArr)
    {
        if (str.find("ad") == string::npos)
            answer.push_back(str);
    }

    return answer;
}

int main()
{

}