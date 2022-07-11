#include<stdio.h>
#include<stdlib.h>

/*
  * the polynomial representation can be done with knowing coefficient ,exponent and the number of terms that polynomial possess
 */

struct Term{
  int coeff;
  int exponent;
};

/*
  * @class Polynomial
  * @terms total number of terms in polynomial
  * @t points to the array of Terms 
*/

struct Polynomial
{
  int terms;
  struct Term *t;
  
};

void Create_polynomial(struct Polynomial *p){
  int i,j;
  printf("Enter the total number of terms in Polynomial");
  scanf("%d",&p->terms);

  /*creating the array of object Term which contains all the cofficient corresponding to their exponent row by row*/

  p->t=(struct Term *)malloc(p->terms*sizeof(struct Term));

  printf("Enter all terms of Polynomial\n");

  for(i=0;i<p->terms;i++){
    printf("term %d",i+1 );
    scanf("%d%d",&p->t[i].coeff,&p->t[i].exponent);
  }
  
}

/*Prints the polynomial on the screen by retrieving data through the array */

void Display(struct Polynomial p)
{
  int i;
  for(i=0;i<p.terms;i++){
    printf("%dx^%d+",p.t[i].coeff,p.t[i].exponent );
  }
}


/*Adding the two polynomials with help of two tables of object Polynomila which contains the information 
about the polynomial row by row *************************************************************************


firstly,i'm comparing the exponents of the two polynomial stored in two different array of structure

1 . if both the exponents are equal then we are going to store the exponent in the new created array in the
row of exponent in the resulted array of Polynomial and add the two corresponding coefficients

2 . if one of the exponent is greater ,then we'll be storing the datas from that array whose exponent is greater

3 . in the end the size of the new resulted array of object Polynomial is decided by the index pointer of the 
resulted array's value after completion*/


struct Polynomial * Add(struct Polynomial *p1,struct Polynomial *p2)
{
  int i,j,k;
  i=j=k=0;

  struct Polynomial *result=(struct Polynomial*)malloc(sizeof(struct Polynomial));

// the size of the created array to store result is initially assumed to be the sum of the number of terms in both the Polynomial 

  result->t=(struct Term *)malloc(p1->terms+p2->terms*sizeof(struct Term));

  while(i<p1->terms && j<p2->terms){
    if(p1->t[i].exponent >p2->t[j].exponent )
      result->t[k++]=p1->t[i++];
    else if(p1->t[i].exponent <p2->t[j].exponent )
      result->t[k++]=p2->t[j++];
    else{
      result->t[k]=p1->t[i];
      result->t[k++].coeff=p1->t[i++].coeff+p2->t[j++].coeff;
    }
  }

  for(;i<p1->terms;i++)
    result->t[k++]=p1->t[i++];
  for(;j<p2->terms;j++)
    result->t[k++]=p2->t[j++];

  result->terms=k;

  return result;

}

 

int main(){
  struct Polynomial p1,p2,*p3;
  Create_polynomial(&p1);
  Create_polynomial(&p2);
  Display(p1);
  printf("\n");
  Display(p2);
  printf("\n");
  p3=Add(&p1,&p2);
  printf("\n");
  Display(*p3);

  return 0;
}
