// 조건에 맞게 수열 변환하기2.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181881

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr)
{
    vector<int> prevArr;
    int size = arr.size();
    int count = 0;

    while (prevArr != arr)
    {
        ++count;
        prevArr = arr;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] >= 50 && arr[i] % 2 == 0)
                arr[i] /= 2;
            else if (arr[i] < 50 && arr[i] % 2 != 0)
                arr[i] = arr[i] * 2 + 1;
        }
    }

    return count - 1;
}

int main()
{

}