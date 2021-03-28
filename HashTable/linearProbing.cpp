/*
    Author : Fakhra Najm <fnajm09@gmail.com>
    Topic : Hash Table implementation with Linear probing
*/

#include<bits/stdc++.h>
using namespace std;

class HashMap{
private:
    int size;
    int *Array;
public:
    HashMap(){}
    int hashkey(int val);
    int probe(int val);
    void create(int size);
    void read();
    void update(int val);
    int Delete(int val);
};


int HashMap :: hashkey(int val){
    return val % this -> size;
}

int HashMap :: probe(int val){
    int i = 0;
    int index = hashkey(val);
    while(this -> Array[index] != 0)
        index = (hashkey(val) + i++) % 10;
    return index;
}

void HashMap :: create(int size){

    this -> size = 2 * size + 1;

    Array = new int[this -> size];
    fill(Array + 0, Array + this -> size, 0);

    cout << "Enter " << size << " data: " << endl;

    while(size--){
        int input_value;
        cin >> input_value;
        update(input_value);
    }
}

void HashMap :: read(){
    for(int key = 0; key < this -> size; ++key)
        cout << this -> Array[key] << " ";
    cout << endl;
}

void HashMap :: update(int val){
    int key = hashkey(val);

    if(this -> Array[key] == 0)
        this -> Array[key] = val;
    else this -> Array[probe(val)] = val;
}

int main(){
    HashMap map;
    map.create(10);
    map.read();
    return 0;
}
