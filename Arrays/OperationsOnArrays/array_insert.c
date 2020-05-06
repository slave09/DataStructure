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

void Insert_array(struct Array *arr ,int index ,int x ){
	int i;
	if(index>=0 && index<=arr->length){
		for ( i = arr->length ; i >index; i--)
		{
			arr->A[i]=arr->A[i-1];
		}

		arr->A[index]=x;
	}
}

int main(){
	struct Array arr = {{2,4,6,8,10,12,14,16,18,20},20,5};
	Insert_array(&arr,3,7);
	Display(arr);
}
