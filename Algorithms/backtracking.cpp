/*
	* Author : Fakhra Najm<fnajm09@gmail.com>
	* Topic : Backtracking
	********************
	* Permutation of String : 
		Given a string print all the possible combinations of the letters of the string
*/

#include<iostream>
#include<cstring>
using namespace std;

void permutate_string(char str[], int index){

// flag Array to check availability of letters
	static int available[100] = {0};

// Array to store permutations 
	static char permutation[100];

// checking availability of each elements for every call

	for(int idx = 0; str[idx] != '\0'; ++idx){


/* 
If the letter is available add that letter to permutaion array and continue
scanning for next letter 
*/
		if(available[idx] == 0){

			available[idx] = 1;
			permutation[index] = str[idx];

			permutate_string(str, index + 1);

// if '\0' is encountered returning phase encounters

// if index is at last position of letter then permutation is printed
			if(index == strlen(str)-1)
				cout << permutation << endl;

// Again current letter is made available
			available[idx] = 0;
		}
	}	
}

int main(){
	char str[100] = "ABC";
	cout << "Enter String : " << endl;
	cin >> str;
	cout << "Permutations of " << str << ":" << endl;
	permutate_string(str, 0);
	return 0;
}