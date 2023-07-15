// 배열의 원소 삭제하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181844

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list)
{
    int arrSize = arr.size();
    int delete_listSize = delete_list.size();

    for (int i = 0; i < delete_listSize; i++)
    {
        auto it = find(arr.begin(), arr.end(), delete_list[i]);

        if(it != arr.end())
            arr.erase(it);
    }

    return arr;
}

int main()
{
    vector<int> arr = { 293, 1000, 395, 678, 94 };
    vector<int> delete_list = { 94, 777, 104, 1000, 1, 12 };

    solution(arr, delete_list);

}