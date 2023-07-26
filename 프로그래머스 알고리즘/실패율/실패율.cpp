// 실패율.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/42889

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(pair<int, float>& a, pair<int, float>& b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second > b.second;
}

std::vector<int> solution(int N, vector<int> stages)
{
    float count;
    int TTLNum = stages.size();
    map<int, float> failures;

    for (int i = 1; i <= N; i++)
    {
        count = 0;

        for (int j : stages)
        {
            if (i == j)
                ++count;
        }

        if (count == 0)
            failures.insert(make_pair(i, 0));
        else
            failures.insert(make_pair(i, (count / TTLNum)));

        TTLNum -= count;
    }

    vector<pair<int, float>> v(failures.begin(), failures.end());
    vector<int> answer;
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        answer.push_back(v[i].first);
    }

    return answer;
}

int main()
{
    solution(2, { 1, 1, 1, 1 });
}