/*
	Author : Fakhra Najm<fnjam09@gmail.com>
	Hash table implementataion : Quadratic Probing
*/

#include<iostream>
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
	void Delete(int val);
};


void HashMap :: create(int size){
	this -> size = size;
	Arr = new int[size];
	for(int i = 0; i < size; ++i)
		Arr[i] = 0;
}

void HashMap :: read(){
	for(int index = 0; index < size; ++index)
		cout << Arr[index] << " ";
	cout << endl;
}

/*
	* To avoid primary clustring of the keys
	* probe = h'(x) = (h(x) + f(i)) % size
	* f(i) = i^
*/
int HashMap :: probe(int val){
	int i = 0, index = hashvalue(val);
	while(Arr[index] != 0){
		index = (hashvalue(val) + i*i) % size ;
		i++;
	}
	return index;
}

int HashMap :: hashvalue(int value){
	return value % size ;
}

void HashMap :: update(int val){
	int indx = hashvalue(val);
	if(Arr[indx] == 0) 
		Arr[indx] = val;
	else{
		indx = probe(val);
		Arr[indx] = val;
	}
}

int HashMap :: find(int val){
	int index = hashvalue(val);
	int i = 0;
	while(Arr[index] != 0 ){
		if(Arr[index] == val) return index;
		index = (hashvalue(val) + i*i) % size ;
		i++;
	}
	return -1;
}

void HashMap :: Delete(int val){
	int key = hashvalue(val);
	if(Arr[key] == val) Arr[key] = 0;
	else{
		int i = 0;
		while(Arr[key] != val){
			if(Arr[key] == 0) return;
			key = (hashvalue(val) + (i)*(i++)) % size;
		}
		Arr[key] = 0;
	}
}

int main(){
	int size, element, remove_element;
	cout << "Enter size of the data elements:" << endl;
	cin >> size;
	cout << "The size of hash table is " << 2 * size << endl;
	HashMap map;
	map.create(size * 2);
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
	if( map.find(element) != -1)  cout << "Founded at index " << map.find(element) << endl ;
	else cout << "ELEMENT NOT FOUND !!!!" << endl;
	cout << "Enter value to be deleted:" << endl;
	cin >> remove_element;
	map.Delete(remove_element);
	cout << "After deleting " << remove_element << ":" << endl;
	map.read();
	return 0;
} 