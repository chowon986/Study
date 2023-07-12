// 순서 바꾸기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181891

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n)
{
    int size = num_list.size();
    vector<int> answer;

    for (int i = n; i < size; i++)
        answer.push_back(num_list[i]);

    for (int i = 0; i < n; i++)
        answer.push_back(num_list[i]);

    return answer;
}

int main()
{

}