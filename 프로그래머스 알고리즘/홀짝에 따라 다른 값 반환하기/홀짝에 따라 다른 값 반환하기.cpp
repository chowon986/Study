// Ȧ¦�� ���� �ٸ� �� ��ȯ�ϱ� : https://school.programmers.co.kr/learn/courses/30/lessons/181935

#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    if (n % 2 != 0)
    {
        while (n != 0)
        {
            answer += n;
            n -= 2;
        }
    }
    else
    {
        while (n != 0)
        {
            answer += n * n;
            n -= 2;
        }
    }

    return answer;
}

int main()
{
    solution(7);
}