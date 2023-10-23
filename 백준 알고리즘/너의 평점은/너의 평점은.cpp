// 너의 평점은.cpp 

#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	float sumScore = 0;
	float sumSubject = 0;

	for (int i = 0; i < 20; i++)
	{
		string a, b, c;
		cin >> a >> b >> c;

		float temp = 0.f;
		if (c == "A+") temp = 4.5f;
		else if (c == "A0") temp = 4.0f;
		else if (c == "B+") temp = 3.5f;
		else if (c == "B0") temp = 3.0f;
		else if (c == "C+") temp = 2.5f;
		else if (c == "C0") temp = 2.0f;
		else if (c == "D+") temp = 1.5f;
		else if (c == "D0") temp = 1.0f;
		else if (c == "F") temp = 0.f;
		else if (c == "P") continue;
		sumScore += stoi(b) * temp;
		sumSubject += stoi(b);
	}

	cout.precision(6);
	cout << sumScore / sumSubject;
}