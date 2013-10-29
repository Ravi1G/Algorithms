#ifndef ITEM_H_
#define ITEM_H_

template <class TYPE>
class Item
{
    public:
        TYPE Data;
        Item *Next;


        Item();
        Item(TYPE val): Data(val), Next(NULL)
        { }
        /*
        int data()
        {
            return Data;
        }

        Item *next()
        {
            return Next;
        }
*/
};

#endif // ITEM_H_
