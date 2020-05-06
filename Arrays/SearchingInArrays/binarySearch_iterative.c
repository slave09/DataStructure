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

int binarySearch(struct Array arr,int key){
	int low=0;
	int high=arr.length-1;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(arr.A[mid]==key){
			return mid;
		}
		else if(arr.A[mid]<key)
			low=mid+1;
		else 
			return high=mid-1;

	}
	return -1;
}

int main(){
	struct Array arr={{2,3,4,5,6},20,5};

	display_array(arr);

	printf("search result :%d\n",binarySearch(arr,5) );


	return 0;
}
