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

        TreeNode* SearchTree(TreeNode *, int *);

    public:

        BinarSearchTree();

        void Insert(int, int);
        void Delete(int);

        void InOrderWalk();
        void PreOrderWalk();
        void PostOrderWalk();

        TreeNode* Search(int key); // search node with key
        TreeNode* Minimum();
        TreeNode* Minimum(TreeNode *);
        TreeNode* Maximum();
        TreeNode* Maximum(TreeNode *);
        TreeNode* Successor(TreeNode*);
        TreeNode* Predecessor(TreeNode *);
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

void BinarSearchTree::Delete(int key)
{
    /*
    3 ситуации:
    а) у узла нет дочерних узлов
    б) 1 дочерний узел
    в) 2 дочерних узла
    */




}

///////////////////////////////////////////
///////////////////////////////////////////

TreeNode* BinarSearchTree::Search(int key)
{
   return SearchTree(Root, &key);
}

///////////////////////////////////////////
///////////////////////////////////////////

TreeNode* BinarSearchTree::SearchTree(TreeNode *ptr, int *k)
{
    if (ptr == NULL || *k == ptr->Key)
        return ptr;

    if (*k < ptr->Key)
        return SearchTree(ptr->Left, k);
    else
        return SearchTree(ptr->Right, k);

}

///////////////////////////////////////////
///////////////////////////////////////////

TreeNode* BinarSearchTree::Minimum()
{
    TreeNode *cur = Root;
    while(cur->Left)
        cur = cur->Left;
    return cur;
}

///////////////////////////////////////////
///////////////////////////////////////////

TreeNode* BinarSearchTree::Minimum(TreeNode *cur)
{
    while(cur->Left)
        cur = cur->Left;
    return cur;
}

///////////////////////////////////////////
///////////////////////////////////////////

TreeNode* BinarSearchTree::Maximum()
{
    TreeNode *cur = Root;
    while(cur->Right)
        cur = cur->Right;
    return cur;
}

///////////////////////////////////////////
///////////////////////////////////////////

TreeNode* BinarSearchTree::Maximum(TreeNode *cur)
{
    while(cur->Right)
        cur = cur->Right;
    return cur;
}

///////////////////////////////////////////
///////////////////////////////////////////

TreeNode* BinarSearchTree::Successor(TreeNode *cur)
{
    if (cur->Right != NULL)
        return Minimum(cur->Right);


    TreeNode *par = cur->Parent;

    while(par != NULL && cur == par->Right){
        cur = par;
        par = cur->Parent;
    }

    return par;
}

///////////////////////////////////////////
///////////////////////////////////////////

TreeNode* BinarSearchTree::Predecessor(TreeNode *cur)
{
    TreeNode *par = cur->Parent;

    if (par == NULL) //т.е. мы в корне
        return Maximum(cur->Left);

    if (cur == par->Right) // узел рут правого поддерева предыдущего (искомого) узла
        return par;

    return Maximum(cur->Left);


}

///////////////////////////////////////////
///////////////////////////////////////////

#endif // BINARSEARCHTREE_H_
