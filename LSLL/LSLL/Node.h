#pragma once

#include<iostream>

using namespace std;

template <class T>
class Node
{
public:

	T data;
	Node <T>* next;

	Node()
	{
		data = 0;
		next = 0;
	}
	Node(T value)
	{
		data = value;
		next = 0;
	}
};

