/*
	* Topic : Iterative binary tree traversal
		1. Inorder
		2. Preorder
		3. Postorder
		4. Leveloreder
		5. PostOrder using one stack
*/

#include<iostream>
#include <queue>
#include <stack>
using namespace std;

class BinaryTree{

	class TreeNode{
	public:
		int val;
		TreeNode *left;
		TreeNode *right;
	};
	TreeNode *root;
public:

	BinaryTree();
	
	TreeNode *getRoot(){return root;}

	void inorderTraversal(TreeNode *root);
	void preorderTraversal(TreeNode *root);
	void postorderTraversal(TreeNode *root);
	void levelorderTraversal(TreeNode *root);
	void postorder(TreeNode *root);

};

int main(){
	BinaryTree tree;
	tree.postorder(tree.getRoot());
	return 0;
}

BinaryTree :: BinaryTree(){
	queue<TreeNode *>TreeNodes;
	int value;
	root = new TreeNode;

	cout << "Enter value of root";
	cin >> value;

	root -> val = value;
	TreeNodes.push(root);

	while(!TreeNodes.empty()){
		int left_value, right_value;
		TreeNode *currNode = TreeNodes.front();
		TreeNodes.pop();

		cout << "Enter Left child of " << currNode -> val << " : "  << endl;
		cin >> left_value;
		cout << "Enter Right child of " << currNode -> val << " : "  << endl;
		cin >> right_value;

		if(left_value != -1){
			TreeNode *curr = new TreeNode;
			curr -> val = left_value;
			currNode -> left  = curr;
			currNode -> right = NULL;
			TreeNodes.push(curr);
		}

		if(right_value != -1){
			TreeNode *curr = new TreeNode;
			curr -> val = right_value;
			if(!currNode->left) currNode -> left = NULL;
			currNode -> right = curr;
			TreeNodes.push(curr);	
		}
	}
}

/* Recursive Inorder Traversal

	1. if root is Not NULL
		push into stack
		move to root's Left
	2. else 
		move to top's right
		print top
		pop top
*/ 

void BinaryTree :: inorderTraversal(TreeNode *root){
	stack<TreeNode *>nodes;

	if(!root ) return;

	nodes.push(root);
	root = root -> left;

	while(!nodes.empty() || root){
		if(root){
			nodes.push(root);
			root = root -> left;
		}
		else{
			root = nodes.top() -> right;
			cout << nodes.top() -> val << " ";
			nodes.pop();
		}
	}
}

void BinaryTree :: preorderTraversal(TreeNode *root){
	stack<TreeNode *>nodes;

	if(! root) return;

	cout << root -> val << " ";
	nodes.push(root);
	root = root -> left;

	while(!nodes.empty() || root){
		if(root){
			cout << root -> val;
			nodes.push(root);
			root = root -> left;
		}
		else{
			root = nodes.top() -> right;
			nodes.pop();
		}
	}
} 

void BinaryTree :: levelorderTraversal(TreeNode *root){
	queue<TreeNode*>nodes;

	nodes.push(root);

	while(!nodes.empty()){
		
		TreeNode *curr = nodes.front();
		nodes.pop();

		if(curr){
			cout << curr -> val << " ";
			nodes.push(curr -> left);
			nodes.push(curr -> right);
		}

	}
}

void BinaryTree :: postorderTraversal(TreeNode *root){
	stack<TreeNode *>childeren;
	stack<TreeNode *>nodes;

	childeren.push(root);

	while(!childeren.empty()){
		TreeNode *node = childeren.top();
		childeren.pop();
		nodes.push(node);
		if(node -> left) childeren.push(node -> left);
		if(node -> right) childeren.push(node -> right);
	}

	while(!nodes.empty()){
		cout << nodes.top() -> val << " ";
		nodes.pop();
	}

	cout << endl;
}

void BinaryTree :: postorder(TreeNode *root){
	if(!root) return;
	
	stack<TreeNode *>nodes;

	nodes.push(root);
	root = root -> left;

	while(!nodes.empty() || root){
		if(root){
			nodes.push(root);
			root = root -> left;
		}
		else{
			root = nodes.top() -> right;
			if(!root){
				TreeNode *last_visited_node = root;
				while(!nodes.empty() && nodes.top() -> right == last_visited_node){
					last_visited_node = nodes.top();
					nodes.pop();
					cout << last_visited_node -> val << " ";
				}
			}
		}
	}
}