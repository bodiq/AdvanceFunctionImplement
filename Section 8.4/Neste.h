#pragma once

#include <iostream>
#include <vector>

template<class T>
class Neste
{
public:
    class iterator;
public:
    Neste(int m_size);
    void add(T a);
    int Getsize() const;
    T get(int a) const;

    iterator begin()
    {
        return iterator(0, *this);
    }
    iterator end()
    {
        return iterator(size, *this);
    }

    ~Neste();
private:
    int pos;
    int size;
    T *arr;
};

template<class T>
class Neste<T>::iterator
{
public:
    iterator(int pos, Neste &nes) : m_pos(pos), m_nes(nes) {}
    iterator &operator++(int)
    {
        m_pos++;
        return *this;
    }
    iterator &operator++()
    {
        m_pos++;
        return *this;
    }
    const T &operator*() const
    {
        return m_nes.get(m_pos);
    }
    bool operator!=(const iterator &it) const
    {
        return (m_pos != it.m_pos);
    }
private:
    int m_pos;
    Neste &m_nes;
};
