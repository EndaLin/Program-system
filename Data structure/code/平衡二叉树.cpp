#include<iostream>
#include<ctime>
using namespace std;
typedef int DataType;


class BiTreeNode 
{
public:
	DataType data;
	BiTreeNode *leftChild;
	BiTreeNode *rightChild;
	static void Insert(BiTreeNode **root,DataType data[]);   //插入算法
	static void InOrder(BiTreeNode *root);    //中序遍历输出
	static bool find(BiTreeNode *root,DataType item);   //查找
	static void deleteData(BiTreeNode *root,DataType item);    //删除某元素
	static void Destroy(BiTreeNode *root);    //销毁二叉树
};

void BiTreeNode::Insert(BiTreeNode **root,DataType data[])
{
    BiTreeNode *current,*parent,*p;
	int i=0,flag=1;
	for(int i=0;i<50;i++){
		 flag=1;
		 current=*root;
		 parent=NULL;
	     while(current!=NULL)
	     {
		       if(current->data==data[i])
			   {
			          flag=0;
					  break;
			   }
	           parent=current;
		       current=data[i]>current->data?current->rightChild:current->leftChild;
	      }
		 if(flag)
		 {
			   p=new BiTreeNode();
			   p->data=data[i];
			   p->leftChild=NULL;
			   p->rightChild=NULL;
			   if(parent==NULL)
			       *root=p;
			   else if(parent->data>p->data)
				   parent->leftChild=p;
			   else
				   parent->rightChild=p;
		 }
	}
}

void BiTreeNode::InOrder(BiTreeNode *root)
{
     if(root!=NULL)
	 {
		 if(root->leftChild!=NULL)
			 InOrder(root->leftChild);
		 cout<<root->data<<" ";
		 if(root->rightChild!=NULL)
			 InOrder(root->rightChild);
	 }
}

bool BiTreeNode::find(BiTreeNode *root,DataType item)
{
     if(root==NULL)
		 return false;
	 else if(root->data==item)
		 return true;
	 else if(root->data>item)
		 return find(root->leftChild,item);
	 else 
		 return find(root->rightChild,item);
}

void BiTreeNode::deleteData(BiTreeNode *root,DataType item)
{
	BiTreeNode *parent,*current;
	current=root;
	parent=NULL;
	while(current!=NULL)
	{
		if(current->data==item)
			break;
		else if(current->data>item)
		{
		    parent=current;
			current=current->leftChild;
		}
		else
		{
		    parent=current;
			current=current->rightChild;
		}
	}
	if(current==NULL)
	{
	     cout<<"该元素不存在"<<endl;
		 return;
	}
	else if(current->leftChild==NULL&&current->rightChild==NULL)
	{
		if(parent->leftChild==current)
			parent->leftChild=NULL;
		else
			parent->rightChild=NULL;
		free(current);
	}
	else if(current->leftChild!=NULL&&current->rightChild==NULL)
	{
		if(parent->leftChild==current)
		{
			parent->leftChild=current->leftChild;
			free(current);
		}
		else
		{
		    
			parent->rightChild=current->leftChild;
			free(current);
		}
	}
	else if(current->rightChild!=NULL&&current->leftChild==NULL)
	{
		if(parent->leftChild==current)
		{
			parent->leftChild=current->rightChild;
			free(current);
		}
		else
		{	    
			parent->rightChild=current->rightChild;
			free(current);
		}	
	}
	else    //寻找左子树的最右节点并删除之
	{
		BiTreeNode *pre=current;
		parent=current;
		current=current->leftChild;
		while(current->rightChild!=NULL)
		{
			parent=current;
			current=current->rightChild;       
		}
		pre->data=current->data;
		parent->rightChild=NULL;
		free(current);
	}
	cout<<"删除成功！"<<endl;
}

void BiTreeNode::Destroy(BiTreeNode *root)
{
     if(root!=NULL)
	 {
		 if(root->leftChild!=NULL)
			 Destroy(root->leftChild);
		 if(root->rightChild!=NULL)
			 Destroy(root->rightChild);
		 free(root);
	 }     
}




void random(DataType num[])    //生成随机数
{
     srand(time(NULL));
	 for(int i=0;i<=50;i++)
	 {
		  num[i]=200+rand()%800;
		  for(int j=0;j<i;j++)
		  {
		        if(num[i]==num[j])
				{
				      i--;
					  break;
				}
		  }
	 }
}


int main()
{
	  DataType num[50];
	  random(num);
	  BiTreeNode *root=NULL;
	  BiTreeNode::Insert(&root,num);
	  cout<<"中序输出平衡二叉树："<<endl;
	  BiTreeNode::InOrder(root);
	  cout<<endl;
	  cout<<"请输入您想要查找的数据：";
	  DataType item;
	  cin>>item;
	  if(BiTreeNode::find(root,item))
		  cout<<"该数据存在"<<endl;
	  else
		  cout<<"该数据不存在"<<endl;
	  cout<<"请输入所要删除的元素：";
	  cin>>item;
	  BiTreeNode::deleteData(root,item);
	  BiTreeNode::InOrder(root);
	  BiTreeNode::Destroy(root);
	  system("pause");
}