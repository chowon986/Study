// 더 크게 합치기 : https://school.programmers.co.kr/learn/courses/30/lessons/181939

#include <string>
#include <vector>

using namespace std;

int solution(int a, int b)
{
    string A = to_string(a);
    string B = to_string(b);

    int AplusB = stoi(A + B);
    int BplusA = stoi(B + A);

    int answer = 0;

    if (AplusB > BplusA)
        answer = AplusB;
    else
        answer = BplusA;

    return answer;
}

int main()
{

}