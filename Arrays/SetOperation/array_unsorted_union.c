#include<stdio.h>
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

struct Array * search_Insert(struct Array *arr2,struct Array *arr3,int key,int index){
	int i;
	while(i<arr2->length){
		if(key!=arr3->A[i])
			return i++;
		else 
			break;
	}
	if(i>=arr2->length){
		arr3->A[index]=key;
		arr3->length++;
	}
	else return arr3;

	return arr3;
}

struct Array * union_unsorted(struct Array *arr1,struct Array *arr2){
	int i, j, k;
	i=j=k=0;

	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
	arr3->length=0;

	for(i=0;i<arr1->length;i++){
		arr3->A[k++]=arr1->A[i];
		arr3->length++;
	}

    for(i=0;i<arr2->length;i++){
    	search_Insert(&arr2,&arr3,arr2->A[i],k);
    	k++;
    }
    return arr3;
}

int main(){
	struct Array arr1 = {{11,23,43,54,67},20,5};
	struct Array arr2 = {{23,67,20,56,76},20,5};
	struct Array *arr3;
	arr3=union_unsorted(&arr1,&arr2);
	Display(*arr3);
}