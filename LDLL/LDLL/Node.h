#pragma once

#include<iostream>

using namespace std;

template <class T>
class Node
{
	T info;
	Node <T>* next;
	Node <T>* prev;

public:
	Node()
	{
		info = 0;
		next = 0;
		prev = 0;
	}
	Node(T val)
	{
		info = val;
		next = 0;
		prev = 0;
	}
};

