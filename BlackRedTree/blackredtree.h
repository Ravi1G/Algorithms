#ifndef BLACKREDTREE_H_
#define BLACKREDTREE_H_

#include "blackrednode.h"

class BlackRedTree
{
    private:
        BlackRedNode *Root;

        void InOrder(BlackRedNode *);

    public:
        BlackRedTree();

        void InOrderWalk();

        void Insert(int, int);

};

BlackRedTree::BlackRedTree(): Root(NULL)
{ }


////

void BlackRedTree::InOrderWalk()
{
    InOrder(Root);
}

////

void BlackRedTree::InOrder(BlackRedNode *tr)
{
    if (tr){
        InOrder(tr->Left);
        std::cout << tr->Data << " ";
        InOrder(tr->Right);
    }
}


void BlackRedTree::Insert(int key, int val)
{
    BlackRedNode *ptr, *cur, *par;
    color cl = BLACK;

    ptr = new BlackRedNode(key, val, cl); // выделение памяти для нового узла

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


#endif // BLACKREDTREE_H_
