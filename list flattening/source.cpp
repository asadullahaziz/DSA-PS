#include"LDLL.h"

int main()
{
    LDLL <int> list[8];
    int data[8][5] =
    {
        {5, 33, 17, 2, 1}, // link list 0
        {6, 25, 6, 0, 0}, // link list 1
        {2, 7, 0, 0, 0}, // link list 2
        {8, 0, 0, 0, 0}, // link list 3
        {9, 0, 0, 0, 0}, // link list 4
        {12, 5, 0, 0, 0}, // link list 5
        {7, 0, 0, 0, 0}, // link list 6
        {21, 3, 0, 0, 0} // link list 7
    };

    for (int i = 0; i < 8; i++)
    {
        list[i].inseart_at_head(data[i][0]);
        for (int j = 1; j < 5; j++)
        {
            if (data[i][j] == 0)
            {
                break;
            }
            list[i].inseart_at_tail(data[i][j]);
        }
        list[i].display();
        cout << endl;
    }

    list[5].inseart_child(list[7].give_head(), 12);
    list[4].inseart_child(list[6].give_head(), 9);
    list[2].inseart_child(list[5].give_head(), 2);
    list[1].inseart_child(list[3].give_head(), 25);
    list[1].inseart_child(list[4].give_head(), 6);
    list[0].inseart_child(list[1].give_head(), 5);
    list[0].inseart_child(list[2].give_head(), 2);

    cout << endl << endl;
    list[0].flat_linked_list();
    list[0].display();

    system("pause");

    return 0;
}