#include<stdio.h>
#include<stdlib.h>

struct Array{
	int *A;
	int size;
	int length;
};

int Display_array(struct Array arr){

	int i;

	for(i=0; i<arr.length; i++){
		printf("%d",arr.A[i]);
	}
}

int main(){
	struct Array arr;

	int n,i;

	printf("Enter the size of the Array");
	scanf("%d",&arr.size);

	arr.A=(int *)malloc(arr.size*sizeof(int));

	arr.length=0;

	printf("Enter Number of elements:\n");
	scanf("%d",&n);

	printf("Enter all the Elements\n");

	for(i=0 ; i<n ; i++){
		scanf("%d",&arr.A[i]);
	}

	arr.length=n;

	Display_array(arr);

	return 0;
} 