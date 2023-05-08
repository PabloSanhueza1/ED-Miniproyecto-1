#include "Array.h"

Array::Array(int initial)
{
    capacity = initial;
    container = new int[capacity];
    count = 0;
}

Array::~Array()
{
    delete[] container;
}

int Array::size()
{
    return count;
}

void Array::insert_left(int v)
{
    if (count == capacity)
        resize();

    for (int i = size() - 1; i >= 0; i--)
    {
        container[i + 1] = container[i];
    }

    container[0] = v;
    count++;
}

void Array::insert_right(int v)
{
    if (count == capacity)
        resize();

    container[count] = v;
    count++;
}

void Array::insert(int val, int pos)
{
    try
    {
        if (pos < 0 || pos > capacity)
            throw "Invalid index!";

        count++;

        if (count >= capacity)
            resize();

        for (int i = count - 1; i >= pos; i--)
        {
            container[i] = container[i - 1];
        }

        container[pos] = val;
    }
    catch (const char *message)
    {
        cerr << message << endl;
        exit(EXIT_FAILURE);
    }
}

void Array::print()
{
    cout << "Elementos en Array: " << endl << endl;
    for (int i = 0; i < size(); i++)
        cout << container[i] << endl;
    cout << endl;
}

bool Array::find(int v)
{
    for (int i = 0; i < size(); i++)
        if (container[i] == v)
            return true;
    return false;
}

bool Array::empty()
{
    return count == 0;
}

void Array::resize()
{
    int new_capacity = capacity * 2;
    int *new_container = new int[new_capacity];
    for (int i = 0; i < count; i++)
        new_container[i] = container[i];

    delete[] container;
    container = new_container;
    capacity = new_capacity;
}