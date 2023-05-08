#include "ListArrADT.h"

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

class ListArr : public ListArrADT
{
  private:
    SummaryNode *root;
    DataNode *head;

    int capacity;
    int leafs;
    bool dataAssigned;

  public:
    ListArr(int b);
    ~ListArr();

    // Seters y getters
    void setDataAssigned(bool v); // Setter de variable auxiliar dataAssigned, util para assignDataNodes
    bool getDataAssigned();       // Getter de variable auxiliar dataAssigned, util para assignDataNodes
    void setLeafs(int v);         // Setter de variable auxiliar leafs, hojas del arbol binario
    int getLeafs();               // Getter de variable auxiliar leafs, hojas del arbol binario

    // Métodos para actualizar arbol binario
    void freeBinaryTree(SummaryNode *node);            // Elimina el arbol binario (libera memoria)
    DataNode *getNode(int index);                      // Retorna el i-ésimo DataNode
    void assignDataNodes(SummaryNode *root, int leaf); // Asigna el i-ésimo DataNode a la i-ésima hoja del arbol binario
    void cleanAllParents(SummaryNode *node); // Elimina toda relacion entre las hojas del arbol con los DataNodes
    int updateQuantity(SummaryNode *node);   // Actualiza la cantidad de elementos ingresados en los nodos del arbol
    int updateCapacity(SummaryNode *node);   // Actualiza la capacidad  en los nodos del arbol
    void updateTree();                       // Actualiza la cantidad y capacidad de los nodos del arbol
    SummaryNode *createBinaryTree(int leaf); // Crea un arbol binario

    // Métodos de inserción
    void insertNode(DataNode *&dataNode); // Crea un DataNode inmediatamente después del nodo recibido en el argumento
    void insertBefore(DataNode *dataNode, int v, int i);         // Inserta a la izquierda de un dataNode
    void insertAfter(DataNode *dataNode, int v, int i);          // Inserta a la derecha de un dataNode
    void insertRecursivo(SummaryNode *actualNode, int v, int i); // Método auxiliar para insert() a implementar

    // Métodos a implementar:
    int size();                // Retorna la cantidad de elementos almacenados en el ListArr
    void insert_left(int v);   // Inserta un nuevo valor v a la izquierda del ListArr
    void insert_right(int v);  // Inserta un nuevo valor v a la derecha del ListArr
    void insert(int v, int i); // Inserta un nuevo valor v en el índice i del ListArr
    void print();              // Imprime por pantalla todos los valores almacenados en el ListArr
    bool find(int v);          // Busca en el ListArr si el valor v se encuentra almacenado
};