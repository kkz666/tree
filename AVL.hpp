#include<iostream>
#include<cstdio>
#include<stack>//之前的栈链接不到这里不知道为什么用了STL的栈来写。。。。。就很尴尬
#include<queue>//两种实现方法没有有这个库另一种写在注释上了。。。。
#include<algorithm>//调用一下max.....不想写了~~~用于AVL计算结点的高度。。。。
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
		int hegiht = 0;//记录结点的高度AVL~~~差大于1的话就旋转~~~
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
			Node* Node = new Node;//申请一个node型变量的地址空间
			Node->v = v;//结点权值为v
			Node->height = 1;//结点高度初始为1
			Node->left = Node->right = nullptr;//初始状态下没有左右孩子结点
			return Node;//返回新建结点的地址
		}//生成一个新节点，v为结点权值}
	int getHeight(Node* root);
	void updateHeight(Node* root);//更新结点的height（深度值）
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
		if (root == NULL)return 0;//空结点高度为0
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
		//root指向A，temp指向B，具体见示意图
		Node* temp = root->right;
		root->right = temp->left;
		temp->left = root;
		updateHeight(root);//更新A的高度
		updateHeight(temp);//更新B的高度
		root = temp;
	}//左旋算法
		template<typename T>
	void binary_sort_tree<T>::R(Node*& root) {
		//类似左旋，只是形状恰好相反
		Node* temp = root->left;
		root->left = temp->right;
		temp->right = root;
		updateHeight(root);
		updateHeight(temp);
		root = temp;
	}//右旋算法
		template<typename T>
		void binary_sort_tree<T>::insert(Node*& root, int v) {
			if (root == nullptr)//到达空结点
			{
				root = newNode(v);
				return;
			}
			if (v < root->data)//v比根结点权值小
			{
				insert(root->left, v);//插入左子树
				updateHeight(root);//更新树高
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
			else//v比根结点权值大
			{
				insert(root->right, v);//插入右子树
				updateHeight(root);//更新树高
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
			Node* root = nullptr;//建立空树根节点
			for (int i = 0; i < n; i++)
				insert(root, data[i]);//插入
			return root;//返回根节点
		}//AVL树的创建
			template<typename T>
			int binary_sort_tree<T>::get(void) {
				if (root != nullptr)
					return root->data;
				else
					return nullptr;

			}//取出值
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
		if (bNode != nullptr) {
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
		Node* r = nullptr;
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
	}
	//后续遍历
#endif