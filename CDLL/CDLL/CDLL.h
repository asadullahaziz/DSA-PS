#pragma once

#include"Node.h"

template <class T>
class CDLL
{
	Node <T>* head;

public:
	CDLL()
	{
		head = 0;
	}

	void inseart_at_head(T val)
	{
		Node <T>* p = new Node <T>(val);

		if (head == 0)
		{
			head = p;
			p->prev = head;
		}
		else
		{
			p->next = head;
			p->prev = head->prev;
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
			p->prev = head;
		}
		else
		{

			p->prev = head->prev;
			p->next = head;
			head->prev->next = p;
		}

		p = 0;
		delete p;
	}
};

