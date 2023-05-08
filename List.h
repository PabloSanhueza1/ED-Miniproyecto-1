#include "ListArrADT.h"

#include <bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = NULL;
    }
};

class List : public ListArrADT
{
  private:
    Node *head;
    Node *tail;

  public:
    List();
    ~List();

    int size();
    void insert_left(int v);
    void insert_right(int v);
    void insert(int v, int i);
    void print();
    bool find(int v);
};