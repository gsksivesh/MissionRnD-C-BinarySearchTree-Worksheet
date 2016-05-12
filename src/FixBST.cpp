/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
void my_inorder_fix(struct node *root, struct node **last_visit, int *flag, struct node **first)
{
	int temp;
	if (root == NULL)
	{
		return;
	}
	if ((*flag) == 0)
	{
		return;
	}
	my_inorder_fix(root->left, last_visit, flag, first);
	if ((*flag) == 0)
	{
		return;
	}
	if ((*last_visit) != NULL && ((*last_visit)->data > root->data))
	{
		if ((*first) == NULL)
		{
			(*first) = (*last_visit);
		}
		else
		{
			temp = (*first)->data;
			(*first)->data = root->data;
			root->data = temp;
			(*flag) = 0;
		}
	}
	(*last_visit) = root;
	my_inorder_fix(root->right, last_visit, flag, first);
	if ((*flag) == 0)
	{
		return;
	}
}

void fix_bst(struct node *root)
{
	struct node *last_visit = NULL, *second = NULL;
	int flag = 1, temp;
	if (root == NULL)
		return;


	second = NULL;
	flag = 1;
	last_visit = NULL;
	my_inorder_fix(root, &last_visit, &flag, &second);
	if (flag == 0 || second == NULL)
		return;
	else
	{
		if (second->data < last_visit->data)
		{
			temp = second->data;
			second->data = root->data;
			root->data = temp;
		}
		else
		{
			temp = last_visit->data;
			last_visit->data = second->data;
			second->data = temp;
		}
	}
}
