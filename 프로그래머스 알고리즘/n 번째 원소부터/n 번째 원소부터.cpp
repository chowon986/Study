// n 번째 원소부터.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181892

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n)
{
    int size = num_list.size();
    vector<int> answer;

    for (int i = n - 1; i < size; i++)
        answer.push_back(num_list[i]);

    return answer;
}

int main()
{

}