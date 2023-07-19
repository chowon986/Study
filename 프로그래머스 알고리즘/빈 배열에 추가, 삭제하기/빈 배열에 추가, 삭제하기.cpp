// 빈 배열에 추가, 삭제하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181860

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag)
{
    int size = arr.size();
    vector<int> answer;

    for (int i = 0; i < size; i++)
    {
        if (flag[i])
        {
            for (int j = 0; j < arr[i] * 2; j++)
                answer.push_back(arr[i]);
        }
        else
            for (int j = 0; j < arr[i]; j++)
                answer.pop_back();
    }

    return answer;
}

int main()
{
    vector<int> arr = { 3, 2, 4, 1, 3 };
    vector<bool> flag = { true, false, true, false, false };
    solution(arr, flag);
}