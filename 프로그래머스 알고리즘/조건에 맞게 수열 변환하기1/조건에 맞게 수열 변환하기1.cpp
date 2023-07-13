// 조건에 맞게 수열 변환하기1.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181882

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 50 && arr[i] % 2 == 0)
            arr[i] /= 2;
        else if (arr[i] < 50 && arr[i] % 2 == 1)
            arr[i] *= 2;
    }

    return arr;
}

int main()
{

}