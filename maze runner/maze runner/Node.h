#pragma once

#include<iostream>

using namespace std;

template <class T>
class Node
{
public:

	T info;
	Node <T>* up;
	Node <T>* down;
	Node <T>* left;
	Node <T>* right;
	Node <T>* next; // only for stack :/ ;

	Node()
	{
		info = 0;
		up = 0;
		down = 0;
		left = 0;
		right = 0;
	}
	Node(T val)
	{
		info = val;
		up = 0;
		down = 0;
		left = 0;
		right = 0;
	}
};

