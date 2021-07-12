#include<iostream>
using namespace std;

class Matrix{
protected:
	int row,col;
	Matrix(int row, int col){
		this -> row = row;
		this -> col = col;
	}
};

class Diagonal : Matrix{
private:
	int *diagonal_values;
public:
	Diagonal(int row, int col, int elements[]) : Matrix(row, col){
		diagonal_values = new int[row];
		for(int index = 1; index <= row; ++index)
			diagonal_values[index] = elements[index];
	}
	void printMatrix();
};

class Symmetric : Matrix{
	private : 
	int * elements;
public:
	Symmetric(int dimension, int values[]) : Matrix(dimension, dimension){
		elements = new int[dimension];
		for(int i = 1; i <= row; ++i){
			for(int j = 1; j <= i + 1; ++j){
				if(i <= j) {
					elements[row*(i-1) - ((i-1)*(i-2))/2 + j -1 ] = values[i];
				}
				else{
					elements[row*(j-1) - ((j-1)*(j-2))/2 + i  -1] = values[i];	
				}
			}
		}
	}
	void printMatrix();
};

void Diagonal :: printMatrix(){
	for(int i = 1; i  <= this -> row; ++i ){
		for(int j = 1; j <= this -> col; ++j){
			if(i == j) cout << this -> diagonal_values[i] << " ";
			else cout << "0 ";
		}
		cout << endl;
	}
}

void Symmetric :: printMatrix(){
	for(int i = 1; i <= row; ++i){
		for(int j = 1; j <= col; ++j){
			if(i <= j){
				cout << elements[row*(i-1) - ((i-1)*(i-2))/2 + j-1] << " " ;
			}
			else{
				cout << elements[row*(j-1) - ((j-1)*(j-2))/2 + i - 1 ] << " " ;
			}
		}
		cout << endl;
	}
}


int main(){
	int arr[3] = {1,1,1};
	Diagonal matrix = Diagonal(3, 3, arr);
	matrix.printMatrix();

	int array[6] = {1,2,3,4,5};
	cout << endl;
	Symmetric sym  = Symmetric(3,array);
	sym.printMatrix();

	return 0;
}