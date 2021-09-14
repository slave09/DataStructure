/*
	* Topic : Generation of Binary Search Tree from
	* 1. Preorder
	* 2. Postorder
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class BSTNode{
public:
	int val;
	BSTNode *left;
	BSTNode *right;
	BSTNode(int val){this -> val = val;}
	~BSTNode(){}
};

class BST{
	BSTNode *root = NULL;
public:
	BST(){}
	void generateBstFromPreorder(vector<int>preorder);
	void generateBstFromPostorder(vector<int>postorder);
	BSTNode * getRootNode(){return this -> root;}
	void printInorderTraversal(BSTNode *root);
	~BST();
};

int main(){
	BST pre;
	BST post;
	pre.generateBstFromPreorder({10,5,3,4,8,7,9,15,12,18,17,22});
	pre.printInorderTraversal(pre.getRootNode());
	cout << endl;
	post.generateBstFromPostorder({4,3,7,8,9,5,12,17,22,18,15,10});
	post.printInorderTraversal(post.getRootNode());
	return 0;
}

BST :: ~BST(){
	delete root;
}

void BST :: printInorderTraversal(BSTNode *root){
	if(!root) return;
	printInorderTraversal(root -> left);
	cout << root -> val << " ";
	printInorderTraversal(root -> right);
}

void BST :: generateBstFromPreorder(vector<int>preorder){
	stack<BSTNode*>nodes;
	BSTNode *root = new BSTNode(preorder[0]);
	this -> root = root;
	int preorderItr = 1;
	while(preorderItr < preorder.size()){
		if(preorder[preorderItr] < root -> val){
			root -> left = new BSTNode(preorder[preorderItr++]);
			nodes.push(root);
			root = root -> left;
		}
		else if(root -> val < preorder[preorderItr] && 
			(nodes.empty() || preorder[preorderItr] < nodes.top() -> val)){
			root -> right = new BSTNode(preorder[preorderItr++]);
			root = root -> right;
		}
		else{
			root = nodes.top();
			nodes.pop();
		}
	}
}

void BST :: generateBstFromPostorder(vector<int>postorder){
	stack<BSTNode*>nodes;
	int index = postorder.size() - 1;
	BSTNode *root = new BSTNode(postorder[index--]);
	this -> root = root;

	while(index >= 0){
		if(root -> val < postorder[index]){
			root -> right = new BSTNode(postorder[index--]);
			nodes.push(root);
			root = root -> right;
		}
		else if(postorder[index] < root -> val 
			&& (nodes.empty() || postorder[index] > nodes.top() -> val)){
			root -> left = new BSTNode(postorder[index--]);
			root = root -> left;
		}
		else{
			root = nodes.top();
			nodes.pop();
		}
	}
}
