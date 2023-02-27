#pragma once

template <typename T>
class MyNode
{
public:
	MyNode() : data(T()), _next(nullptr), _prev(nullptr)
	{

	}
	MyNode(const T& value) : data(value), _next(nullptr), _prev(nullptr)
	{

	}
public:
	MyNode* _next;
	MyNode* _prev;
	T data;
};



template <typename T>
class MyQueue
{
public:
	MyQueue() : _size(0), _head(nullptr),_tail(nullptr),_rear(nullptr)
	{
		_head = new MyNode<T>;
		_tail = new MyNode<T>;

		_head->_next = _tail;
		_head->_prev = _head;

		_tail->_next = _tail;
		_tail->_prev = _head;
	}
	
	void push(const T& value)
	{
		MyNode<T>* newNode = new MyNode<T>(value);

		MyNode<T>* prevRear = _tail->_prev;

		prevRear->_next = newNode;
		newNode->_prev = prevRear;

		_tail->_prev = newNode;
		newNode->_next = _tail;
		++_size;
	}

	T pop()
	{
		MyNode<T>* _front = _head->_next;
		MyNode<T>* _nextNode = _front->_next;

		_head->_next = _nextNode;
		_nextNode->_prev = _head;

		T tmp = _front->data;
		delete _front;

		--_size;
		return tmp;
	}

	size_t size() { return _size; }
	bool empty() { return _size == 0; }

	T front()
	{
		MyNode<T>* _front = _head->_next;
		return _front->data;
	}
	T back()
	{
		MyNode<T>* _back = _tail->_prev;
		return _back->data;
	}

public:
	MyNode<T>* _head;
	MyNode<T>* _tail;
	MyNode<T>* _rear;
	size_t _size;
};

