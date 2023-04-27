#include "ListArr.h"

int main()
{
    ListArr list(3);
    list.insert_left(10);
    list.insert_left(20);
    list.insert_left(30);
    list.print();
    return 0;
}