#include<stdio.h>
#include<stdlib.h>

struct Matrix {
	int *A;
	int n;
};

//set function will set the non-zero elements in the single dimensional array from the given matrix
void set(struct Matrix *m,int i,int j,int x){
	if(i>=j)
		//copying non-zero elements from the lower triangular matrix column by column in the created single dimensional array 
		m->A[(m->n*(j-1))+((j-1)*(j-2)/2)+(i-j)]=x;
}

//retreiving the data from the single dimensional array if index of row is greater than or equal to column index otherwise ,it will return zero
int get(struct Matrix m,int i,int j){
	if(i>=j)
		return m.A[(m.n*(j-1))+((j-1)*(j-2)/2)+(i-j)];
	else 
		return 0;
}

//prints the matrix on the screen with the help of single dimensional array in heap 
//if the row index is greater than or equal to column index then it will return elements from created 1D array,otherwise it will print zero
void Display(struct Matrix m){
	int i,j;
	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			if(i>=j)
				printf("%d ",m.A[(m.n*(j-1))+((j-1)*(j-2)/2)+(i-j)]);
			else
				printf("0 ");
		}

		printf("\n");
	}
}


int main(){
	struct Matrix m;
	int i,j,x;

	printf("Enter the dimension of the matrix:");
	scanf("%d",&m.n);

	//creating a single dimensional array dynamically to store non-zero elements of the matrix

	m.A=(int *)malloc(m.n*(m.n-1)/2*sizeof(int));

	printf("Enter all elements\n");

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
