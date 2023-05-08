#include "ListArrADT.h"

#include <bits/stdc++.h>
using namespace std;

class Array : public ListArrADT
{
  private:
    int *container;
    int capacity;
    int count;

    void resize();

  public:
    Array(int initial);
    ~Array();

    int size();
    void insert_left(int v);
    void insert_right(int v);
    void insert(int v, int i);
    void print();
    bool find(int v);

    bool empty();
};