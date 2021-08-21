#include<iostream>
#include <queue>
using namespace std;

class BinaryTree{

	class TreeNode{
	public:
		int val;
		TreeNode *left;
		TreeNode *right;
	};


public:

	TreeNode *root;

	BinaryTree();

	void preorder(TreeNode *root);
	void inorder(TreeNode *root);
	void postorder(TreeNode *root);
	void levelorder();
	
	TreeNode *getRoot(){return root;}
	int getHeight(TreeNode *root);
	int getTotalNodes(TreeNode *root);
	int getTotalLeafNodes(TreeNode *root);
	int getSingleDegreeNodes(TreeNode *root);
	int getSecondDegreeNodes(TreeNode *root);
	int getNonLeafNodes(TreeNode *root);

	friend void inorderTraversal(TreeNode *root);
};

int main(){

	BinaryTree binarytree;
	cout << "Tree created ! " << endl;
	cout << "inorder : ";
	binarytree.inorder(binarytree.getRoot());
	cout << endl;
	cout << "preorder : ";
	binarytree.preorder(binarytree.getRoot());
	cout << endl;
	cout << "postorder : ";
	binarytree.postorder(binarytree.getRoot());
	cout << endl;
	cout << "levelorder : ";
	binarytree.levelorder();
	cout << endl;
	cout << "getHeight : " ;
	cout << binarytree.getHeight(binarytree.getRoot());
	cout << endl;
	cout << "Total Nodes : " ;
	cout << binarytree.getTotalNodes(binarytree.getRoot());
	cout << endl;
	cout << "Total Leaf Nodes : " ;
	cout << binarytree.getTotalLeafNodes(binarytree.getRoot());
	cout << endl;
	cout << "One degree Nodes : " ;
	cout << binarytree.getSingleDegreeNodes(binarytree.getRoot());
	cout << endl;
	cout << "second degree Nodes : " ;
	cout << binarytree.getSecondDegreeNodes(binarytree.getRoot());
	cout << endl;
	cout << "Non Leaf Nodes : " ;
	cout << binarytree.getNonLeafNodes(binarytree.getRoot());
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

void BinaryTree :: inorder(TreeNode *root){
	if(!root) return;
	inorder(root -> left);
	cout << root -> val << " ";
	inorder(root -> right); 
}

void BinaryTree :: postorder(TreeNode *root){
	if(!root) return;
	postorder(root -> left);
	postorder(root -> right); 
	cout << root -> val << " ";
}

void BinaryTree :: preorder(TreeNode *root){
	if(!root) return;
	cout << root -> val << " ";
	preorder(root -> left);
	preorder(root -> right); 
}

void BinaryTree :: levelorder(){
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

int BinaryTree :: getHeight(TreeNode *root){
	if(!root || (!root -> left && !root -> right)) return 0;
	return max(getHeight(root -> left), getHeight(root -> right)) + 1;
}

int BinaryTree :: getTotalNodes(TreeNode *root){
	if(!root) return 0;
	return getTotalNodes(root -> left) + getTotalNodes(root -> right) + 1;
}

int BinaryTree :: getTotalLeafNodes(TreeNode *root){
	if(!root) return 0;
	if(!root -> left && !root -> right) return 1;
	return getTotalLeafNodes(root -> left) + getTotalLeafNodes(root -> right);
}

int BinaryTree :: getSingleDegreeNodes(TreeNode *root ){
	if(!root || (!root -> left && !root -> right)) return 0;
	if(!root -> left || !root -> right) return 1;
	return getSingleDegreeNodes(root -> left) + getSingleDegreeNodes(root -> right);
}

int BinaryTree :: getSecondDegreeNodes(TreeNode *root){
	if(!root) return 0;
	if(root -> left && root -> right) 
		return getSecondDegreeNodes(root -> left) + getSecondDegreeNodes(root -> right) + 1;
	return getSecondDegreeNodes(root -> left) + getSecondDegreeNodes(root -> right);
}

int BinaryTree :: getNonLeafNodes(TreeNode *root){
	if(!root || (!root -> left && !root -> right)) return 0;

	if(root -> left || root -> right)
		return getNonLeafNodes(root -> left ) + getNonLeafNodes(root -> right) + 1;
	return getNonLeafNodes(root -> left ) + getNonLeafNodes(root -> right);
}

#endif