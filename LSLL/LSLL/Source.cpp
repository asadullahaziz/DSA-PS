#include"LSLL.h"


int menu()
{
	system("cls");

	cout << "--Linear Singly Link List--" << endl;
	cout << "<1> Inseart At Head" << endl;
	cout << "<2> Inseart At Tail" << endl;
	cout << "<3> Remove At Head" << endl;
	cout << "<4> Remove At tail" << endl;
	cout << "<5> Display" << endl;
	cout << "<6> Inseart After" << endl;
	cout << "<7> Inseart Before" << endl;
	cout << "<8> Remove After" << endl;
	cout << "<9> Remove Before" << endl;
	cout << "<0> Exit" << endl;

	int choice;
	cout << "Choose Operation : ";
	cin >> choice;

	return choice;
}

int main()
{
	LSLL <int> l;
	int choice = 0;

	do
	{
		choice = menu();

		int value = 0, key = 0;

		switch (choice)
		{
		case 1:
			cout << "Data :";
			cin >> value;
			l.InseartAtHead(value);
			break;

		case 2:
			cout << "Data :";
			cin >> value;
			l.InseartAtTail(value);
			break;

		case 3:
			l.RemoveAtHead();
			break;

		case 4:
			l.RemoveAtTail();
			break;

		case 5:
			l.display();
			break;

		case 6:
			cout << "Data :";
			cin >> value;
			cout << "key :";
			cin >> key;
			l.InseartAfter(value, key);
			break;

		case 7:
			cout << "Data :";
			cin >> value;
			cout << "key :";
			cin >> key;
			l.InseartBefore(value, key);
			break;

		case 8:
			int key;
			cout << "key :";
			cin >> key;
			l.RemoveAfter(key);
			break;

		case 9:
			cout << "key :";
			cin >> key;
			l.RemoveAfter(key);
			break;
		}
		system("pause");

	} while (choice != 0);

	return 0;
}