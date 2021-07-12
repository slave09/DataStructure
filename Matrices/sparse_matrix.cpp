/*
	* Topic : Sparse Matrix
	* very few Non zero elements is present in such matrix
	* Store only nonzero elements and optimize space
	* Two methods : 
		1. Three column representation/ Co-ordinate List Representation
		2. Compressed Sparse Row
	* Operations : 
		1. Create => Compressed Sparse Row Representation
		2. Add  =>  Co-ordinate List Representation
*/

#include<iostream>
using namespace std;

class Elements{
public :  
	int i, j, val;
};

class Sparse {
	private: 
		int nonzero_elements;
		int row;
		int col;
		Elements * details;
	public:

	Sparse(){

		cout << "Enter Dimension m x n : " << endl;
		cin >> this -> row  >> this -> col;

		cout << "Enter number of nonzero elements :" << endl;	
		cin >> this -> nonzero_elements;

		this -> details = new Elements[this -> nonzero_elements];

		for(int elements = 0; elements < this -> nonzero_elements; ++elements){

			cout << "Enter row index i :" << endl;
			cin >> details[elements].i;

			cout << "Enter column index j : " << endl;
			cin >> details[elements].j; 

			cout << "Enter value of M[i][j] : " << endl;
			cin >> details[elements].val; 
		}

	} 

	void print();
};


void Sparse :: print(){
	int index = 0;
	for(int i = 1; i <= this -> row; ++i){
		for(int j = 1; j <= this -> col; ++j){
			if(this -> details[index].i == i && this -> details[index].j == j){
				cout << details[index++].val << " ";
			}
			else{
				cout << "0 ";
			}
		}
		cout << endl;
	}
}

int main(){
	Sparse matrix;
	matrix.print();
	return 0;
}