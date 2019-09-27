#include "MyVector.h"

MyVector::MyVector()
{
}

MyVector::MyVector(int n)
{
	size = n;
	ar = new int[size];
	for (int i = 0; i < size; i++)
	{
		ar[i] = 0;
	}
}

MyVector::MyVector(int n, int value)
{
	size = n;
	ar = new int[size];
	for (int i = 0; i < size; i++)
	{
		ar[i] = value;
	}
}

MyVector::MyVector(const MyVector & vec)
{
	size = vec.size;
	int* tmp = new int[size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = vec.ar[i];
	}
	this->ar = tmp;
}

int MyVector::getCapacity() const
{
	return capacity;
}

void MyVector::addCapacity(int n)
{
	capacity = capacity + n;
	int* tmp = new int[capacity];
	for (int i = 0; i < size; i++)
		tmp[i] = ar[i];
	for (int i = size + 1; i < capacity; i++)
		tmp[i] = 0;
	ar = tmp;
}

void MyVector::pushBack(int val)
{
	size = getSize();
	if (size < capacity)
		ar[size++] = val;
	else
	{
		capacity = getCapacity()+1;
		ar[size++] = val;
	}
}

int MyVector::popBack()
{
	size--;
	return ar[size];
}

void MyVector::insert(int index, int val)
{
	if (index > capacity)
		addCapacity(index - capacity);
	if (index < size)
	{
		for (int i = size - 1; i >= index; i--)
		{
			ar[i + 1] = ar[i];
		}
	}
	ar[index] = val;
	size++;
}

int MyVector::remove(int index)
{
	int ptr = ar[index];
	for (int i = index; i < size; i++)
	{
		ar[i] = ar[i + 1];
	}
	size--;
	return ptr;
}

MyVector & MyVector::operator=(const MyVector & vec)
{
	if (this == &vec)
		return *this;
	delete[]this->ar;
	size = vec.size;
	capacity = vec.capacity;
	ar = new int[capacity];
	for (int i = 0; i < vec.size; i++)
		ar[i] = vec.ar[i];
	return *this;
}
