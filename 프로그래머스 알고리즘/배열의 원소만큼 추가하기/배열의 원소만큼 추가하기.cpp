// 배열의 원소만큼 추가하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181861

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}

int main()
{
    vector<int> arr = { 5, 1, 4 };
    solution(arr);
}