#pragma once

#include<iostream>
using namespace std;

#include"Node.h"

template <class T>
class Graph
{
	Node <T>* head;

public:

	Graph()
	{
		head = 0;
	}

	void add_vertics(T info)
	{
		Node <T>* p = new Node <T>(info);
		Node <T>* temp = head;

		if (head == 0)
		{
			head = p;
			return;
		}

		while (temp->down != 0)
		{
			if (temp->info == info)
			{
				cout << "info aleady exists !" << endl;
				return;
			}
			temp = temp->down;
		}
		temp->down = p;

		temp = 0;
		p = 0;
		delete temp;
		delete p;
	}

	void add_edge(T info1, T info2)
	{
		if (head == 0 || head->down == 0)
		{
			cout << "there are not enough virteces ! Please inseart atleast two virteces." << endl;
			return;
		}

		Node <T>* temp = head;
		bool check1 = false;
		bool check2 = false;
		Node <T>* n;

		while (temp->down != 0)
		{
			if (temp->info == info1)
			{
				check1 = true;
				n = temp;
			}
			if (temp->info == info2)
			{
				check2 = true;
			}
			if (check1 == true && check2 == true)
			{
				break;
			}
			temp = temp->down;
		}
		if (check1 == false || check2 == false)
		{
			cout << "Vertics does not exist !!" << endl;
		}
		else
		{
			temp = new node <T>(info2);
			while (n->next != 0)
			{
				n = n->next;
			}
			n->next = temp;
		}

		temp = 0;
		n1 = 0;
		n2 = 0;
		delete temp;
		delete n1;
		delete n2;
	}

	void remove_vertics(T info)
	{
		if (head == 0)
		{
			cout << "No vertices exists !" << endl;
			return;
		}

		Node <T>* temp = head;
		Node <T>* del = 0;
		bool exist = false;

		while (temp->down != 0)
		{
			remove_edge(temp->info, info);
			if (temp->down != 0)
			{
				if (temp->down->info == info)
				{
					exist = true;
					del = temp->down;
					temp->down = del->down;
				}
			}
			
			temp = temp->down;
		}
		if (exist == false)
		{
			cout << "the vertics already does not exist !" << endl;
		}
		else
		{
			Node <T>* select = del;
			del = del->next;
			while (del->next != 0)
			{
				delete select;

				select = del;
				del = del->next;
			}
		}

		delete del;
		temp = 0;
		delete temp;
		
	}

	void remove_edge(T info1, T info2)
	{
		if (head == 0 || head->down == 0)
		{
			cout << "there are not enough virteces ! Please inseart atleast two virteces." << endl;
			return;
		}

		Node <T>* temp = head;

		while (temp != 0)
		{
			if (temp->info == info1)
			{
				break;
			}
			temp = temp->down;
		}

		if (temp == 0)
		{
			cout << "One of the given Node does not exists!" << endl;
		}
		else
		{
			Node <T>* edge;
			while (temp->next != 0)
			{
				if (temp->next->info == info2)
				{
					break;
				}
				temp = temp->next;
			}
			edge = temp->next;
			temp->next = edge->next;
			delete edge;
		}
		temp = 0;
		delete temp;
	}

	int indegree(T info)
	{
		if (head == 0)
		{
			cout << "No vertices exists !" << endl;
			return -1;
		}

		int degree = 0;
		Node <T>* temp = head;
		Node <T>* temp2 = 0;

		while (temp != 0)
		{
			temp2 = temp;

			while (temp2 != 0)
			{
				if (temp2->info == info)
				{
					degree++;
					break;
				}
				temp2 = temp2->next;
			}

			temp = temp->down;
		}

		return degree;
	}

	int outdegree(T info)
	{
		if (head == 0)
		{
			cout << "No Vertics exist in graph !" << endl;
			return -1;
		}

		int degree = 0;
		Node <T>* temp = head;

		while (temp != 0)
		{
			if (temp->info == info)
			{
				break;
			}

			temp = temp->down;
		}
		if (temp == 0)
		{
			return -1;
		}
		while (temp != 0)
		{
			degree++;
			temp = temp->next
		}

		return degree;
	}

	void display()
	{
		if (head == 0)
		{
			cout << "Graph is empty !" << endl;
			return;
		}

		Node <T>* temp = head;
		Node <T>* temp1 = head;
		Node <T>* temp2 = head;

		int size = 0;
		while (temp != 0)
		{
			size++;
			temp = temp->down;
		}
		int array[size][size];

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				array[i][j] = 0;
			}
		}

		temp = head;
		// We will search all the lists one by one for the selected Vertics.
		for (int j = 0; j < size; j++)
		{
			// here the vertics will be selected
			temp1 = head;
			for (int i = 0; i < size; i++) // The list to be search is selected here
			{
				temp2 = temp1;

				while (temp2 != 0) // we will check if the selected node exists in this list or not
				{
					if (temp2->info == temp->info)
					{
						arr[i][j] = 1; // assignning 1 if the selected node exists here
					}
					temp2 = temp2->next; // assigning next node in the list.
				}

				temp1 = temp->down; // selecting the next list
			}

			temp = temp->down; // selecting the next vertics to be searched.
		}

		temp = head;
		while (temp != 0)
		{
			cout << temp->info << "	 ";
			temp = temp->down;
		}
		cout << endl;

		temp = head;
		for (int i = 0; i < size; i++)
		{
			cout << temp->info << "  ";
			for (int j = 0; j < size; j++)
			{
				cout << array[i][j] << "  ";
			}
			cout << endl;
			temp = temp->down;
		}
		
		temp = 0;
		temp1 = 0;
		temp2 = 0;
		delete temp;
		delete temp1;
		delete temp2;
	}
};

