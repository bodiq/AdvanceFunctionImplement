#include "Neste.h"


template<class T>
Neste<T>::Neste(int m_size) : size(m_size), pos(0)
{
    arr = new T[size];
}

template<class T>
int Neste<T>::Getsize() const
{
    return size;
}

template<class T>
void Neste<T>::add(T a)
{
    if(pos == size)
    {
        T temp = arr[0];
        arr[0] = a;
        for(size_t i = 1; i < size - 1; i++)
        {
            arr[i + 1] = arr[i];
            arr[i] = temp;
            temp = arr[i];
        }
    }
    else
    {
        arr[pos++] = a;
    }
}

template<class T>
T Neste<T>::get(int a) const
{
    return arr[a];
}

template<class T>
Neste<T>::~Neste() { delete []arr; }













