// 수열과 구간 쿼리2.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181923

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
    vector<int> answer;

    // queries의 각 요소는 s, e, k
    int queriesSize = queries.size();
    int arrSize = arr.size();

    for (int i = 0; i < queriesSize; i++)
    {
        int s = queries[i][0];
        int e = queries[i][1];
        int k = queries[i][2];
        int minValue = -1;

        bool hasAnswer = false;

        for (int j = s; j <= e; j++)
        {
            if (arr[j] > k)
            {
                if (minValue == -1 || minValue > arr[j])
                {
                    minValue = arr[j];
                    hasAnswer = true;
                }
            }
        }

        if (hasAnswer)
            answer.push_back(minValue);
        else
            answer.push_back(-1);
    }

    return answer;
}

int main()
{
    vector<int> arr = { 0,1,2,4,3 };
    vector<vector<int>> queries = { {0,4,2},{0,3,2},{0,2,2} };
    solution(arr, queries);
}