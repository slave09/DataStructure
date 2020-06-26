#include <stdio.h>
int print_recursive(int a[],int n,int i)
{
	if(i >= n) return 0;
	return 5*(a[i]*a[i])+ 1 + print_recursive(a, n, i + 1);
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	printf("%d", print_recursive(a,10,0,0));
	return 0;
} 