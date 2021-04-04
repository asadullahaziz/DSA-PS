#include<iostream>

using namespace std;

class Queue
{
private:
	int* a;
	int size;
	int front;
	int rear;
	int noe;

public:
	Queue(int s)
	{
		a = new int[s];
		size = s;
		front = 0;
		rear = 0;
		noe = 0;
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
			return;
		}
	}
	int de_queue()
	{
		if (if_empty())
		{
			cout << "Queue is empty !" << endl;
			return 0;
		}
		else
		{
			int x = a[front++];
			noe--;
			return x;
		}
	}
};

void menu()
{
	int input = 1;
	Queue data(5);

	while (input != 0)
	{
		system("cls");
		cout << "--MENU--" << endl;
		cout << endl;

		cout << "<1> EnQueue." << endl;
		cout << "<2> DeQueue." << endl;
		cout << "<0> Exit." << endl;

		cout << "choose an option :";
		cin >> input;

		switch (input)
		{
		case 1:
			int d;
			cout << "enter intiger: ";
			cin >> d;
			data.en_queue(d);
			system("pause");
			break;
		case 2:
			int d2 = data.de_queue();
			cout << d2 << endl;
			system("pause");
			break;
		}
	}
}

int main()
{
	menu();
	return 0;
}