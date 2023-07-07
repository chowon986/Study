// 배열 만들기4.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181918

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int size = arr.size();
    int i = 0;
    int j = 0;
    vector<int> stk;

    while (i < size)
    {
        if (i == 0)
        {
            stk.push_back(arr[i]);
            i++;
        }
        else
        {
            j = stk.size() - 1;

            if (stk[j] < arr[i])
            {
                stk.push_back(arr[i]);
                i++;
            }
            else
                stk.pop_back();
        }
    }

    return stk;
}

int main()
{
    vector<int> arr = { 1, 4, 2, 5, 3 };
    solution(arr);
}