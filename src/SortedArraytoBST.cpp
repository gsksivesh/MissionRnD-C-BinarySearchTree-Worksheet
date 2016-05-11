/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

int is_ascending(int *arr, int len)
{
	int i;
	for (i = 0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return 0;
	}
	return 1;
}
int is_descending(int *arr, int len)
{
	int i;
	for (i = 0; i < len - 1; i++)
	{
		if (arr[i] < arr[i + 1])
			return 0;
	}
	return 1;
}
struct node * convert(int *arr, int len)
{
	int middle;
	struct node *root = NULL;
	if (len <= 0)
		return NULL;
	middle = len / 2;
	root = (struct node *)malloc(sizeof(struct node));
	root->data = arr[middle];
	root->left = convert(arr, middle);
	root->right = convert(arr + middle + 1, len - (middle + 1));
	return root;
}
struct node * convert_array_to_bst(int *arr, int len){
	if (arr == NULL)
		return NULL;
	if (is_ascending(arr, len) || is_descending(arr, len))
	{
		return convert(arr, len);
	}
	return NULL;
}
