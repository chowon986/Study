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
//class Deque
//{
//public:
//	void push_front(int Num);
//	void push_back(int Num);
//	void pop_front();
//	void pop_back();
//	int size();
//	bool empty();
//	int front();
//	int back();
//
//public:
//	Node* Head;
//};
//
//void Deque::push_front(int Num)
//{
//	Node* NewNode = new Node();
//	NewNode->Data = Num;
//
//	if (Head == nullptr)
//	{
//		Head = NewNode;
//		return;
//	}
//
//	Node* NextNode = Head;
//	Head = NewNode;
//	Head->Next = NextNode;
//}
//
//void Deque::push_back(int Num)
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
//void Deque::pop_front()
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
//void Deque::pop_back()
//{
//	if (Head == nullptr)
//	{
//		cout << -1 << endl;
//		return;
//	}
//
//	Node* CurNode = Head;
//	Node* PrevNode = Head;
//
//	while (CurNode->Next != nullptr)
//	{
//		PrevNode = CurNode;
//		CurNode = CurNode->Next;
//	}
//
//	cout << CurNode->Data << endl;
//	PrevNode->Next = nullptr;
//	if (CurNode == Head)
//	{
//		Head = nullptr;
//	}
//
//	delete CurNode;
//}
//
//int Deque::size()
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
//bool Deque::empty()
//{
//	if (size() > 0)
//		return 0;
//	else return 1;
//}
//
//int Deque::front()
//{
//	if (Head == nullptr)
//	{
//		return -1;
//	}
//
//	return Head->Data;
//}
//
//int Deque::back()
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
//	Deque* NewDeque = new Deque();
//
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		string Word;
//		cin >> Word;
//
//		if (Word == "push_back")
//		{
//			int N;
//			cin >> N;
//
//			NewDeque->push_back(N);
//		}
//		else if (Word == "push_front")
//		{
//			int N;
//			cin >> N;
//
//			NewDeque->push_front(N);
//		}
//		else if (Word == "pop_front")
//		{
//			NewDeque->pop_front();
//		}
//		else if (Word == "pop_back")
//		{
//			NewDeque->pop_back();
//		}
//		else if (Word == "size")
//		{
//			cout << NewDeque->size() << endl;
//		}
//		else if (Word == "empty")
//		{
//			cout << NewDeque->empty() << endl;
//		}
//		else if (Word == "front")
//		{
//			cout << NewDeque->front() << endl;;
//		}
//		else if (Word == "back")
//		{
//			cout << NewDeque->back() << endl;;
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

class deque
{
public:
	void push_front(int data)
	{
		if (head == nullptr)
		{
			myNode* newNode = new myNode();
			newNode->data = data;
			head = newNode;
			return;
		}
		else
		{
			myNode* newNode = new myNode();
			newNode->data = data;
			newNode->nextNode = head;
			head = newNode;
		}
	}

	void push_back(int data)
	{
		if (head == nullptr)
		{
			myNode* newNode = new myNode();
			newNode->data = data;
			head = newNode;
			return;
		}
		else
		{
			myNode* newNode = new myNode();
			newNode->data = data;

			myNode* curNode = head;

			while (curNode->nextNode != nullptr)
			{
				curNode = curNode->nextNode;
			}

			curNode->nextNode = newNode;
		}
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << -1 << '\n';
			return;
		}

		else
		{
			cout << head->data << '\n';

			if (head->nextNode != nullptr)
			{
				head = head->nextNode;
			}
			else
			{
				head = nullptr;
			}
		}
	}
	
	void pop_back()
	{
		if (head == nullptr)
		{
			cout << -1 << '\n';
			return;
		}

		else
		{
			myNode* curNode = head;
			myNode* prevNode = head;

			while (curNode->nextNode != nullptr)
			{
				prevNode = curNode;
				curNode = curNode->nextNode;
			}

			cout << curNode->data << '\n';

			if (prevNode == curNode)
			{
				head = nullptr;
			}
			else
			{
				prevNode->nextNode = nullptr;
			}
		}
	}

	void size()
	{

		if (head == nullptr)
		{
			cout << 0 << '\n';
			return;
		}

		myNode* curNode = head;
		int count = 1;

		while (curNode->nextNode != nullptr)
		{
			curNode = curNode->nextNode;
			++count;
		}

		cout << count << '\n';
	}

	void empty()
	{
		if (head == nullptr)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	void front()
	{
		if (head == nullptr)
		{
			cout << -1 << '\n';
			return;
		}

		else
		{
			cout << head->data << '\n';
		}
	}

	void back()
	{
		if (head == nullptr)
		{
			cout << -1 << '\n';
			return;
		}

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
	
private:
	myNode* head;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	deque* newDeque = new deque();

	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;

		if (word == "push_front")
		{
			int temp;
			cin >> temp;
			newDeque->push_front(temp);
		}
		else if (word == "push_back")
		{
			int temp;
			cin >> temp;
			newDeque->push_back(temp);
		}
		else if (word == "pop_back")
		{
			newDeque->pop_back();
		}
		else if (word == "pop_front")
		{
			newDeque->pop_front();
		}
		else if (word == "size")
		{
			newDeque->size();
		}
		else if (word == "empty")
		{
			newDeque->empty();
		}
		else if (word == "front")
		{
			newDeque->front();
		}
		else if (word == "back")
		{
			newDeque->back();
		}
	}
}
