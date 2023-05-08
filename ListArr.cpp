#include "ListArr.h"

// Métodos que no pertenecen al a clase ListArr:
// Mueve los elementos hacia la derecha de un arreglo a partir del j-ésimo elemento
void moveRight(DataNode *&dataNode, int j)
{
    for (int i = dataNode->count - 1; i >= j; i--)
    {
        dataNode->container[i + 1] = dataNode->container[i];
    }
}

// Imprime por pantalla recorrido pre-order del arbol binario
void preOrder(SummaryNode *root)
{
    if (root != NULL)
    {
        cout << root->quantity << " " << root->sCapacity << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

ListArr::ListArr(int b)
{
    capacity = b;
    setLeafs(1);
    setDataAssigned(false);
    DataNode *initialNode = new DataNode(capacity);
    head = initialNode;
    root = createBinaryTree(getLeafs());
    updateTree();
}

ListArr::~ListArr()
{
    freeBinaryTree(root);
    DataNode *temp = head;
    while (temp != NULL)
    {
        DataNode *next = temp->next;
        delete[] temp->container;
        delete temp;
        temp = next;
    }
}

// Seters y getters
void ListArr::setLeafs(int i)
{
    leafs = i;
}

int ListArr::getLeafs()
{
    return leafs;
}

void ListArr::setDataAssigned(bool v)
{
    dataAssigned = v;
}

bool ListArr::getDataAssigned()
{
    return dataAssigned;
}

// Métodos para actualizar arbol binario
void ListArr::freeBinaryTree(SummaryNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    freeBinaryTree(node->left);
    freeBinaryTree(node->right);
    delete node;
}

DataNode *ListArr::getNode(int index)
{
    DataNode *currentNode = head;
    int i = 1;
    while (currentNode != NULL && i < index)
    {
        currentNode = currentNode->next;
        i++;
    }
    return currentNode;
}

void ListArr::assignDataNodes(SummaryNode *node, int index)
{

    if (node == NULL ||
        getDataAssigned()) // si ya se asignó el nodo de datos o se llegó al final del árbol, termina la función
    {
        return;
    }

    if (node->left == NULL && node->right == NULL && node->data == NULL)
    {
        // "node" es hoja
        node->data = getNode(index); // asigna el nodo de datos
        setDataAssigned(true);       // marca que ya se asignó el nodo de datos
        return;
    }
    else
    { // "node" no es hoja, sigue llamando recursivamente
        assignDataNodes(node->left, index);
        assignDataNodes(node->right, index);
    }
}

void ListArr::cleanAllParents(SummaryNode *node)
{
    if (node != NULL)
    {
        node->data = NULL;

        cleanAllParents(node->left);
        cleanAllParents(node->right);
    }
}

int ListArr::updateQuantity(SummaryNode *node)
{
    int leftQuantity = 0;
    int rightQuantity = 0;
    int dataQuantity = 0;

    if (node->left != NULL)
    {
        leftQuantity = updateQuantity(node->left);
    }

    if (node->right != NULL)
    {
        rightQuantity = updateQuantity(node->right);
    }

    if (node->data != NULL)
    {
        dataQuantity = node->data->count;
    }

    node->quantity = leftQuantity + rightQuantity + dataQuantity;

    return node->quantity;
}

int ListArr::updateCapacity(SummaryNode *node)
{
    int leftCapacity = 0;
    int rightCapacity = 0;
    int dataCapacity = 0;

    if (node->left != NULL)
    {
        leftCapacity = updateCapacity(node->left);
    }

    if (node->right != NULL)
    {
        rightCapacity = updateCapacity(node->right);
    }

    if (node->data != NULL)
    {
        dataCapacity = node->data->nCapacity;
    }

    node->sCapacity = leftCapacity + rightCapacity + dataCapacity;

    return node->sCapacity;
}

void ListArr::updateTree()
{
    updateQuantity(root);
    updateCapacity(root);
}

// devuelve la raíz del árbol binario creado
SummaryNode *ListArr::createBinaryTree(int leaf)
{
    if (leaf == 1)
    {
        SummaryNode *summaryNode = new SummaryNode();
        summaryNode->data = head;
        return summaryNode;
    }

    SummaryNode *newNode = new SummaryNode();

    // crear sub-árboles izquierdo y derecho recursivamente
    newNode->left = createBinaryTree(leaf / 2);
    newNode->right = createBinaryTree(leaf - leaf / 2);

    updateQuantity(newNode);
    updateCapacity(newNode);

    return newNode;
}

// Métodos de inserción
void ListArr::insertNode(DataNode *&dataNode)
{
    DataNode *newDataNode = new DataNode(dataNode->nCapacity);

    // se conecta el nuevo nodo con el resto de la estructura
    if (dataNode->next != NULL)
        newDataNode->next = dataNode->next;

    dataNode->next = newDataNode;
}

void ListArr::insertBefore(DataNode *dataNode, int v, int i)
{
    if (dataNode->count == dataNode->nCapacity)
    {
        if (dataNode->next == NULL || dataNode->next->isFull())
        {
            setLeafs(getLeafs() + 1);
            insertNode(dataNode);

            dataNode->next->container[0] = dataNode->container[dataNode->count - 1];
            dataNode->next->count = dataNode->next->count + 1;

            moveRight(dataNode, i);
            dataNode->container[i] = v;

            freeBinaryTree(root);
            root = createBinaryTree(getLeafs());
            cleanAllParents(root);
            for (int j = 1; j <= getLeafs(); j++)
            {
                setDataAssigned(false);
                assignDataNodes(root, j);
            }
            updateTree();
        }
        else
        {
            moveRight(dataNode->next, 0);
            dataNode->next->container[0] = dataNode->container[dataNode->count - 1];
            dataNode->next->count = dataNode->next->count + 1;

            moveRight(dataNode, i);
            dataNode->container[i] = v;

            freeBinaryTree(root);
            root = createBinaryTree(getLeafs());
            cleanAllParents(root);
            for (int j = 1; j <= getLeafs(); j++)
            {
                setDataAssigned(false);
                assignDataNodes(root, j);
            }
            updateTree();
        }
    }
    else
    {
        moveRight(dataNode, i);
        dataNode->container[i] = v;
        dataNode->count = dataNode->count + 1;
        updateTree();
    }
}

void ListArr::insertAfter(DataNode *dataNode, int v, int i)
{
    if (dataNode->count == dataNode->nCapacity)
    {
        setLeafs(getLeafs() + 1);
        insertNode(dataNode);

        dataNode->next->container[0] = v;
        dataNode->next->count = dataNode->next->count + 1;

        freeBinaryTree(root);
        root = createBinaryTree(getLeafs());
        cleanAllParents(root);
        for (int j = 1; j <= getLeafs(); j++)
        {
            setDataAssigned(false);
            assignDataNodes(root, j);
        }
        updateTree();
    }
    else
    {
        dataNode->container[i] = v;
        dataNode->count = dataNode->count + 1;
        updateTree();
    }
}

// Método auxiliar para insert() a implementar
void ListArr::insertRecursivo(SummaryNode *actualNode, int v, int i)
{
    if (actualNode->data == NULL)
    {
        if (i < actualNode->left->quantity)
            insertRecursivo(actualNode->left, v, i);
        else
            insertRecursivo(actualNode->right, v, i - actualNode->left->quantity);
    }
    else
        insertBefore(actualNode->data, v, i);
}

// Métodos a implementar:
int ListArr::size()
{
    return root->quantity;
}

void ListArr::insert_left(int v)
{
    insertBefore(head, v, 0);
}

void ListArr::insert_right(int v)
{
    SummaryNode *actualNode = root;

    // Llega al último DataNode de la derecha
    while (actualNode->right != NULL)
        actualNode = actualNode->right;

    DataNode *dataNode = actualNode->data;
    int pos = dataNode->count;

    insertAfter(dataNode, v, pos);
}

void ListArr::insert(int v, int i)
{
    try
    {
        if (i > root->sCapacity)
            throw "Invalid index!";
        if (root->data != NULL)
            insertBefore(root->data, v, i);
        else if (i < root->left->quantity)
            insertRecursivo(root->left, v, i);
        else
            insertRecursivo(root->right, v, i - root->left->quantity);
    }
    catch (const char *message)
    {
        cerr << message << endl;
        exit(EXIT_FAILURE);
    }
}

void ListArr::print()
{
    DataNode *dataNode = head;

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

    preOrder(root);
}

bool ListArr::find(int v)
{
    DataNode *actualNode = head;

    while (actualNode != NULL)
    {
        for (int i = 0; i < actualNode->count; i++)
            if (actualNode->container[i] == v)
                return true;
        actualNode = actualNode->next;
    }
    return false;
}