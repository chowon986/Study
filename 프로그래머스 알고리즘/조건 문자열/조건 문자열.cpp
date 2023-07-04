// 조건 문자열.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181934

#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m)
{
    if (eq == "!")
    {
        if (ineq == ">")
            return n > m ? 1 : 0;
        else
            return n < m ? 1 : 0;
    }
    else
    {
        if (ineq == ">")
            return n >= m ? 1 : 0;
        else
            return n <= m ? 1 : 0;
    }
}

int main()
{

}