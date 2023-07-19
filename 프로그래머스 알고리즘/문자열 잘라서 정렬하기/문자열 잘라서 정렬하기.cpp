// 문자열 잘라서 정렬하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181866#

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString)
{
    int size = myString.size();
    vector<string> answer;
    string temp = "";
    for (int i = 0; i < size; i++)
    {
        if (myString[i] == 'x')
        {
            if (temp != "")
                answer.push_back(temp);
            temp = "";
        }
        else
            temp += myString[i];
    }

    if (temp != "")
        answer.push_back(temp);

    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{

}