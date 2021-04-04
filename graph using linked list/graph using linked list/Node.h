#pragma once

template <class T>
class Node
{
public:
	Node <T>* next;
	Node <T>* down;
	T info;

	Node()
	{
		info = 0;
		next = 0;
		down = 0;
	}
	Node(T info)
	{
		this->info = info;
		next = 0;
		down = 0;
	}
};

