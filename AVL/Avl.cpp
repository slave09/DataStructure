#include<iostream>
#include <vector>
#include<queue>
using namespace std;

class TreeNode{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val){this -> val = val;}
};

class AVL{
	TreeNode *root;
public:
	AVL(vector<int>values);
	TreeNode *getRoot(){return this -> root;}
	TreeNode *createNode(int val){return new TreeNode(val);}

	int getHeight(TreeNode *root);
	int getBalanceFactor(TreeNode *root);

	TreeNode * insertNode(TreeNode *root,int val);
	TreeNode * rotate(TreeNode *root, int balanceFactor);
	TreeNode * LL_Rotation(TreeNode *root);
	TreeNode * RR_Rotation(TreeNode *root);
	TreeNode * LR_Rotation(TreeNode *root);
	TreeNode * RL_Rotation(TreeNode *root);

	void levelorderTraversal(TreeNode *root);
	void printPreorder(TreeNode *root);
	void printInorder(TreeNode *root);

	~AVL(){delete root;}
};

int main(){
	AVL tree({1,2,3,4,5,6,15,23,11,3,2,33,16});
	cout << tree.getBalanceFactor(tree.getRoot()) << endl;
	tree.printInorder(tree.getRoot());
	cout << endl;
	tree.printPreorder(tree.getRoot());
	return 0;
}

AVL :: AVL(vector<int>values){
	int index = 0;
	this -> root = insertNode(NULL,values[index++]);
	while(index < values.size()){
		insertNode(this -> root, values[index++]);
	}
}

TreeNode* AVL :: insertNode(TreeNode *root, int val){
	if(!root) return createNode(val);
	if(root -> val == val) return root;
	if(root -> val > val) 
		root -> left = insertNode(root -> left, val);
	else root -> right = insertNode(root -> right, val);
	int balanceFactor = getBalanceFactor(root);
	root = rotate(root,balanceFactor);
	return root;
}

int AVL :: getHeight(TreeNode *root){
	if(!root) return 0;
	if(!root -> left && !root -> right) return 0;
	return max(getHeight(root -> left), getHeight(root -> right)) + 1;
}

int AVL :: getBalanceFactor(TreeNode *root){
	return getHeight(root -> left) - getHeight(root -> right);
}

TreeNode * AVL :: rotate(TreeNode *root, int balanceFactor){
	if(balanceFactor == 2){
		if(getBalanceFactor(root -> left) < 0)
			return LR_Rotation(root);
		return LL_Rotation(root);
	}
	else if(balanceFactor == -2){
		if(getBalanceFactor(root -> right) < 0)
			return RR_Rotation(root);
		return RL_Rotation(root);
	}
	return root;
}

TreeNode * AVL :: LL_Rotation(TreeNode *root){
	TreeNode *rootLeft = root -> left;
	root -> left = rootLeft -> right;
	rootLeft -> right = root;
	if(root == this -> root) this -> root = rootLeft;
	return rootLeft;
}

TreeNode * AVL :: RR_Rotation(TreeNode *root){
	TreeNode *right = root -> right;
	root -> right = right -> left;
	right -> left = root;
	if(root == this -> root) this -> root = right;
	return right;
}

TreeNode * AVL :: LR_Rotation(TreeNode *root){
	root -> left = RR_Rotation(root -> left);
	return LL_Rotation(root);
}

TreeNode * AVL :: RL_Rotation(TreeNode *root){
	root -> right = LL_Rotation(root -> left);
	return RR_Rotation(root);
}

void AVL :: printInorder(TreeNode *root){
	if(!root) return;
	printInorder(root -> left);
	cout << root -> val << " ";
	printInorder(root -> right);
}

void AVL :: printPreorder(TreeNode *root){
	if(!root) return;
	cout << root -> val << " ";
	printPreorder(root -> left);
	printPreorder(root -> right);
}
void AVL :: levelorderTraversal(TreeNode *root){
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