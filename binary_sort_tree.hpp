#include<iostream>
#include<cstdio>
#include<stack>//之前的栈链接不到这里不知道为什么用了STL的栈来写。。。。。就很尴尬
#include<queue>//两种实现方法没有有这个库另一种写在注释上了。。。。
using std::cout;
using std::cin;
using std::endl;
using namespace std;
#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H
#define M 100
using std::cout;
using std::endl;
using std::string;
template<typename T>class binary_sort_tree {
public:

	typedef int ElemType;
	typedef struct Node {
		T data;
		struct Node* left, * right;
		int isout = 0;
	};
	Node* root = nullptr; 
	//stack<Node> s;
protected:
	typedef struct BinarySortTree {
		Node* next = NULL;
	};
	BinarySortTree* proot=nullptr;
	
	Node* Binaryroot = nullptr;
	int count = 0;
public:
	binary_sort_tree();
	binary_sort_tree(T num);
	~binary_sort_tree();
	Node* getroot() {
		return proot->next;
	}
	void destory(Node* bNode);
	bool isFind(const T& theElement, Node* t);
	void inOrder(Node* bNode);
	void preOrder(Node* bNode);
	void postOrder(Node* bNode);
	void freeTree(Node* broot);
	bool BST_init(Node*);
	bool BST_insert(T value);
	void BST_delete(Node* t, T num);
	bool BST_search(Node*, ElemType);
	void BST_preorderI(Node* t);
	void BST_preorderR(Node* t);
	void BST_inorderI(Node* t);
	void BST_inorderR(Node* t);
	void BST_postorderI(Node* t);
    void BST_postorderR(Node* t);
	void BST_levelOrder(Node* t);
	void R_Rotate(Node* p)//右旋
	{
		Node* L;
		L = p->left;//
		p->left = L->right;
		L->right = p;
		p = L;

	}
};
template<typename T>
binary_sort_tree<T>::binary_sort_tree() {
	BinarySortTree* p = new BinarySortTree;
	proot = p;
	proot->next = root;

};

/*template<typename T>
binary_sort_tree<T>::binary_sort_tree(T num) {
	if (StackNode* temp = new StackNode) {
		temp->data = num;
		temp->next = nullptr;
		top = temp;
	}
	else cout << "内存分配失败" << endl;
}*/
template<typename T>
bool binary_sort_tree<T>::BST_insert(T value) {
	if (proot == nullptr) {
		cout << "二叉排序树未初始化 " << endl;
		return false;
	}
	Node* troot, * tnode;
	troot = root;
	Node* p = new Node;
	if (!p)return false;
	p->data = value;
	p->left = nullptr;
	p->right = nullptr;
	if (root == nullptr) {
		root = p;
		return true;
	}
	while (troot) {
		tnode = troot;
		if (troot->data == value) {
			cout << "插入数字已存在 ";
			return false;
		}
		troot = (value < troot->data) ? troot->left : troot->right;
	}
	if (value < tnode->data)
		tnode->left = p;
	else
		tnode->right = p;
	return true;
};
//插入~未测试
template<typename T>
void binary_sort_tree<T>::destory(Node* bNode) {
	if (bNode!=nullptr) {
		if (bNode->left) {
			destory(bNode->left);
			//判断是否右节点，如果存在右节点一直递归下去
			if (bNode->right)
				destory(bNode->right);
			//当一个结点无左结点和右结点，将此结点delete掉
			delete bNode;
			bNode = nullptr;

		}
	}
};
template<typename T>
binary_sort_tree<T>::~binary_sort_tree()
{
	destory(root);
}

