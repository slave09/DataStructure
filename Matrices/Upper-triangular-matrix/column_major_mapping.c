#include<stdio.h>
#include<stdlib.h>

struct  Matrices {
	int *A;
	int n;
};

/*
	* In upper triangular matrix lower triangular elememts are all zeroes
	* In upper triangular matrix row index is always less than or equal to column index
*/

void Display(struct Matrices m){
	int i,j;
	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			if(i<=j)
				printf("%d ",m.A[j*(j-1)/2+(i-1)] );
			else
				printf("0 ");
		}
			printf("\n");
	}

}

//Sets the elements on the matrix if index of column is greater than the row index otherwise,the element is zero

void set(struct Matrices *m,int i,int j,int x){
	if(i<=j)

		//copying elements column by column from matrix in the single dimensional created array
		
		m->A[j*(j-1)/2+(i-1)]=x;
}

//if the requested index for column is greater than requested index for row then the get function will return data from single dimensional created array
//otherwise it will return zero as in upper triangular matrix lower triangular part is always zero

int Get(struct Matrices m,int i,int j){
	if(i<=j)
		return m.A[j*(j-1)/2+(i-1)];
	else 
		return 0;
}

int main(){
	struct Matrices m;
	int i,j,x;
	printf("Enter dimmension:");
	scanf("%d",&m.n);

	//we are meant to store only non zero elements in a 
	//single dimensional array

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
