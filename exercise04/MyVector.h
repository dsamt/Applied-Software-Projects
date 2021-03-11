// Starter code for Exercise-04 
// (You should not need to change this file)
#ifndef MYVECTOR_H
#define MYVECTOR_H

template <class T>
class MyVector {
public:
    MyVector();
    MyVector(const MyVector<T>& obj);
    ~MyVector();

    MyVector<T>& operator=(const MyVector<T>& obj);
    int size();
    bool empty();
    void push_back(const T& value);
    T& at(int i);

private:
    T * m_data;
    int m_capacity;
    int m_size;
};

#include "MyVector.tpp"
#endif
