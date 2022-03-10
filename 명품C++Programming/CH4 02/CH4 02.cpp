// 정수 공간 5개를 배열로 동적 할당받고, 정수를 5개 입력받아 평균을 구하고 출력한 뒤
// 배열을 소멸시키도록 main() 함수를 작성하라

#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    double avg = 0;
    cout << "정수 5개 입력>>";
    int* arr = new int[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    avg = (double)sum / 5;
    cout << avg;

    delete[] arr;
}

