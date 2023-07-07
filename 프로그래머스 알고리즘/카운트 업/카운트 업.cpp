// 카운트 업.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181920

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start, int end)
{
    vector<int> answer;

    for (int i = start; i <= end; i++)
        answer.push_back(i);

    return answer;
}

int main()
{

}