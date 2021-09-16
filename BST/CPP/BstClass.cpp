#include<iostream>
#include <vector>
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
public:
	BSTNode *root = NULL;
	BST();

	int getNodeVal(BSTNode *node){return node -> val;}
	int height(BSTNode *root);
	BSTNode * getRootNode(){return this -> root;}
	BSTNode *inorderSuccessor(BSTNode *root);
	BSTNode *inorderPredecessor(BSTNode *root);

	void createBST();
	BSTNode* insertNode(BSTNode *root, int val);

	BSTNode* deleteNode(BSTNode*root, int val);
	int searchNode(BSTNode *root, int val);
	void printInorderTraversal(BSTNode *root);

	~BST();
};

int main(){
	BST bst;
	cout << "Inorder : ";
	BSTNode *rootNode = bst.getRootNode();
	bst.printInorderTraversal(rootNode);
	cout << endl;
	int val;
	cout << "Enter value to find : ";
	cin >> val;
	if(bst.searchNode(rootNode,val) == 0)
		cout << "Found" << endl;
	else cout << "Not Found" << endl;
	cout << "Enter value to delete : ";
	cin >> val;
	bst.deleteNode(rootNode, val);
	bst.printInorderTraversal(bst.getRootNode());
	return 0;
}

BST :: BST (){
	createBST();
}

BST :: ~BST(){
	delete root;
}

BSTNode* BST :: insertNode(BSTNode *root, int val){
	if(!root){
		return new BSTNode(val);
	}
	if(root -> val > val) 
		root -> left = insertNode(root -> left, val);
	else if(root -> val < val) 
		root -> right = insertNode(root -> right, val);
	return root;
}

void BST :: createBST(){
	int totalNodes, val;
	cout << "Enter Total number of Nodes : " ;
	cin >> totalNodes;
	cout << "Enter -1 for null nodes" << endl;
	while(totalNodes--){
		cout << "Enter Values : " << endl;
		cin >> val;
		if(val != -1){
			if(!this -> root) 
				this -> root = insertNode(root, val);
			else insertNode(root, val);
		}
	}
}

void BST :: printInorderTraversal(BSTNode *root){
	if(!root) return;
	printInorderTraversal(root -> left);
	cout << root -> val << " ";
	printInorderTraversal(root -> right);
}

int BST :: searchNode(BSTNode *root, int val){
	if(root){
		if(root -> val == val) return 0;
		else if(root -> val > val) return searchNode(root -> left, val);
		else return searchNode(root -> right, val);
	}
	return 1;
}

BSTNode * BST :: deleteNode(BSTNode *root, int val){
	if(!root) return root;

	if(!root -> left && !root -> right && root -> val == val){
		if(root == this -> root) root = NULL;
		delete root;
		return NULL;
	}
	if(root -> val > val)
		root -> left = deleteNode(root -> left, val);
	else if(root -> val < val)
		root -> right = deleteNode(root -> right, val);
	else{
		int leftSubHeight = height(root -> left);
		int rightSubHeight = height(root -> right);

		if(leftSubHeight > rightSubHeight){
			BSTNode *predecessor = inorderPredecessor(root -> left);
			root -> val = predecessor -> val;
			root -> left = deleteNode(root -> left, predecessor -> val);
		}
		else{
			BSTNode *successor = inorderSuccessor(root -> right);
			root -> val = successor -> val;
			root -> right = deleteNode(root -> right, successor -> val);
		}
	}

	return root;
}

int BST :: height(BSTNode *root){
	if(!root || (!root -> left && !root -> right)) return 0;
	return max(height(root -> left), height(root -> right)) + 1;
}

BSTNode * BST :: inorderSuccessor(BSTNode *root){
	while(root && root -> left)
		root = root -> left;
	return root;
}

BSTNode * BST :: inorderPredecessor(BSTNode *root){
	while(root && root -> right)
		root = root -> right;
	return root;
}