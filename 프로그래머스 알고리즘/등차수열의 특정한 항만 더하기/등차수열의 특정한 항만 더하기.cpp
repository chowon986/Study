// 등차수열의 특정한 항만 더하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181931

#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included)
{
    int size = included.size();
    int answer = 0;

    for (int i = 0; i < size; i++)
    {
        if (included[i] == true)
        {
            answer += a;
        }

        a += d;
    }

    return answer;
}

int main()
{

}