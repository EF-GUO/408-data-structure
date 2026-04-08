#pragma once

#include "Stack.h"

template<typename T>
struct node
{
    T _data;
    node<T>* _next;
    node(const T& data,node<T>* next = nullptr):_data(data),_next(next){}
};


template<typename T>
class LiStack: public Stack<T>
{
    /*
    *   链栈
    *   头节点处入栈出栈
    */
private:
    node<T> * _head = nullptr;
    int _size = 0;
public:
    LiStack() = default;

    ~LiStack() override
    {
        clear();
    }
    
    bool push(const T& x) override;
    bool pop(T& x) override;
    int size() const override;
    bool empty() const override;
    bool top(T& x)const override;
    void clear() override;
};

template <typename T>
inline bool LiStack<T>::push(const T &x)
{
    node<T>* newNode = new node<T>(x,_head);
    _head = newNode;
    ++_size;
    return true;
}

template <typename T>
inline bool LiStack<T>::pop(T &x)
{
    if(empty()) 
        return false;
    x = _head->_data;
    node<T>* popNode = _head;
    _head = _head->_next;
    delete popNode;
    --_size;
    return true;
}

template <typename T>
inline int LiStack<T>::size() const
{
    // int count = 0;
    // node<T> * theNode = _head;
    // while(theNode)
    // {
    //     ++count;
    //     theNode = theNode->_next;
    // }
    // return count;

    return _size;
}

template <typename T>
inline bool LiStack<T>::empty() const
{
    return _head == nullptr;
}

template <typename T>
inline bool LiStack<T>::top(T &x) const
{
    if(empty()) return false;
    x = _head->_data;
    return true;
}

template <typename T>
inline void LiStack<T>::clear()
{
    node<T> * nextNode = nullptr;
    while(_head)
    {
        nextNode = _head->_next;
        delete _head;
        _head = nextNode;
    }
    _size = 0;
}
