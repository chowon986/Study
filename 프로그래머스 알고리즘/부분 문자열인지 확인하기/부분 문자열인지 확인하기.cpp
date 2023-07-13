// 부분 문자열인지 확인하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181843

#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target)
{
    return my_string.find(target) != -1 ? 1 : 0;
}

int main()
{

}