#ifndef NODE_H_
#define NODE_H_

struct Node
{
    int Key;
    int Data;
    Node *Parent,
         *Left,
         *Right;

    Node(int k, int d)
    {
        Key = k;
        Data = d;

        Parent = Left = Right = NULL;
    }

};











#endif // NODE_H_
