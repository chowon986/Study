// 멀리 뛰기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/12914

#include <string>
#include <vector>

using namespace std;

long long solution(int n)
{
    int d[2001] = { 0, };
    d[0] = 1;
    d[1] = 1;

    for (int i = 2; i <= n; i++)
        d[i] = (d[i - 1] + d[i - 2]) % 1234567;

    long long answer = d[n];

    return answer;
}

int main()
{

}