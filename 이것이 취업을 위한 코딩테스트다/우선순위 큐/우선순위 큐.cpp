// 우선순위 큐

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> pq;

	pq.push(9);
	pq.push(8);
	pq.push(7);
	pq.push(1);

	while (!pq.empty())
	{
		cout << pq.top() << ' ';
		pq.pop();
	}

	// 출력 결과 9 8 7 1

	pq.push(-9);
	pq.push(-8);
	pq.push(-7);
	pq.push(-1);

	while (!pq.empty())
	{
		cout << pq.top() << ' ';
		pq.pop();
	}

	// 출력 결과 -1 -7 -8 -9
}