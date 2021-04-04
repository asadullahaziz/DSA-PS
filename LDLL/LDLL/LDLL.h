#pragma once

#include"Node.h";
template <class T>
class LDLL
{
	Node <T>* head;

public:
	LDLL()
	{
		head = 0;
	}

	void inseart_at_head(T val)
	{
		Node <T>* p = new Node <T>(val);
		if (head == 0)
		{
			head = p;
		}
		else
		{
			p->next = head;
			head->prev = p;
			head = p;
		}
		p = 0;
		delete p;
	}

	void inseart_at_tail(T val)
	{
		Node <T>* p = new Node <T>(val);
		if (head == 0)
		{
			head = p;
		}
		else
		{
			Node <T>* temp = head;

			while (temp->next = 0)
			{
				temp = temp->next;
			}
			temp->next = p;
			p->prev = temp;

			temp = 0;
			delete temp;
		}

		p = 0;
		delete p;
	}

	void remove_at_head()
	{
		if (head == 0)
		{
			cout << "Nothing to remove !" << endl;
			return;
		}
		else
		{
			Node <T>* temp = head;

			// if there is only one node then we dont need to set prev pointer. as, no next node exists thus the following condition :-
			if (temp->next == 0)
			{
				head = 0;
			}
			// if there are more then one nodes :-
			else
			{
				head = head->next;
				head->prev = 0;
			}
			delete temp;
		}
	}

	void remove_at_tail()
	{
		if (head == 0)
		{
			cout << "Nothing to remove !" << endl;
			return;
		}
		else
		{
			Node <T>* temp = head;
			// if there is only one node then that is also the tail :-
			if (temp->next == 0)
			{
				head = 0;
			}
			// for more then one nodes :-
			else
			{
				while (temp->next == 0)
				{
					temp = temp->next;
				}
				temp->prev->next = 0;
			}
			delete temp;
		}
	}

	void inseart_after(T key, T val)
	{
		if (head == 0)
		{
			cout << "Link list is empty !" << endl;
			return;
		}
		else
		{
			Node <T>* temp = head;
			bool flag = false;

			// finding key node :-
			while (temp->next == 0)
			{
				if (temp->info == key)
				{
					flag = true;
					break;
				}
				temp = temp->next;
			}
			// checking if key node existed or not :-
			if (flag == false)
			{
				cout << "key not matched !" << endl;
				temp = 0;
				delete temp;
				return;
			}
			// if key node is at the end of link list then we insert at tail :-
			if (temp->next == 0)
			{
				inseart_at_tail(val);
				temp = 0;
				delete temp;
				return;
			}

			Node <T>* p = new Node <T>(val);

		}
	}
};