#include<iostream>

using namespace std;

class Queue
{
private:
	int* a;
	int size;
	int front;
	int rear;

public:

	int noe;
	int tt;

	Queue(int s)
	{
		a = new int[s];
		size = s;
		front = 0;
		rear = 0;
		noe = 0;
		tt = 0;
	}
	bool if_full()
	{
		if (noe == size)
			return true;
		else
			return false;
	}
	bool if_empty()
	{
		if (noe == 0)
			return true;
		else
			return false;
	}
	void en_queue(int d)
	{
		if (if_full())
		{
			cout << "Queue is full !" << endl;
			return;
		}
		else
		{
			a[rear++] = d;
			noe++;
			tt = tt + d;
			return;
		}
	}
};

int main()
{
	Queue q[3] = { Queue(5), Queue(5), Queue(5) };

	int input = 1;
	
	while (input != 0)
	{

		cout << "--Menu--" << endl;
		cout << "1- Enter Task." << endl;
		cout << "0- Exit." << endl;

		cout << "choose: ";
		cin >> input;

		if (input == 1)
		{
			int t = 0;
			cout << "Enter time for Task: ";
			cin >> t;

			int small = q[0].tt;
			int s = 0;
			for (int i = 0; i < 3; i++)
			{
				if (q[i].tt < small)
				{
					small = q[i].tt;
					s = i;
				}
			}
			q[s].en_queue(t);
		}
	}


	return 0;
}