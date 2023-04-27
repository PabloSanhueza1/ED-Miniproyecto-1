#include "ListArr.h"

ListArr::ListArr(int b)
{
    capacity = b;
    DataNode *initialNode = new DataNode(capacity);
    root = new SummaryNode(0, capacity);
    root->data = initialNode;
}

void ListArr::insert_left(int v)
{
    SummaryNode *nodeAux = root;

    while (nodeAux->left != NULL)
    {
        nodeAux = nodeAux->left;
    }

    nodeAux->data->container[nodeAux->data->count] = v;
    nodeAux->data->count = nodeAux->data->count + 1;
}

void ListArr::print()
{
    SummaryNode *nodeAux = root;
    while (nodeAux->left != NULL)
    {
        nodeAux = nodeAux->left;
    }

    DataNode *dataNode = nodeAux->data;

    cout << endl;
    while (dataNode != NULL)
    {
        int i = 0;
        cout << "Node " << i << ":" << endl;
        
        for (int j = 0; j < dataNode->count; j++)
        {
            cout << dataNode->container[j] << " ";
        }

        cout << endl;
        dataNode = dataNode->next;

        i++;
    }
}