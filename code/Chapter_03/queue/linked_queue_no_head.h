#pragma once

#include "Queue.h"


template<typename T>
struct Node
{
	T _data;
	Node* _next;

	Node(const T& t, Node<T>* next = nullptr)
	{
		_data = t;
		_next = next;
	}
};


template<typename T>
class LinkQueue : public Queue<T>
{
private:
	Node<T>* _front;       //指向队头节点
	Node<T>* _rear;        //指向队尾节点
	int _size = 0;		   //队列元素个数

public:
	LinkQueue();
	~LinkQueue() override;
	bool empty() const override;
	bool enqueue(const T& x) override;
	bool dequeue(T& x) override;
	void clear() override;
	bool get_front(T& x) const override;
	int size() const override;

};

template <typename T>
inline LinkQueue<T>::LinkQueue()
{
	//不带头节点
	_front = _rear = nullptr;
}

template<typename T>
inline LinkQueue<T>::~LinkQueue()
{
	clear();
}

template <typename T>
inline bool LinkQueue<T>::empty() const
{
	//不带头节点
	return _front == nullptr;
}

template <typename T>
inline bool LinkQueue<T>::enqueue(const T& x)
{

	Node<T>* node = new Node<T>(x);

	//不带头节点
	if (_front == nullptr) //队列为空
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
inline bool LinkQueue<T>::dequeue(T& x)
{
	//不带头节点
	if (empty()) return false;

	Node<T>* popNode = _front;
	x = popNode->_data;
	_front = _front->_next;

	if (!_front)//如果出队后队列变空了
		_rear = nullptr;

	delete popNode;
	--_size;
	return true;

}

template <typename T>
inline void LinkQueue<T>::clear()
{
	//不带头节点
	while (_front)
	{
		Node<T>* popNode = _front;
		_front = _front->_next;
		delete popNode;
	}

	//恢复队列状态
	_front = _rear = nullptr;
	_size = 0;
}

template<typename T>
bool LinkQueue<T>::get_front(T& x) const
{
	if (empty()) return false;

	x = _front->_data;
	return true;
}

template<typename T>
int LinkQueue<T>::size() const
{
	//1.
	//return _size;

	//2.
	Node<T>* currentNode = _front;

	int count = 0;
	while (currentNode)
	{
		++count;
		currentNode = currentNode->_next;
	}
	return count;
}