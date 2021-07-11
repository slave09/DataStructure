/*
  author Fakhra Najm,
  email : fnajm09@gmail.com
**/

#include<stdio.h>
#include<stdlib.h>

//creating object element which will store row index ,column index and the element itself

struct Element
{
  int i;
  int j;
  int x;
};

// sparse will contain total number of rows,columns and elements as well as it have a pointer 
//to the element e which can retrieve all the datas from element

struct Sparse
{
  int m;
  int n;
  int num;
  struct Element *e;
};

void Create(struct Sparse *s);
struct Sparse * Add(struct Sparse *s1,struct Sparse *s2);
void Display(struct Sparse s);

//@create by creating an array which is pointed by sparse dynamically of the size equal to the total number
//of non-zero elements in the sparse matrix 
//@create by storing all the non zero elements along with their row index ,column index,and element itself

void Create(struct Sparse *s)
{
  int i;

  printf("Enter Dimension:");
  scanf("%d%d",&s->m,&s->n);
  printf("Enter number of non-zero elements:");
  scanf("%d",&s->num);
  s->e = (struct Element *)malloc(s->num*sizeof(struct Element ));

  printf("Enter datas for all non-zero elements:");

  for(i = 0; i < s->num; i++){
    scanf("%d%d%d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
  }
}

/*
  * addition of two sparse matrix
  * @param sparse s1 pointer to the first matrix 
  * @param sparse s2 pointer to the second matrix 
  * @return sum of two sparse matrix
*/

struct Sparse * Add(struct Sparse *s1,struct Sparse *s2){
//creating a new object sum which will store the final values of newly formed sparse matrix
//and contains Element object e which will store datas after addition of the two matrices
  struct Sparse *sum;
  int i,j,k;
  i = j = k = 0;
  sum=(struct Sparse *)malloc(sizeof(struct Sparse));
//the exact size of the sum Matrix could not be find before the addition but we can find the 
//the maximum lenght of the matrix which is the sum of total number of non-zero elements in both sparse matrices which is to be added.
  sum->e=(struct Element *)malloc(s1->m+s2->m*sizeof(struct Element));
  if(s1->m==s2->m && s1->n==s2->n){
    while(i<s1->num && j<s2->num){
      if(s1->e[i].i<s2->e[j].i)
        sum->e[k++]=s1->e[i++];
      else if(s1->e[i].i>s2->e[j].i)
        sum->e[k++]=s2->e[j++];
      else{
        if(s1->e[i].j<s2->e[j].j)
          sum->e[k++]=s1->e[i++];
        else if(s1->e[i].j>s2->e[j].j)
          sum->e[k++]=s2->e[j++];
        else{
          sum->e[k]=s1->e[i];
          sum->e[k++].x=s1->e[i++].x+s2->e[j++].x;
        }
      }
    }
  }
  for(;i<s1->num;i++)
    sum->e[k++]=s1->e[i++];
  for(;j<s2->num;j++)
    sum->e[k++] = s2->e[j++];
  sum->m = s1->m;
  sum->n = s1->n;
  sum->num = k;
  return sum;
}

/*
  * prints the sparse matrix
  * @param the sparse pointer to the sparse matrix
*/

void Display(struct Sparse s)
{
  int i,j,k=0;
//checking if the row index i(here) and column index j(here) are present in the element of the sparse
//if it is present in the array then it will display the corresponding element from the array otherwise,
//it will display a 0 on the screen  
  for(i=0;i<s.m;i++){
    for(j=0;j<s.m;j++){   
      if(i==s.e[k].i && j==s.e[k].j)
        printf("%d  ",s.e[k++].x );
      else
        printf("0  ");
    }
    printf("\n");
  }
}

int main(){
  struct Sparse s1,s2,*s3;
  printf("Details of first sparse Matrix:\n");
  Create(&s1);
  printf("Details of second sparse Matrix:\n");
  Create(&s2);
  s3=Add(&s1,&s2);
  Display(*s3);
  return 0;
}
