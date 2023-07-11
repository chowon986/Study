// 가까운 1찾기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181898

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int idx)
{
    int size = arr.size();

    for (int i = idx; i < size; i++)
    {
        if (arr[i] == 1)
            return i;
    }

    return -1;
}

int main()
{
    vector<int> arr = { 1, 0, 0, 1, 0, 0 };
    solution(arr, 4);
}