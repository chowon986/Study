// 글자 지우기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181900

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices)
{
    int indicesSize = indices.size();
    sort(indices.begin(), indices.end(), greater<>());

    for (int i = 0; i < indicesSize; i++)
    {
        my_string.erase(my_string.begin() + indices[i]);
    }

    return my_string;
}

int main()
{

}