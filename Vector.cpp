#pragma once
#include <iostream>

template <class T>
class Vector
{
private:
	T * start;
	int currentCount;
	int capasity;

	void resize()
	{
		capasity *= 2;
		int *old = start;
		start = new T[capasity];
		for (int i = 0; i < currentCount; i++)
		{
			*(start + i) = *(old + i);
		}
		delete[] old;
	}
	void copy(const Vector& other)
	{
		capasity = other.capasity;
		currentCount = other.currentCount;
		start = new T[capasity];
		for (int i = 0; i < currentCount; i++)
		{
			*(start + i) = *(other.start + i);
		}

	}
	void erase()
	{
		delete[] start;
		currentCount = 0;
		capasity = 0;
	}
public:
	Vector()
	{
		capasity = 4;
		start = new T[capasity];
		currentCount = 0;
	}
	Vector(const Vector& other)
	{
		copy(other);
	}
	Vector& operator= (const Vector& other)
	{
		if (start != other.start)
		{
			erase();
			copy(other);
		}
		return *this;
	}
	bool operator==(const Vector<T>& elements)const
	{
		if (getCurrentCount() != elements.getCurrentCount()) return false;
		for (int i = 0; i < currentCount; i++)
		{
			if (!contains(elements[i])) return false;
		}
		return true;
	}
	void operator+ (T element)
	{
		pushBack(element);
	}
	void operator- (T element)
	{
		pop(element);
	}
	void pushBack(T element)
	{
		if (currentCount == capasity - 1)
		{
			resize();
		}
		start[currentCount] = element;
		currentCount++;
	}
	bool contains(T element)const
	{
		for (int i = 0; i < currentCount; i++)
		{
			if (*(start + i) == element) return true;
		}
		return false;
	}
	T get(int index)
	{
		if (index < capasity) return *(start + index);
	}
	void insertAtPos(int index, T element)
	{
		if (currentCount == capasity) resize();
		T temp;
		for (int i = currentCount - 1; i >= index; i--)
		{
			*(start + i + 1) = *(start + i);
		}
		*(start + index) = element;
		currentCount++;
	}
	bool remove(T element)
	{
		if (contains(element))
		{
			for (int i = 0; i < currentCount; i++)
			{
				if (*(start + i) == element)
				{
					for (int j = i; j < currentCount; j++)
					{
						*(start + j) = *(start + j + 1);
					}
					currentCount--;
				}
			}
			return true;
		}
		else return false;
	}
	void pop(int index)
	{
		for (int i = index; i < currentCount - 1; i++)
		{
			start[i] = start[i + 1];
		}
		currentCount--;
	}
	T& operator[] (int index)const
	{
		return start[index];
	}
	/*bool operator< (T element)
	{
		if (currentCount < element.currentcount) return true;
		return false;
	}*/
	void print() { for (int i = 0; i < currentCount; ++i) std::cout << start[i] << " "; }
	int getCurrentCount()const { return currentCount; }
	~Vector()
	{
		delete[] start;
	}
};
