#pragma once

#include"stack.h"

class Maze
{
	Node <int>* start;
	Node <int>* end;

public:

	Maze()
	{ 
		start = 0;
		end = 0;
	}

	void create_maze()
	{
		Node <int>* list[4][4];

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				list[i][j] = new Node <int>(1);
				if (j != 0)
				{
					list[i][j - 1]->right = list[i][j];
					list[i][j]->left = list[i][j - 1];
				}
				if (i != 0)
				{
					list[i - 1][j]->down = list[i][j];
					list[i][j]->up = list[i - 1][j];
				}
			}
		}
		start = list[0][0];
		end = list[3][3];

		list[0][0]->right = 0;
		list[0][1]->left = 0;

		list[1][0]->right = 0;
		list[1][1]->left = 0;

		list[3][1]->right = 0;
		list[3][2]->left = 0;

		list[1][2]->right = 0;
		list[1][3]->left = 0;

		list[2][2]->right = 0;
		list[2][3]->left = 0;

		list[1][1]->right = 0;
		list[2][2]->left = 0;

		list[1][1]->down = 0;
		list[2][1]->up = 0;

		list[2][1]->down = 0;
		list[2][1]->up = 0;

		list[2][3]->down = 0;
		list[3][3]->up = 0;
	}

	void find_path()
	{
		Stack <Node <int>*> path;
		Node <int>* runner = start;

		while (runner != end)
		{
			runner->info = 0;
			if (runner->up != 0 && runner->up->info != 0)
			{
				path.push(runner->up);
			}
			if (runner->down != 0 && runner->down->info != 0)
			{
				path.push(runner->down);
			}
			if (runner->left != 0 && runner->left->info != 0)
			{
				path.push(runner->left);
			}
			if (runner->right != 0 && runner->right->info != 0)
			{
				path.push(runner->right);
			}
			runner = path.pop();
		}
		if (runner == end)
		{
			cout << "runner has successfully exited the maze !" << endl;
		}
	}

	void play()
	{
		create_maze();
		find_path();
	}
};
