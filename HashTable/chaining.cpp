#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int val, Node *next);
};

Node :: Node(int val, Node *next){
	this -> data = val;
	this -> next = next;
}

class HashTable{
public:
	Node** HashArray;
	HashTable();
	int hash(int key);
	void Insert(int key);
	int Search(int key);
	~HashTable();
};

HashTable :: HashTable() {
	HashArray = new Node*[10];
	for (int index = 0; index < 10; index++){
		HashArray[index] = nullptr;
	}
}

int HashTable::hash(int key) {
	return key % 10;
}

void HashTable::Insert(int key) {
	int hashKey = hash(key);
	Node* node = new Node(key, nullptr);
	// Case: No nodes in the linked list
	if(HashArray[hashKey] == nullptr){
		HashArray[hashKey] = node;
	} 
	else {
		Node *currNodeItr = HashArray[hashKey];
		Node *lastNodeItr = HashArray[hashKey];
		// Traverse to find insert position
		while (currNodeItr && currNodeItr -> data < key){
			lastNodeItr = currNodeItr;
			currNodeItr = currNodeItr -> next;
		}
		// Case: insert position is first
		if(lastNodeItr == HashArray[hashKey]){
			node -> next = HashArray[hashKey];
			HashArray[hashKey] = node;
		} 
		else {
			node -> next = lastNodeItr -> next;
			lastNodeItr -> next = node;
		}
	}
}

int HashTable::Search(int key) {
	int hashKey = hash(key);
	Node* currNodeItr = HashArray[hashKey];
	while (currNodeItr){
		if (currNodeItr -> data == key){
			return currNodeItr -> data;
		}
		currNodeItr = currNodeItr -> next;
	}
	return -1;
}

HashTable::~HashTable() {
	for (int index = 0; index < 10; index++){
		Node* currNodeItr = HashArray[index];
		while (HashArray[index]){
			HashArray[index] = HashArray[index] -> next;
			delete currNodeItr;
			currNodeItr = HashArray[index];
		}
	}
	delete []HashArray;
}

int main() {
	int key, value;
	int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int size = sizeof(A)/sizeof(A[0]);
	HashTable map;
	for (int index = 0; index < size; index++){
		map.Insert(A[index]);
	}
	key = 6;
	value = map.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	key = 95;
	value = map.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	return 0;
}