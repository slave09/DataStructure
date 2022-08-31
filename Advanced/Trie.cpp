/*
	* Author : Fakhra Najm <fnajm09@gmail.com>
	* Topic : Implementation of Trie Datastructure
	* A Trie is a special data structure used to store strings that can be visualized like a graph.
	* They are used to represent the “Retrieval” of data and thus the name Trie. 
	* Application - String Processing
		- Search Engine
		- Gnome analysis
		- Data Analytics
*/

#include<bits/stdc++.h>
using namespace std;

class Trie{
	map<char, Trie *> next = {};
	bool isWord = false;

public:
	
	void update(string word){
		Trie *node = this;
		for(auto letter : word){
			if(!node -> next[letter]) node -> next[letter] = new Trie();
			node = node -> next[letter];
		}
		node -> isWord = true;
	}

	bool read(string word){
		Trie *node = this;

		for(auto letter : word){
			if(!node -> next[letter]) return false;
			node = node -> next[letter];
		}
		return node -> isWord;
	}

	bool isPrefix(string prefix){
		Trie *node = this;
		for(auto letter : prefix){
			if(!node -> next[letter]) return false;
			node = node -> next[letter];
		}
		return true;
	}
};

int main(){
	Trie trie;
	string word, prefix, search;
	cout << "Enter String : " << endl;
	cin >> word;
	trie.update(word);
	cout << "Enter Prefix : " << endl;
	cin >> prefix;
	if(trie.isPrefix(prefix)) cout << "Prefix found" << endl;
	else cout << "Prefix Not Found " << endl;
	cout << "Enter word to search : " << endl;
	cin >> search;
	if(trie.read(search)) cout << "Word found" << endl;
	else cout << "Word Not Found " << endl;
	
	return 0;
}