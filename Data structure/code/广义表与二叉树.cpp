#include <iostream>
#include <string>
using namespace std;

class node//二叉树节点类
{
public:
	node(char c):data(c){leftchild=NULL;rightchild=NULL;}
	char data;
	node * leftchild;
	node * rightchild;
	node(){};
	static int NumLeaves;
	static int NumNodes;
};

class LQNode      //创建队列节点
{
public:
	node *curr;
	LQNode *next;
};



node * create_bt(string str)//构造二叉树，返回指向根节点的指针
{

	if (str.length()==0) return NULL;
	else 
	{
		node *p=new node(str[0]);
		if(str.length()==1) return p;
		int pair=0,i=0;
		for(;i<str.length();i++)
		{
			if (str[i]=='(') pair++;
			if (str[i]==')') pair--;
			if ((str[i]==',')&&(pair==1)) break;
		}
		if(1<=i-2)
		{
			string leftstr=str.substr(2,i-2);
			p->leftchild=create_bt(leftstr);
		}
		if(1<=str.length()-2-i)
		{
			string rightstr=str.substr(i+1,str.length()-2-i);
			p->rightchild=create_bt(rightstr);
		}
		return p;
	}
}

void destroy(node * root)//撤销二叉树
{
	if (root==NULL) return;
	destroy(root->leftchild);
	destroy(root->rightchild);
	delete root;
}

void print(node * root, int t)//凹入法输出二叉树
{
	if (root==NULL) return;
	print(root->rightchild,t+1);
	for(int i=0;i<t;i++) cout<<'\t';
	cout<<root->data<<endl;;
	print(root->leftchild,t+1);
}

int BiTreeDepth(node *root)     //求树的深度
{
    if(root==NULL)
		return 0;
	int leftDepth=BiTreeDepth(root->leftchild);
	int rightDepth=BiTreeDepth(root->rightchild);
	return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
}

void findNum(node *root)    //求二叉树的节点和叶节点的数量
{
    if(root!=NULL)
	{
		if(root->leftchild==NULL&&root->rightchild==NULL)
			node::NumLeaves++;
		node::NumNodes++;
		if(root->leftchild!=NULL)
			findNum(root->leftchild);
		if(root->rightchild!=NULL)
			findNum(root->rightchild);
	}
}

int node::NumLeaves=0;
int node::NumNodes=0;

int main()
{
	string str="A(B(D,E(G,)),C(,F))";//构造二叉树的广义表字符串，格式为 “根节点（左子树，右子树）“
	node *p=create_bt(str);//p为指向构建的二叉树的根节点的指针
	print(p,0);
	cout<<"该二叉树的深度为："<<BiTreeDepth(p)<<endl;
	findNum(p);
	cout<<"该二叉树的节点数量为："<<node::NumNodes<<endl;
	cout<<"该二叉树的叶节点数量为："<<node::NumLeaves<<endl;
	destroy(p);
	system("pause");
	return 0;
}
