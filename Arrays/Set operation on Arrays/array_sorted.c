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

int is_Sorted(struct Array *arr){
	int i;
	while(arr->A[i]>arr->A[i+1]){
		return 0;
	}
	return 1;
}
int main(){
	struct Array arr={{5,10,15,20,25,30,35,40},20,7};
	Display(arr);
	printf("%d\n",is_Sorted(&arr) );
}
