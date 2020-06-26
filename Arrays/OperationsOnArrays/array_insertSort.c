#include<stdio.h>
#include<stdlib.h>

struct Array{
	int A[20];
	int size;
	int length;
};

void Display(struct Array arr){
	int i;
	for(i=0; i<arr.length; i++){
		printf("%d\n",arr.A[i]);
	}
}

void InsertSort(struct Array *arr, int x){
	int i=arr->length-1;
	while(arr->A[i]>x){
		arr->A[i+1]=arr->A[i];
		i--;
	}
	arr->A[i+1]=x;
	arr->length++;

}

int main(){
	struct Array arr={{5,10,15,20,25,30,35,40},20,7};
	InsertSort(&arr,26);
	Display(arr);
}