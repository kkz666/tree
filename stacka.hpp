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
	int cnts; //��ջ����
	node* head; //ջ��ͷ��
public:

	myStack() { cnts = 0; head = new node; head->next = nullptr; }
	void stackPush(T arg); //��ջ
	T stackPop();  //��ջ
	T stackTop(); //��ȡջ��Ԫ��

	void printStack(); //��ӡջ
	int counts(); //��ȡջ��Ԫ�ظ���
	bool isEmpty(); //�жϿ�
};

template<typename T>
void myStack<T>::stackPush(T arg)
{
	node *pnode = new node; //������ջԪ�صĿռ�
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