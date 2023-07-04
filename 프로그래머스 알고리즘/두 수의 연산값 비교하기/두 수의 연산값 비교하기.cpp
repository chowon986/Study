// 두 수의 연산값 비교하기 : https://school.programmers.co.kr/learn/courses/30/lessons/181938

#include <string>
#include <vector>

using namespace std;

int solution(int a, int b)
{
    int temp1 = stoi(to_string(a) + to_string(b));

    int temp2 = 2 * a * b;

    return temp1 >= temp2 ? temp1 : temp2;
}

int main()
{

}