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
        void DeleteNode(TreeNode *);
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
        if (tr->Left)
            PreOrder(tr->Left);
        if (tr->Right)
            PreOrder(tr->Right);
    }
}

///////////////////////////////////////////
///////////////////////////////////////////

void BinarSearchTree::PostOrder(TreeNode *tr)
{
    if (tr){
        PostOrder(tr->Left);
        PostOrder(tr->Right);
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

        if (key < cur->Data)
            cur = cur->Left;
        else
            cur = cur->Right;
    }

    ptr->Parent = par;

    if(key < par->Data)
        par->Left = ptr;
    else
        par->Right = ptr;
}

///////////////////////////////////////////
///////////////////////////////////////////

void BinarSearchTree::Delete(int key)
{

    TreeNode *f = Search(key);
    std::cout << "\nNow deleting elem with key " << key <<". It contains " << f->data() << std::endl;
    DeleteNode(f);

    //f = NULL;

/*
    3 ситуации:
    а) у узла нет дочерних узлов
    б) 1 дочерний узел
    в) 2 дочерних узла

*/



}

///////////////////////////////////////////
///////////////////////////////////////////

TreeNode* BinarSearchTree::DeleteNode(TreeNode *delNode)
{

    // при удалении узла из дерева возможны 3 ситуации:
    // а) у узла нет потомков. тогда все просто.
    // б) у узла один дочерний узел (правый или левый), тогда все тоже просто.
    // в) у узла 2 дочерних узла. тут будем думать.

    //а)
/*/
    TreeNode *par = del->Parent;

    std::cout << "\n parent is "<< par->Key << ":" << par->Data;
    if ((del->Left == NULL) && (del->Right == NULL)){
        if (par->Left == del)
            par->Left = NULL;
        else
            par->Right = NULL;


        delete del;
        del == NULL;
    }

    //б)
    //б1) нет левого дочернего узла

    else if (del->Left == NULL){
        if (par->Left == del)
            par->Left = del->Right;
        else
            par->Right = del->Right;
    }


    //б2) нет правого дочернего узла
    else if (del->Right == NULL){
        if (par->Left == del)
            par->Left = del->Left;
        else
            par->Right = del->Left;
    }

    //в)

    else{

    }

//*/
/*

    TreeNode *par = del->Parent;

    if (!del->Left && !del->Right)
    {

        if (par->Left == del)
            par->Left = NULL;
        else
            par->Right = NULL;
        //delete del;

        //
        //del = NULL;
        //delete del;
        return;

    }
//*/

    // ищем cur - элемент убираемый путем "склейки" родителя и потомка // узел на подмену
    // a)cur = del  -  сам узел (если у узла не более одного дочернего узла,
                                      //т.е. либо один узел, либо ни одного.).

    // б)кур = следующий за удаляемым (у узла нет левой дочки)
    //- если у узла 2 дочерних узла.

    // вариант кормена


    TreeNode *changeNode, *cur = NULL;

    if(!delNode->Left || !delNode->Right)
        changeNode = delNode;  //узел на подмену - сам удаляемый узел.
    else
        changeNode = Successor(del); // у узла 2 доч.узла=> узел на подмену следующий в симметричном обходе.


    if (changeNode->Left)
        cur = changeNode->Left;
    else
        cur = changeNode->Right;

    // определив если ли у

    if (cur)
        x->Parent = changeNode->Parent;

    if (!changeNode->Parent)
        Root = x;
    else if (changeNode == changeNode->Parent->Left)
        changeNode->Parent->Left = x;
    else
        changeNode->Parent->Right = x;


    if (changeNode != delNode){
        del->Key = changeNode->Key;
        del->Data = changeNode->Data;
    }

    //delete del;
    //if(!cur->Left)




    /*
    TreeNode *par = cur->Parent;

    TreeNode *cur, *x;

    if (!cur->Left || !cur->Right)
        cur = del;
    else
        cur = Successor(del); // подумать над cur = successor(cur);


    if (cur->Left != NULL)
        x = cur->Left;
    else
        x = cur->Right;

    if (x != NULL){


        if (cur == par->Left)
            par->Left = NULL;
        if (cur == par->Right)
            par->Right = NULL;
        delete cur;
    }
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

    if (cur->Left != NULL)
        return Maximum(cur->Left);


    TreeNode *par = cur->Parent;

    while (par->Right != cur){
        cur = par;
        par = cur->Parent;
    }

    return par;
}

///////////////////////////////////////////
///////////////////////////////////////////

#endif // BINARSEARCHTREE_H_
