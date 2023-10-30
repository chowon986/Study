// 진법 변환.cpp

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    string n;
    int b;
    cin >> n >> b;

    int j = 0;
    unsigned int sum = 0;

    for (int i = n.size() - 1; i >= 0; i--)
    {
        int temp = n[i] - '0';
        if (n[i] >= 'A')
            temp = n[i] - '7';

		sum += temp * pow(b, j++);
    }

    cout << sum;
}