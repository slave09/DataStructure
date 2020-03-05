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
void swap(int *x ,int *y){
	int temp;
	temp=*x;
    *x=*y;
	*y=temp;
}

int linearSearch_transposition(struct Array *arr ,int key){
	int i;
	for(i=0; i<arr->length ; i++){
		if(key==arr->A[i]){
			swap(&arr->A[i],&arr->A[0]);
		    return i;
		}
	}
	return -1;
}
int main(){
	struct Array arr = {{10,15,20,25,30,35,40,45,50,55,60,65},20,12};
	printf("The index for 45 is:%d\n",linearSearch_transposition(&arr,45));
	Display(arr);
	printf("The index for 45 is:%d\n",linearSearch_transposition(&arr,45));
	return 0;
}
