#pragma once
#include <iostream>

template<typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	void addToBack(const T newElem);
	void removeFromBack();

	void addToStart(const T newElem);
	void removeFromStart();

	void removeAt(const size_t index);

	//void removeAll();

	size_t getSize() const;

	T operator[](const size_t index) const;
	Vector<T> operator+(const Vector& other);
	Vector<T>& operator+=(const Vector& other);

	friend std::ostream& operator<<(std::ostream& out, const Vector<T>& vec) // ??? Glupoooost
	{
		for (size_t i = 0; i < vec.getSize(); i++)
		{
			out << vector[i] << std::endl;
		}
		return out;
	}

	void printVector() const;
private:
	T* vector;
	size_t size;
	size_t capacity;

	void copy(const Vector& other);
	void resize();
	void swap(T& a, T& b);
};

template<typename T>
inline Vector<T>::Vector()
{
	size = 0;
	capacity = 5;
	vector = new T[capacity];
}

template<typename T>
inline Vector<T>::Vector(const Vector& other)
{
	this->copy(other);
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector& other)
{
	if (this != &other)
	{
		delete[] vector;
		this.copy(other);
	}
	return *this;
}

template<typename T>
inline Vector<T>::~Vector()
{
	delete[] vector;
}

template<typename T>
inline void Vector<T>::addToBack(const T newElem)
{
	if (size >= capacity)
	{
		resize();
	}
	vector[size++] = newElem;
}

template<typename T>
inline void Vector<T>::removeFromBack()
{
	if (size > 0)
	{
		size--;
	}
}

template<typename T>
inline void Vector<T>::addToStart(const T newElem)
{
	if (size >= capacity) {
		resize();
	}

	for (size_t i = 0; i < size; i++)
	{
		swap(vector[i], vector[size]);
	}
	vector[0] = newElem;
	size++;
}

template<typename T>
inline void Vector<T>::removeFromStart()
{
	if (size <= 0)
	{
		std::cout << "No elements left!\n";
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		swap(vector[i], vector[i + 1]);
	}
	size--;
}

template<typename T>
inline void Vector<T>::removeAt(const size_t index)
{
	if (index <= 0) {
		std::cout << "No elements left!\n";
		return;
	}
	if (index >= size)
	{
		std::cout << "Too big index!\n";
	}
	for (size_t i = index; i < size; i++)
	{
		swap(vector[i], vector[i + 1]);
	}
	size--;
}

//template<typename T>
//inline void Vector<T>::removeAll()
//{
//	delete[] vector;
//	size = 0;
//	capacity = 5;
//	vector = new T[capacity];
//}

template<typename T>
inline size_t Vector<T>::getSize() const
{
	return size;
}

template<typename T>
inline T Vector<T>::operator[](const size_t index) const
{
	if (index >= size)
	{
		std::cout << "Index is too big!\n";
		return 0;
		//throw _exception; //exception
	}
	return vector[index];
}

template<typename T>
inline Vector<T> Vector<T>::operator+(const Vector& other)
{
	Vector temp;
	temp.size = this->size + other.size;
	temp.capacity = this->capacity + other.capacity;
	temp.vector = new T[capacity];

	for (size_t i = 0; i < this->size; i++)
	{
		temp.vector[i] = this->vector[i];
	}
	for (size_t i = this->size; i < temp.size; i++)
	{
		temp.vector[i] = other.vector[i];
	}
	return temp;
}

template<typename T>
inline Vector<T>& Vector<T>::operator+=(const Vector& other)
{
	*this = *this + other;
	return *this;
}

template<typename T>
inline void Vector<T>::printVector() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << vector[i] << ' ';
	}
	std::cout << std::endl;
}

template<typename T>
inline void Vector<T>::copy(const Vector& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->vector = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		vector[i] = other.vector[i];
	}
}

template<typename T>
inline void Vector<T>::resize()
{
	capacity *= 2;
	T* biggerVector = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		biggerVector[i] = vector[i];
	}
	delete[] vector;
	vector = biggerVector;
}

template<typename T>
inline void Vector<T>::swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}