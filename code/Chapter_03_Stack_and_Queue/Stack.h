#pragma once


template <typename T>
class Stack
{
//ADT
public:
    virtual ~Stack() {}
    virtual bool push(const T& x) = 0;
    virtual bool pop(T& x) = 0;
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual bool top(T& x)const = 0;
    virtual void clear() = 0;
};