template< typename T>
void binary_sort_tree<T>::BST_delete(Node* t, T num)
{       //输入要删除的结点的值
	Node* temp, * previous;
	temp = root;
	previous = root;
	while (temp != NULL)
	{
		if (temp->data == num)
			break;
		else if (temp->data > num)
		{
			previous = temp;
			temp = temp->left;
		}
		else
		{
			previous = temp;
			temp = temp->right;
		}
	}
	if (temp != NULL)
	{
		if (temp->left == NULL)        //要删的结点的左孩子为空的情况
		{
			if (temp == root && temp->right == NULL)
			{
				delete temp;
				temp = NULL;
			}
			else
			{
				previous->left == temp ? previous->left = temp->right : previous->right = temp->right;
				delete temp;
			}
		}
		else if (temp->right == NULL)        //要删的结点的右孩子为空的情况
		{
			previous->left == temp ? previous->left = temp->left : previous->right = temp->left;
			delete temp;
		}
		else                            //要删的结点的左、右孩子都不为空的情况
		{
			Node* right_min = temp->right;
			previous = right_min;
			while (right_min->left != NULL)        //找到右子树最小结点
			{
				previous = right_min;
				right_min = right_min->left;
			}
			temp->data = right_min->data;            //最小结点的值赋给要删除的结点
			if (right_min == previous)
			{
				temp->right = right_min->right;
			}
			else
			{
				previous->left = right_min->right;
			}
			delete right_min;                //删除右子树的最小结点
		}
	}
}
	template<typename T>
	void binary_sort_tree<T>::BST_inorderI(Node* t) {
		if (t == NULL)
			return; 
		stack<Node*> s;
		Node* pb = t;

		while (pb || !s.empty())
		{
			//先一直向左节点方向走
			while (pb)
			{
				s.push(pb);
				pb = pb->left;
			}
			//若为最左的那个节点输出
			if (!s.empty())
			{
				pb = s.top();
				s.pop();
				cout << pb->data << " ";
				pb = pb->right;
			}
		}
	}
	template<typename T>
	void binary_sort_tree<T>::BST_preorderI(Node* t) {
		if (t == NULL)
			return;
		stack<Node*> s;
		Node* pb = t;
		while (!s.empty() || pb)
		{
			//先遍历左子树节点
			while (pb)
			{
				cout << pb->data << " ";
				s.push(pb);
				pb = pb->left;
			}
			//到最左的一个节点，看看它有没有右子树，若有，继续寻找该右子树的左节点
			if (!s.empty())
			{
				pb = s.top();
				s.pop();
				pb = pb->right;
			}
		}

	}
	template<typename T>
	void binary_sort_tree<T>::BST_postorderI(Node* t) {
		Node* r=nullptr;
		if (t == NULL)
			return;
		stack<Node*> s;
		Node* pb = t;
		
		while (!s.empty() || pb)
		{
			//走到最左边
			if (pb)
			{
				s.push(pb);
				pb = pb->left;
			}
			else
			{
				pb = s.top();   //向右
				//判断其是否含有右子树，若有，则将右子树压入栈中，
				//若无，则输出，且记录该节点为已经访问过的节点
				if (pb->right && pb->right != r)//右子树存在且未被访问过
				{
					pb = pb->right;     //转向右
					s.push(pb);        //压入栈
					pb = pb->left;     //再向左
				}
				else
				{
					pb = s.top();         //弹出再访问
					s.pop();
					cout << pb->data << " ";
					r = pb;               //标记已经被访问过的节点
					pb = NULL;            //重置指针p
				}
			}

		}
	}
	
	
	
	
	
	
	
	
	template<typename T>
	void binary_sort_tree<T>::BST_levelOrder(Node* t) {
		Node* q[100];
		int front = 0, rear = 0;
		Node* p;
		if (t == nullptr)
			return;
		q[rear] = t;
		rear = (rear + 1) % 100;
		while (front != rear)
		{
			p = q[front];
			front = (front + 1) % 100;
			cout<<p->data;
			if (p->left)
			{
				q[rear] = p->left;
				rear = (rear + 1) % 100;
			}
			if (p->right)
			{
				q[rear] = p->right;
				rear = (rear + 1) % 100;
			}
		}
/*queue<Node*> q;
q.push(t);
while (!q.empty()) {
	Node* now = q.front();
	q.pop();
	cout << now->data<<" ";
	if (now->left != NULL)
		q.push(now->left);
	if (now->right != NULL)
		q.push(now->right);

}*/
	}











//binary_sort_tree
template< typename T>
bool binary_sort_tree<T>::isFind(const T& num, Node* p) {
	if (nullptr == p) {
		cout << "未找到" << num << endl;
		return false;
	}
	else if (num < p->data) {
		return isFind(num, p->left);
	}
	else if (num > p->data) {
		return isFind(num, p->right);
	}
	else { //匹配
		cout << "找到" << num << endl;
		return true;
	}
};
//查找数据

template< typename T>
void binary_sort_tree<T>::preOrder(Node* bNode) {
	if (nullptr != bNode) {
		std::cout << bNode->data << " ";
		preOrder(bNode->left);
		preOrder(bNode->right);
	}
};
//前序遍历

template< typename T>
void binary_sort_tree<T>::inOrder(Node* bNode) {
	if (nullptr != bNode) {
		inOrder(bNode->left);
		std::cout << bNode->data << " ";
		inOrder(bNode->right);
	}
};
//中序遍历
template< typename T>
void binary_sort_tree<T>::postOrder(Node* bNode) {
	if (nullptr != bNode) {
		postOrder(bNode->left);
		postOrder(bNode->right);
		std::cout << bNode->data << " ";
	}
};

//后续遍历

#endif