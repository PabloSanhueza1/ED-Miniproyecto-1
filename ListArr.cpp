#include "ListArr.h"

ListArr::ListArr(int b)
{
    capacity = b;
    leafs = 0;
    DataNode *initialNode = new DataNode(capacity);
    head = initialNode;
    root = new SummaryNode();
    root->data = initialNode;
}

void ListArr::insertNode(DataNode *&dataNode)
{
    DataNode *newDataNode = new DataNode(dataNode->nCapacity);

    // se conecta el nuevo nodo con el resto de la estructura
    if (dataNode->next != NULL)
        newDataNode->next = dataNode->next;
    dataNode->next = newDataNode;
}
// a
void moveRight(DataNode *&dataNode)
{
    for (int i = dataNode->count - 1; i >= 0; i--)
    {
        dataNode->container[i + 1] = dataNode->container[i];
    }
}

int ListArr::updateQuantity(SummaryNode *node)
{
    int leftQuantity = updateQuantity(node->left);
    int rightQuantity = updateQuantity(node->right);
    node->quantity = leftQuantity + rightQuantity + node->data->count;
    node->sCapacity = node->left->sCapacity + node->right->sCapacity + node->data->nCapacity; // + 1;

    return node->quantity;
}

void ListArr::updateTree()
{
    updateQuantity(root);
}

// devuelve la raíz del árbol binario creado
SummaryNode *ListArr::createBinaryTree(int leafs)
{
    if (leafs == 1)
    { /*
         for (int i = 0; i < leafs; i++)
         {
             DataNode *dataNode = head->next;
         }*/
        DataNode *dataNode = head;
        SummaryNode *summaryNode = new SummaryNode();
        summaryNode->data = dataNode;
        // summaryNode->quantity = dataNode->count;
        // summaryNode->sCapacity = dataNode->nCapacity;
        return summaryNode;
    }

    SummaryNode *newNode = new SummaryNode();
    newNode->left = createBinaryTree(leafs / 2);
    newNode->right = createBinaryTree(leafs - leafs / 2);
    if (newNode->left->data != NULL)
    {
        newNode->data = newNode->left->data;
        DataNode *current = newNode->data;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode->right->data;
    }

    updateQuantity(newNode);

    return newNode;
}

void ListArr::insert_left(int v)
{
    SummaryNode *actualNode = root;

    // llega al primer DataNode de la izquierda
    while (actualNode->left != NULL)
        actualNode = actualNode->left;

    DataNode *dataNode = actualNode->data;

    if (dataNode->count == dataNode->nCapacity)
    {
        if (dataNode->next == NULL || dataNode->next->isFull())
        {
            insertNode(dataNode);
            leafs++;
            createBinaryTree(leafs);

            dataNode->next->container[0] = dataNode->container[dataNode->count - 1];
            dataNode->next->count = dataNode->next->count + 1;

            moveRight(dataNode);
            dataNode->container[0] = v;
        }
        else
        {
            moveRight(dataNode->next);
            dataNode->next->container[0] = dataNode->container[dataNode->count - 1];
            dataNode->next->count = dataNode->next->count + 1;

            moveRight(dataNode);
            dataNode->container[0] = v;
        }
    }
    else
    {
        moveRight(dataNode);
        dataNode->container[0] = v;
        dataNode->count = dataNode->count + 1;
    }
}

void ListArr::insert_right(int v)
{
    SummaryNode *actualNode = root;
    int flag = 0;

    // llega al último DataNode de la derecha
    // SE NECESITA ARBOL PARA NAVEGAR HACIA LA DERECHA
    while (actualNode->right != NULL)
        actualNode = actualNode->right;

    DataNode *dataNode = actualNode->data;

    // si el último nodo está lleno, se debe crear un nuevo nodo llamando a insertNode()
    if (dataNode->count == dataNode->nCapacity)
    {
        // flag = 1;
        insertNode(dataNode);
        leafs++;
        createBinaryTree(leafs);

        dataNode->next->container[dataNode->next->count] = v;
        dataNode->next->count = dataNode->next->count + 1;
    }

    // si el flag es verdadero, el nuevo DataNode estará vacío, por lo que se ingresa un elemento en la posición 0
    // sino, el arreglo no está lleno y se agrega un elemento en la posicion después del último ingresado
    // if (flag)
    //{
    // dataNode->container[0] = v;
    // dataNode->count = dataNode->count + 1;
    //}
    else
    {
        dataNode->container[dataNode->count] = v;
        dataNode->count = dataNode->count + 1;
    }
}

void inOrderTraversal(SummaryNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrderTraversal(root->left);
    // Aquí se puede realizar la operación deseada con el nodo actual
    cout << root->quantity << " " << root->sCapacity << endl;
    inOrderTraversal(root->right);
}

void ListArr::print()
{
    SummaryNode *actualNode = root;
    while (actualNode->left != NULL)
    {
        actualNode = actualNode->left;
    }
    DataNode *dataNode = actualNode->data;

    cout << "a" << endl;
    cout << dataNode->count << endl;
    cout << root->quantity << endl;
    cout << root->sCapacity << endl;

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

    inOrderTraversal(root);
}