/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node * right;
};

void my_inorder(struct node *root, int *arr, int *count)
{
	if (root == NULL || arr == NULL)
	{
		return;
	}
	my_inorder(root->left, arr, count);
	arr[*count] = root->data;
	(*count)++;
	my_inorder(root->right, arr, count);
}
void inorder(struct node *root, int *arr)
{
	int temp = 0;
	my_inorder(root, arr, &temp);
}
void my_preorder(struct node *root, int *arr, int *count)
{
	if (root == NULL || arr == NULL)
	{
		return;
	}
	arr[*count] = root->data;
	(*count)++;
	my_preorder(root->left, arr, count);
	my_preorder(root->right, arr, count);
}
void preorder(struct node *root, int *arr)
{
	int temp = 0;
	my_preorder(root, arr, &temp);
}
void my_postorder(struct node *root, int *arr, int *count)
{
	if (root == NULL || arr == NULL)
	{
		return;
	}
	my_postorder(root->left, arr, count);
	my_postorder(root->right, arr, count);
	arr[*count] = root->data;
	(*count)++;
}
void postorder(struct node *root, int *arr)
{
	int temp = 0;
	my_postorder(root, arr, &temp);
}

