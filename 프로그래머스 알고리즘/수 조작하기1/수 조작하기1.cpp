// 수 조작하기1.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181926

#include <string>
#include <vector>

using namespace std;

int solution(int n, string control)
{
    int size = control.size();

    for (int i = 0; i < size; i++)
    {
        if (control[i] == 'w')
            n += 1;
        else if (control[i] == 's')
            n -= 1;
        else if (control[i] == 'd')
            n += 10;
        else
            n -= 10;
    }

    return n;
}

int main()
{
    solution(0, "wsdawsdassw");
}