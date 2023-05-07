#include "ListArr.h"

int main()
{
    ListArr list(4);
    list.insert_right(1);
    list.insert_right(2);
    list.insert_right(3);
    list.insert_right(4);
    list.insert_right(5);
    list.insert_right(6);
    list.insert_right(7);
    list.insert_right(8);
    list.insert_right(9);

    list.print();
    cout << "TAMANIO " << list.size() << endl;
    cout << "Se encuentra " << 10 << ": " << list.find(10) << endl;

    list.insert(10, 8);
    list.print();
    cout << "Se encuentra " << 10 << ": " << list.find(10) << endl;

    return 0;
}