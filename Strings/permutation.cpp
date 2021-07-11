/*
	Topic : Permutation of strings 
	Logic : swapping using recursion
*/

#include<iostream>
#include<cstring>
using namespace std;

void permutation(char str[], int low, int high){

	if(low == high) cout << str << endl;

	else {
		for(int i = low; i <= high; ++i){
			
			swap(str[i], str[low]);

			permutation(str, low + 1, high);
		}

	}

}

int main(){

	char str[100];

	cout << "Enter String" << endl;
	cin >> str;

	int length = strlen(str);

	permutation(str, 0, length - 1);

	return 0;
}