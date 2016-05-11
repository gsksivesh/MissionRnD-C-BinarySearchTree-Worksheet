/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void height(struct node * root, int level, int *max_height)
{
	if (root == NULL)
	{
		if (*max_height < level)
			*max_height = level - 1;
		return;
	}
	height(root->left, level + 1, max_height);
	height(root->right, level + 1, max_height);
}

int get_height(struct node *root)
{
	int ht = 0;
	if (root == NULL)
		return 0;
	height(root, 1, &ht);
	return ht;
}
void sum(struct node * root, int *ans)
{
	if (root == NULL)
	{
		return;
	}
	(*ans) += root->data;
	sum(root->left, ans);
	sum(root->right, ans);
}

int get_left_subtree_sum(struct node *root)
{
	int left_sum = 0;
	if (root == NULL)
		return 0;
	sum(root->left, &left_sum);
	return left_sum;
}

int get_right_subtree_sum(struct node *root)
{
	int right_sum = 0;
	if (root == NULL)
		return 0;
	sum(root->right, &right_sum);
	return right_sum;
}

