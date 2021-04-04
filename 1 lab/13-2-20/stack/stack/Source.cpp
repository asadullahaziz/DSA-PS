#include<iostream>

using namespace std;

class Stack
{
private:
	int arr[5];
	int index;

public:

	Stack()
	{
		index = -1;
	}

	void push()
	{
		if (index == 4)
		{
			cout << "stack full !" << endl;
			return;
		}
		else
		{
			int value = 0;
			cout << "Enter value :";
			cin >> value;
			index++;
			arr[index] = value;
		}
	}

	int pop()
	{
		if (index == -1)
		{
			cout << "stack empty !" << endl;
		}
		else
		{
			int value = 0;
			value = arr[index];
			index--;
			return value;
		}
	}

};

void menu()
{
	int choice = 0;
	Stack st;

	while (choice != 3)
	{
		cout << "--MENU--" << endl;
		cout << "<1> Push." << endl;
		cout << "<2> POP." << endl;
		cout << "<3> end." << endl;

		cout << "Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			st.push();
			break;
		case 2:
			int p;
			p = st.pop();
			cout << "POP value: " << p << endl;
			break;
		case 3:
			break;
		}
	}
}

int main()
{
	menu();

	return 0;
}