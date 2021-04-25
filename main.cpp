#include<iostream>
#include"binary_sort_tree.hpp"
#include<cstdio>
using std::cout;
using std::cin;
using std::endl;
using namespace std;
int t;
int q;
int num;
int u;
int delnum;
int inputCheck(int* val);
int main(void) {
	binary_sort_tree<int>A;
	printf("是否创建一个树------1创建/0退出\n");
	int n = 0;
	printf("请输入您想执行的操作:");
	while (inputCheck(&n) == -1||(n!=1&&n!=0))
	{
		printf("输入错误！请重新输入:");
	}
	if (n != 0 && n != 1) {
		printf("\n错误输入-----结束");
	}
	if (n == 1) {
		cout << "空树创建" << endl;
	}
	if (n == 0) {
		return 0;
	}
	while (q !=11) {
		printf("选项:\n");
		printf("1.插入数字\n");
		printf("2.查找数字\n");
		printf("3.删除数字\n");
		printf("4.递归前序遍历\n");
		printf("5.递归中序遍历\n");
		printf("6.递归后序遍历\n");
		printf("7.迭代前序遍历\n");
		printf("8.迭代中序遍历\n");
		printf("9.迭代后序遍历\n");
		printf("10.层序遍历\n");
		printf("11.退出程序\n");
		printf("请输入您想执行的操作:");
		while (inputCheck(&q) == -1||q>11||q<1)
		{
			printf("输入错误！请重新输入:");
		}
		switch (q) {
		case 1:
			cout<<("输入你想插入的数据？（如果重复会暴毙的~~~~~只能是正数哦~~）:\n");
			while (inputCheck(&num) == -1||num<0 )
			{
				printf("输入错误！请重新输入:");
			}
			A.BST_insert(num);
			break;
		case 2:
			cout << "输入你要查找的数" << endl;
			while (inputCheck(&u) == -1 ||u<0)
			{
				if (u < 0)cout << "只能是正数哦" << endl;
				else printf("输入错误！请重新输入:");
			}
			A.isFind(u, A.root);
			break;
		case 3:
			cout << "输入要删除的数" << endl;
			while (inputCheck(&delnum) == -1 || u < 0)
			{
				if (delnum < 0)cout << "只能是正数哦" << endl;
				else printf("输入错误！请重新输入:");
			}
			A.BST_delete(A.root, delnum);
			break;
		case 4:A.preOrder(A.root);
			break;
		case 5:
			A.inOrder(A.root);
			break;
		case 6: A.postOrder(A.root); 
			break;
		case 7: A.BST_preorderI(A.root); break;
		case 8:A.BST_inorderI(A.root); break;
		case 9:A.BST_postorderI(A.root); break;
		case 10:A.BST_levelOrder(A.root); break;
		default:break;
		}
		cout << endl;
	}
	return 0;
}




int inputCheck(int* val)  //检查输入
{
	char n[50] = { 0 };
	int i = 0, flag = 0, minus = 0;
	// 用户开始输入
	scanf("%s", n);
	getchar();
	for (int j = 0; n[j] != '\0'; j++)
	{
		// 检测是否正确输入符号位
		if (j == 0 && (n[j] == '-' || n[j] == '+'))
		{
			continue;
		}
		if (n[j] < '0' || n[j] > '9')
			flag = 1;
	}
	if (flag == 1)
	{
		// flag==1 则说明用户的输入发生了错误
		return -1;
	}
	int temp = 0, simple = 1;
	for (int j = 0; n[j] != '\0'; j++)
	{
		if (n[j] == '-')
		{
			// simple用于检测用户是否输入了负数
			simple = -1;
			continue;
		}
		else if (n[j] == '+')
		{
			continue;
		}
		temp = temp * 10 + (n[j] - 48);
	}

	*val = temp * simple;
	return 1;
}