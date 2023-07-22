// 두 수의 합.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181846

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string a, string b)
{
    if (a == "0" && b == "0")
        return a;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> tempAnswer;

    if (a.size() < b.size())
        swap(a, b);

    tempAnswer.resize(a.size() + 1, 0);

    b.resize(a.size(), '0');

    for (int i = 0; i < a.size(); i++)
    {
        int temp = (a[i] - '0') + (b[i] - '0');
        tempAnswer[i] = temp;
    }

    for (int j = 0; j < a.size(); j++)
    {
        if (tempAnswer[j] >= 10)
        {
            tempAnswer[j] -= 10;
            tempAnswer[j + 1] += 1;
        }
    }

    reverse(tempAnswer.begin(), tempAnswer.end());;

    string answer = "";

    for (int i = 0; i < tempAnswer.size(); i++)
    {
        if (i == 0 && tempAnswer[i] == '0')
        {

        }
        else
            answer += (tempAnswer[i] + '0');
    }

    return answer;
}

int main()
{
    string a = "18446744073709551615";
    string b = "287346502836570928366";
    solution(a, b);
}