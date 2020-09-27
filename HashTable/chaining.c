/*
  * Author: Fakhra Najm<fnajm09@gmail.com>
  * Topic: Hash Table implementation code in c programming language 
  * OPEN HASHING
  * CHAINING
*/

#include<stdio.h>
#include<stdlib.h>
#include"chains.h"


struct Node *Hash[10];

/*
  @param key value of the key
  @return new hash key
*/
int hash(int value){
  return value%10;
}

void Insert(int value){
    int hash_key = hash(value);
    InsertSort(Hash[hash_key],value);
}

struct Node *search(int val){
  int hash_key = hash(val);
  struct Node * hT = searchList(Hash[hash_key], val);
  return hT;
}

int main(){
  for (int i = 0; i < 10; i++)
  {
    Hash[i] = NULL;
  }
  Insert(10);
  Insert(120);
  Insert(12);
  Insert(123);
  Insert(22);
  // struct Node *temp = search(16);
  // printf("%d", temp->data);
  return 0;
}