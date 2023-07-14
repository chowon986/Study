// 5명씩.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181886

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names)
{
    int size = names.size();
    vector<string> answer;

    for (int i = 0; i < size; i += 5)
        answer.push_back(names[i]);

    return answer;
}

int main()
{

}