#include<iostream>

using namespace std;

int integer_sum(int value)
{
	int sum = 0;
	int last = value % 10;
	int remain = value / 10;

	if (remain == 0)
	{
		return last;
	}
	sum = sum + last;
	sum = sum + integer_sum(remain);
}

int main()
{
	int val;
	cout << "Enter value: ";
	cin >> val;

	int result = integer_sum(val);

	cout << "result: " << result << endl;


	return 0;
}