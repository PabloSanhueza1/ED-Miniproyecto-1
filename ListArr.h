#ifndef LISTARR_H
#define LISTARR_H

#include <bits/stdc++.h>
using namespace std;

class DataNode
{
  public:
    int *container;
    int count;
    int nCapacity;

    DataNode *next;
    DataNode(int nCapacity)
    {
        this->nCapacity = nCapacity;
        container = new int[nCapacity];
        count = 0;
        next = NULL;
    }

    bool isFull()
    {
        return count == nCapacity;
    }
};

class SummaryNode
{
  public:
    int quantity;
    int sCapacity;

    SummaryNode *left;
    SummaryNode *right;
    SummaryNode *parent;

    DataNode *data;

    SummaryNode()
    {
        quantity = 0;
        sCapacity = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
        data = NULL;
    }
};

class ListArr
{
  private:
    SummaryNode *root;
    DataNode *head;
    int capacity;

  public:
    ListArr(int b);
    //~ListArr();
    SummaryNode *createBinaryTree(int leafs);
    int leafs;
    void insertNode(DataNode *&dataNode);
    int updateQuantity(SummaryNode *node);
    void updateTree();
    // int size() = 0;                // Retorna la cantidad de elementos almacenados en el ListArr
    void insert_left(int v);  // Inserta un nuevo valor v a la izquierda del ListArr
    void insert_right(int v); // Inserta un nuevo valor v a la derecha del ListArr
                              // void insert(int v, int i) = 0; // Inserta un nuevo valor v en el índice i del ListArr
    void print();             // Imprime por pantalla todos los valores almacenados en el ListArr
    // bool find(int v) = 0;          // Busca en el ListArr si el valor v se encuentra almacenado
};

#endif