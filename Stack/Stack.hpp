#include <iostream>
using namespace std;

template<class T>
class Stack
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

	node *top;
	int size;

	void copy(const Stack& o);
	void clean();
public:
	Stack();
	Stack(const Stack& o);
	Stack& operator=(const Stack& o);
	~Stack();

	bool isEmpty()const;

	void push(T data);
	void pop();

	const T& peek()const;

	void print()const;

	int getSize()const;
};
template<class T>
void Stack<T>::copy(const Stack& o)
{
	if (o.isEmpty())
		return;
	top = new node(o.top->data,o.top->next);
	node *copy = o.top;
	node *copier = top;
	while (copy->next!= nullptr)
	{
		copy = copy->next;
		copier->next= new node(copy->data);
		copier = copier->next;
		
	}
	size = o.size;
}
template<class T>
void Stack<T>::clean()
{
	node *destroy;
	while (top!= nullptr)
	{
		destroy = top;
		top = top->next;
		delete destroy;
	}
}
template<class T>
Stack<T>::Stack() :top(nullptr), size(0)
{

}
template<class T>
Stack<T>::Stack(const Stack& o) :top(nullptr)
{
	copy(o);
}
template<class T>
Stack<T>& Stack<T>::operator=(const Stack& o)
{
	if (this != &other)
	{
		clean();
		copy(o);
	}
	return *this;
}
template<class T>
Stack<T>::~Stack()
{
	clean();
}
template<class T>
bool Stack<T>::isEmpty()const
{
	return size == 0;
}
template<class T>
void Stack<T>::push(T data)
{
	if (isEmpty())
	{
		top = new node(data);
	}
	else
	{

		node *push = new node(data);
		push->next = top;
		top = push;
	}
	size++;
}
template<class T>
void Stack<T>::pop()
{
	if (isEmpty())
		throw "Is empty";

	node *destroy = top;
	top = top->next;
	delete destroy;
	size--;
}
template<class T>
const T& Stack<T>::peek()const
{
	return top->data;
}
template<class T>
void Stack<T>::print()const
{
	node *print = top;
	while (print != nullptr)
	{
		cout << print->data << " ";
		print = print->next;
	}
	cout << endl;
}
template<class T>
int Stack<T>::getSize()const
{
	return size;
}
