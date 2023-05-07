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

    DataNode *data;

    SummaryNode()
    {
        quantity = 0;
        sCapacity = 0;
        left = NULL;
        right = NULL;
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
    void insertBefore(DataNode *dataNode, int v, int i);
    void insertAfter(DataNode *dataNode, int v, int i);
    void insertRecursivo(SummaryNode *actualNode, int v, int i);
    bool dataAssigned = false;
    void assignDataNodes(SummaryNode *root, int leaf);
    DataNode *getNode(int index);
    ListArr(int b);
    //~ListArr();
    void cleanAllParents(SummaryNode *node);
    SummaryNode *createBinaryTree(int leafs);
    int leafs;
    void insertNode(DataNode *&dataNode);
    int updateQuantity(SummaryNode *node);
    int updateCapacity(SummaryNode *node);
    void updateTree();

    int size();                // Retorna la cantidad de elementos almacenados en el ListArr
    void insert_left(int v);   // Inserta un nuevo valor v a la izquierda del ListArr
    void insert_right(int v);  // Inserta un nuevo valor v a la derecha del ListArr
    void insert(int v, int i); // Inserta un nuevo valor v en el índice i del ListArr
    void print();              // Imprime por pantalla todos los valores almacenados en el ListArr
    bool find(int v);          // Busca en el ListArr si el valor v se encuentra almacenado
};

#endif