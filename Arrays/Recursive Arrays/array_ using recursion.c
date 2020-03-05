#include<stdio.h>

void print_recursive(int a[],int n,int i)
{
	if(i<n)
	{
		printf("%d",a[i] );
		print_recursive(a,n,++i);
	}
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	print_recursive(a,10,0);
	return 0;
}
