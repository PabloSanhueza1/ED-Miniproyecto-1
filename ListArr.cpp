#include "ListArr.h"

void insertNode(DataNode *&dataNode)
{
    DataNode *newDataNode = new DataNode(dataNode->nCapacity);

    // se conecta el nuevo nodo con el resto de la estructura
    if (dataNode->next != NULL)
        newDataNode->next = dataNode->next;
    dataNode->next = newDataNode;
}

void moveRight(DataNode *&dataNode)
{
    for (int i = dataNode->count - 1; i >= 0; i--)
    {
        dataNode->container[i + 1] = dataNode->container[i];
    }
}

ListArr::ListArr(int b)
{
    capacity = b;
    DataNode *initialNode = new DataNode(capacity);
    root = new SummaryNode(0, capacity);
    root->data = initialNode;
}

void ListArr::insert_left(int v)
{
    SummaryNode *actualNode = root;
    int flag = 0;

    // llega al primer DataNode de la izquierda
    while (actualNode->left != NULL)
        actualNode = actualNode->left;

    DataNode *dataNode = actualNode->data;

    if (dataNode->count == dataNode->nCapacity)
    {
        if (!dataNode->next->isFull())
        {
            insertNode(dataNode);
            dataNode->next->container[0] = dataNode->container[dataNode->count - 1];
            dataNode->next->count = dataNode->next->count + 1;
            dataNode->count = dataNode->count - 1;
            flag = 1;
        }
    }

    while (dataNode != NULL)
    {
        for (int i = dataNode->count - 1; i >= 0; i--)
        {
            dataNode->container[i + 1] = dataNode->container[i];
        }

        dataNode->container[0] = v;
        dataNode->count = dataNode->count + 1;

        if (flag)
            break;
        dataNode = dataNode->next;
    }
}

void ListArr::insert_right(int v)
{
    SummaryNode *actualNode = root;
    int flag = 0;

    // llega al último DataNode
    while (actualNode->right != NULL)
        actualNode = actualNode->right;

    DataNode *dataNode = actualNode->data;

    // si el último nodo está lleno, se debe crear un nuevo nodo llamando a insertNode()
    if (dataNode->count == dataNode->nCapacity)
    {
        flag = 1;
        insertNode(dataNode);
    }

    // si el flag es verdadero, el nuevo DataNode estará vacío, por lo que se ingresa un elemento en la posición 0
    // sino, el arreglo no está lleno y se agrega un elemento en la posicion después del último ingresado
    if (flag)
    {
        dataNode->container[0] = v;
        dataNode->count = dataNode->count + 1;
    }
    else
    {
        dataNode->container[dataNode->count] = v;
        dataNode->count = dataNode->count + 1;
    }
}

void ListArr::print()
{
    SummaryNode *actualNode = root;

    while (actualNode->left != NULL)
        actualNode = actualNode->left;

    DataNode *dataNode = actualNode->data;

    cout << endl;
    int i = 0;

    while (dataNode != NULL)
    {
        cout << "Node " << i << ":" << endl;
        for (int j = 0; j < dataNode->count; j++)
            cout << dataNode->container[j] << " ";

        cout << endl << endl;
        i++;

        dataNode = dataNode->next;
    }
}