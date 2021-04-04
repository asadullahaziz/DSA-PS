#pragma once

#include"Node.h"

template <class T>
class Queue
{
	Node <T>* front;
	Node <T>* rear;

public:

	Queue()
	{
		front = 0;
		rear = 0;
	}

	void enqueue(T value)
	{
		Node <T>* p = new Node<T>(val);

		if (front == 0 && rear == 0)
		{
			front = p;
			rear = p;
		}
		else
		{
			rear->next = p;
			rear = p;
		}

		p = 0;
		delete p;
	}

	T dequeue()
	{
		if (front == 0 && end == 0)
		{
			cout << "Queue empty !" << endl;
		}
		else
		{
			Node <T>* temp = front;

			if (front == rear)
			{
				front = rear = 0;
			}
			else
			{
				front = front->next;
			}

			T data = temp->data;
			delete temp;
			return data;
		}
	}
};

