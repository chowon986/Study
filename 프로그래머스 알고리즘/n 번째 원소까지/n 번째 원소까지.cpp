// n 번째 원소까지.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181889

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n)
{
    vector<int> answer;

    for (int i = 0; i < n; i++)
        answer.push_back(num_list[i]);

    return answer;
}

int main()
{

}