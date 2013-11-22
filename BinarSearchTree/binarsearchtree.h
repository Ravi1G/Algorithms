#ifndef BINARSEARCHTREE_H_
#define BINARSEARCHTREE_H_

#include "node.h"


class BinarSearchTree
{
    private:
        TreeNode *Root; // pointer to root of tree;

        void InOrder(TreeNode *ptr)
        {
            if (ptr != NULL){
                InOrder(ptr->Left);
                std::cout << ptr->Data << " ";
                InOrder(ptr->Right);
            }
        }
    public:
        int ShowRoot(){
            return Root->Data;

        }

        BinarSearchTree()
        {
            Root = NULL;
        }

        void add(int x)
        {
            TreeNode *ptr = new TreeNode(x),
                     *cur;


            // if tree is empty
            if (Root == NULL){
                Root = ptr;
                return;
            }
            // else
            cur = Root;

            if (x < cur->Data){
                cur->Left = ptr;
            }

            if (x > cur->Data)
                cur->Right = ptr;

        }


        void InOrderWalk()
        {
            InOrder(Root);
        }















};








#endif // BINARSEARCHTREE_H_
