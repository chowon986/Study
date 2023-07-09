// 배열 만들기5.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181912

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l)
{
    int size = intStrs.size();
    vector<int> answer;

    for (int i = 0; i < size; i++)
    {
        string tempString = "";
        for (int j = s; j < s + l; j++)
        {
            tempString += intStrs[i][j];
        }

        int curNum = stoi(tempString);

        if (curNum > k)
            answer.push_back(curNum);
    }

    return answer;
}

int main()
{
    vector<string> intStrs = { "0123456789","9876543210","9999999999999" };
    int k = 50000;
    int s = 5;
    int l = 5;

    solution(intStrs, k, s, l);
}