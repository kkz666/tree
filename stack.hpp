#ifndef __STACKTP_H__
#define __STACKTP_H__
#include<iostream>
using namespace std;
template<typename T>
class Stack
{
public:
	Stack();
	~Stack();
	bool IsFull();
	bool IsEmpty();
	bool Push(const T& x);
	T Pop();
	int Lenth();
	void Show();
	T gettop();
private:
	enum { MAX = 100 };//枚举类型是常数，类似#define MAX 100
	T item[MAX];
	int top;
};

template<typename T>
Stack<T>::Stack()
{
	top = 0;
}
template<typename T>
Stack<T>::~Stack()
{
	top = 0;
}
template<typename T>
bool Stack<T>::IsFull()
{
	return top == MAX;
}
template<typename T>
bool Stack<T>::IsEmpty()
{
	return top == 0;
}
template<typename T>
T Stack<T>::gettop() {
	return item[top];
}
template<typename T>
bool Stack<T>::Push(const T& x)
{
	if (IsFull())
	{
		std::cout << "the stack is full!" << std::endl;
		return false;
	}
	item[top++] = x;
	return true;
}
template<typename T>
T Stack<T>::Pop()
{
	T x;
	if (IsEmpty())
	{
		std::cout << "the stack is empty!" << std::endl;
		return 0;
	}
	x = item[--top];
	return x;
}
template<typename T>
int Stack<T>::Lenth()
{
	return top;
}
template<typename T>
void Stack<T>::Show()
{
	for (int i = 0; i < top; ++i)
	{
		std::cout << item[i] << " ";
	}
	cout << std::endl;
}
#endif