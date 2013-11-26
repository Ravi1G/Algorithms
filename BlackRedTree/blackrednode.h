#ifndef BLACKREDNODE_H_
#define BLACKREDNODE_H_

enum color{BLACK, RED};

class BlackRedNode
{
    public:
        int Key;
        int Data;
        BlackRedNode *Left,
                     *Right,
                     *Parent;
        color Color;

        BlackRedNode();
        BlackRedNode(int, int, color);
};

BlackRedNode::BlackRedNode()
{
    Parent = Left = Right = NULL;
}

BlackRedNode::BlackRedNode(int key, int val, color cl)
{
    Parent = Left = Right = NULL;
    Data = val;
    Key = key;
    Color = cl;
}


#endif // BLACKREDNODE_H_
