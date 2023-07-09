// 9로 나눈 나머지.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181914

#include <string>
#include <vector>

using namespace std;

int solution(string number)
{
    int size = number.size();
    int answer = 0;

    for (int i = 0; i < size; i++)
    {
        answer += number[i] - '0';
    }

    return answer % 9;
}

int main()
{

}