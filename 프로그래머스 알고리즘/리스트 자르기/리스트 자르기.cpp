// 리스트 자르기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181897

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list)
{
    vector<int> answer;
    int startIdx = 0;
    int endIdx = 0;
    int interval = 1;

    if (n == 1)
    {
        startIdx = 0;
        endIdx = slicer[1];
    }
    else if (n == 2)
    {
        startIdx = slicer[0];
        endIdx = num_list.size() - 1;
    }
    else if (n == 3)
    {
        startIdx = slicer[0];
        endIdx = slicer[1];
    }
    else if (n == 4)
    {
        startIdx = slicer[0];
        endIdx = slicer[1];
        interval = slicer[2];
    }

    for (int i = startIdx; i <= endIdx; i += interval)
    {
        answer.push_back(num_list[i]);
    }

    return answer;
}

int main()
{
    int n = 3;
    vector<int> slicer = { 1,5,2 };
    vector<int> num_list = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    solution(n, slicer, num_list);
}