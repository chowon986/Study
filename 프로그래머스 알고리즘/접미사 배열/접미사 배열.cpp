// 접미사 배열.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181909

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string my_string)
{
    vector<string> answer;
    int size = my_string.size();

    for (int i = 0; i < size; i++)
    {
        string tempString = "";

        for (int j = i; j < size; j++)
        {
            tempString += my_string[j];
        }

        answer.push_back(tempString);
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{

}