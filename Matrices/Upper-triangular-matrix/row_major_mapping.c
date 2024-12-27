#include<stdio.h>
#include<stdlib.h>

struct  Matrices {
	int *A;
	int n;
};

//display function will only display the elements of created single dimensional array when
//the column index is greater than or equal to row index,otherwise it will return 0 

void Display(struct Matrices m){
	int i,j;
	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
			if(i<=j)
				printf("%d ",m.A[m.n*(i-1)-(i-1)*(i-2)/2+(j-1)] );
			else
				printf("0 ");
		}
			printf("\n");
	}

}

//the set function will only take datas which is non zero in the matrix that is for index of column must be 
//greater than or equal to row index

void set(struct Matrices *m,int i,int j,int x){
	if(i<=j)
		
		//copying elements row by row in the array from the matrix

		m->A[(i-1)*m->n-(i-1)*(i-2)/2+(j-1)]=x;
}


//get function will retrieve elements from created single dimensional array if
//column index is greater than or equal to row index ,otherwise it will return zero
int Get(struct Matrices m,int i,int j){
	if(i<=j)
		return m.A[(i-1)*m.n-(i-1)*(i-2)/2+(j-1)];
	else 
		return 0;
}

int main(){
	struct Matrices m;
	int i,j,x;
	printf("Enter dimmension:");
	scanf("%d",&m.n);

	//only need to store non-zero elements from the matrix as all other elements are going to be zero
	//creating array dynamically of size p = total number of non zero elements

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
