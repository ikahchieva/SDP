#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
class List
{
	struct node
	{
		T data;
		node *next;

		node(T data, node* n = nullptr)
		{
			this->data = data;
			this->next = n;
		}
	};

	node *front;
	node *back;
	int size;

	void copy(const List& o);
	void clean();

public:
	List();
	List(const List& o);
	List& operator = (const List& o);
	~List();

	void pushBack(T data);
	void pushFront(T data);
	
	void popBack();
	void popFront();

	const T& topBack()const;
	const T& topFront()const;


	void print()const;

	bool search(T data)const;
	bool isEmpty()const;
};

template<class T>
bool List<T>::isEmpty()const
{
	return size == 0;
}
template<class T>
void List<T>::copy(const List& o)
{
	if (o.isEmpty())
		return;

	front = new node(o.front);
	node *copy = o.front;
	node *copier = front;

	while (copy->next != nullptr)
	{
		copy = copy->next;
		copier->next = new node(copy->data);
		copier = copier->next;
	}

	back = copier;
}
template<class T>
void List<T>::clean()
{
	node *del;
	
	while(front != nullptr)
	{
		del = front;
		front = front->next;
		delete del;
	}
	front = nullptr;
	back = nullptr;
	size = 0;
}

template<class T>
List<T>::List() :front(nullptr), back(nullptr), size(0)
{

}
template<class T>
List<T>::List(const List& o) : front(nullptr), back(nullptr), size(o.size)
{
	copy(o);
}
template<class T>
List<T>& List<T>::operator = (const List& o)
{
	if (this != &other)
	{
		clean();
		copy(o);
	}
	return *this;
}
template<class T>
List<T>::~List()
{
	clean();
}
template<class T>
void List<T>::pushBack(T data)
{
	if (isEmpty())
	{
		front = new node(data);
		back = front;
	}
	else
	{
		back->next = new node(data);
		back = back->next;
	}
	size++;
}
template<class T>
void List<T>::pushFront(T data)
{
	if (isEmpty())
	{
		front = new node(data);
		back = front;
	}
	else
	{
		node *p = new node(data);
		p->next = front;
		front = p;
	}
	size++;
}
template<class T>
void List<T>::popBack()
{
		if (isEmpty())
			throw "IsEMpty";

		if (size == 1)
		{
			delete front;
			front = nullptr;
			back = nullptr;
		}
		else
		{
			node *pop = front;
			while (pop->next != back)
			{
				pop = pop->next;
			}
			delete back;
			back = pop;
			back->next = nullptr;
		}
		size--;

}
template<class T>
void List<T>::popFront()
{
	if (isEmpty())
		throw "Is empty";
	if (size == 1)
	{
		delete front;
		front = nullptr;
		back = nullptr;
	}
	else
	{
		node *pop = front;
		front = front->next;
		delete pop;
	}
	size--;
}
template<class T>
const T& List<T>::topBack()const
{
	return back;
}
template<class T>
const T& List<T>::topFront()const
{
	return front;
}
template<class T>
void List<T>::print()const
{
	node *print = front;
	while (print != nullptr)
	{
		cout << print->data << " ";
		print = print->next;
	}
	cout << endl;
}
template<class T>
bool List<T>::search(T data)const
{
	node *s = front;
	while (s != nullptr)
	{
		if (s->data == data)
			return true;
		s = s->next;
	}
	return false;
}
