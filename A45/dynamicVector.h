#pragma once
#include "Event.h"

template <typename T>
class DynamicVector {
private:
	int capacity;
	int size;
	T* data;

public:
	DynamicVector(int capacity = 10);
	DynamicVector(const DynamicVector&);
	~DynamicVector();
	int getSize() const;
	int getCapacity() const;
	T* getAll() const;
	T getItem(const int index) const;
	void addItem(const T& item);
	void removeItem(const int index);
	void updateItem(const T&, const int index);
	DynamicVector& operator = (const DynamicVector&);

private:
	void resize();
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->data = new T[capacity];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->data;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}

template <typename T>
int DynamicVector<T>::getCapacity() const
{
	return this->capacity;
}

template <typename T>
T* DynamicVector<T>::getAll() const
{
	return this->data;
}

template <typename T>
T DynamicVector<T>::getItem(const int index) const
{
	return this->data[index];
}

template <typename T>
void DynamicVector<T>::addItem(const T& item)
{
	if (this->size == this->capacity)
	{
		this->resize();
	}

	this->data[this->size] = item;
	this->size++;
}

template <typename T>
void DynamicVector<T>::removeItem(const int index)
{
	for (int i = index; i < this->size - 1; i++)
		this->data[i] = this->data[i + 1];

	this->size--;
}

template <typename T>
void DynamicVector<T>::resize()
{
	T* new_data = new T[this->capacity * 2];

	for (int i = 0; i < this->size; i++)
		new_data[i] = this->data[i];

	delete[] this->data;
	this->data = new_data;
	this->capacity *= 2;
}

template <typename T>
void DynamicVector<T>::updateItem(const T& item, const int index)
{
	this->data[index] = item;
}

