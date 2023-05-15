#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> Heights;

    for (int i = 0; i < 9; i++)
    {
        int Temp;
        cin >> Temp;
        Heights.push_back(Temp);
    }

    sort(Heights.begin(), Heights.end());

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            int Sum = 0;
            for (int k = 0; k < 9; k++)
            {
                if (k != i && k != j)
                {
                    Sum += Heights[k];

                    if (Sum > 100)
                        break;
                }
            }

            if (Sum == 100)
            {
                for (int l = 0; l < 9; l++)
                {
                    if (l != i && l != j)
                        cout << Heights[l] << '\n';
                }

                return 0;
            }
        }
    }
}