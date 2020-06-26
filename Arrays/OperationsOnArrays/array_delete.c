#include<stdio.h>
#include<stdlib.h>

struct Array{
	int A[20];
	int size;
	int length;
};

void Display(struct Array arr){
	int i;
	for(i=0 ; i < arr.length ; i++){
		printf("%d\n",arr.A[i]);
	}
}

int Delete(struct Array *arr, int index){
	int x=0;
	int i;
	if(index>=0 && index<arr->length){
		x=arr->A[index];
		for(i=index ; i<arr->length-1 ; i++){
			arr->A[i]=arr->A[i+1];
		}
	arr->length--;
	return x;
	}
	return 0;
}

int main(){
	struct Array arr = {{2,4,6,8,10,12,14,16,18,20},20,10};
	Delete(&arr,5);
	Display(arr);
	return 0;
}