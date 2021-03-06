// tree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "math.h"
using namespace std;
int max(int a, int b) { return a > b ? a : b; }


typedef struct node {
	node * lchild, *rchild;
	char data;
}node;
class BTree {
public:
	BTree();
	void preorder() { preorder(root); }
	void inorder() { inorder(root); }
	int inorder1() { int i; i=inorder1(root,i); return i; }
	void postorder() { postorder(root); }
	void CreateBTree() { CreateBTree(root); }
	int high(node * T);
	node * root;
private:
	
	void visit(node*T);
	void preorder(node*T);
	void inorder(node*T);
	int inorder1(node*T,int &);
	void postorder(node*T);
	void CreateBTree(node *&T);

};
BTree::BTree() {
	root = NULL;
}
void BTree::visit(node*T) {
	cout << T->data;
}
void BTree::inorder(node*T) {
	if (T != NULL) {
		inorder(T->lchild);
		visit(T);
		inorder(T->rchild);
	}
	else return;
}int BTree::inorder1(node*T,int &i) {
	if (T != NULL) {
		i++;
		inorder1(T->lchild,i);
		inorder1(T->rchild,i);
	}
	else return i;
}
void BTree::postorder(node*T) {
	if (T != NULL) {
		postorder(T->lchild);
		postorder(T->rchild);
		visit(T);
	}
	else return;
}
void BTree::preorder(node*T) {
	if (T != NULL) {
		visit(T);
		preorder(T->lchild);
		preorder(T->rchild);
	}
	else return;
}
void BTree::CreateBTree(node *&T) {
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else {
		T = new node;
		T->data = ch;
		CreateBTree(T->lchild);
		CreateBTree(T->rchild);
	}
}
int BTree::high(node *T)
{
	if (T == NULL)
		return 0;
	else return max(high(T->lchild), high(T->rchild)) + 1;
}
int leavesnum(BTree a)
{
	int i;
	i=a.inorder1();
	cout <<i;
	return 0;
}
int main()
{
	int h;
	BTree a;
	cout << "start create a new tree" << endl;
	a.CreateBTree();
	a.preorder();
	cout << endl;
	a.inorder();
	cout << endl;
	a.postorder();
	cout << endl;
	h=a.high(a.root);
	cout <<"high:"<<h;
	leavesnum(a);
	return 0;
}



