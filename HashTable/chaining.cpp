#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
};

class List{
	ListNode *head;
public:
	List(){head = NULL;}
	List(int value);
	~List();

	List update(ListNode *head, int value){
		ListNode *curr = head;
		while(curr && curr -> next -> val < value) 
			curr = curr -> next;
		ListNode *node ;
		node -> val = value;
		node -> next = curr -> next ;
		curr -> next = node;
		return head;
	}
};

List :: List(int value){
	ListNode *node;
	node -> val = value;
	node -> next = NULL;
	head = node;
}

List :: ~List(){
	ListNode *curr = head;
	while(curr){
		head = head -> next ;
		delete curr;
		curr = head;
	}
}

class HashTable{
public:
	int *hashtable;
	int size;
	HashTable(){hashtable = new int[0];}
	HashTable(vector<int> values, int size);
	~HashTable();
	int read(int value);
	int hash(int value){
		return value % 10;
	}
};

HashTable :: HashTable(vector<int> values, int size){
	hashtable = new int[size];
	for(auto vect : values){
		int index = hash(vect);
		hashtable[index] = i;
	}
}
int main(){
	return 0;
}