// 배열 조각하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181893

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query)
{
    int querySize = query.size();

    for (int i = 0; i < querySize; i++)
    {
        if (i % 2 == 0)
        {
            arr.erase(arr.begin() + query[i] + 1, arr.begin() + arr.size());
        }
        else
        {
            arr.erase(arr.begin(), arr.begin() + query[i]);
        }
    }

    vector<int> answer;
    return answer;
}

int main()
{
    vector<int> arr = { 0, 1, 2, 3, 4, 5 };
    vector<int> query = { 4, 1, 2 };

    solution(arr, query);
}