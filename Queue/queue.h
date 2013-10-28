#ifndef QUEUE_H_
#define QUEUE_H_


template <class TYPE>
class Queue
{
    private:
        TYPE *Q;
        int top,
            size,
            head,
            tail;

    public:
        Queue(int);
        ~Queue();
        void Enqueue(TYPE);
        TYPE Dequeue();
        bool isEmpty();
};


template <class TYPE>
Queue<TYPE>::Queue(int sz)
{
    Q = new TYPE[size];
    size = sz;
    head = 0;
    tail = 0;
}


template <class TYPE>
Queue<TYPE>::~Queue()
{
    delete [] Q;
}


template <class TYPE>
void Queue<TYPE>::Enqueue(TYPE val)
{
    Q[tail] = val;
    if (tail == size - 1)
        tail = 0;
    else
        tail++;
}


template <class TYPE>
TYPE Queue<TYPE>::Dequeue()
{
    TYPE x = Q[head];
    if (head == size - 1)
        head = 0;
    else
        head++;
    return x;
}

#endif // QUEUE_H_
