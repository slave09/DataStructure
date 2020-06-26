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
		printf("%d\n",arr.A[i]);
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

int missing(struct Array * arr,int first){
	int i, difference;
	difference=first-0;
	for(i=0;i<arr->length;i++){
		if(arr->A[i]-i!=difference){
			printf("Missing element is %d\n",i+difference );
		    break;
		}
	}
}

int main()
{
	int choice,index,x,f;
	struct Array arr;
	printf("Enter size of the array:");
	scanf("%d",&arr.size);

	arr.A = (int*)malloc(arr.size*sizeof(int));
	arr.length=0;

	do{
		printf("\nMenu\n");
		printf("1 . Insert\n");
		printf("2 . Delete\n");
		printf("3 . Display\n");
		printf("4 . Missing\n");
		printf("5 . Exit\n");
		printf("Enter your choice:",choice);
		scanf("%d",&choice);
		switch(choice){
		case 1:printf("Enter index:",index);
		       scanf("%d",&index);
		       printf("Enter Element:",x);
		       scanf("%d",&x);
		       Insert(&arr,index,x);
		       break;
		case 2:printf("Enter index:",index);
		       scanf("%d",&index);
		       x=Delete(&arr,index);
		       printf("Deleted element is %d",x);
		       break;
		case 3:Display(arr);
		       break;
		case 4:printf("Enter first element of the array:\n",f);
			   scanf("%d",&f);
		       missing(&arr,f);
			   break;

		}
	}while(choice<5);
	return 0;
}