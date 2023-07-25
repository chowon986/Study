// 정사각형으로 만들기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181830

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr)
{
    int row = arr[0].size();
    int column = arr.size();
    int size = 0;

    if (row < column)
    {
        size = column - row;
        for (int i = 0; i < column; i++)
        {
            for (int j = 0; j < size; j++)
                arr[i].push_back(0);
        }
    }
    else
    {
        arr.resize(row);

        for (int i = column; i < row; i++)
        {
            for (int j = 0; j < row; j++)
                arr[i].push_back(0);
        }
    }

    return arr;
}

int main()
{
    vector<vector<int>> arr = { {572, 22, 37}, {287, 726, 384}, {85, 137, 292}, {487, 13, 876 } };
    solution(arr);
}