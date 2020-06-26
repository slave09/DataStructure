#include<stdio.h>
#include<stdlib.h>

struct Array{
	int A[20];
	int size;
	int length;
};


int display_array(struct Array arr){
	int i;

	for(i=0 ; i<arr.length ; i++){
		printf("%d\n",arr.A[i] );
	}

}

int shift_array(struct Array *arr){
	int i;
	int x = arr->A[0];
	for(i=0; i<arr->length; i++){
		arr->A[i]=arr->A[i+1];
	}
	arr->A[arr->length-1]=x;

}

int main(){
	struct Array arr={{2,3,4,5,6},20,5};
	shift_array(&arr);
	display_array(arr);


	return 0;
}
