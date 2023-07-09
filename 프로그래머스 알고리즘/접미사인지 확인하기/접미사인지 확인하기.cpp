// 접미사인지 확인하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181908

#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix)
{
    int size = my_string.size();
    vector<string> suffixs;

    for (int i = 0; i < size; i++)
    {
        string tempString = "";

        for (int j = i; j < size; j++)
        {
            tempString += my_string[j];
        }

        suffixs.push_back(tempString);
    }

    for (string curString : suffixs)
    {
        if (curString == is_suffix)
            return 1;
    }

    return 0;
}

int main()
{

}