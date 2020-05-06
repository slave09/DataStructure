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

void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void Rearrange_Integers(struct Array *arr){
	int i=0;
	int j=arr->length-1;
	while(i<j){

		while(arr->A[i]<0) i++;
		while(arr->A[j]>0) j--;
		if(i<j)
			swap(&arr->A[i],&arr->A[j]);
	}
}

int main(){
	struct Array arr={{-5,10,15,-20,25,30,-35,40},20,8};
	Rearrange_Integers(&arr);
	Display(arr);
}
