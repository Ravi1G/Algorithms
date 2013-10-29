#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "item.h"
#include <iostream>

template <class TYPE>
class LinkedList
{
    private:
        Item *head;

    public:
        LinkedList(): head(NULL)
        { }

        void add(TYPE val)
        {
            Item *It = new Item(val);

            Item *cur = head;

            if (cur == NULL)
                head = It;
            else{
                while (cur->Next){
                    cur = cur->Next;
                }
                cur->Next = It;
            }

        }

        void display()
        {
            Item* cur = head;


            while(cur)
            {
                std::cout << cur->Data << " ";
                cur = cur->Next;
            }

        }
};





#endif // LINKEDLIST_H_
