// 무작위로 K개의 수 뽑기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181858

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int k)
{
    vector<int> answer;

    for (int num : arr)
    {
        if (answer.size() < k)
        {
            if (answer.size() == 0 ||
                find(answer.begin(), answer.end(), num) == answer.end())
                answer.push_back(num);
        }
    }

    while (answer.size() < k)
    {
        answer.push_back(-1);
    }

    return answer;
}

int main()
{
    vector<int> arr = { 0, 1, 1, 2, 2, 3 };
    int k = 3;
    solution(arr, k);
}