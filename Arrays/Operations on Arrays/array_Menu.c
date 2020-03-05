#include<stdio.h>
#include<stdlib.h>

struct Array{
	int *A;
	int size;
	int length;
};

int Display(struct Array arr){
	
	int i;

	printf("\nElements are:\n");

	for(i=0; i<arr.length; i++){
		printf("%d",arr.A[i]);
	}
}

void Insert(struct Array *arr ,int index ,int x ){
	int i;
	if(index>=0 && index<=arr->length){
		for ( i = arr->length ; i >index; i--)
		{
			arr->A[i]=arr->A[i-1];
		}

		arr->A[index]=x;
	}
	arr->length++;
}

int Delete(struct Array *arr, int index){
	int x=0;
	int i;
	if(index>=0 && index<arr->length){
		x=arr->A[index];
		for(i=index ; i<arr->length-1 ; i++){
			arr->A[i]=arr->A[i+1];
		}
	arr->length--;
	return x;
	}
	return 0;
}

int LinearSearch(struct Array *arr , int key){
	int i;
	for(i=0; i<arr->length ; i++){
		if(key==arr->A[i])
			return i;
	}
	return -1;
}

int Sum(struct Array arr){
	int s=0;
	int i;
	for(i=0; i<arr.length ; i++)
		s=s+arr.A[i];
	return s;
}

int main(){

	int choice;
	int index ,x;
	struct Array arr1;
	printf("Enter size of array");
	scanf("%d",&arr1.size);

	arr1.A = (int *)malloc(arr1.size*sizeof(int));
	arr1.length=0;
	do{
	printf("\nMenu:\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Search\n");
	printf("4. Sum\n");
	printf("5. Display\n");
	printf("6. Exit\n");

	printf("Enter your choice:",choice);
	scanf("%d",&choice);

	switch(choice){
		case 1: printf("Enter an element and index");
		 scanf("%d%d",&x,&index);
		 Insert(&arr1,index,x);
		 break;
		 case 2: printf("Enter index ");
		 scanf("%d",&index);
		 x=Delete(&arr1,index);
		 printf("Deleted Element is %d\n",x);
		 break;
		 case 3:printf("Enter element to search ");
		 scanf("%d",&x);
		 index=LinearSearch(&arr1,x);
		 printf("Element index %d",index);
		 break;
		 case 4:printf("Sum is %d\n",Sum(arr1));
		 break;
		 case 5:Display(arr1);
		}
		 }while(choice<6);
		 return 0;
}		 
