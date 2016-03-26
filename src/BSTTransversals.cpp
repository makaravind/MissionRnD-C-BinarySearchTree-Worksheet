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
	struct node *right;
};

void mInorder(struct node *root, int *arr,int *added);
void mPreorder(struct node *root, int *arr, int *added);
void mPostorder(struct node *root, int *arr, int *added);

void inorder(struct node *root, int *arr){

	if (root == NULL || arr == NULL) return;
	int added = 0;
	mInorder(root, arr, &added);
}
void mInorder(struct node *root, int *arr, int *added){


	if (root){
		mInorder(root->left, arr,added);
		arr[*added] = root->data;
		*added = *added + 1;
		mInorder(root->right, arr,added);
	}

}
void preorder(struct node *root, int *arr){
	
	if (root == NULL || arr == NULL) return;
	int added = 0;
	mPreorder(root, arr, &added);
}
void mPreorder(struct node *root, int *arr, int *added){

	if (root){
		arr[*added] = root->data;
		*added = *added + 1;
		mPreorder(root->left, arr, added);
		mPreorder(root->right, arr, added);
	}
}
void postorder(struct node *root, int *arr){
	
	if (root == NULL || arr == NULL) return;
	int added = 0;
	mPostorder(root, arr, &added);
}
void mPostorder(struct node *root, int *arr, int *added){

	if (root){
		mPreorder(root->left, arr, added);
		mPreorder(root->right, arr, added);
		arr[*added] = root->data;
		*added = *added + 1;
	}
}
