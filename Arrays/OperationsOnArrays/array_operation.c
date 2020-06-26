#include<stdio.h>
#include<stdlib.h>

struct Array{
	int A[20];
	int size;
	int length;
};


int display_array(struct Array arr){
	int i;

	for(i=0 ; i<arr.length ; i++){
		printf("%d\n",arr.A[i] );
	}

}

int Get(struct Array arr,int index ){
	if(index>=0 && index<arr.length)
		return arr.A[index];
}

int set(struct Array *arr,int index,int x){
	if(index>=0 && index<arr->length)
		arr->A[index]=x;
}

int sum(struct Array arr){
	int s=0;
	int i;
	for(i=0; i<arr.length ; i++)
		s=s+arr.A[i];
	return s;
}

float Avg(struct Array arr ){
	      return (float)sum(arr)/arr.length;
}

int max(struct Array arr){
	int max=arr.A[0];
	int i;
	for(i=1; i<arr.length; i++){
		if(max<arr.A[i])
			max=arr.A[i];
	}
    return max;
}

int min(struct Array arr){
	int min=arr.A[0];
	int i;
	for(i=1; i<arr.length; i++){
		if(min>arr.A[i])
			min=arr.A[i];
	}
	return min;
}

int main(){
	struct Array arr={{2,3,4,5,6},20,5};
	printf("Get Result:%d\n",Get(arr,0) );
	printf("maximum of the element is%d\nminimum of the element is%d\n",max(arr),min(arr) );
	printf("Sum of all element:%d\n", sum(arr));
	printf("Average of all element is:%f\n",Avg(arr) );
	set(&arr,0,1);
	display_array(arr);
	return 0;
}