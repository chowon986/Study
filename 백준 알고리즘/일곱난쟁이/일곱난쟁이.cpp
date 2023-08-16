//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    vector<int> Heights;
//
//    for (int i = 0; i < 9; i++)
//    {
//        int Temp;
//        cin >> Temp;
//        Heights.push_back(Temp);
//    }
//
//    sort(Heights.begin(), Heights.end());
//
//    for (int i = 0; i < 8; i++)
//    {
//        for (int j = i + 1; j < 9; j++)
//        {
//            int Sum = 0;
//            for (int k = 0; k < 9; k++)
//            {
//                if (k != i && k != j)
//                {
//                    Sum += Heights[k];
//
//                    if (Sum > 100)
//                        break;
//                }
//            }
//
//            if (Sum == 100)
//            {
//                for (int l = 0; l < 9; l++)
//                {
//                    if (l != i && l != j)
//                        cout << Heights[l] << '\n';
//                }
//
//                return 0;
//            }
//        }
//    }
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int count = 9;
	int sum = 0;
	vector<int> talls;

	for (int i = 0; i < count; i++)
	{
		int value;
		cin >> value;

		talls.push_back(value);
		sum += value;
	}

	sort(talls.begin(), talls.end());

	int i = 0;
	int j = 1;
	int copySum = sum;
	while (i < count - 1)
	{
		if (j == count)
		{
			++i;
			j = i + 1;
		}
		else if (j > count)
			break;

		copySum -= talls[i];
		copySum -= talls[j];

		if (copySum == 100)
		{
			for (int k = 0; k < count; k++)
			{
				if (k != i && k != j)
					cout << talls[k] << '\n';
			}
			break;
		}
		else
		{
			copySum = sum;
			++j;
		}
	}
}