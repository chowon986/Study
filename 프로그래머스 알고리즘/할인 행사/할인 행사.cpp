// 할인 행사.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/131127

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    vector<string> allWants;
    for (int i = 0; i < number.size(); i++)
    {
        for (int j = 0; j < number[i]; j++)
            allWants.push_back(want[i]);
    }

    int answer = 0;
    int start = 0;
    while ((start + 10) <= discount.size())
    {
        vector<string> temp = allWants;
        for (int i = start; i < start + 10; i++)
        {
            auto it = find(temp.begin(), temp.end(), discount[i]);
            if (it != temp.end())
                temp.erase(temp.begin() + (it - temp.begin()));
            else
                break;
        }

        if (temp.empty())
            ++answer;

        ++start;
    }

    return answer;
}

int main()
{
    vector<string> want = { "banana", "apple", "rice", "pork", "pot" };
    vector<int> number = { 3, 2, 2, 2, 1 };
    vector<string> discount = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };

    solution(want, number, discount);
}