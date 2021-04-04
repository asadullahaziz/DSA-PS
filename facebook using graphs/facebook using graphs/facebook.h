#pragma once

#include"User.h";

class facebook
{
	User* head;
	int id_no;

	// =======================================================================================================

	// opened profile functions: -

	int profile_menu()
	{
		int choice;
		system("cls");
		cout << "<1> Display Profile Data." << endl;
		cout << "<2> Edit data" << endl;
		cout << "<3> Add friend." << endl;
		cout << "<4> Show Friends Profile." << endl;
		cout << "<5> Show Connections." << endl;
		cout << "<0> Logout." << endl;

		cin >> choice;

		system("cls");
		return choice;
	}

	void display_data(User* n)
	{
		cout << "Name: " << n->name << endl;
		cout << "ID: " << n->id << endl;
		cout << "Address: " << n->address << endl;
		cout << "Education: " << n->education << endl;
		cout << "Work: " << n->work << endl;
		cout << "Number of Friends: " << n->no_of_friends << endl;
	}

	void edit_data(User* n)
	{
		string edit;
		int choice = 0;
		cout << "what do you want to edit ?" << endl;

		cout << "<1> Name." << endl;
		cout << "<2> Address." << endl;
		cout << "<3> Education." << endl;
		cout << "<4> Work." << endl;
		cout << "<0> Cancel." << endl;
		cout << "Choose an option: ";
		cin >> choice;

		if (choice == 0)
		{
			return;
		}

		cout << "Enter new data: ";
		cin >> edit;

		switch (choice)
		{
		case 1:
			n->name = edit;
			break;
		case 2:
			n->address = edit;
			break;
		case 3:
			n->education = edit;
			break;
		case 4:
			n->work = edit;
			break;
		}
		cout << "Data changed successfully !" << endl;
	}

	void add_friend(User* n)
	{
		string search;
		cin.ignore();
		cout << "Enter Person's Name/ID: " << endl;
		getline(cin, search);

		User* frnd = search_profile(search);

		if (frnd == 0)
		{
			return;
		}

		User* p = new User;
		p->id = frnd->id;
		p->name = frnd->name;

		User* temp = n;
		while (temp->next != 0)
		{
			temp = temp->next;
		}

		temp->next = p;

		p = 0;
		delete p;

		cout << "Friend Added !" << endl;
	}

	void show_friend_profile(User* n)
	{
		string name;

		cout << "Friend name/ID: ";
		cin >> name;

		User* temp = n;
		while (temp != 0)
		{
			if (name == temp->name || name == temp->id)
			{
				break;
			}
			temp = temp->next;
		}
		if (temp == 0)
		{
			cout << "No friend found with given name/ID !" << endl;
			return;
		}

		temp = head;
		while (temp->down != 0)
		{
			if (name == temp->name || name == temp->id)
			{
				break;
			}
			temp = temp->down;
		}

		cout << "Name: " << temp->name << endl;
		cout << "ID: " << temp->id << endl;
		cout << "Address: " << temp->address << endl;
		cout << "Education: " << temp->education << endl;
		cout << "Work: " << temp->work << endl;
		cout << "Number of Friends: " << temp->no_of_friends << endl;
	}

	void connections(User* n)
	{
		cout << "Your friend List: -" << endl;
		User* temp = n;

		while (temp != 0)
		{
			cout << temp->name << endl;
			temp = temp->next;
		}
		cout << endl;
	}

public:
	// constructor:-
	facebook()
	{
		head = 0;
		id_no = 0;
	}

	// =======================================================================================================

	// user data functions:-
	string genrate_id()
	{
		string id;
		id = "user_id#" + to_string(id_no);
		id_no++;
		return id;
	}

	void get_data(User* n)
	{
		char job;
		cin.ignore();

		cout << "Name: ";
		getline(cin, n->name);

		cout << "Address: ";
		getline(cin, n->address);

		cout << "Education: ";
		getline(cin, n->education);

		cout << "do you have a job/work ? (y/n): ";
		cin >> job;

		cin.ignore();
		if (job == 'y')
		{
			cout << "Work/job/profession: ";
			getline(cin, n->work);
		}
		
		cout << "Password: ";
		getline(cin, n->password);

		n->id = genrate_id();

		cout << "Your user profile ID is: " << n->id << endl;

		n = 0;
		delete n;
	}

	// =======================================================================================================

	// main menu functions: -
	void main_menu()
	{
		int choice = 1;

		while (choice != 0)
		{
			system("cls");
			cout << "<1> Open Profile." << endl;
			cout << "<2> Create Profile." << endl;
			cout << "<0> Exit." << endl;
			cin >> choice;

			system("cls");
			switch (choice)
			{
			case 1:
				open_profile();
				break;
			case 2:
				create_profile();
				break;
			}
			system("pause");
		}
	}
	
	void create_profile()
	{
		User* p = new User;
		get_data(p);

		if (head == 0)
		{
			head = p;
		}
		else
		{
			User* temp = head;

			while (temp->down != 0)
			{
				temp = temp->down;
			}
			temp->down = p;

			temp = 0;
			delete temp;
		}

		p = 0;
		delete p;

		cout << "Profile Created Successfully !" << endl;
	}

	User* search_profile(string name)
	{
		if (head == 0)
		{
			cout << "No user exists yet !" << endl;
			return 0;
		}

		User* temp = head;

		while (temp != 0)
		{
			if (name == temp->name || name == temp->id)
			{
				break;
			}
			temp = temp->down;
		}

		if (temp == 0)
		{
			cout << "No profile found with given name/id !" << endl;
			return 0;
		}

		return temp;
	}

	void open_profile()
	{
		cin.ignore();
		string name, password;
		cout << "Enter the following data:-" << endl;
		cout << "Name:";
		getline(cin, name);
		cout << "Password:";
		getline(cin, password);

		User* profile = search_profile(name);

		if (profile == 0 || profile->password != password)
		{
			cout << "Either Name/ID OR Password is incorrect !" << endl;
			return;
		}

		int choice = 1;

		while (choice != 0)
		{
			choice = profile_menu();
			switch (choice)
			{
			case 1:
				display_data(profile);
				break;
			case 2:
				edit_data(profile);
				break;
			case 3:
				add_friend(profile);
				break;
			case 4:
				show_friend_profile(profile);
				break;
			case 5:
				connections(profile);
				break;
			}
			system("pause");
		}
	}

};