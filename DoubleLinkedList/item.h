#ifndef ITEM_H_
#define ITEM_H_


//template <class TYPE>
class Item
{
    public:
        int Data;
        Item *Next, *Prev;


        Item();
        Item(int val): Data(val), Next(NULL), Prev(NULL)
        { }

};




#endif // ITEM_H_
