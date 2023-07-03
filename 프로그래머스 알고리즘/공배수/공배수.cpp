// 공배수.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181936

#include <string>
#include <vector>

using namespace std;

int solution(int number, int n, int m)
{
    bool result1 = number % n == 0 ? true : false;

    if (result1 == false)
        return false;

    result1 = number % m == 0 ? true : false;

    if (result1 == false)
        return false;

    return true;
}