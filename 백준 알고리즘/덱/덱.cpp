#include <iostream>
using namespace std;

struct Node
{
	int Data;
	Node* Next;
};

class Deque
{
public:
	void push_front(int Num);
	void push_back(int Num);
	void pop_front();
	void pop_back();
	int size();
	bool empty();
	int front();
	int back();

public:
	Node* Head;
};

void Deque::push_front(int Num)
{
	Node* NewNode = new Node();
	NewNode->Data = Num;

	if (Head == nullptr)
	{
		Head = NewNode;
		return;
	}

	Node* NextNode = Head;
	Head = NewNode;
	Head->Next = NextNode;
}

void Deque::push_back(int Num)
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

void Deque::pop_front()
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

void Deque::pop_back()
{
	if (Head == nullptr)
	{
		cout << -1 << endl;
		return;
	}

	Node* CurNode = Head;
	Node* PrevNode = Head;

	while (CurNode->Next != nullptr)
	{
		PrevNode = CurNode;
		CurNode = CurNode->Next;
	}

	cout << CurNode->Data << endl;
	PrevNode->Next = nullptr;
	if (CurNode == Head)
	{
		Head = nullptr;
	}

	delete CurNode;
}

int Deque::size()
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

bool Deque::empty()
{
	if (size() > 0)
		return 0;
	else return 1;
}

int Deque::front()
{
	if (Head == nullptr)
	{
		return -1;
	}

	return Head->Data;
}

int Deque::back()
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

	Deque* NewDeque = new Deque();

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string Word;
		cin >> Word;

		if (Word == "push_back")
		{
			int N;
			cin >> N;

			NewDeque->push_back(N);
		}
		else if (Word == "push_front")
		{
			int N;
			cin >> N;

			NewDeque->push_front(N);
		}
		else if (Word == "pop_front")
		{
			NewDeque->pop_front();
		}
		else if (Word == "pop_back")
		{
			NewDeque->pop_back();
		}
		else if (Word == "size")
		{
			cout << NewDeque->size() << endl;
		}
		else if (Word == "empty")
		{
			cout << NewDeque->empty() << endl;
		}
		else if (Word == "front")
		{
			cout << NewDeque->front() << endl;;
		}
		else if (Word == "back")
		{
			cout << NewDeque->back() << endl;;
		}
	}
}
