/*

	* Author : Fakhra Najm <fnajm09@gmail.com>
	* Topic  : Morris Algorithm for preorder traversal

*/


#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void createTree(struct Node *root){
	struct Node *holder;
	int value;
	struct Queue q;
	createQ(&q,100);
	printf("Enter root value : ");
	scanf("%d", &value);
	root = (struct Node *)malloc(sizeof(struct Node));
	root->data = value;
	root->left_child = root->right_child = NULL;
	enqueue(&q, root);

	while(! isEmpty(q)){
		struct Node *node;
		holder = dequeue(&q);
		printf("Enter left child of %d : ", holder->data);
		scanf("%d", &value); 
		if( value != -1){
			node = (struct Node *)malloc(sizeof(struct Node));
			node->data = value;
			node->left_child = node->right_child = NULL;
			holder->left_child = node;
			enqueue(&q, node);
		}
		printf("Enter right child of %d : ", holder->data);
		scanf("%d", &value); 
		if( value != -1){
			node = (struct Node *)malloc(sizeof(struct Node));
			node->data = value;
			node->left_child = node->right_child = NULL;
			holder->right_child = node;
			enqueue(&q, node);
		}
	}
}

struct Node * predecessor(struct Node *root){
	root = root->left_child;
	while(root->right_child) root = root->right_child;
	return root;
}

void morrisInorder(struct Node * root){
	printf("Entered into morrisInorder\n");
	struct Node *curr = root;
	if( !curr) printf("Stack overflow\n");
	while(curr){
		printf("Entered into while loop\n");
		if(! curr){
			printf("Entered into !curr\n");
			printf("%d ", curr->data);
			curr = root->right_child;
		}

		else {
			printf("Entered into else condition\n");
			struct Node *pre = predecessor(root);
			if(! pre->right_child){
				printf("Entered into ! pre->right\n");
				pre->right_child = curr;
				curr = curr->left_child;
			}
			else{
				printf("Entered into pre->right_child\n");
				pre->right_child = NULL;
				printf("%d ", curr->data);
				curr = curr->right_child;
			}
		}
	}
}

int main(){
	struct Node *root ;
	createTree(root);
	printf("Morris Inorder traversal:\n");
	morrisInorder(root);
	printf("\n");
	return 0;
}