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
	printf("�Ƿ񴴽�һ����------1����/0�˳�\n");
	int n = 0;
	printf("����������ִ�еĲ���:");
	while (inputCheck(&n) == -1||(n!=1&&n!=0))
	{
		printf("�����������������:");
	}
	if (n != 0 && n != 1) {
		printf("\n��������-----����");
	}
	if (n == 1) {
		cout << "��������" << endl;
	}
	if (n == 0) {
		return 0;
	}
	while (q !=11) {
		printf("ѡ��:\n");
		printf("1.��������\n");
		printf("2.��������\n");
		printf("3.ɾ������\n");
		printf("4.�ݹ�ǰ�����\n");
		printf("5.�ݹ��������\n");
		printf("6.�ݹ�������\n");
		printf("7.����ǰ�����\n");
		printf("8.�����������\n");
		printf("9.�����������\n");
		printf("10.�������\n");
		printf("11.�˳�����\n");
		printf("����������ִ�еĲ���:");
		while (inputCheck(&q) == -1||q>11||q<1)
		{
			printf("�����������������:");
		}
		switch (q) {
		case 1:
			cout<<("���������������ݣ�������ظ��ᱩ�е�~~~~~ֻ��������Ŷ~~��:\n");
			while (inputCheck(&num) == -1||num<0 )
			{
				printf("�����������������:");
			}
			A.BST_insert(num);
			break;
		case 2:
			cout << "������Ҫ���ҵ���" << endl;
			while (inputCheck(&u) == -1 ||u<0)
			{
				if (u < 0)cout << "ֻ��������Ŷ" << endl;
				else printf("�����������������:");
			}
			A.isFind(u, A.root);
			break;
		case 3:
			cout << "����Ҫɾ������" << endl;
			while (inputCheck(&delnum) == -1 || u < 0)
			{
				if (delnum < 0)cout << "ֻ��������Ŷ" << endl;
				else printf("�����������������:");
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




int inputCheck(int* val)  //�������
{
	char n[50] = { 0 };
	int i = 0, flag = 0, minus = 0;
	// �û���ʼ����
	scanf("%s", n);
	getchar();
	for (int j = 0; n[j] != '\0'; j++)
	{
		// ����Ƿ���ȷ�������λ
		if (j == 0 && (n[j] == '-' || n[j] == '+'))
		{
			continue;
		}
		if (n[j] < '0' || n[j] > '9')
			flag = 1;
	}
	if (flag == 1)
	{
		// flag==1 ��˵���û������뷢���˴���
		return -1;
	}
	int temp = 0, simple = 1;
	for (int j = 0; n[j] != '\0'; j++)
	{
		if (n[j] == '-')
		{
			// simple���ڼ���û��Ƿ������˸���
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