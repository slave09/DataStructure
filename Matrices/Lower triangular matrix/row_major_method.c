#include<stdio.h>
#include<stdlib.h>

struct  Matrices {
	int *A;
	int n;
};

//printing the entire lower triangular matrix with the help of 1D matrix
//if row index is greater than or equal to column index, it prints corresponding index elememt from the created array,otherwise it will ptint zero

void Display(struct Matrices m){
	int i,j;
	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			if(i>=j)
				printf("%d ",m.A[i*(i-1)/2+j-1] );
			else
				printf("0 ");
		}
		printf("\n");
	}

}

//setting the non-zero elements in the one dimensional array 

void set(struct Matrices *m,int i,int j,int x){
	//non-zero elements is only present there where row index is greater than or equal to column index 
	if(i>=j)
		//setting the non-zero elements in the created single dimensional array row by row
		m->A[i*(i-1)/2+j-1]=x;
}

//returning the elments from the matrix with the help of one dimensional array
int Get(struct Matrices m,int i,int j){
	//Check for non-zero elements 
	if(i>=j)
		return m.A[i*(i-1)/2+j-1];
	else 
	return 0;
}

int main(){
	struct Matrices m;
	int i,j,x;
	printf("Enter dimmension:");
	scanf("%d",&m.n);

	//creating a single dimensional array dynamically to store all non zero elements from the matrix row by row
	//the size of the array is equal to the total number of non-zero elements in the matrix

	m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));

	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			scanf("%d",&x);
			set(&m,i,j,x);
		}
	}
	printf("\n\n");

	Display(m);

	return 0;
}
