// 전국 대회 선발 고사.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181851

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance)
{
    int size = rank.size();
    map<int, int> attendees;

    for (int i = 0; i < size; i++)
    {
        if (attendance[i])
            attendees.insert(make_pair(rank[i], i));
    }

    int answer = 0;

    auto iter = attendees.begin();
  
    answer = iter->second * 10000;
    ++iter;
    answer += iter->second * 100;
    ++iter;
    answer += iter->second;

    return answer;
}

int main()
{
    vector<int> rank = { 3, 7, 2, 5, 4, 6, 1 };
    vector<bool> attendance = { false, true, true, true, true, false, false };

    solution(rank, attendance);
}