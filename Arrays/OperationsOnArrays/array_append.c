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

int append_array(struct Array *arr , int x){
	if(arr->length < arr->size){
		arr->A[arr->length]=x;
		arr->length++;
	}
}

int main(){
	struct Array arr={{2,3,4,5,6},20,5};
	append_array(&arr , 10);
	display_array(arr);
	return 0;
}