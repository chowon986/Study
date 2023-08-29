// 이전 풀이

//#include <iostream>
//using namespace std;
//
//struct Node
//{
//	int Data;
//	Node* Next;
//};
//
//class Queue
//{
//public:
//	void push_back(int Num);
//	void pop_front();
//	int size();
//	bool empty();
//	int front();
//	int back();
//
//public:
//	Node* Head;
//};
//
//void Queue::push_back(int Num)
//{
//	Node* CurNode = Head;
//	Node* NewNode = new Node();
//	NewNode->Data = Num;
//
//	if (Head != nullptr)
//	{
//		while (CurNode->Next != nullptr)
//		{
//			CurNode = CurNode->Next;
//		}
//
//		CurNode->Next = NewNode;
//	}
//	else
//	{
//		Head = NewNode;
//	}
//}
//
//void Queue::pop_front()
//{
//	if (Head == nullptr)
//	{
//		cout << -1 << endl;
//		return;
//	}
//
//	cout << Head->Data << endl;
//	Node* NextNode = Head->Next;
//	delete Head;
//	Head = NextNode;
//}
//
//int Queue::size()
//{
//	Node* CurNode = Head;
//	int Count = 1;
//
//	if (CurNode == nullptr)
//		return 0;
//
//	while (CurNode->Next != nullptr)
//	{
//		CurNode = CurNode->Next;
//		++Count;
//	}
//
//	return Count;
//}
//
//bool Queue::empty()
//{
//	if (size() > 0)
//		return 0;
//	else return 1;
//}
//
//int Queue::front()
//{
//	if (Head == nullptr)
//	{
//		return -1;
//	}
//
//	return Head->Data;
//}
//
//int Queue::back()
//{
//	Node* CurNode = Head;
//	if (CurNode == nullptr)
//		return -1;
//
//	while (CurNode->Next != nullptr)
//	{
//		CurNode = CurNode->Next;
//	}
//
//	return CurNode->Data;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	Queue* NewQueue = new Queue();
//
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		string Word;
//		cin >> Word;
//
//		if (Word == "push")
//		{
//			int N;
//			cin >> N;
//
//			NewQueue->push_back(N);
//		}
//		else if (Word == "pop")
//		{
//			NewQueue->pop_front();
//		}
//		else if (Word == "size")
//		{
//			cout << NewQueue->size() << endl;
//		}
//		else if (Word == "empty")
//		{
//			cout << NewQueue->empty() << endl;
//		}
//		else if (Word == "front")
//		{
//			cout << NewQueue->front() << endl;;
//		}
//		else if (Word == "back")
//		{
//			cout << NewQueue->back() << endl;;
//		}
//	}
//}

#include <iostream>
#include <string>
using namespace std;

struct myNode
{
	int data;
	myNode* nextNode;
};

class queue
{
public:
	void push(int _data)
	{
		if (head == nullptr)
		{
			myNode* newNode = new myNode();
			head = newNode;
			head->data = _data;
			return;
		}
		else
		{
			myNode* newNode = new myNode();
			newNode->data = _data;
			
			myNode* curNode = head;

			while (curNode->nextNode != nullptr)
			{
				curNode = curNode->nextNode;
			}

			curNode->nextNode = newNode;
		}
	}

	void pop()
	{
		if (head == nullptr)
		{
			cout << -1 << '\n';
			return;
		}
		else
		{
			cout << head->data << '\n';
			myNode* newHead = head->nextNode;
			head->nextNode = nullptr;
			delete head;
			head = newHead;
		}
	}

	int size()
	{
		if (head == nullptr)
			return 0;

		myNode* curNode = head;
		int count = 1;
		while (curNode->nextNode != nullptr)
		{
			curNode = curNode->nextNode;
			++count;
		}

		return count;
	}

	bool empty()
	{
		return head == nullptr;
	}

	void front()
	{
		if (head == nullptr) cout << -1 << '\n';
		else cout << head->data << '\n';
	}

	void back()
	{
		if (head == nullptr) cout << -1 << '\n';
		else
		{
			myNode* curNode = head;

			while (curNode->nextNode != nullptr)
			{
				curNode = curNode->nextNode;
			}

			cout << curNode->data << '\n';
		}
	}

public:
	myNode* head;
};

int main()
{
	int n;
	cin >> n;

	queue* newNode = new queue();

	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;

		if (word == "push")
		{
			int temp;
			cin >> temp;
			newNode->push(temp);
		}
		else if (word == "pop")
		{
			newNode->pop();
		}
		else if (word == "size")
		{
			cout << newNode->size() << '\n';
		}
		else if (word == "empty")
		{
			if (newNode->empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (word == "front")
		{
			newNode->front();
		}
		else if (word == "back")
		{
			newNode->back();
		}
	}
}