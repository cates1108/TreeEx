
#include "stdio.h"
#include "stdlib.h"

typedef struct node_t tree_node_t;

struct node_t
{
	int data;
	tree_node_t* left_node;
	tree_node_t* right_node;	
};

tree_node_t* g_root = NULL;

void InsertNode(int value)
{
	
	if(g_root == NULL)
	{
		printf("root\n");
		g_root = (tree_node_t* )malloc(sizeof(tree_node_t));
		g_root->left_node = NULL;
		g_root->right_node = NULL;
		g_root->data = value;
		return;
	}
	else
	{
		tree_node_t* ptr = g_root;
		tree_node_t* tmp = (tree_node_t*)malloc(sizeof(tree_node_t));

		tmp->data = value;
		tmp->right_node = NULL;
		tmp->left_node = NULL;

		while(ptr != NULL)
		{
				
			if(tmp->data <= ptr->data)
			{
				if(ptr->left_node == NULL)
				{
					printf("left data\n");
					ptr->left_node = tmp;
					return;
				}
				else
					ptr = ptr->left_node;	
			}
			else
			{
				if(ptr->right_node == NULL)
				{	
					printf("right data\n");
					ptr->right_node = tmp;
					return;
				}
				else	
					ptr = ptr->right_node;
			}
					
		}
	}
}

void Inorder(tree_node_t* ptr)
{
	
	if(ptr == NULL)
		return;
	
	Inorder(ptr->left_node);
	printf("%d ",ptr->data);
	Inorder(ptr->right_node);
}




void main(void)
{
int a[] = {3,5,2,7,1,2};
int i;

for(i = 0; i < 6; i++)
	InsertNode(a[i]);

Inorder(g_root);

}

