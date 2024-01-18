// Thread.cpp

#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

// 요즘에는 os에 상관없이 멀티 스레드를 사용할 수 있게 변하고 있음
// 아직 소켓은 여기에 포함되어 있지 않음 ㅜㅜ

void Hellofunc()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "하세요" << endl;
		this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void Byefunc()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "잘가" << endl;
	}
}

//int main()
//{
//	thread t(Hellofunc);
//	thread t2([]()
//		{
//			for (int i = 0; i < 10; i++)
//			{
//				cout << "람다 잘가" << endl;
//				this_thread::sleep_for(std::chrono::milliseconds(500));
//			}
//		});
//	// thread 변수명(함수명);
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << "안녕하세요" << endl;
//		this_thread::sleep_for(std::chrono::milliseconds(500));
//	}
//
//	t.join();
//	t2.join();
//
//	return 0;
//}

//int main()
//{
//	// atomic
//	// 전부 처리하거나 아무것도 하지 못하게 함
//	atomic<int> num = 0;
//	thread tA([&]()
//		{
//			for (int i = 0; i < 100000; i++)
//			{
//				num++;
//			}
//		});
//
//	thread tB([&]()
//		{
//			for (int i = 0; i < 100000; i++)
//			{
//				num--;
//			}
//		});
//
//
//	tA.join();
//	tB.join();
//
//	cout << num << endl;
//}

int main()
{
	thread tC([&]()
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "안녕하세요" << endl;
			this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}
	);

	int cnt = 0;
	cout << "입력 : ";
	cin >> cnt;

	cout << cnt;
	cout << "입력한 값 : " << cnt << endl;

	tC.join();

	return 0;
}