#pragma once

#include"Node.h"

template <class T>
class LDLL
{
    Node <T>* head;
    Node <T>* tail;

public:

    LDLL()
    {
        head = 0;
        tail = 0;
    }

    void inseart_at_head(T val)
	{
		Node <T>* p = new Node <T>(val);
		if (head == 0)
		{
			head = p;
            tail = p;
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
		if(head == 0)
		{
			head = p;
			tail = p;
		}
		else
		{
			tail->next = p;
			p->prev = tail;
			tail = p;
		}
		p = 0;
		delete p;
	}

	Node <T>* give_head()
	{
		return head;
	}

	void inseart_child(Node <T>* h,T key)
	{
		if(head == 0)
		{
			cout << "link list is empty !" << endl;
			return;
		}

		Node <T>* temp = head;

		while(temp != 0)
		{
			if(temp->data == key)
			{
				break;
			}
			temp = temp->next;
		}
		if(temp == 0)
		{
			cout << "Node not found !" << endl;
			return;
		}

		temp->child = h;

		temp = 0;
		delete temp;
		h = 0;
		delete h;
	}


	// ############################################################################
	//#############################################################################

	void flat_linked_list()
	{
		if(head == 0)
		{
			cout << "This linked list is empty !" << endl;
			return;
		}

		Node <T>* temp = head;
		
		while(temp != 0)
		{
			if(temp->child != 0)
			{
				tail->next = temp->child;
				temp->child->prev = tail;
				temp->child = 0;
				while(tail->next !=0)
				{
					tail = tail->next;
				}
			}
			temp = temp->next;
		}

		temp = 0;
		delete temp;
	}

	//################################################################################
	//################################################################################


	void display()
	{
		if(head == 0)
		{
			cout << "linked list is empty" << endl;
		}
		else
		{
			Node <T>* temp = head;

			while(temp != 0)
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

};