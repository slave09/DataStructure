/*
	* Author: Fakhra Najm<fnajm09@gmail.com>
	* Topic: Hashing Technique
	* Linear Probing
*/

#include<stdio.h>
#include<stdlib.h>

int size;  // The size of the Hash Table

/*
	* Creates an index where the value is supposed to be inserted
	* @param key the value to be inserted in hash Table
	* @return index of the hashTable where value is to be inserted 
*/
int hash(int key){
	return key%size;
}

/*
	* Check for collision of index inside a Hash Table
	* @param Hash pointer to the Hash Table
	* @param index where to check the presence or absence of key
*/
int ifCollision(int *Hash, int index){
	if(Hash[index] != 0) return 1;
	return 0;
}

/*
	* returns an index which is free to store key
	* @param Hash pointer to the Hash Table
	* @param index equal to the value of the key
	* @return index the free index of the Hash Table 
*/

int probe(int *Hash, int index){
	index = hash(index);
	while(ifCollision(Hash,index)){
		static int i = 0;
		index = (index + i++) % size ;
	}
	return index;
}
/*
	* Inserts value into the Hash Table
	* @param Hash pointer to the Hash Table
	* @param key value to be inserted
*/
void insert(int *Hash, int key){
	int hash_key = probe(Hash, key);
	Hash[hash_key] = key;
}

/*
	* Searches the given key value
	* @param Hash pointer to the Hash Table
	* @param key value to be searched
	* @return search_key where the value is found
*/
int search(int * Hash, int key){
	int search_key = hash(key);
	while(Hash[search_key] != key && Hash[search_key] != 0){
		static int i = 0;
		search_key = ( search_key + i++ ) % size; 
	}
	return search_key;
}

int main(){
	int *Hash;
	printf("Enter size of HashTable:");
	scanf("%d", &size);
	printf("You are allowed to put only %d elements\n", size/2);
	Hash = (int *)malloc(size*sizeof(int));
	insert(Hash, 15);
	insert(Hash, 25);
	insert(Hash, 13);
	insert(Hash, 12);
	insert(Hash, 14);
	insert(Hash, 34);
	printf("key is found at index %d\n",search(Hash, 15));
	printf("key is found at index %d\n",search(Hash, 13));
	printf("key is found at index %d\n",search(Hash, 10));
	printf("key is found at index %d\n",search(Hash, 25));
	return 0;
}
