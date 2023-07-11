// 문자열 뒤집기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181905

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, int s, int e)
{
    reverse(my_string.begin() + s, my_string.begin() + e + 1);

    return my_string;
}

int main()
{

}