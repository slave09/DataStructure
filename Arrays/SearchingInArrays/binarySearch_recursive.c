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

int binarySearch_recursive(int a[],int key,int low ,int high){
	int mid;
	if(low<=high){
		mid=(low+high)/2;
		if(a[mid]==key){
			return mid;
		}
		else if(a[mid]<key)
			return binarySearch_recursive(a,key,mid+1,high);
		else 
			return binarySearch_recursive(a,key,low,mid-1);

	}
	return -1;
}

int main(){
	struct Array arr={{2,3,4,5,6},20,5};

	display_array(arr);

	printf("search result :%d\n",binarySearch_recursive(arr.A,5,0,arr.length) );


	return 0;
}