#pragma once

#include<iostream>
#include<string>

using namespace std;

class User
{
public:
	// user data:-
	string name;
	string password;
	string address;
	string id;
	string work;
	string education;
	int no_of_friends;

	// pointers:-
	User* down;
	User* next;

	// constructors:-
	User()
	{
		down = 0;
		next = 0;
		no_of_friends = 0;
	}
};

