// 문자열이 몇 번 등장하는지 세기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181871

#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat)
{
    int size = myString.size();
    int patSize = pat.size();
    int answer = 0;

    for (int i = 0; i < size; i++)
    {
        int k = 0;
        int count = 0;
        if (myString[i] == pat[k])
        {
            int lastIdx = (i + patSize) > size ? size : (i + patSize);
            for (int j = i; j < lastIdx; j++)
            {
                if (myString[j] == pat[k++])
                    ++count;
            }

            if(count == patSize)
                ++answer;
        }
    }

    return answer;
}

int main()
{
    string myString = "banana";
    string pat = "ana";

    solution(myString, pat);
}