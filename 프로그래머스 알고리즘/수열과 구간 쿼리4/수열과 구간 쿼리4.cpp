// 수열과 구간 쿼리4.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181922

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
    vector<int> answer;
    int queriesSize = queries.size();
    int arrSize = arr.size();

    for (int i = 0; i < queriesSize; i++)
    {
        int minValue = queries[i][0];
        int maxValue = queries[i][1];
        int baseValue = queries[i][2];

        for (int j = minValue; j <= maxValue; j++)
        {
            if (j % baseValue == 0)
            {
                arr[j] += 1;
            }
        }
    }

    return arr;
}

int main()
{

}