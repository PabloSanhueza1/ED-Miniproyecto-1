#include "ListArr.h"

ListArr::ListArr(int b)
{
    capacity = b;
    leafs = 1;
    DataNode *initialNode = new DataNode(capacity);
    head = initialNode;
    root = createBinaryTree(leafs); // se llama al método para crear el árbol binario
    updateTree();
}

void ListArr::insertNode(DataNode *&dataNode)
{
    DataNode *newDataNode = new DataNode(dataNode->nCapacity);
    newDataNode->name = leafs;
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
SummaryNode *ListArr::createBinaryTree(int leafs)
{
    if (leafs == 1)
    {
        SummaryNode *summaryNode = new SummaryNode();
        summaryNode->data = head;
        return summaryNode;
    }

    SummaryNode *newNode = new SummaryNode();

    // crear sub-árboles izquierdo y derecho recursivamente
    newNode->left = createBinaryTree(leafs / 2);
    newNode->right = createBinaryTree(leafs - leafs / 2);

    updateQuantity(newNode);
    updateCapacity(newNode);

    return newNode;
}

void ListArr::insert_left(int v)
{

    DataNode *dataNode = head;

    if (dataNode->count == dataNode->nCapacity)
    {
        if (dataNode->next == NULL || dataNode->next->isFull())
        {
            leafs++;
            insertNode(dataNode);

            dataNode->next->container[0] = dataNode->container[dataNode->count - 1];
            dataNode->next->count = dataNode->next->count + 1;

            moveRight(dataNode);
            dataNode->container[0] = v;

            // cout << "SE ACTUALIZA CON " << leafs << " HOJAS"
            //   << " [SE CREA NODO NUEVO]" << endl;
            // cleanAllParents();
            root = createBinaryTree(leafs);
            cleanAllParents(root);
            for (int i = 1; i <= leafs; i++)
            {
                dataAssigned = false;
                assignDataNodes(root, i);
            } // cout << "AAAAAAAAAAAAAAAAAAAAAAA" << endl;
            updateTree();
        }
        else
        {
            moveRight(dataNode->next);
            dataNode->next->container[0] = dataNode->container[dataNode->count - 1];
            dataNode->next->count = dataNode->next->count + 1;

            moveRight(dataNode);
            dataNode->container[0] = v;
            // cout << "SE ACTUALIZA CON " << leafs << "HOJAS"
            //   << "[no se CREA NODO NUEVO]" << endl;

            // cleanAllParents();
            root = createBinaryTree(leafs);
            cleanAllParents(root);
            for (int i = 1; i <= leafs; i++)
            {
                dataAssigned = false;
                assignDataNodes(root, i);
            }
            updateTree();
        }
    }
    else
    {
        moveRight(dataNode);
        dataNode->container[0] = v;
        dataNode->count = dataNode->count + 1;
        updateTree();
    }
}

void ListArr::insert_right(int v)
{
    SummaryNode *actualNode = root;
    // llega al último DataNode de la derecha
    while (actualNode->right != NULL)
        actualNode = actualNode->right;

    DataNode *dataNode = actualNode->data;

    // si el último nodo está lleno, se debe crear un nuevo nodo llamando a insertNode()
    if (dataNode->count == dataNode->nCapacity)
    {
        insertNode(dataNode);
        leafs++;
        createBinaryTree(leafs);

        dataNode->next->container[dataNode->next->count] = v;
        dataNode->next->count = dataNode->next->count + 1;
    }
    else
    {
        dataNode->container[dataNode->count] = v;
        dataNode->count = dataNode->count + 1;
    }
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
        dataAssigned) // si ya se asignó el nodo de datos o se llegó al final del árbol, termina la función
    {
        return;
    }

    if (node->left == NULL && node->right == NULL && node->data == NULL)
    {                                // es una hoja
        node->data = getNode(index); // asigna el nodo de datos
        dataAssigned = true;         // marca que ya se asignó el nodo de datos
        return;
    }
    else
    { // no es hoja, sigue llamando recursivamente
        assignDataNodes(node->left, index);
        assignDataNodes(node->right, index);
    }
}

void preOrderTraversal(SummaryNode *root)
{
    if (root != NULL)
    {
        cout << root->quantity << " " << root->sCapacity << endl;
        /* if (root->left == NULL && root->right == NULL)
        {
            cout << "nombre: " << root->data->name << endl;
        }*/
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
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

    preOrderTraversal(root);
}