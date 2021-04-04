#pragma once

#include"Node.h"

template <class T>
class LSLL
{
	Node <T>* head;

public:

	LSLL()
	{
		head = 0;
	}

	void InseartAtHead(T val)
	{
		Node <T>* p = new Node <T>(val);
		if (head == 0)
		{
			head = p;
		}
		else
		{
			p->next = head;
			head = p;
		}
		p = 0;
		delete p;
	}

	void InseartAtTail(T val)
	{
		if (head == 0)
		{
			InseartAtHead(val);
		}
		else
		{
			Node <T>* p = new Node <T>(val);
			Node <T>* temp = head;
			while (temp->next != 0)
			{
				temp = temp->next;
			}
			temp->next = p;
			temp = 0;
			p = 0;
			delete temp;
			delete p;
		}
	}

	void display()
	{
		Node <T>* temp = head;
		while (temp != 0)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		temp = 0;
		delete temp;
	}

	void RemoveAtHead()
	{
		if (head == 0)
		{
			cout << "head is null !" << endl;
		}
		else
		{
			Node <T>* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void RemoveAtTail()
	{
		if (head == 0 || head->next == 0)
		{
			RemoveAtHead();
		}
		else
		{
			Node <T>* temp = head;
			while (temp->next->next != 0)
			{
				temp = temp->next;
			}
			Node <T>* p = temp->next;
			temp->next = 0;
			delete p;
			temp = 0;
			delete temp;
		}
	}

	void InseartAfter(T val, T key)
	{
		if (head == 0)
		{
			cout << "head is null !" << endl;
		}
		else
		{
			Node <T>* temp = head;

			while (temp!=0)
			{
				if (temp->data == key)
				{
					break;
				}
				temp = temp->next;
			}

			if (temp == 0)
			{
				cout << "key did not matched !" << endl;
				delete temp;
				return;
			}

			Node <T>* p = new Node <T>(val);
			if (temp->next == 0)
			{
				p->next = 0;
			}
			else
			{
				p->next = temp->next;
			}
			temp->next = p;

			temp = 0;
			p = 0;
			delete temp;
			delete p;
		}
	}

	void InseartBefore(T val, T key)
	{
		if (head == 0)
		{
			cout << "head is null !" << endl;
			return;
		}
		else if (head->next == 0)
		{
			if (head->data == key)
			{
				InseartAtHead(val);
				return;
			}
			cout << "key not matched !" << endl;
			return;
		}
		else
		{
			Node <T>* temp = head;

			while (temp->next->data != key)
			{
				temp = temp->next;
				if (temp == 0)
				{
					cout << "key not matched !" << endl;
					delete temp;
					return;
				}
			}

			Node <T>* p = new Node <T>(val);
			p->next = temp->next;
			temp->next = p;

			temp = 0;
			p = 0;
			delete temp;
			delete p;
		}
	}

	void RemoveAfter(T key)
	{
		if (head == 0 || head->next == 0)
		{
			cout << "Link List too short to perform this operation !" << endl;
		}
		else
		{
			Node <T>* temp = head;

			while (temp != 0)
			{
				if (temp->data == key)
				{
					break;
				}
				temp = temp->next;
			}
			if (temp == 0)
			{
				cout << "key did not matched !" << endl;
				return;
			}
			if (temp->next == 0)
			{
				cout << "There is no node to remove after this node !" << endl;
				return;
			}

			Node <T>* p = temp->next;
			temp->next = p->next;
			delete p;
			temp = 0;
			delete temp;
		}
	}

	void RemoveBefore(T key)
	{
		if (head == 0 || head->next == 0)
		{
			cout << "Link List too short to perform this operation !" << endl;
		}
		else if (head->next->next->data == key)
		{
			RemoveAtHead();
		}
		else
		{
			Node <T>* temp = head;
			bool flag = false;

			while (temp->next->next->next != 0)
			{
				if (temp->next->next->data == key)
				{
					flag = true;
					break;
				}
				temp = temp->next;
			}
			if (flag == false)
			{
				if (temp->next->next->data != key)
				{
					cout << "key did not matched !" << endl;
					return;
				}
			}
			Node <T>* p = temp->next;
			temp->next = temp->next->next;
			delete p;
			temp = 0;
			delete temp;
		}
	}

	void swap(T m, T n)
	{
		if (head == 0 || head->next == 0)
		{
			cout << "Linklist too short to perform this operation !" << endl;
		}
		else
		{
			T swap;
			Node <T>* temp = head;
			Node <T>* temp1 = head;
			Node <T>* temp2 = head;
			bool find_m = false;
			bool find_n = false;


			while (temp->next != 0)
			{
				if (temp->data == m)
				{
					temp1 = temp;
					find_m = true;
				}
				if (temp->data == n)
				{
					temp2 = temp;
					find_n = true;
				}

				temp2 = temp2->next;
			}

			if (find_m == false || find_n == false)
			{
				cout << "Either of the given falues does not exist in Link List!" << endl;
			}
			else
			{
				swap = temp1->data;
				temp1->data = temp2->data;
				temp2->data = swap;
				cout << "data successfully swapped." << endl;
			}

			temp = 0;
			temp1 = 0;
			temp2 = 0;

			delete temp;
			delete temp1;
			delete temp2;
		}

	}

	Node <T>* give_head()
	{
		return head;
	}

	bool check_joining(LSLL l1, LSLL l2)
	{
		Node <T>* head1 = l1.give_head();
		Node <T>* head2 = l2.give_head();

		Node <T>* temp = head1;

		while (temp != 0)
		{
			if (temp == head2)
			{
				return true;
			}
			temp = temp->next;
		}

		temp = head2;

		while (temp != 0)
		{
			if (temp == head1)
			{
				return true;
			}
			temp = temp->next;
		}
		head1 = 0;
		head2 = 0;
		temp = 0;
		delete head1;
		delete head2;
		delete head3;

		return false;
	}
};

