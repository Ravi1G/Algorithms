#ifndef BINARSEARCHTREE_H_
#define BINARSEARCHTREE_H_

#include "node.h"


class BinarSearchTree
{
    public:
        Node *Root; // pointer to root of tree;

        int ShowRoot(){
            return Root->Data;

        }

        BinarSearchTree(): Root(NULL)
        { }



        void TreeInsert(int val)
        {
            TreeInsertHelper(Root, val);

        }

        void TreeInsertHelper(Node *ptr, int val)
        {

            if (!ptr)
                Node *ptr  = new Node(val, val);
            else{
                if (ptr->Data > val)
                    TreeInsertHelper(ptr->Left, val);
                else
                    TreeInsertHelper(ptr->Right, val);

            }

        }

};








#endif // BINARSEARCHTREE_H_
