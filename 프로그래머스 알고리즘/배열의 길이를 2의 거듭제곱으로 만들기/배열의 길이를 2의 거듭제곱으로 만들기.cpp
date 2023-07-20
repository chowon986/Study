// 배열의 길이를 2의 거듭제곱으로 만들기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181857

#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int base = 2;
    int size = arr.size();

    if (size == 1)
        return arr;

    while (base < size)
    {
        base *= 2;
    }

    base -= size;

    for (int i = 0; i < base; i++)
    {
        arr.push_back(0);
    }

    return arr;
}

int main()
{

}