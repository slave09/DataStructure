/*
    Author : Fakhra Najm <fnajm09@gmail.com>
    Topic : Hash Table implementation with Linear probing

    * Operations:
	* create
	* read
	* update
	* Delete
	* probe
	* hashkey
*/

#include<bits/stdc++.h>
using namespace std;

class HashMap{
private:
  int size;
  int *Array;
public:
  HashMap(int size);
  int hashkey(int val);
  int probe(int val);
  void create();
  void read();
  void update(int val);
  void Delete(int val);
  int search(int val);
};

HashMap :: HashMap(int size = 0){
  this -> size = 2 * size;
  Array = new int[this -> size];
  fill(Array + 0, Array + this -> size, 0);
  create();
}

int HashMap :: hashkey(int val){
  return val % size ;
}

// h'(x) = (h(x) + f(i)) % size 
// where f(i) = i 
// i = 0,1,2,3,4,...

int HashMap :: probe(int val){
  int i = 0;
  int index = hashkey(val);
  while(Array[index] != 0)
    index = (hashkey(val) + i++) % (size);
  return index;
}

void HashMap :: create(){
  cout << "Enter Values:" << endl;
  int size = this -> size / 2;
  while(size--){
    int input_value;
    cin >> input_value;
    update(input_value);
  }
}

void HashMap :: read(){
  for(int key = 0; key < size; ++key)
    cout << Array[key] << " ";
  cout << endl;
}

void HashMap :: update(int val){
  int key = hashkey(val);
  if(Array[key] == 0)
    Array[key] = val;
  else Array[probe(val)] = val;
}

void HashMap :: Delete(int val){
  int key = hashkey(val);
  if(Array[key] == val) Array[key] = 0;
  else{
    int i = 0;
    while(Array[key] != val){
      if(Array[key] == 0) return ;
      key = (hashkey(val), ++i) % size;
    }
  }
  Array[key] = 0;
  return ;
}

int HashMap :: search(int val){
  int key = hashkey(val);
  if(Array[key] == val) return key;
  else{
    int i = 0;
    while(Array[key] != val){
      if(Array[key] == 0) return -1;
      key = (hashkey(val) + ++i) % size;
    }
  }
  return key;
}

int main(){
  int val;
  HashMap map(10);
  map.read();
  cout << "Enter Value to delete : ";
  cin >> val;
  map.Delete(val);
  map.read();
  return 0;
}
