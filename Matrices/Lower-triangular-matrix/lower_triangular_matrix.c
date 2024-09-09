#include<stdio.h>
#include<stdlib.h>

//if column index is lesser than row index then elements are zero
//if row is greater than or equal to column then that is the non zero part of lower triangular matrix

int Display(int S[5][5],int n){
	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i>=j)
				 printf("%d ",S[i][j]);
			else printf("0 ");

		}
		printf("\n");
	}
}

int main()
{
	int A[5][5]={1,0,0,0,0,1,2,0,0,0,1,2,3,0,0,1,2,3,4,0,1,2,3,4,5};
	int n,i,j;
	printf("Enter dimension of the square matrix: ");
	scanf("%d",&n);
	printf("The diagonal elements are:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)
				printf("%d ",A[i][j] );
		}
	}
	printf("\nThe lower triangular matrix is:\n");
	Display(A,5);
	return 0;
}
