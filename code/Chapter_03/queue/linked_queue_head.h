#pragma once
#include "Queue.h"

template<typename T>
struct Node
{
	T _data;
	Node<T>* _next;
	Node(const T& t, Node<T>* next = nullptr)
		:_data(t), _next(next){}
};

/*
* 带头节点的链式循环队列
*/
template<typename T>
class LinkQueue : public Queue<T>
{
private:
	Node<T>* _front;       //指向队头节点
	Node<T>* _rear;        //指向队尾节点
	int _size = 0;		   //队列元素个数
public:
	LinkQueue();
	~LinkQueue() override {
		clear();
		delete _front;
		_front = _rear = nullptr;
	};
	bool empty() const override;
	bool enqueue(const T& x) override;
	bool dequeue(T& x) override;
	bool get_front(T& x) const override;
	int size() const override;
	void clear() override;
};

template <typename T>
LinkQueue<T>::LinkQueue()
{
	_rear = _front = new Node<T>(T(),nullptr);
}

template <typename T>
bool LinkQueue<T>::empty() const
{
	return _front == _rear;
}

template <typename T>
bool LinkQueue<T>::enqueue(const T& x)
{
	Node<T>* newNode = new Node<T>(x);
	_rear->_next = newNode;
	_rear = newNode;
	++_size;
	return true;
}

template <typename T>
bool LinkQueue<T>::dequeue(T& x)
{
	if (empty()) return false;
	x = _front->_next->_data;
	Node<T>* popNode = _front->_next;
	_front->_next = popNode->_next;
	if (popNode == _rear)
		_rear = _front;
	delete popNode;
	--_size;
	return true;
}

template<typename T>
bool LinkQueue<T>::get_front(T& x) const
{
	if (empty()) return false;
	x = _front->_next->_data;
	return true;
}

template<typename T>
int LinkQueue<T>::size() const
{
	return _size;
	
	////方式2
	//Node<T>* cur = _front;
	//int count = 0;
	//while (cur != _rear)
	//{
	//	++count;
	//	cur = cur->_next;
	//}
	//return count;
}

template<typename T>
void LinkQueue<T>::clear()
{
	Node<T>* cur = _front->_next;
	Node<T>* popNode = nullptr;
	while (cur)
	{
		popNode = cur;
		cur = cur->_next;
		delete popNode;
	}
	_rear = _front;
	_front->_next = nullptr;
	_size = 0;
}
