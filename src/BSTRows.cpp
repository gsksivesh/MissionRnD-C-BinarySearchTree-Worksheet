/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};



void height(struct node * root, int *arr, int *arr_index, int level, int max_height)
{
	if (root == NULL)
	{
		return;
	}
	if (level == max_height)
	{
		arr[*arr_index] = root->data;
		(*arr_index)++;
		return;
	}
	height(root->right, arr, arr_index, level + 1, max_height);
	height(root->left, arr, arr_index, level + 1, max_height);
}

int* BSTRighttoLeftRows(struct node* root)
{
	int *arr;
	int arr_index = 0, i, temp;
	if (root == NULL)
		return NULL;
	arr = (int*)malloc(sizeof(int)*100);
	for (i = 1;; i++)
	{
		temp = arr_index;
		height(root, arr, &arr_index, 1, i);
		if (temp == arr_index)
			break;
	}
	return arr;
}