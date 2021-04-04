#pragma once

#include"Node.h"

template<class T>
class Stack
{
	Node <T>* top;

public:
	Stack()
	{
		top = 0;
	}

	void push(T val)
	{
		Node <T>* p = new Node <T>(val);

		if (top == 0)
		{
			top = p;
		}
		else
		{
			p->next = top;
			top = p;
		}

		p = 0;
		delete p;
	}

	T pop()
	{
		if (top == 0)
		{
			cout << "stack is empty!" << endl;
		}
		else
		{
			Node <T>* temp = top;
			top = top->next;

			T info = temp->info;
			delete temp;

			return info;
		}
	}
};

