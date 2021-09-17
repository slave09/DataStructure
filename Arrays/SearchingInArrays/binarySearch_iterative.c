#include<stdio.h>
#include<stdlib.h>

struct Array{
	int A[20];
	int size;
	int length;
};


int display_array(struct Array arr){
	int index;
	while(index < arr.length){
		printf("%d\n",arr.A[index++]);
	}
}

int binarySearch(struct Array arr,int key){
	int front = 0;
	int back = arr.length - 1;
	while(front < back){
		int mid = front + (back - front)/2;
		if(arr.A[mid] == key) return mid;
		if(arr.A[mid] < key) front = mid + 1;
		else back = mid - 1;
	}
	return -1;
}

int main(){
	struct Array arr={{2,3,4,5,6},20,5};
	display_array(arr);
	printf("search result :%d\n",binarySearch(arr,5) );
	return 0;
}