#include<iostream>

using namespace std;

class Queue
{
	int* a;
	int size;
	int front;
	int rear;
	int noe;
public:
	Queue()
	{
		size = 2;
		a = new int[size];
		front = 0;
		rear = 0;
		noe = 0;
	}
	void set_size(int s)
	{
		size = s;
		delete[] a;
		a = new int[size];
	}
	bool is_empty()
	{
		if (noe == 0) return true;
		else return false;
	}
	bool is_full()
	{
		if (noe == size) return true;
		else return false;
	}
	void en_queue(int v)
	{
		if (is_full())
		{
			cout << "queue full !" << endl;
		}
		else
		{
			a[rear] = v;
			rear = (rear + 1) % size;
			noe++;
		}
	}
	int de_queue()
	{
		if (is_empty())
		{
			cout << "Queue is empty !" << endl;
			return 0;
		}
		else
		{
			int x = a[front];
			front = (front + 1) % size;
			noe--;
			return x;
		}
	}
};

class Stack
{
	int size;
	Queue q;
	Queue temp;

public:
	Stack(int s)
	{
		size = s;
		q.set_size(size);
		temp.set_size(size);
	}

	void push(int x)
	{
		q.en_queue(x);
	}
	int pop()
	{	
		int x = 0;
		while (!q.is_empty())
		{
			x = q.de_queue();
			if (!q.is_empty())
			{
				temp.en_queue(x);
			}
		}
		while (!temp.is_empty())
		{
			q.en_queue(temp.de_queue());
		}
		return x;
	}
};

int main()
{
	Stack s(10);
	int x = 1;

	while (x != 0)
	{
		cout << "choose:-" << endl;
		cout << "<1> push." << endl;
		cout << "<2> pop." << endl;
		cout << "<0> end." << endl;
		cout << "enter :";
		cin >> x;

		switch (x)
		{
		case 1:
			int v;
			cout << "value: ";
			cin >> v;
			s.push(v);
			break;
		case 2:
			cout << s.pop() << endl;
			break;
		}
	}

	return 0;
}