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
struct node* buildBST(int *arr,int left, int right);
struct node * convert_array_to_bst(int *arr, int len){
	
	//init checking
	if (arr == NULL || len <= 0) return NULL;

	struct node * result =  buildBST(arr, 0, len);
	return result;
}
struct node* buildBST(int *arr,int left, int right){

	if (left > right) return NULL;
	
	struct node * newnode = (struct node*)malloc(sizeof(struct node));
	int mid;
	if (left == right){
		newnode->data = arr[left];
		newnode->left = NULL;
		newnode->right = NULL;
	}
	else{
		mid = left + (right - left) / 2;
		newnode->data = arr[mid];
		newnode->left = buildBST(arr, left, mid - 1);
		newnode->right = buildBST(arr, mid + 1, right);
	}
	return newnode;
}
