//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int E, S, M;
//
//	cin >> E >> S >> M;
//
//	vector<int> Year(3, 1);
//
//	int Count = 1;
//	while (Year[0] != E || Year[1] != S || Year[2] != M)
//	{
//		++Year[0];
//		if (Year[0] == 16)
//			Year[0] = 1;
//
//		++Year[1];
//		if (Year[1] == 29)
//			Year[1] = 1;
//
//		++Year[2];
//		if (Year[2] == 20)
//			Year[2] = 1;
//
//		++Count;
//	}
//
//	cout << Count;
//}

#include <iostream>
using namespace std;

int main()
{
	int e = 1;
	int s = 1;
	int m = 1;

	int cine, cins, cinm;

	cin >> cine >> cins >> cinm;

	int curYear = 1;
	while (e != cine || s != cins || m != cinm)
	{
		++e;
		if (e == 16) e = 1;
		++s;
		if (s == 29) s = 1;
		++m;
		if (m == 20) m = 1;
		++curYear;
	}
	cout << curYear;
}