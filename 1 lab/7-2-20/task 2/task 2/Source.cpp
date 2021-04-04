#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class StudentData
{
	int index;
	string name[3];
	string rollno[3];

public:

	StudentData()
	{
		index = 0;
	}

	void enterstudent()
	{
		if (index == 3)
		{
			cout << "Space full cannot enter more data !" << endl;
			return;
		}

		cin.ignore();

		cout << "Enter Student data :-" << endl;
		cout << "name :";
		getline(cin, name[index]);
		cout << "Roll No:";
		getline(cin, rollno[index]);

		index++;
	}

	void seerecord()
	{
		if (index == 0)
		{
			cout << "no data entered yet !" << endl;
			return;
		}
		cout << setw(20) << left;
		cout << "NAME" << "Roll No" << endl;
		for (int i = 0; i < index; i++)
		{
			cout << setw(20) << left;
			cout << name[i] << rollno[i] << endl;
		}
	}

	void search()
	{

		if (index == 0)
		{
		cout << "no data entered yet" << endl;
		return;
		}

		cin.ignore();
		string r;
		cout << "enter rollno: ";
		getline(cin, r);

		for (int i = 0; i < index; i++)
		{
			if (r == rollno[i])
			{
				cout << "name: " << name[i] << endl;
				cout << "roll no: " << rollno[i] << endl;
			}
		}
	}
};

void menu()
{
	char input = 'r';
	StudentData student;

	while (input != 'e')
	{
		system("cls");
		cout << "--MENU--" << endl;
		cout << endl;
		cout << "<n> Enter student." << endl;
		cout << "<p> See all record." << endl;
		cout << "<s> Search." << endl;
		cout << "<e> Exit." << endl;

		cout << "choose an option :";
		cin >> input;

		switch (input)
		{
		case 'N':
		case 'n':
			system("cls");
			student.enterstudent();
			system("pause");
			break;
		case 'P':
		case 'p':
			system("cls");
			student.seerecord();
			system("pause");
			break;
		case 'S':
		case 's':
			system("cls");
			student.search();
			system("pause");
			break;
		case 'E':
		case 'e':
			return;
		}
	}
}

int main()
{
	menu();
	return 0;
}