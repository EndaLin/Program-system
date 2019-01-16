#include<iostream>
using namespace std;

typedef char DataType;

class BiTreeNode    //二叉树节点类
{
public:
     DataType data;
	 BiTreeNode *leftChild;
	 BiTreeNode *rightChild;
};

class Stack        //栈节点类
{
public:
	BiTreeNode *curr;
	Stack *next;
};

class LQNode      //链式队列节点类
{
public:
	BiTreeNode *curr;
	LQNode *next;
};

class LQueue
{
public:
	LQNode *front;    //队头指针
	LQNode *rear;     //队尾指针
};



//二叉树的基本操作（不带空的根节点）
void Initiate(BiTreeNode **root)   //初始化二叉树的根节点
{
     *root=new BiTreeNode();
	 (*root)->leftChild=NULL;
	 (*root)->rightChild=NULL;
}

BiTreeNode *InsertLeftChild(BiTreeNode *curr,DataType x)   //插入左孩子节点
{
     BiTreeNode *s,*t;
	 if(curr==NULL){
	       return NULL;
	 }
	 t=curr->leftChild;
	 s=new BiTreeNode();
	 s->rightChild=NULL;
	 s->data=x;
	 curr->leftChild=s;
	 s->leftChild=t;
	 return curr->leftChild;
}

BiTreeNode *InsertRightChild(BiTreeNode *curr,DataType x)  //插入右孩子节点
{
     BiTreeNode *s,*t;
	 if(curr==NULL)return NULL;
	 t=curr->rightChild;
	 s=new BiTreeNode();
	 s->leftChild=NULL;
	 s->data=x;
	 curr->rightChild=s;
	 s->rightChild=t;
	 return curr->rightChild;
}


void Destroy(BiTreeNode **root)    //销毁二叉树
{
     if((*root)!=NULL&&(*root)->leftChild!=NULL)
		 Destroy(&(*root)->leftChild);
	 if((*root)!=NULL&&(*root)->rightChild!=NULL)
		 Destroy(&(*root)->rightChild);
	 free(*root);
}

//栈的基本操作（链式结构，带头节点）

void InitiateStack(Stack **head)   //初始化栈
{
	(*head)=new Stack();
	(*head)->curr=NULL;
	(*head)->next=NULL;
}

void StackPush(Stack *head,BiTreeNode *p)  //入栈
{
	if(p==NULL)
		return;
    Stack *s=new Stack();
	s->curr=new BiTreeNode();
	s->curr->data=p->data;
	s->curr->leftChild=p->leftChild;
	s->curr->rightChild=p->rightChild;
	s->next=head->next;
	head->next=s;
}

bool StackPop(Stack *head,BiTreeNode *p)   //出栈
{
    if(head->next!=NULL)
	{
	     Stack *temp=head->next;
		 p->data=temp->curr->data;
		 p->leftChild=temp->curr->leftChild;
		 p->rightChild=temp->curr->rightChild;
		 head->next=temp->next;
		 free(temp->curr);
		 free(temp);
		 return true;
	}
	else
		 return false;
}

void Destroy(Stack **head)   //销毁栈的头节点
{
    free(*head);
}

//队列的基本操作
void QueueInitiate(LQueue **head)
{
	*head=new LQueue();
	(*head)->front=NULL;
	(*head)->rear=NULL;
}

void QueueAppend(LQueue *head,BiTreeNode *p)    //入队列
{
    LQNode *q=new LQNode();
	q->curr=new BiTreeNode();
	q->curr->data=p->data;
	q->curr->leftChild=p->leftChild;
	q->curr->rightChild=p->rightChild;
	q->next=NULL;
	if(head->rear!=NULL)
		head->rear->next=q;
	head->rear=q;
	if(head->front==NULL)
		head->front=q;
}

void QueueGetNode(LQueue *head,BiTreeNode *p)   //出队列
{
	if(head->front==NULL)
		return;
	LQNode *temp=head->front;
	p->data=head->front->curr->data;
	p->leftChild=head->front->curr->leftChild;
	p->rightChild=head->front->curr->rightChild;
	head->front=head->front->next;
	free(temp->curr);
	free(temp);
}

void Destroy(LQueue **head)   //销毁
{
     free(*head);
}

//树的输出操作

void PreOrder(BiTreeNode *root,Stack *head)    //非递归前序输出二叉树节点
{
	BiTreeNode *p=new BiTreeNode();
	StackPush(head,root);
    while(head->next!=NULL)
	{
	     StackPop(head,p);
		 cout<<p->data<<" ";
		 if(p->rightChild!=NULL)
		   StackPush(head,p->rightChild); 
		 if(p->rightChild!=NULL)
		   StackPush(head,p->leftChild);
	}
}


