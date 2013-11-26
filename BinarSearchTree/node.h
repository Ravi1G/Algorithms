#ifndef NODE_H_
#define NODE_H_


//template <class TYPE>
class TreeNode
{
    private:
        friend class BinarSearchTree;
        int Key;
        int Data;
        TreeNode *Parent,
                       *Left,
                       *Right;


    public:
    TreeNode();
    TreeNode(int key, int val);

};

//////////////////////////////////////////////
//////////////////////////////////////////////

//template <class TYPE>
TreeNode::TreeNode()
    {
        Parent = Left = Right = NULL;
    }

//////////////////////////////////////////////
//////////////////////////////////////////////

//template <class TYPE>
TreeNode::TreeNode(int key, int val)
    {
        Parent = Left = Right = NULL;
        Data = val;
        Key = key;
    }

#endif // NODE_H_
