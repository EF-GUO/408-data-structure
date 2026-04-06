#include "Stack.h"

template<typename T>
class SqStack : public Stack<T>
{
    static constexpr int MAXSIZE = 1000;
private:
    T _data[MAXSIZE];
    int _top = -1;  //① top = -1; ② top = 0;

public:
    SqStack() = default;
    ~SqStack() override = default;

    bool push(const T& x) override;
    bool pop(T& x) override;
    int size() const override;
    bool empty() const override;
    bool top(T& x) const override;
    void clear() override;
};

template<typename T>
bool SqStack<T>::push(const T& x)
{
    /*
    *   栈溢出检查
    *   ① _top == MAXSIZE - 1    (_top初始为-1)
    *   ② _top == MAXSIZE        (_top初始为0)
    */
    if(_top == MAXSIZE - 1) return false;
    
    /*
    *   入栈时改变指针
    *   ① _data[++_top] = x; (_top初始为-1)
    *   ② _data[_top++] = x; (_top初始为0)
    */
    _data[++_top] = x;
    return true;
}


template<typename T>
bool SqStack<T>::pop(T& x) 
{
    //下溢检查
    if(_top == -1) return false;

    /*
    *   出栈时改变指针
    *   ① x = _data[_top--] (_top初始为-1)
    *   ② x = _data[--_top] (_top初始为0)
    */
    x = _data[_top--];
    return true;
}

template<typename T>
int SqStack<T>::size() const 
{
    /*
    *   ① size = _top + 1; (_top初始为-1)
    *   ② size = _top;     (_top初始为0)  
    */
    return _top + 1;
}

template<typename T>
bool SqStack<T>::empty() const 
{
    /*
    *   ①: _top == -1    (_top初始为-1)
    *   ②: _top == 0         (_top初始为0)
    */
    if(_top == -1)  
        return true;
    return false;
}

template<typename T>
bool SqStack<T>::top(T& x) const 
{
    if(_top == -1) return false;
    /*
    *   ①:  x = _data[_top];        (_top初始为-1)
    *   ②:  x = _data[_top - 1];    (_top初始为0)
    */
    x = _data[_top];    
    return true;
}

template<typename T>
void SqStack<T>::clear() 
{
    _top = -1;
}
