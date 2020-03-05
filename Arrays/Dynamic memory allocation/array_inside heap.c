#include <stdio.h>

int main()
{
	int **p;
	int i,j;
	p=(int **)malloc(3*sizeof(int));
	p[0]=(int **)malloc(4*sizeof(int));
	p[1]=(int **)malloc(4*sizeof(int));
	p[2]=(int **)malloc(4*sizeof(int));
    
    for (i = 0; i < 3; ++i)
    {
    	for (j = 0; j < 4; ++j)
    	{
    		printf("%d\n",p[i][j] );
    	}
    }
}