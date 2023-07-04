// flag에 따라 다른 값 반환하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181933

#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag)
{
    return flag == true ? a + b : a - b;
}

int main()
{

}