// 주사위 게임2.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181930

#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int a, int b, int c)
{
    int answer = 0;
    int sameCount = 0;

    if (a == b)
        sameCount++;

    if (b == c)
        sameCount++;

    if (a == c)
        sameCount++;

    if (sameCount == 0)
        answer = a + b + c;
    else if (sameCount == 1)
        answer = (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2));
    else if (sameCount == 3)
        answer = (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2)) * (pow(a, 3) + pow(b, 3) + pow(c, 3));

    return answer;
}

int main()
{

}