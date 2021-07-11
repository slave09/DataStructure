#include<stdio.h>

//creating a class of one dimensional array to store all the diagonal elements of any square diagonal matrix

struct Matrix
{
	int A[10];
	int n;
};

//set is to insert the diagonal elements inside the matrix

void Set(struct Matrix *m,int i,int j,int x){
	if(i==j)
		m->A[i-1]=x;
}

//function to retrieve an element from the matrix at any index

int Get(struct Matrix m,int i,int j){
	if(i==j)
		printf("%d\n",m.A[i-1]);
	else return 0;
}

//displaying all the elements of the square matrix row by row

void Display(struct Matrix m){
	int i,j;
	for(i=0;i<m.n;i++){
		for(j=0;j<m.n;j++){
			if(i==j)
				printf("%d ",m.A[i] );
			else printf("0 ");
		}
		printf("\n");
	}
}


int main(){
	struct Matrix m;
	m.n=4;
	Set(&m,1,1,5);
	Set(&m,2,2,7);
	Set(&m,3,3,9);
	Set(&m,4,4,11);
	Get(m,2,2);
	Display(m);
	return 0;
}