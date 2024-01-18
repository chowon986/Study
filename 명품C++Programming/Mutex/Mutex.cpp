// Mutex.cpp

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int main()
{
	mutex testMutex;
	int num = 0;

	thread t([&]()
		{
			testMutex.lock();
			for (int i = 0; i < 50000; i++)
			{
				num++;
			}
			testMutex.unlock();
		});


	testMutex.lock();

	for (int i = 0; i < 50000; i++)
	{
		num--;
	}

	testMutex.unlock();

	t.join();

	cout << "num : " << num << endl;


	return 1;
}