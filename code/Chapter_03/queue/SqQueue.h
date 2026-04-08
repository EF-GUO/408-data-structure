#pragma once

#include "Queue.h"

template<typename T>
class SqQueue : public Queue<T>
{
   
    /*
    *   循环队列的顺序存储实现
    */

    static constexpr int MAXSIZE = 1000;
private:
    T _data[MAXSIZE];
    int _front = 0;
    int _rear = 0;
public:
    ~SqQueue(){};
    bool empty() const override;
    bool enqueue(const T& x) override;
    bool dequeue(T& x) override;
    bool get_front(T& x) const override;

    int size() const override;
    void clear() override;

};

template <typename T>
inline bool SqQueue<T>::empty() const
{
    /*
    * 顺序存储循环队列判空  front == rear
    *   true:   队列为空
    *   false:  队列不为空         
    */
    return _rear == _front;
}

template <typename T>
inline bool SqQueue<T>::enqueue(const T &x)
{
    /*
    * 入队操作
    *
    *  1.判断队列是否满了
    *   (rear + 1) % MAXSIZE == front
    *
    *  2.入队操作
    *   queue[rear] = newElement
    * 
    *  3.更新指针
    *   rear = (rear + 1) % MAXSIZE
    */

    if((_rear + 1) % MAXSIZE == _front)
        return false;
    _data[_rear] = x;
    _rear = (_rear + 1 ) % MAXSIZE;
    return true;
}

template <typename T>
inline bool SqQueue<T>::dequeue(T &x)
{
    /*
    * 出队操作
    * 1.空队列判断
    * 2.出队列
    * 3.更新指针
    */

    if(_rear == _front) return false;
    x = _data[_front];
    _front = (_front + 1) % MAXSIZE;
    return true;
}

template <typename T>
inline bool SqQueue<T>::get_front(T &x) const
{
    if(_rear == _front) return false;
    x = _data[_front];
    return true;
}

template <typename T>
inline int SqQueue<T>::size() const
{
    /*
    *   获取队列元素个数
    *   (rear - front + MAXSIZE) % MAXSIZE
    */
   return (_rear - _front + MAXSIZE) % MAXSIZE;
}

template <typename T>
inline void SqQueue<T>::clear()
{
    _front = _rear = 0;
}
