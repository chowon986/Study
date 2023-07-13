// n개 간격의 원소들.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181888

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n)
{
    vector<int> answer;
    int size = num_list.size();

    for (int i = 0; i < size; i += n)
        answer.push_back(num_list[i]);

    return answer;
}

int main()
{

}