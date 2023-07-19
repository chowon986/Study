// 배열 만들기6.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181859

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int i = 0;
    int size = arr.size();
    vector<int> stk;

    while (i < size)
    {
        if (stk.size() == 0)
            stk.push_back(arr[i]);
        else
        {
            int stkSize = stk.size();

            if (stk[stkSize - 1] == arr[i])
                stk.pop_back();
            else
                stk.push_back(arr[i]);
        }

        ++i;
    }

    if (stk.size() == 0)
        stk.push_back(-1);

    return stk;
}

int main() 
{

}