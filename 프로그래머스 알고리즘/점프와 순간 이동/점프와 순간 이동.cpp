﻿// 점프와 순간 이동.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/12980

#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;

    while (n != 0)
    {
        if (n % 2 == 0)  n /= 2;
        else
        {
            n--;
            answer += 1;
        }
    }

    return answer;
}

int main()
{

}