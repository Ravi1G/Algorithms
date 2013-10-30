#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "item.h"
#include <iostream>

template <class TYPE>
class LinkedList
{
    private:
        Item<TYPE> *head;

    public:
        LinkedList(): head(0)
        { }

        void add(TYPE val)
        {
            Item<TYPE> *It = new Item<TYPE>(val);

            Item<TYPE> *cur = head;

            if (cur == 0)
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
            Item<TYPE> *cur = head;


            while(cur)
            {
                std::cout << cur->Data << " ";
                cur = cur->Next;
            }

        }
};





#endif // LINKEDLIST_H_
