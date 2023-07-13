// 배열의 길이에 따라 다른 연산하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181854

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n)
{
    int size = arr.size();
    int startIdx = -1;

    startIdx = (size % 2 == 0 ? 1 : 0);

    for (int i = 0; i < size; i += 2)
        arr[i] += n;

    return arr;
}

int main()
{
    vector<int> arr = { 444, 555, 666, 777 };
    int n = 100;

    solution(arr, n);
}