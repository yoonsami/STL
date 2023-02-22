#pragma once

template <typename T>
class Node
{
public:
	Node() : _prev(nullptr), _next(nullptr), data(T())
	{}
	Node(const T& value) : _prev(nullptr), _next(nullptr), data(value)
	{}
public:
	Node* _prev;
	Node* _next;
	T data;
};

template <typename T>
class MyIterator
{
public:
	MyIterator() : _node(nullptr) {	}
	MyIterator(Node<T>* node) : _node(node) {}
	MyIterator(const MyIterator& rhs) { _node = rhs._node; }
public:
	bool operator==(const MyIterator& rhs) { return _node == rhs._node; }
	bool operator!=(const MyIterator& rhs) { return !(_node == rhs._node); }
	MyIterator& operator++() { _node = _node->_next; return *this; }
	MyIterator operator++(int) { MyIterator<T> tmp(_node);  _node = _node->_next; return tmp; }
	MyIterator& operator--() { _node = _node->_prev; return *this; }
	MyIterator operator--(int) { MyIterator<T> tmp(_node);  _node = _node->_prev; return tmp; }
	T& operator*() { return _node->data; }

public:
	Node<T>* _node;
};

template <typename T>
class MyList
{
public:
	MyList()
	{
		_header = new Node<T>;
		_header->_next = _header;
		_header->_prev = _header;
		_size = 0;
	}
	~MyList()
	{
		while (_size > 0)
		{
			Pop_back();
		}
	}
	// [1] [2] [beforeNode] [header]
	// [1] [2] [beforeNode] [newNode] [header] <-> [1]

	Node<T>* Delete(Node<T>* targetNode)
	{
		Node<T>* beforeNode = targetNode->_prev;
		Node<T>* nextNode = targetNode->_next;

		beforeNode->_next = nextNode;
		nextNode->_prev = beforeNode;
		--_size;
		delete targetNode;
		return nextNode;
	}

	Node<T>* Add(Node<T>* beforeNode, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* nextNode = beforeNode->_next;

		beforeNode->_next = newNode;
		newNode->_prev = beforeNode;

		nextNode->_prev = newNode;
		newNode->_next = nextNode;
		++_size;
		return newNode;
	}

	void Push_back(const T& value)
	{
		Add(_header->_prev, value);
	}

	void Pop_back()
	{
		Delete(_header->_prev);
	}

	typedef MyIterator<T> Iterator;

	Iterator Begin()
	{
		
		return Iterator(_header->_next);
	}

	Iterator End()
	{
		return  Iterator(_header);
	}
	size_t Size() { return _size; }

	Iterator Insert(Iterator it, const T& value)
	{
		return Iterator( Add(it._node, value));

	}
	Iterator erase(Iterator it)
	{
		return Iterator(Delete(it._node));
	}
private:
	Node<T>* _header;
	size_t _size;
};