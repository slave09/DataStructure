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
	printf("\n");
}

int swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void reverse_array(struct Array *arr){
	int i,j;
	int *B;
	B=(int *)malloc(arr->length*sizeof(int));
	for(i=arr->length-1,j=0; i>=0; j++,i--){
		B[j]=arr->A[i];
	}
	for(i=0; i<arr->length; i++){
	arr->A[i]=B[i];
	}
}

void reverse_swap(struct Array *arr){
	int i,j;
	for(i=0,j=arr->length-1 ; i<j;  i++,j--){
		swap(&arr->A[i],&arr->A[j]);
	}
}

int main(){
	struct Array arr ={{2,6,9,8,12,17,19,10},20,5};
	reverse_swap(&arr);
	Display(arr);
	reverse_array(&arr);
	Display(arr);
} 