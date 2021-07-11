#include<stdio.h>
#include<stdlib.h>

//class Matrix of single dimensional array to store all the distinct elements in toeplitz matrix
//Toeplitz matrix is the mtrix having all the same diagonal elements.

struct Matrix
{
	int *A;
	int n;
};

//elements of the first row lies in upper triangular Matrix while elements of first column lies in lower triangular matrix
//setting all distinct elements which has entered as a matrix element in the array of class Matrix dynamically

void Set(struct Matrix *m,int i,int j,int x )
{
	if(i<=j)
		m->A[j-i]=x;
	else if(i>j)
		m->A[m->n+(i-j)-1]=x;
}

//function to return all the elements of the toeplitz matrix with the help of array of class Matrix

int Get(struct Matrix m,int i,int j)
{
	if(i<=j)
		return m.A[j-i];
	else if(i>j)
		return m.A[m.n+(i-j)-1];
}

//displaying all the elements of the matrix from array of class Matrix

void Display(struct Matrix m)
{
	int i,j;
	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			if(i<=j)
				printf("%d ",m.A[j-i]);
			else
				printf("%d ",m.A[m.n+(i-j)-1]);
		}
		printf("\n");
	}
}

int main(){

	int i,j,x;

	struct Matrix m;

	printf("Enter dimension of the array:");
	scanf("%d",&m.n);

//storing all the first row elements and first column elements in the Array 
//the size of the array will be total of first row elements and first column elements i.e. "(n)+n-1" 
//row 1 column 1 as it is common in both

	m.A=(int *)malloc(2*m.n-1*sizeof(int));

	printf("\nEnter all elements of the matrix\n");

	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			scanf("%d",&x);
			Set(&m,i,j,x);
		}
	}

	printf("\n\n");

	Display(m);

	printf("\n\n");

	printf("the distinct elements in Matrix are\n");

	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			if(i==1)
				printf("%d ",Get(m,i,j) );
			else if(j==1){
				for(i=1;i<m.n;i++){
					printf("%d ",Get(m,i+1,j));
				}
			}
			else
				return;
		}
	}
	return 0;
}
