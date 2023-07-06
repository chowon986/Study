// 수열과 구간 쿼리3.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181924

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
    int size = queries.size();
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        int firstIndex = queries[i][j];
        int lastIndex = queries[i][j + 1];

        std::swap(arr[firstIndex], arr[lastIndex]);
    }

    return arr;
}

int main()
{
    vector<int> arr = { 0, 1, 2, 3, 4 };
    vector<vector<int>> queries = { {0,3}, {1,2}, {1,4} };

    solution(arr, queries);
}