#pragma once

#include"Node.h"

template <class T>
class CSLL
{
	Node <T>* head;

public:

	CSLL()
	{
		head = 0;
	}

	// member methods:-

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
			head = p;

			Node <T>* temp = head;
			while (temp->next != 0)
			{
				temp = temp->next;
			}
			temp->next = head;


			// deleteing temporairy pointer
			temp = 0;
			delete temp;
		}

		p = 0;
		delete p;
	}
};

