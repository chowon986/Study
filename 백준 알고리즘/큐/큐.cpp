#include <iostream>
using namespace std;

struct Node
{
	int Data;
	Node* Next;
};

class Queue
{
public:
	void push_back(int Num);
	void pop_front();
	int size();
	bool empty();
	int front();
	int back();

public:
	Node* Head;
};

void Queue::push_back(int Num)
{
	Node* CurNode = Head;
	Node* NewNode = new Node();
	NewNode->Data = Num;

	if (Head != nullptr)
	{
		while (CurNode->Next != nullptr)
		{
			CurNode = CurNode->Next;
		}

		CurNode->Next = NewNode;
	}
	else
	{
		Head = NewNode;
	}
}

void Queue::pop_front()
{
	if (Head == nullptr)
	{
		cout << -1 << endl;
		return;
	}

	cout << Head->Data << endl;
	Node* NextNode = Head->Next;
	delete Head;
	Head = NextNode;
}

int Queue::size()
{
	Node* CurNode = Head;
	int Count = 1;

	if (CurNode == nullptr)
		return 0;

	while (CurNode->Next != nullptr)
	{
		CurNode = CurNode->Next;
		++Count;
	}

	return Count;
}

bool Queue::empty()
{
	if (size() > 0)
		return 0;
	else return 1;
}

int Queue::front()
{
	if (Head == nullptr)
	{
		return -1;
	}

	return Head->Data;
}

int Queue::back()
{
	Node* CurNode = Head;
	if (CurNode == nullptr)
		return -1;

	while (CurNode->Next != nullptr)
	{
		CurNode = CurNode->Next;
	}

	return CurNode->Data;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Queue* NewQueue = new Queue();

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string Word;
		cin >> Word;

		if (Word == "push")
		{
			int N;
			cin >> N;

			NewQueue->push_back(N);
		}
		else if (Word == "pop")
		{
			NewQueue->pop_front();
		}
		else if (Word == "size")
		{
			cout << NewQueue->size() << endl;
		}
		else if (Word == "empty")
		{
			cout << NewQueue->empty() << endl;
		}
		else if (Word == "front")
		{
			cout << NewQueue->front() << endl;;
		}
		else if (Word == "back")
		{
			cout << NewQueue->back() << endl;;
		}
	}
}