void InOrder(BiTreeNode *root,Stack *head)    //非递归中序输出二叉树节点
{
	BiTreeNode *q=root->leftChild,*p= new BiTreeNode();
	StackPush(head,root);  //此处插入是为了进入后面的循环
	while(head->next!=NULL)
	{
		while(q!=NULL){          //先把所有节点的左孩子入栈
			StackPush(head,q);
			q=q->leftChild;
		}
		if(head->next!=NULL)
		{
		    StackPop(head,p);
			cout<<p->data<<" ";
			if(p->rightChild!=NULL){
				StackPush(head,p->rightChild);      //若发现某一个节点的右子树不为空，则提前入栈，避免因为无法到达根节点的右子树
				q=p->rightChild->leftChild;         //记录更节点左子树的位置
			}
		}
	}
}

void PostOrder(BiTreeNode *root,void visit(DataType item))     //递归后序遍历输出二叉树
{
    if(root!=NULL)
	{
		PostOrder(root->leftChild,visit);
		PostOrder(root->rightChild,visit);
		visit(root->data);
	}
}

void visit(DataType item)
{
     cout<<item<<" ";
}

void PrintBiTree(BiTreeNode *root,LQueue *Q)  //二叉树的层序遍历输出
{
	BiTreeNode *q=new BiTreeNode();
	QueueAppend(Q,root);
	while(Q->front!=NULL)
	{
         QueueGetNode(Q,q);
		 cout<<q->data<<" ";
		 if(q->leftChild!=NULL)
			 QueueAppend(Q,q->leftChild);
		 if(q->rightChild!=NULL)
			 QueueAppend(Q,q->rightChild);
	}
}

int BiTreeDepth(BiTreeNode *root)    //求二叉树的深度
{
    if(root==NULL)
		return 0;
	int LeftDepth=BiTreeDepth(root->leftChild);
	int RightDepth=BiTreeDepth(root->rightChild);
	return LeftDepth>RightDepth?LeftDepth+1:RightDepth+1;
}

void PrintLeaves(BiTreeNode *root,void visit(DataType item))    //用后序遍历输出叶节点
{
	if(root!=NULL)
	{
		PrintLeaves(root->leftChild,visit);
		PrintLeaves(root->rightChild,visit);
		if(root->leftChild==NULL&&root->rightChild==NULL)
			visit(root->data);
	}
}

void PrintNotLeaves(BiTreeNode *root,LQueue *Q)    //使用层序遍历输出非叶节点
{
	BiTreeNode *p=new BiTreeNode();
	QueueAppend(Q,root);
	while(Q->front!=NULL)
	{
		QueueGetNode(Q,p);
		if(p->leftChild!=NULL&&p->rightChild!=NULL)
			cout<<p->data<<" ";
		if(p->leftChild!=NULL)
			QueueAppend(Q,p->leftChild);
		if(p->rightChild!=NULL)
			QueueAppend(Q,p->rightChild);
	}
}
int main()
{
	BiTreeNode *root,*p,*q;
	Stack *head;
	LQueue *Q;
	Initiate(&root);
	InitiateStack(&head);
	QueueInitiate(&Q);
	//构造二叉树根节点的左子树和右子树
	//step1:构造根节点的左子树
	root->data='A';
	p=InsertLeftChild(root,'B');
	q=p;
	p=InsertLeftChild(p,'C');
	q=InsertRightChild(q,'D');
	q=p;
	p=InsertLeftChild(p,'E');
	q=InsertRightChild(q,'F');
	//step2:构造根节点的右子树
	p=InsertRightChild(root,'G');
	q=p;
	p=InsertLeftChild(p,'H');
	q=InsertRightChild(q,'I');
	q=p;
	p=InsertLeftChild(p,'J');
	q=InsertRightChild(q,'K');
	cout<<"前序：";
	PreOrder(root,head);   //前序
	cout<<endl;
	cout<<"中序：";
	InOrder(root,head);    //中序
	cout<<endl;
	cout<<"后序：";
	PostOrder(root,visit);      //后序
	cout<<endl;
	cout<<"层序：";
	PrintBiTree(root,Q);     //层序
	cout<<endl;
	cout<<"该二叉树的深度为："<<BiTreeDepth(root)<<endl;
	cout<<"输出该树的叶节点：";
	PrintLeaves(root,visit);
	cout<<endl;
	cout<<"输出该树的非叶节点：";
	PrintNotLeaves(root,Q);
	cout<<endl;
	Destroy(&root);
	Destroy(&head);
	Destroy(&Q);
	system("pause");
	return 0;
}