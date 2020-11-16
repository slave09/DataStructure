/*
  * Author: Fakhra Najm<fnajm09@gmail.com>
  * Topic: Hash Table implementation code in c programming language 
  * OPEN HASHING
  * CHAINING
*/

#include<stdio.h>
#include"chains.h"


void printChain(struct Node *head){
  while(head){
    printf("%d\n",head->data );
    head = head->next;
  }
}

/*
  * @param key value of the key
  * @return new hash key
*/
int hash(int value){
  return value%10;
}
/*
  * @param value the value to be inserted
  * Insert function to insert values into the HashTable
*/
void Insert(struct Node *Hash[], int value){
  int hash_key = hash(value);
  InsertSort(Hash[hash_key],value);
  printChain(Hash[hash_key]);
}
/*
  * @param value the value to be searched
  * @return hT returns the pointer to the index of hashtable
*/
struct Node *search(struct Node *Hash[], int val){
  int hash_key = hash(val);
  struct Node * hT = searchList(Hash[hash_key], val);
  return hT;
}

int main(){
  struct Node *Hash[10];
  for(int i = 0; i < 10; i++) Hash[i] = NULL;
  Insert(Hash, 10);
  Insert(Hash, 120);
  Insert(Hash, 12);
  Insert(Hash, 123);
  Insert(Hash, 22);
  // struct Node *temp = search(16);
  // printf("%d", temp->data);
  return 0;
}