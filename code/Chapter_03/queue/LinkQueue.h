#pragma once

#include "Queue.h"


template<typename T>
struct Node
{
    T _data;
    Node *_next;

    Node(const T& t,Node<T> *next = nullptr)
    {
        _data = t;
        _next = next;
    }
};


template<typename T>
class LinkQueue : public Queue<T>
{
private:
    Node *_front;
    Node *_rear;
    int _size;

public:
    LinkQueue();
    ~LinkQueue() override;
    bool empry() const override;
    bool enqueue(const T& x) override;
    bool dequeue(T& x) override;
    void clear() override;

};

template <typename T>
inline LinkQueue<T>::LinkQueue()
{
    /*
    *   第一种  不带头节点
    *   front = rear = nullptr  
    * 
    *   第二种  带头节点
    *   
    */


    //不带头节点
    _front = _rear = nullptr;

    //带头节点

}

template<typename T>
inline LinkQueue<T>::~LinkQueue()
{

}

template <typename T>
inline bool LinkQueue<T>::empry() const
{
    //不带头节点
    return _front == nullptr;


}

template <typename T>
inline bool LinkQueue<T>::enqueue(const T &x)
{
    
    Node<T>* node = new Node<T>(x);
    
    //不带头节点
    if(_front == nullptr) //队列为空
            _front = _rear = node;
    else//队列非空
    {
        _rear->_next = node;
        _rear = node;
    }
    ++_size;
    return true;

    //带头节点



}

template<typename T>
inline bool LinkQueue<T>::dequeue(T & x)
{
 
}

template <typename T>
inline void LinkQueue<T>::clear()
{


}
