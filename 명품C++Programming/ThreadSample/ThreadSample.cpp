#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

int main()
{
	atomic<int> rate = 0;

	thread t([&]() {

		for (int i = 0; i <= 100; i++)
		{
			++rate;
			this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	});

	while (true)
	{
		system("cls");
	
		for (int i = 0; i < 10; i++)
		{
			if (i < rate / 10)
				cout << "■";
			else
				cout << "□";
		}
		cout << endl;

		cout << "Loading : " << rate << '%' << endl;

		if (rate >= 100)
			break;

		this_thread::sleep_for(std::chrono::milliseconds(50));
	}

	t.join();

	system("cls");
	cout << "로딩완료";

	return 0;
}