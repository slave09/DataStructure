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

	TreeNode * insertNode(TreeNode *root, int val);
	TreeNode * deleteNode(TreeNode *root, int val);
	TreeNode * inorderPredecessor(TreeNode *root);
	TreeNode * inorderSuccessor(TreeNode *root);

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


vector<int>values;
int val;

void getInput(){
	values.clear();
	int nodes;
	cout << "Enter number of nodes : ";
	cin >> nodes;
	while(nodes--){
		int val;
		cin >> val;
		values.push_back(val);
	}
}

int main(){
	getInput();
	AVL tree(values);
	cout << "Root : " << tree.getRoot() -> val << endl;
	tree.printInorder(tree.getRoot());
	cout << endl;
	cout << "Enter value to delete : ";
	cin >> val;
	tree.deleteNode(tree.getRoot(), val);
	tree.printInorder(tree.getRoot());
	cout << endl;
	cout << "Balance factor of root after deletion : ";
	cout << tree.getBalanceFactor(tree.getRoot()) << endl;
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

TreeNode * AVL :: deleteNode(TreeNode *root, int val){
	if(!root) return root;
	if(!root -> left && !root -> right && val == root -> val){
		if(root == this -> root) this -> root = NULL;
		delete(root);
		return NULL;
	}
	if(root -> val > val) 
		root -> left = deleteNode(root -> left, val);
	else if(root -> val < val)
		root -> right = deleteNode(root -> right, val);
	else{
		int leftSubHeight = getHeight(root -> left);
		int rightSubHeight = getHeight(root -> right);

		if(leftSubHeight > rightSubHeight){
			TreeNode* predecessor = inorderPredecessor(root -> left);
			root -> val = predecessor -> val;
			root -> left = deleteNode(root -> left, predecessor -> val);
		}
		else{
			TreeNode* successor = inorderSuccessor(root -> right);
			root -> val = successor -> val;
			root -> right = deleteNode(root -> right, successor -> val);
		}
	}
	root = rotate(root, getBalanceFactor(root));
	return root;
}

int AVL :: getHeight(TreeNode *root){
	if(!root) return 0;
	// if(!root -> left && !root -> right) return 1;
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
	cout << root -> val << " " << getBalanceFactor(root) << endl;
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

TreeNode * AVL :: inorderPredecessor(TreeNode *root){
	while(root && root -> right)
		root = root -> right;
	return root;	
}

TreeNode * AVL :: inorderSuccessor(TreeNode *root){
	while(root && root -> left)
		root = root -> left;
	return root;	
}