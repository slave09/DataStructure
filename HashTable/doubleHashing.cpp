#include<iostream>
using namespace std;

class HashMap{

private:
	int size;
	int doubleKey ;
	int * Array;

public:
	HashMap(){}
	void create();
	void read();
	void update(int val);
	void Delete(int val);
	int find(int val);
	int first_hash(int val);
	int second_hash(int val);
	int doubleHashing(int val);
};

bool isPrime(int val){

	if (val <= 1) return false;

	for (int factor = 2; factor < val; factor++)
		if (val % factor == 0) return false;

	return true;
}

void HashMap :: create(){
	int size, doubleKey;

	cout << "Enter number of data items: ";
	cin >> size;

	this -> size = 2 * size ;

	cout << "size of Hash Table is " << this -> size << endl;

	this -> Array = new int[this -> size]; 

	for(int key = 0; key < this -> size; ++key)
		Array[key] = 0;

	for(int key = this -> size; key >= 0; --key){
		if(isPrime(key)){
			this -> doubleKey = key;
			break;
		}
	}

	// cout << "DEBUG : doublekey : " <<  this -> doubleKey << endl;

	cout << "Enter " << size << " data elements : " ;

	for(int element = 0; element < size; ++element){
		int val ;
		cin >> val;
		this -> update(val);
	}
}

void HashMap :: read(){
	for(int key = 0; key < this -> size; ++key)
		cout << Array[key] << " ";
	cout << endl;
}

int HashMap :: first_hash(int val){
	return val % 10;
}

int HashMap :: second_hash(int val){
	return doubleKey - (val % doubleKey);
}

int HashMap :: doubleHashing(int val){

	int first_hash_key = first_hash(val);
	int second_hash_key = second_hash(val);
	int index = first_hash_key;
	int i = 0;

	while(this -> Array[index] != 0)
		index = (first_hash_key + (i++) * (second_hash_key)) % 10;
	
	return index;
}

void HashMap :: update(int val){

	int hash_key = first_hash(val);

	if(this -> Array[hash_key] == 0)
		this -> Array[hash_key] = val;

	else{
		hash_key = doubleHashing(val);
		this -> Array[hash_key] = val;
	}
}

int main(){
	HashMap map;
	map.create();
	map.read();
	return 0;
}