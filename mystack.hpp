#include<iostream>
using namespace std;

template<typename T>class myStack
{
protected:
	struct node
	{
		T value;
		node* next;

		node() :next(nullptr) {};
		node(T t) :value(t), next(nullptr) {};
	};
private:
	int cnts; //入栈数量
	node* head; //栈的头部
public:

	myStack() { cnts = 0; head = new node; }
	void stackPush(T arg); //入栈
	T stackPop();  //出栈
	T stackTop(); //获取栈顶元素

	void printStack(); //打印栈
	int counts(); //获取栈内元素个数
	bool isEmpty(); //判断空
};

template<typename T>
void myStack<T>::stackPush(T arg)
{
	node *pnode = new node(arg); //申请入栈元素的空间
	pnode->next = head->next;
	head->next = pnode;
	cnts++;
}
template<typename T>
T myStack<T>::stackPop()
{
	if (head->next!=nullptr) 
	{
		node* temp = head->next;
		head->next = head->next->next;
		T popVal = temp->value;
		delete temp;
		return popVal;
	}
}
template<typename T>
T myStack<T>::stackTop()
{
	if (head->next!=nullptr)
	{
		return head->next->value;
	}
}
template<typename T>
void myStack<T>::printStack()
{
	if (head->next != nullptr)
	{
		node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			cout << temp->value << endl;
		}
	}
}
template<typename T>
int myStack<T>::counts()
{
	return cnts;
}
template<typename T>
bool myStack<T>::isEmpty()
{
	if (cnts)
		return false;
	else
		return true;
}