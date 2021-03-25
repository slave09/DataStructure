/*
	Author : Fakhra Najm<fnjam09@gmail.com>
	Hash table implementataion : Quadratic Probing
*/


#include<bits/stdc++.h>
using namespace std;


class HashMap{

private:
	int *Arr;
	int size;

public :
	HashMap(){}
	void create(int size);
	void update(int val);
	int find(int val);
	int probe(int val);
	int hashvalue(int val);
	void read();
};


void HashMap :: create(int size){
	this -> size = size;
	this -> Arr = new int[size];
	for(int i = 0; i < size; ++i)
		Arr[i] = 0;
}

void HashMap :: read(){
	for(int index = 0; index < this -> size; ++index)
		cout << this -> Arr[index] << " ";
	cout << endl;
}

int HashMap :: probe(int val){
	int i = 0, index = hashvalue(val);
	while(this -> Arr[index] != 0){
		index = (hashvalue(val) + (int)pow(++i,2)) % 10;
	}
	return index;
}

int HashMap :: hashvalue(int value){
	return value % 10;
}

void HashMap :: update(int val){

	int indx = hashvalue(val);

	if(this -> Arr[indx] == 0) 
		this -> Arr[indx] = val;

	else{
		indx = probe(val);
		this -> Arr[indx] = val;
	}

}

int HashMap :: find(int val){
	int i = 0;
	int index = hashvalue(val);
	while(Arr[index] != 0 ){
		if(this -> Arr[index] == val) return index;
		index = (hashvalue(val) + (int)pow(++i,2)) % 10;
	}

	return -1;
}

int main(){

	int size, element;

	cout << "Enter size of the data elements:" << endl;
	cin >> size;

	cout << "The size of hash table is " << 2 * size + 1 << endl;

	HashMap map;
	map.create(size * 2 + 1);

	cout << "Enter elements:" << endl;

	for(int data = 0; data < size ; ++data){
		int value;
		cin >> value;
		map.update(value);
	}


	cout << "Stored value : " << endl;
	map.read();

	cout << "Enter element to be found : " << endl ;
	cin >>  element;


	if( map.find(element) != -1)  cout << "Founded at index " << map.find(element) << " " ;
	else cout << "ELEMENT NOT FOUND !!!!";

	return 0;
} 