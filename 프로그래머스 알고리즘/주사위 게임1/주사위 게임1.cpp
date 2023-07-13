// 주사위 게임1.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181839

#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int solution(int a, int b)
{
    if (a % 2 != 0 && b % 2 != 0)
    {
        return pow(a, 2) + pow(b, 2);
    } 
    else if (a % 2 != 0 || b % 2 != 0)
    {
        return 2 * (a + b);
    }
    else
    {
        return abs(a - b);
    }
}

int main()
{
    int a = 2;
    int b = 4;

    std::cout << solution(a, b);
}