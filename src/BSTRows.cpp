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
#define MAX 30
struct node{
	struct node * left;
	int data;
	struct node *right;
};
void Enqueue(struct node **q, int *front, int *rear, struct node *ele);
struct node* Dequeue(struct node **q, int *front, int *rear);
int IsEmpty(struct node **q, int *front, int *rear);
int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;

	struct node *queue[MAX];
	for (int i = 0; i < MAX; i++)
		//queue[i] = (struct node*)malloc(sizeof(struct node));
		queue[i] = (struct node*)calloc(1, sizeof(struct node));
	int front = -1;
	int rear = -1;
	int *result = (int*)calloc(MAX, sizeof(int));
	int index = 0;

	if (root)
		Enqueue(queue, &front,&rear,root);
	while (!IsEmpty(queue, &front, &rear))
	{
		struct node* temp = Dequeue(queue,&front,&rear);
		result[index++] = temp->data;
		if (temp->right)
			Enqueue(queue, &front, &rear, temp->right);
		if (temp->left)
			Enqueue(queue, &front, &rear, temp->left);
	}
	return result;
}
void Enqueue(struct node **q, int *front, int *rear, struct node *ele){

	if (*rear == MAX - 1) return;
	else{
		if (*front == -1)
			*front = 0;
		*rear = *rear + 1;
		q[*rear] = ele;
	}

}
struct node* Dequeue(struct node **q, int *front, int *rear){

	struct node* temp = q[*front];
	*front = *front + 1;
	return temp;
}
int IsEmpty(struct node **q, int *front, int *rear){

	if (*front == -1 || *front > *rear)
		return 1;
	return 0;
}