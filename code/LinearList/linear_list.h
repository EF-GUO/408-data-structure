#pragma once


//  线性表抽象数据类型 ADT
//
template<typename T>
class LinearList
{
public:
    virtual ~LinearList() {};
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& get(int the_index) const = 0;
    

};


