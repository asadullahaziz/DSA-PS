#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Stack // Stack data structure.
{
private:
	int* arr;
	int size;
	int index;

public:

	Stack(int s)
	{
		size = s;
		arr = new int[size];
		index = -1;
	}

	void push(int val)
	{
		if (index == size)
		{
			cout << "stack full !" << endl;
			return;
		}
		else
		{
			index++;
			arr[index] = val;
		}
	}

	int pop()
	{
		if (index == -1)
		{
			cout << "stack empty !" << endl;
		}
		else
		{
			int value = arr[index];
			index--;
			return value;
		}
	}

	int top()
	{
		if (index == -1)
		{
			cout << "stack empty !" << endl;
		}
		else
		{
			int value = arr[index];
			return value;
		}
	}

	bool is_empty()
	{
		if (index == -1) return true;
		else return false;
	}
	bool is_full()
	{
		if (index == size) return true;
		else return false;
	}
};

int getpostfix(int size, string infix, Stack st, int* postfix);
int getanswer(int *postfix, int size, int index);

//=========================================================================
int main()
{
	string infix;
	cout << "Enter :";
	getline(cin, infix);

	int size = infix.size();
	int* postfix = new int[size];
	Stack st(size);

	int index = getpostfix(size, infix, st, postfix);
	int result = getanswer(postfix, size, index);

	for (int i = 0; i < index; i++)
	{
		cout << postfix[i] << " ";
	}
	cout << endl;

	cout << "Answer: " << result << endl;

	return 0;
}
//==========================================================================

int getpostfix(int size, string infix, Stack st, int* postfix) // convert infix into postfix.
{
	Stack s(size);
	int index = 0;

	for (int i = 0; i < size; i++)
	{
		if (infix[i] >= 48 && infix[i] <= 57) // converting into intiger and saving it in the postfix array.
		{
			s.push(infix[i] - 48); // pushing characters in stack by converting in intiger.
			if (infix[i + 1] < 48 || infix[i + 1] > 57) // if an operator comes this means the number is complete.
			{
				int number = 0;
				int unit = 1;
				while (!s.is_empty()) // converting into number.
				{
					number = s.pop() * unit + number;
					unit = unit * 10;
				}
				postfix[index] = number; // saving the number in postfix intiger array.
				index++;
			}
		}
		else if (infix[i] == 47 || infix[i] == 42 || infix[i] == 40) // for '*' & '/' & ')'.
		{
			st.push(-infix[i]);
		}

		else if (infix[i] == 43 || infix[i] == 45) // for '+' & '-'.
		{
			if (st.top() == 42 || st.top() == 47) // checking if an operator of lower precidence is in stack.
			{
				while (!st.is_empty() || st.top() != -40) // poping all the values in stack
				{
					postfix[index] = st.pop();
					index++;
				}
				st.pop();
				st.push(-infix[i]);
			}
			else
			{
				st.push(-infix[i]);
			}
		}

		else if (infix[i] == 42) // for')' .
		{
			while (st.top() != -40) // running the loop until opening bracket comes.
			{
				postfix[index] = st.pop();
				index++;
			}
			st.pop(); // ignoring the opening brackets.
		}
	}

	while (!st.is_empty())
	{
		postfix[index] = st.pop();
		index++;
	}
	return index;
}

int getanswer(int *postfix, int size, int index)
{
	Stack s(size);
	int res = 0;

	for (int i = 0; i < index; i++)
	{
		if (postfix[i] >= 0)
		{
			s.push(postfix[i]);
		}
		else
		{
			int v1, v2;
			v1 = s.pop();
			v2 = s.pop();

			switch (postfix[i])
			{
			case -43: // '+'
				res = v2 + v1;
				break;
			case -45: // '-'
				res = v2 - v1;
				break;
			case -42: // '*'
				res = v2 * v1;
				break;
			case -47: // '/'
				res = v2 / v1;
				break;
			}

			s.push(res);
		}
	}
	return res;
}