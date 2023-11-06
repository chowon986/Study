#include <iostream>
#include <string>
using namespace std;

struct node
{
	int data;
	node* nextNode;
};

class myDeque
{
public:
	void push_front(int num);
	void push_back(int num);
	void pop_front();
	void pop_back();
	void size();
	void empty();
	void front();
	void back();

private:
	node* head;
};

void myDeque::push_front(int num)
{
	node* newNode = new node();
	newNode->data = num;

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	node* curNode = head;
	newNode->nextNode = curNode;
	head = newNode;
}

void myDeque::push_back(int num)
{
	node* newNode = new node();
	newNode->data = num;

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	node* curNode = head;

	while (curNode->nextNode != nullptr)
	{
		curNode = curNode->nextNode;
	}

	curNode->nextNode = newNode;
}

void myDeque::pop_front()
{
	if (head == nullptr)
	{
		cout << -1 << '\n';
		return;
	}

	cout << head->data << '\n';

	if (head->nextNode == nullptr)
	{
		head = nullptr;
	}
	else
	{
		node* curNode = head->nextNode;
		head = curNode;
	}
}

void myDeque::pop_back()
{
	if (head == nullptr)
	{
		cout << -1 << '\n';
		return;
	}

	node* prevNode = head;
	node* curNode = head;

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
		prevNode->nextNode = nullptr;
}

void myDeque::size()
{
	if (head == nullptr)
	{
		cout << 0 << '\n';
		return;
	}

	node* curNode = head;
	int count = 1;

	while (curNode->nextNode != nullptr)
	{
		curNode = curNode->nextNode;
		++count;
	}

	cout << count << '\n';
}

void myDeque::empty()
{
	int value = head == nullptr ? 1 : 0;
	cout << value << '\n';
}

void myDeque::front()
{
	if (head == nullptr)
	{
		cout << -1 << '\n';
		return;
	}

	cout << head->data << '\n';
}

void myDeque::back()
{
	if (head == nullptr)
	{
		cout << -1 << '\n';
		return;
	}

	node* curNode = head;

	while (curNode->nextNode != nullptr)
	{
		curNode = curNode->nextNode;
	}

	cout << curNode->data << '\n';
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	myDeque* dq = new myDeque();

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		if (temp == "push_front")
		{
			int num;
			cin >> num;
			dq->push_front(num);
		}
		else if (temp == "push_back")
		{
			int num;
			cin >> num;
			dq->push_back(num);
		}
		else if (temp == "pop_front")
		{
			dq->pop_front();
		}
		else if (temp == "pop_back")
		{
			dq->pop_back();
		}
		else if (temp == "size")
		{
			dq->size();
		}
		else if (temp == "empty")
		{
			dq->empty();
		}
		else if (temp == "front")
		{
			dq->front();
		}
		else if (temp == "back")
		{
			dq->back();
		}
	}
}

