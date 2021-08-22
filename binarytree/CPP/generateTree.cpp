/*
	Topic : generating tree from preorder and inorder traversals
	Link : "https://ideone.com/GD10kh"
*/

#include <iostream>
#include<queue>
#include <stack>
using namespace std;

class TreeNode{
	public :
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode();
	TreeNode(int val){this -> val = val;}

	~TreeNode();
};


class Tree{
	TreeNode *root;
public:

	Tree(){this -> root = NULL;}
	TreeNode * getRoot(){return root;}
	int search(int arr[], int begin, int end, int val);
	TreeNode * generateTreeFromTraversal(int inorder[], int preorder[], int begin, int end);
	void preorder(TreeNode *root);
	~Tree(){};

};


int Tree :: search(int arr[], int begin, int end, int val){
	for(int i = begin; i <= end; ++i){
		if(arr[i] == val) return i;
	}
	return -1;
}

TreeNode * Tree :: generateTreeFromTraversal(int inorder[], int preorder[], int begin, int end){
	static int index = 0;

	if(index > end || begin > end) return NULL;

	TreeNode *node = new TreeNode(preorder[index++]);

	if(begin == end) return node;

	int splitIndex = search(inorder, begin, end, node -> val);
	node -> left = generateTreeFromTraversal(inorder, preorder, begin, splitIndex - 1);
	node -> right = generateTreeFromTraversal(inorder, preorder, splitIndex + 1, end);

	return node;
}


void Tree :: preorder(TreeNode *root){
	if(!root) return;
	cout << root -> val << " "; 
	preorder(root -> left);
	preorder(root -> right);
}

int main(){
	int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
	int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
	Tree binarytree;
	TreeNode *root = binarytree.generateTreeFromTraversal(inorder, preorder, 0, 8);
	binarytree.preorder(root);
	cout << endl;
	return 0;
}