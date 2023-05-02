#include "ListArr.h"

int main()
{
    ListArr list(4);
    list.insert_left(1);
    list.insert_left(2);
    list.insert_left(3);
    list.insert_left(4);
    list.insert_left(5);
    list.insert_left(6);
    list.insert_left(7);
    list.insert_left(8);
    list.insert_left(9);

    list.print();
    return 0;
}