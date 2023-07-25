// 커피 심부름.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181837

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order)
{
    int answer = 0;
    for (string curWord : order)
    {
        if (curWord == "iceamericano" || curWord == "americanoice" || curWord == "americano" || curWord == "anything" ||
            curWord == "hotamericano" || curWord == "americanohot")
            answer += 4500;
        else if (curWord == "icecafelatte" || curWord == "cafelatteice" || curWord == "hotcafelatte" ||
            curWord == "cafelattehot" || curWord == "cafelatte")
            answer += 5000;
    }

    return answer;
}

int main()
{

}