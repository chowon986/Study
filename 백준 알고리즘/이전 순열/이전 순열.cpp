// 이전 순열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> numbers;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    if (prev_permutation(numbers.begin(), numbers.end()))
    {
        for (int i = 0; i < n; i++)
        {
            cout << numbers[i] << ' ';
        }
    }
    else
    {
        cout << "-1";
    }

    return 0;
}
