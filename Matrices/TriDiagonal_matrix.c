#include<stdio.h>
#include<stdlib.h>

//array which will store the upper, lower and main diagonal elements of the triDiagonal Matrix

struct Matrix{
	int *A;
	int n;
};


//main diagonal:the difference of indices is zero in every cases
//upper diagonal:the difference of indices is -1 in every cases
//lower Diagonal:the difference of indices is 1 in every cases 
//setting all the non-zero elements in 1D array diagonal by diagonal

void Set(struct Matrix *m,int i,int j,int x)
{
	if(i-j==0)
		m->A[m->n-1+i-1]=x;
	else if(i-j==1)
		m->A[i-2]=x;
	else if(i-j==-1)
		m->A[2*m->n-1+i-1]=x;
}

// Returns diagonal elements

int Get(struct Matrix m,int i,int j)
{
	if(i-j==0)
		return m.A[m.n-1+i-1];
	else if(i-j==1)
		return m.A[i-2];
	else if(i-j==-1)
		return m.A[2*m.n-1+i-1];
	else 
		return 0;
}

//prints the triDiagonal Matrix

void Display(struct Matrix m)
{
	int i,j;

	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			if(i-j==0)
				printf("%d ",m.A[m.n-1+i-1] );
			else if(i-j==1)
				printf("%d ",m.A[i-2] );
			else if(i-j==-1)
				printf("%d ",m.A[2*m.n-1+i-1]);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	int i,j,x;

	struct Matrix m;

	m.A=(int *)malloc((3*m.n-2)*sizeof(int));
	
	printf("Enter dimension of the Matrix:");
	scanf("%d",&m.n);

	printf("Enter the elements of the Matrix:");

	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			scanf("%d",&x);
			Set(&m,i,j,x);
		}
	}
	printf("\n\n");

	Display(m);

	printf(" \nAll the diagonal elements are\n");
	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			if(i-j==0)
				printf("%d ",Get(m,i,j) );
		}
		printf("\n");
	}

	printf(" \nAll the upper diagonal elements are\n");

	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			if(i-j==-1)
				printf("%d \n",Get(m,i,j) );
		}
	}

	printf(" \nAll the lower diagonal elements are\n");

	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			if(i-j==1)
				printf("%d \n",Get(m,i,j) );
		}
	}


	return 0;
}
