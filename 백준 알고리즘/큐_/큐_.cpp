#include <iostream>
#include <string>
using namespace std;

struct node
{
	int data;
	node* nextNode;
};

class myQueue
{
public:
	void push(int num);
	void pop();
	void size();
	void empty();
	void front();
	void back();


private:
	node* head;
};

void myQueue::push(int num)
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

void myQueue::pop()
{
	if (head == nullptr)
	{
		cout << -1 << '\n';
		return;
	}

	cout << head->data << '\n';

	node* newNode = head->nextNode;
	if (newNode == nullptr)
	{
		head = nullptr;
	}
	else
	{
		head = newNode;
	}
}

void myQueue::size()
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

void myQueue::empty()
{
	int result = head == nullptr ? 1 : 0;
	cout << result << '\n';
}

void myQueue::front()
{
	if (head == nullptr)
	{
		cout << -1 << '\n';
		return;
	}

	cout << head->data << '\n';
}

void myQueue::back()
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

	myQueue* q = new myQueue();

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		if (temp == "push")
		{
			int num;
			cin >> num;

			q->push(num);
		}
		else if (temp == "pop")
		{
			q->pop();
		}
		else if (temp == "size")
		{
			q->size();
		}
		else if (temp == "empty")
		{
			q->empty();
		}
		else if (temp == "front")
		{
			q->front();
		}
		else if (temp == "back")
		{
			q->back();
		}
	}
}