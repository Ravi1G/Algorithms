#ifndef BINARSEARCHTREE_H_
#define BINARSEARCHTREE_H_

#include "node.h"

//template <class TYPE>
class BinarSearchTree
{
    private:


        TreeNode *Root; // pointer to root of tree

        void InOrder(TreeNode *);
        void PreOrder(TreeNode *);
        void PostOrder(TreeNode *);

    public:

        BinarSearchTree();

        void Insert(int, int);

        void InOrderWalk();
        void PreOrderWalk();
        void PostOrderWalk();


};

///////////////////////////////////////////
///////////////////////////////////////////

//template <class TYPE>
BinarSearchTree::BinarSearchTree()
{
    Root = NULL;
}

///////////////////////////////////////////
///////////////////////////////////////////

//template <class TYPE>
void BinarSearchTree::InOrderWalk()
{
    InOrder(Root);
}

///////////////////////////////////////////
///////////////////////////////////////////

void BinarSearchTree::PreOrderWalk()
{
    PreOrder(Root);
}

///////////////////////////////////////////
///////////////////////////////////////////

void BinarSearchTree::PostOrderWalk()
{
    PostOrder(Root);
}

///////////////////////////////////////////
///////////////////////////////////////////

//template <class TYPE>
void BinarSearchTree::InOrder(TreeNode *tr)
{
    if (tr){
        InOrder(tr->Left);
        std::cout << tr->Data << " ";
        InOrder(tr->Right);
    }
}

///////////////////////////////////////////
///////////////////////////////////////////

void BinarSearchTree::PreOrder(TreeNode *tr)
{
    if (tr){
        std::cout << tr->Data << " ";
        InOrder(tr->Left);
        InOrder(tr->Right);
    }
}

///////////////////////////////////////////
///////////////////////////////////////////

void BinarSearchTree::PostOrder(TreeNode *tr)
{
    if (tr){
        InOrder(tr->Left);
        InOrder(tr->Right);
        std::cout << tr->Data << " ";
    }
}

///////////////////////////////////////////
///////////////////////////////////////////

//template <class TYPE>
void BinarSearchTree::Insert(int key, int val)
{
    TreeNode *ptr, *cur, *par;

    ptr = new TreeNode(key, val); // выделение памяти для нового узла

    if (Root == NULL){ // if tree is empty
        Root = ptr;
        return;
    }

    cur = Root;
    par = NULL;

    while (cur){
        par = cur;

        if (val < cur->Data)
            cur = cur->Left;
        else
            cur = cur->Right;
    }

    ptr->Parent = par;

    if(val < par->Data)
        par->Left = ptr;
    else
        par->Right = ptr;
}

///////////////////////////////////////////
///////////////////////////////////////////






















#endif // BINARSEARCHTREE_H_
