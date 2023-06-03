#include<stdio.h>
#include<stdlib.h>

struct Matrix 
{
	int *A;
	int n;
};

//prints the symmetric matrix 
void Display(struct Matrix m)
{
	int i,j;
	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			if(i<=j)
				printf("%d ",m.A[m.n*(i-1)-(i-1)*(i-2)/2+(j-1)]);
			else
				printf("%d ",m.A[m.n*(j-1)-(j-1)*(j-2)/2+(i-1)] );
		}
		printf("\n");
	}
}

//stores all the upper triangular elements in the array
//all the upper triangular elements are copied in lower triangular elements
void Set(struct Matrix *m,int i,int j,int x)
{
	if(i<=j)
		m->A[m->n*(i-1)-(i-1)*(i-2)/2+(j-1)]=x;
	else
		m->A[m->n*(j-1)-(j-1)*(j-2)/2+(i-1)]=x;
}

//Returns desired elements from the array
//it will check if the given index lies in upper triangular part or not and then return elements from array
//two times occuring elements are stored only once and it will return mirror image of the required index which is same as passed index
int Get(struct Matrix m,int i,int j)
{
	if(i<=j)
		return m.A[m.n*(i-1)-(i-1)*(i-2)/2+(j-1)];
	else
		return m.A[m.n*(j-1)-(j-1)*(j-2)/2+(i-1)];
}

int main(){
	int i,j,x;
	struct Matrix m;
	printf("Enter the dimension of the Matrix: ");
	scanf("%d",&m.n);

	//creating a single dimensional array so that the repeated elements are stored only once row by row 
	//the size the array is the size of elments of upper triangular matrix
	m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));

	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			scanf("%d",&x);
			Set(&m,i,j,x);
		}
	}
	printf("\n");

	Display(m);

	printf("\nAll symmetric elements are:\n");

//prints all the elements which occurs twice in the given square symmetric matrix
	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			if(i<=j)
				printf("%d ",Get(m,i,j)); 
		}
	}
	return 0;
}
