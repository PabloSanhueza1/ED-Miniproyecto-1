#ifndef LISTARRADT_H
#define LISTARRADT_H

#include <bits/stdc++.h>
using namespace std;

class ListArrADT
{
  public:
    virtual int size() = 0;                // Retorna la cantidad de elementos almacenados en el ListArr
    virtual void insert_left(int v) = 0;   // Inserta un nuevo valor v a la izquierda del ListArr
    virtual void insert_right(int v) = 0;  // Inserta un nuevo valor v a la derecha del ListArr
    virtual void insert(int v, int i) = 0; // Inserta un nuevo valor v en el índice i del ListArr
    virtual void print() = 0;              // Imprime por pantalla todos los valores almacenados en el ListArr
    virtual bool find(int v) = 0;          // Busca en el ListArr si el valor v se encuentra almacenado
};

#endif