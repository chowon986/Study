// 2의 영역.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181894

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> indexs;
    vector<int> answer;
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 2)
            indexs.push_back(i);
    }

    if (indexs.size() == 1)
    {
        answer.push_back(arr[indexs[0]]);
        return answer;
    }
    else if (indexs.size() == 0)
    {
        answer.push_back(-1);
        return answer;
    }

    int endIdx = indexs.size() -1;

    for (int i = indexs[0]; i <= indexs[endIdx]; i++)
    {
        answer.push_back(arr[i]);
    }

    return answer;
}

int main()
{
    vector<int> arr = {1, 2, 1 };
    solution(arr);
}