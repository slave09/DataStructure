#include <stdio.h>
#include<stdlib.h>

struct Array{
	int A[20];
	int size;
	int length;
};

void Display(struct Array arr){
	int i;
	for(i=0;i<arr.length;i++){
		printf("%d\n",arr.A[i]);
	}
}

struct Array * Difference_of_Arrays(struct Array *arr,struct Array *arr2){
	int i,j,k;
	i=j=k=0;
	struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
	while(i<arr->length && j<arr2->length){
		if(arr->A[i]<arr2->A[j])
			arr3->A[k++]=arr->A[i++];
		else if(arr->A[i]>arr2->A[j])
			j++;
		else if(arr->A[i]==arr2->A[j]){
			i++;
		    j++;
		}
	}
	for(;i<arr->length;i++)
		arr3->A[k++]=arr->A[i];
	arr3->length=k;
	arr3->size=arr->length+arr2->length;
	return arr3;
}


int main(){
	struct Array x = {{2,3,4,5,6},20,5};
	struct Array y = {{1,3,5,7,9},20,5};
	struct Array *z;
	z=Difference_of_Arrays(&x,&y);
	Display(*z);
}