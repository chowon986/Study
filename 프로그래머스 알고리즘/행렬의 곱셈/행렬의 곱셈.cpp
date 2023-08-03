// 행렬의 곱셈.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/12949

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    int arr1Size = arr1.size();
    answer.resize(arr1.size());

    for (int i = 0; i < arr1Size; i++)
    {
        int tempSize = arr1[i].size();

        for (int k = 0; k < arr2[0].size(); k++)
        {
            int tempValue = 0;

            for (int j = 0; j < tempSize; j++)
                tempValue += arr1[i][j] * arr2[j][k];

            answer[i].push_back(tempValue);
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> arr1 = { {1, 4},{3, 2},{4, 1} };
    vector<vector<int>> arr2 = { {3, 3},{3, 3} };

    solution(arr1, arr2);
}