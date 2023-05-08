#include "List.h"

List::List()
{
    head = NULL;
    tail = NULL;
}

List::~List()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current->next;
        delete current;
        current = temp;
    }
}

int List::size()
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void List::insert_left(int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void List::insert_right(int value)
{
    Node *newNode = new Node(value);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void List::insert(int value, int pos)
{
    try
    {
        if (pos < 0 || pos > size())
            throw "Invalid index";

        Node *newNode = new Node(value);

        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *prevNode = head;

            for (int i = 0; i < pos - 1; i++)
                prevNode = prevNode->next;

            newNode->next = prevNode->next;
            prevNode->next = newNode;
        }
    }
    catch (const char *message)
    {
        cout << message << endl;
        exit(EXIT_FAILURE);
    }
}

void List::print()
{
    Node *actualNode = head;

    while (actualNode != NULL)
    {
        cout << actualNode->value << endl;
        actualNode = actualNode->next;
    }

    cout << endl;
}

bool List::find(int v)
{
    Node *actualNode = head;

    while (actualNode != NULL)
    {
        if (actualNode->value == v)
            return true;
        actualNode = actualNode->next;
    }

    return false;
}