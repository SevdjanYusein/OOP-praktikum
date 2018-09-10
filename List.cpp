#pragma once
template <typename T>
class Element
{
public:
	T information;
	Element<T>* next;
	Element<T>(T _information, Element<T>* _next = nullptr)
	{
		information = _information;
		next = _next;
	}
};

template <typename T>
class List
{
private:
	Element<T>* first;
	Element<T>* last;
	int count;
	void copy(const List& other);
	void erase();
public:
	List();
	List(const List& other);
	List& operator= (const List& other);
	~List();

	void pushBack(const T& inf);
	void pushFront(T inf);
	void pushAfter(int pos, const T& inf);
	void popBack();
	void popFront();
	void removeAt(T inf);
	T& getFromPos(int index);
	T& operator[] (int pos);
	bool member(const T& other);

	void sort();

	int getCount()const;
};

template<typename T>
void List<T>::copy(const List & other)
{
	Element<T>* crr = other.first;
	while (crr != nullptr)
	{
		pushBack(crr->information);
		crr = crr->next;
	}
}

template<typename T>
void List<T>::erase()
{
	Element<T>* crr;
	while (first != nullptr)
	{
		crr = first;
		first = first->next;
		delete crr;
	}
	first = last = nullptr;
	count = 0;
}

template<typename T>
List<T>::List()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

template<typename T>
List<T>::List(const List & other)
{
	copy(other);
}

template<typename T>
List<T> & List<T>::operator=(const List & other)
{
	if (first == other.first) return *this;
	erase();
	copy(other);
	return *this;
}

template<typename T>
List<T>::~List()
{
	erase();
}

template<typename T>
void List<T>::pushBack(const T& inf)
{
	Element<T>* newElem = new Element<T>(inf);
	if (count == 0)
	{
		first = last = newElem;
	}
	else
	{
		last->next = newElem;
		last = newElem;
	}
	count++;
}

template<typename T>
void List<T>::pushFront(T inf)
{
	Element<T>* newElem = new Element<T>(T, nullptr);
	if (count == 0)
	{
		first = last = newElem;
	}
	else
	{
		Element<T>* temp = first;
		first = newElem;
		first->next = temp;
	}
	count++;
}

template<typename T>
void List<T>::pushAfter(int pos, const T& inf)
{
	if (pos == count)
	{
		pushBack(inf);
		return;
	}
	Element<T>* newElem = new Element<T>(inf, nullptr);
	Eelement<T>* crr = first;
	for (int i = 0; i < pos - 1; i++)
	{
		crr = crr->next;
	}
	newElem.next = crr->next;
	crr->next = newElem;
	count++;
}

template<typename T>
void List<T>::popBack()
{
	if (count == 0) return;
	Element<T>* crr = first;
	for (int i = 0; i < size - 1; i++)
	{
		crr = crr->next;
	}
	crr->next = nullptr;
	delete last;
	last = crr;
	count--;
	if (count == 0) first = last = nullptr;
}

template<typename T>
void List<T>::popFront()
{
	if (count == 0) return;
	Element<T>* temp = first->next;
	delete first;
	first = temp;
	count--;
	if (count == 0) first = last = nullptr;
}

template<typename T>
void List<T>::removeAt(T inf)
{
	Element<T>* crr = first;
	for (int i = 0; i < count - 1; i++)
	{
		if (crr->information == inf)
		{
			Element<T>* temp = crr->next;
			crr->next = nullptr;
			crr = temp;
			delete temp;
			break;
		}
		crr = crr->next;
	}
}

template<typename T>
T& List<T>::getFromPos(int index)
{
	if (index <= count - 1)
	{
		Element<T>* crr = first;
		for (int i = 0; i < count - 1; i++)
		{
			crr = crr->next;
		}
		return crr->information;
	}
	return last->information;
}

template<typename T>
T & List<T>::operator[](int pos)
{
	return getFromPos(pos);
}

template<typename T>
bool List<T>::member(const T & other)
{
	Element<T>* crr = first;
	for (int i = 0; i < count; i++)
	{
		if (other == crr->information) return true;
	}
	return false;
}

template<typename T>
void List<T>::sort()
{
	bool flag = true;
	for (int i = 0; i < count - 2 && flag; ++i)
	{
		flag = false;
		Element<T>* before = first;
		Element<T>* crr = first;
		Element<T>* temp = crr->next;
		for (int j = 1; j < count - 1 - i; j++)
		{
			if (crr->information > temp->information)
			{
				crr->next = temp->next;
				temp->next = crr;
				before->next = temp;
				flag = true;
			}
			before = before->next;
			crr = crr->next;
			temp = temp->next;
		}
	}
}

template<typename T>
int List<T>::getCount() const
{
	return count;
}
