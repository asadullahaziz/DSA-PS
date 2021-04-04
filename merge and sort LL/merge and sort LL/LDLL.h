#pragma once

#include"Node.h"

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

			while (temp->next != 0)
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

	void display()
	{
		if (head == 0)
		{
			cout << "linked list is empty" << endl;
		}
		else
		{
			Node <T>* temp = head;

			while (temp != 0)
			{
				cout << temp->data;
				if (temp->next != 0)
				{
					cout << " -> ";
				}
				temp = temp->next;
			}
			cout << endl;
		}

	}

	Node<T> * get_head()
	{
		return head;
	}

    void merge(LDLL l1,LDLL l2)
    {
		if (head != 0)
		{
			char choose;
			cout << "This Linked List contains Nodes !" << endl;
			cout << "Do you stll want to inseart these Linked Lists at the end of this one ? (y/n): ";
			cin >> choose;
			if (choose == 'n')
			{
				return;
			}
		}

		Node <T>* temp = l1.get_head();
		
		for(int i=0; i<2; i++)
		{
			while(temp != 0)
			{
				inseart_at_tail(temp->data);
				temp = temp->next;
			}
			temp = l2.get_head();
		}
		temp = 0;
		delete temp;
    }

	void sort()
	{
		Node <T>* temp = head;
		Node <T>* p = temp;
		Node <T>* small;
		T swap;
		bool flag = true; // to check if the Linked List is already sorted;

		while(temp != 0)
		{
			p = temp->next;
			small = temp;
			while (p != 0)
			{
				if (p->data < small->data)
				{
					small = p;
					flag = false;
				}
				p = p->next;
			}

			if (flag == true)
			{
				cout << "this Linked List is already sorted." << endl;
				return;
			}

			swap = temp->data;
			temp->data = small->data;
			small->data = swap;

			temp = temp->next;
		}

		temp = 0;
		p = 0;
		small = 0;
		delete temp;
		delete p;
		delete small;
	}
};