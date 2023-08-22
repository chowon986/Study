// 차이를 최대로

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
int sum = -10000000;
int n;

void check()
{
    int temp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        temp += abs(numbers[i] - numbers[i + 1]);
    }

    sum = max(sum, temp);
}

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    sort(numbers.begin(), numbers.end());

    do
    {
        check();
    } while (next_permutation(numbers.begin(), numbers.end()));

    cout << sum;
}