#include<iostream>
#include<string>

using namespace std;

class Entry
{
	string name;
	string password;

public:

	Entry()
	{
		name = "0";
		password = "0";
	}

	void input()
	{
		string n, p;
		cout << "Enter Name: ";
		cin >> name;
		cout << "Enter Password: ";
		cin >> password;
	}

	void show()
	{
		cout << "Name: " << name << endl;
		cout << "Password: " << password << endl;
	}

};



int main()
{
	Entry user;
	char input = 'r';
	bool flag = true;
	while (flag == true)
	{
		cout << "Enter new data :-" << endl;
		user.input();

		system("cls");

		cout << "last entered data :-" << endl;
		user.show();

		cout << "Do you want to exit? ";
		cin >> input;
		if (input == 'e' || input == 'E')
		{
			break;
		}
	}


	return 0;
}