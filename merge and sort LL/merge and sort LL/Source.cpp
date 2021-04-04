#include"LDLL.h"

int main()
{
	LDLL <int> l1, l2, l3;

	l1.inseart_at_tail(4);
	l1.inseart_at_tail(8);
	l1.inseart_at_tail(3);
	l1.inseart_at_tail(5);

	cout << " Linked List 1:-" << endl;
	l1.display();
	cout << endl;

	l2.inseart_at_tail(9);
	l2.inseart_at_tail(2);
	l2.inseart_at_tail(7);
	l2.inseart_at_tail(6);

	cout << " Linked List 2:-" << endl;
	l2.display();
	cout << endl;

	l3.merge(l1, l2);
	cout << "Linked List 3 before sorting :-" << endl;
	l3.display();
	l3.sort();
	cout << "Linked List 3 after sorting :-" << endl;
	l3.display();

	return 0;
}