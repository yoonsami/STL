#pragma once


template <typename T>
class MyIterator
{
public:
	MyIterator() : _PTR(nullptr) {}
	MyIterator(T* ptr) : _PTR(ptr) {}
	MyIterator& operator++() { ++_PTR; return *this; }
	MyIterator operator++(int a) { MyIterator tmp = *this; ++_PTR; return tmp; }
	bool operator==(const MyIterator<T>& rhs) { return _PTR == rhs._PTR; }
	bool operator!=(const MyIterator<T>& rhs) { return _PTR != rhs._PTR; }

	T& operator*() { return *_PTR; }

public:
	T* _PTR;
};


template <typename T>
class MyVector
{
public:
	MyVector();
	MyVector(size_t newSize);
	MyVector(size_t newSize, T Index);
	~MyVector()
	{
		if (m_index)
			delete[] m_index;
	}

public:


	void Push_back(const T& newIndex)
	{

		if (_Capacity == 0)
		{
			++_Capacity;
			m_index = new T[_Capacity];
			m_index[0] = newIndex;
			++_Size;
		}
		else
		{
			if (_Size == _Capacity)
			{

				T* tmp;

				if (_Capacity == 1)
					++_Capacity;
				else if (_Capacity >= 2)
					_Capacity = static_cast<size_t>(_Capacity * 1.5);

				tmp = new T[_Capacity];
				for (size_t i = 0; i < _Size; ++i)
					tmp[i] = m_index[i];

				delete[] m_index;
				m_index = tmp;
				m_index[_Size] = newIndex;
				++_Size;
			}
			else if (_Size < _Capacity)
				m_index[_Size++] = newIndex;
		}

	}
	size_t Capacity() { return _Capacity; }
	size_t Size() { return _Size; }
	T& operator[](const int pos) { return m_index[pos]; }
	typedef MyIterator<T> Iterator;

	Iterator Begin() { return &m_index[0]; }
	Iterator End() { return &m_index[_Size]; }

private:
	size_t _Capacity;
	size_t _Size;
	T* m_index;

};

template<typename T>
inline MyVector<T>::MyVector() :_Capacity(0), _Size(0), m_index(nullptr)
{

}

template<typename T>
inline MyVector<T>::MyVector(size_t Size) :_Capacity(Size), _Size(Size), m_index(nullptr)
{
	m_index = new T[_Capacity];

}

template<typename T>
inline MyVector<T>::MyVector(size_t Size, T Index) :_Capacity(Size), _Size(Size), m_index(nullptr)
{
	m_index = new T[_Capacity];
	for (int i = 0; i < _Capacity; ++i)
	{
		m_index[i] = Index;
	}
}
