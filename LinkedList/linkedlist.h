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
        LinkedList();
        ~LinkedList();

        void push_back(TYPE val);
        void pull_back();
        void remove(int);
        void display();
        void reverse();


};

/////////////////////////////////////////
/////////////////////////////////////////

template <class TYPE>
LinkedList<TYPE>::LinkedList(): head(0)
{ }

/////////////////////////////////////////
/////////////////////////////////////////

template <class TYPE>
LinkedList<TYPE>::~LinkedList()
{
    Item<TYPE> *cur = head;

    while (cur->Next){
        cur = cur->Next;
        delete head;
        head = cur;
    }

    delete head;
}

/////////////////////////////////////////
/////////////////////////////////////////

template <class TYPE>
void LinkedList<TYPE>::push_back(TYPE val)
{
    Item<TYPE> *It = new Item<TYPE>(val);

    Item<TYPE> *cur = head;

    if (!cur)
        head = It;

    else{
        while (cur->Next)
            cur = cur->Next;

        cur->Next = It;
    }
}

/////////////////////////////////////////
/////////////////////////////////////////

template <class TYPE>
void LinkedList<TYPE>::pull_back()
{


}


/////////////////////////////////////////
/////////////////////////////////////////

template <class TYPE>
void LinkedList<TYPE>::display()
{
    Item<TYPE> *cur = head;

    while(cur){
        std::cout << cur->Data << " ";
        cur = cur->Next;
    }

    std::cout << "\n";
}

/////////////////////////////////////////
/////////////////////////////////////////

template <class TYPE>
void LinkedList<TYPE>::reverse()
{
    Item<TYPE> *cur = head->Next, *temp;

    head->Next = NULL;

    while(cur){
        temp = cur;
        cur = cur->Next;
        temp -> Next = head;
        head = temp;
    }

    cur = temp = NULL;
}







#endif // LINKEDLIST_H_
