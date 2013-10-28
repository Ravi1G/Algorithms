#ifndef SORTING_H_
#define SORTING_H_

/////////////////////////////////////////////
template <class T>
void BubbleSort(T *arr, int size)
{
	T min, temp;
	int index;
	for (int i = 0; i < size - 1; i++){
		min = arr[i];
		index = i;
		for (int j = i; j < size; j++){
			if(arr[j] < min){
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}

}
/////////////////////////////////////////////

/////////////////////////////////////////////
template <class T>
void InsertSort(T *arr, int size)
{
	T key;
	int j;
	for(int i = 1; i < size; i++){
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
/////////////////////////////////////////////

/////////////////////////////////////////////
template <class T>
T Left(T i)
{
    return i*2+1;
}

template <class T>
T Right(T i)
{
    return i*2 + 2;
}

template <class T>
void swap(T *x, T *y)
{
    T tmp = *x;
    *x = *y;
    *y = tmp;
}

// поддержание кучи
template <class T>
void Heapify(T *arr, int i, int n)
{
    int max = i,
        lt = Left(i),
        rt = Right(i);

    if(lt < n && arr[lt] > arr[max])
        max = lt;
    if(rt < n && arr[rt] > arr[max])
        max = rt;
    if (max != i){
        swap(&arr[i], &arr[max]);
        Heapify(arr, max, n);
    }
}

// собственно сортировка

template <class T>
void HeapSort(T *arr, int n)
{
    for (int i = n/2; i >=0; i--)
        Heapify(arr, i, n);

    for (int i = n - 1; i > 0; i--){
        swap(&arr[0], &arr[i]);
        n--;
        Heapify(arr, 0, n);
    }
}
/////////////////////////////////////////////

/////////////////////////////////////////////
#endif // SORTING_H_
