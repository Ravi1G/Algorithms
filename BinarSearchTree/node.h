#ifndef NODE_H_
#define NODE_H_

class TreeNode
{
    private:
        friend class BinarSearchTree;
        //char Key;
        int Data;
        TreeNode *Parent,
             *Left,
             *Right;

    public:
    TreeNode()
    {
        Parent = Left = Right = NULL;
    }

    TreeNode(int x)
    {
        Parent = Left = Right = NULL;
        Data = x;
    }



/*
    Node(int k, int d)
    {
        Key = k;
        Data = d;

        Parent = Left = Right = NULL;
    }
*/
};











#endif // NODE_H_
