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
	Queue(int s)
	{
		size = s;
		a = new int[size];
		front = 0;
		rear = 0;
		noe = 0;
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

int main()
{
	Queue q;

	return 0;
}