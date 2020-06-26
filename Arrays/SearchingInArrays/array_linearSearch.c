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

int linearSearch(struct Array arr , int key){
	int i;
	for(i=0; i<arr.length ; i++){
		if(key==arr.A[i])
			return i;
	}
	return -1;
}

int main(){
	struct Array arr = {{10,15,20,25,30,35,40,45,50,55,60,65},20,12};
	printf("The index of the element is:%d\n",linearSearch(arr,25));
	Display(arr);
	return 0;
}