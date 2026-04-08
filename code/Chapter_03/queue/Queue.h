#pragma once


template <typename T>
class Queue
{
public:
    //ADT method
    virtual ~Queue() = default;

    virtual bool empty() const = 0;             //判空
    virtual bool enqueue(const T& x) = 0;       //入队
    virtual bool dequeue(T& x) = 0;             //出队
    virtual bool get_front(T& x) const = 0;     // 取队头

    virtual int size() const = 0;
    virtual void clear() = 0;
    
};
