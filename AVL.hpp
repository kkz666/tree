#include<iostream>
#include<cstdio>
#include<stack>//֮ǰ��ջ���Ӳ������ﲻ֪��Ϊʲô����STL��ջ��д�����������ͺ�����
#include<queue>//����ʵ�ַ���û�����������һ��д��ע�����ˡ�������
#include<algorithm>//����һ��max.....����д��~~~����AVL������ĸ߶ȡ�������
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
		int hegiht = 0;//��¼���ĸ߶�AVL~~~�����1�Ļ�����ת~~~
	};
	Node* root = nullptr;
	//stack<Node> s;
protected:
	typedef struct BinarySortTree {
		Node* next = NULL;
	};
	BinarySortTree* proot = nullptr;

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
};
	Node* newNode(int v) {
		{
			Node* Node = new Node;//����һ��node�ͱ����ĵ�ַ�ռ�
			Node->v = v;//���ȨֵΪv
			Node->height = 1;//���߶ȳ�ʼΪ1
			Node->left = Node->right = nullptr;//��ʼ״̬��û�����Һ��ӽ��
			return Node;//�����½����ĵ�ַ
		}//����һ���½ڵ㣬vΪ���Ȩֵ}
	int getHeight(Node* root);
	void updateHeight(Node* root);//���½���height�����ֵ��
	int getBalanceFactor(Node* root);
	void L(Node*& root);
	void R(Node*& root);
	void insert(Node*& root, int v);
	Node* create(int data[], int n);
	int get();
	Node* flag();
	Node* getRoot() {
		return root;
	}

	};
		template<typename T>
	int binary_sort_tree<T>::getHeight(Node* root) {
		if (root == NULL)return 0;//�ս��߶�Ϊ0
		return root->height;
	}
		template<typename T>
	void binary_sort_tree<T>::updateHeight(Node* root) {
		root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
	}
		template<typename T>
		int binary_sort_tree<T>::getBalanceFactor(Node* root) {
		return getHeight(root->lchild) - getHeight(root->rchild);
	}


		template<typename T>
	void binary_sort_tree<T>::L(Node*& root) {
		//rootָ��A��tempָ��B�������ʾ��ͼ
		Node* temp = root->right;
		root->right = temp->left;
		temp->left = root;
		updateHeight(root);//����A�ĸ߶�
		updateHeight(temp);//����B�ĸ߶�
		root = temp;
	}//�����㷨
		template<typename T>
	void binary_sort_tree<T>::R(Node*& root) {
		//����������ֻ����״ǡ���෴
		Node* temp = root->left;
		root->left = temp->right;
		temp->right = root;
		updateHeight(root);
		updateHeight(temp);
		root = temp;
	}//�����㷨
		template<typename T>
		void binary_sort_tree<T>::insert(Node*& root, int v) {
			if (root == nullptr)//����ս��
			{
				root = newNode(v);
				return;
			}
			if (v < root->data)//v�ȸ����ȨֵС
			{
				insert(root->left, v);//����������
				updateHeight(root);//��������
				if (getBalanceFactor(root) == 2)
				{
					if (getBalanceFactor(root->left) == 1)//LL
						R(root);
					else if (getBalanceFactor(root->left) == -1)//LR
					{
						L(root->left);
						R(root);
					}
				}
			}
			else//v�ȸ����Ȩֵ��
			{
				insert(root->right, v);//����������
				updateHeight(root);//��������
				if (getBalanceFactor(root) == -2)
				{
					if (getBalanceFactor(root->right) == -1)//RR
						L(root);
					else if (getBalanceFactor(root->right) == 1)//RL
					{
						R(root->right);
						L(root);
					}
				}
			}
		}

		template<typename T>
		binary_sort_tree<T>::Node* binary_sort_tree<T>::create(int data[], int n) {
			Node* root = nullptr;//�����������ڵ�
			for (int i = 0; i < n; i++)
				insert(root, data[i]);//����
			return root;//���ظ��ڵ�
		}//AVL���Ĵ���
			template<typename T>
			int binary_sort_tree<T>::get(void) {
				if (root != nullptr)
					return root->data;
				else
					return nullptr;

			}//ȡ��ֵ
				template<typename T>
			binary_sort_tree<T>::Node* binary_sort_tree<T>::flag(void) {
				Node* node = new Node;
				node->v = 0;
				node->height = 0;
				node->left = node->right = NULL;
				return node;
			}





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
		else cout << "�ڴ����ʧ��" << endl;
	}*/
	template<typename T>
	bool binary_sort_tree<T>::BST_insert(T value) {
		if (proot == nullptr) {
			cout << "����������δ��ʼ�� " << endl;
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
				cout << "���������Ѵ��� ";
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
	//����~δ����
	template<typename T>
	void binary_sort_tree<T>::destory(Node* bNode) {
		if (bNode != nullptr) {
			if (bNode->left) {
				destory(bNode->left);
				//�ж��Ƿ��ҽڵ㣬��������ҽڵ�һֱ�ݹ���ȥ
				if (bNode->right)
					destory(bNode->right);
				//��һ�������������ҽ�㣬���˽��delete��
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
	{       //����Ҫɾ���Ľ���ֵ
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
			if (temp->left == NULL)        //Ҫɾ�Ľ�������Ϊ�յ����
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
			else if (temp->right == NULL)        //Ҫɾ�Ľ����Һ���Ϊ�յ����
			{
				previous->left == temp ? previous->left = temp->left : previous->right = temp->left;
				delete temp;
			}
			else                            //Ҫɾ�Ľ������Һ��Ӷ���Ϊ�յ����
			{
				Node* right_min = temp->right;
				previous = right_min;
				while (right_min->left != NULL)        //�ҵ���������С���
				{
					previous = right_min;
					right_min = right_min->left;
				}
				temp->data = right_min->data;            //��С����ֵ����Ҫɾ���Ľ��
				if (right_min == previous)
				{
					temp->right = right_min->right;
				}
				else
				{
					previous->left = right_min->right;
				}
				delete right_min;                //ɾ������������С���
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
			//��һֱ����ڵ㷽����
			while (pb)
			{
				s.push(pb);
				pb = pb->left;
			}
			//��Ϊ������Ǹ��ڵ����
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
			//�ȱ����������ڵ�
			while (pb)
			{
				cout << pb->data << " ";
				s.push(pb);
				pb = pb->left;
			}
			//�������һ���ڵ㣬��������û�������������У�����Ѱ�Ҹ�����������ڵ�
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
		Node* r = nullptr;
		if (t == NULL)
			return;
		stack<Node*> s;
		Node* pb = t;

		while (!s.empty() || pb)
		{
			//�ߵ������
			if (pb)
			{
				s.push(pb);
				pb = pb->left;
			}
			else
			{
				pb = s.top();   //����
				//�ж����Ƿ��������������У���������ѹ��ջ�У�
				//���ޣ���������Ҽ�¼�ýڵ�Ϊ�Ѿ����ʹ��Ľڵ�
				if (pb->right && pb->right != r)//������������δ�����ʹ�
				{
					pb = pb->right;     //ת����
					s.push(pb);        //ѹ��ջ
					pb = pb->left;     //������
				}
				else
				{
					pb = s.top();         //�����ٷ���
					s.pop();
					cout << pb->data << " ";
					r = pb;               //����Ѿ������ʹ��Ľڵ�
					pb = NULL;            //����ָ��p
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
			cout << p->data;
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
			cout << "δ�ҵ�" << num << endl;
			return false;
		}
		else if (num < p->data) {
			return isFind(num, p->left);
		}
		else if (num > p->data) {
			return isFind(num, p->right);
		}
		else { //ƥ��
			cout << "�ҵ�" << num << endl;
			return true;
		}
	};
	//��������

	template< typename T>
	void binary_sort_tree<T>::preOrder(Node* bNode) {
		if (nullptr != bNode) {
			std::cout << bNode->data << " ";
			preOrder(bNode->left);
			preOrder(bNode->right);
		}
	};
	//ǰ�����

	template< typename T>
	void binary_sort_tree<T>::inOrder(Node* bNode) {
		if (nullptr != bNode) {
			inOrder(bNode->left);
			std::cout << bNode->data << " ";
			inOrder(bNode->right);
		}
	};
	//�������
	template< typename T>
	void binary_sort_tree<T>::postOrder(Node* bNode) {
		if (nullptr != bNode) {
			postOrder(bNode->left);
			postOrder(bNode->right);
			std::cout << bNode->data << " ";
		}
	}
	//��������
#endif