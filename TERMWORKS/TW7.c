/* TW 7 Program for addition of two polynomials
 * polynomial are stored using structure
 * and program uses array of structures
 */

#include<stdio.h>

typedef struct poly
{
    int coff;
    int expo;
}poly;

int readPoly(poly [30]);
int addPoly(poly [30], poly [30], poly [30], int, int);
void display(poly [30], int);

int readPoly(poly p[30])
{
   int t,i;
   printf("\nEnter the total number of terms in the polynomial: ");
   scanf("%d",&t);
   printf("\nEnter the COEFFICIENT and EXPONENT in DESCENDING ORDER");
   for(i=0;i<t;i++)
   {
       printf("\nEnter the coefficient(%d): ",i+1);
       scanf("%d",&p[i].coff);
       printf("\nEnter the exponent(%d): ",i+1);
       scanf("%d",&p[i].expo);        /* only statement in loop */
   }
   return(t);
}

int addPoly(poly p1[30], poly p2[30], poly p3[30], int t1, int t2)
{
    int i,j,k;
    i=j=k=0;
    
    while(i<t1 && j<t2)
    {
        if(p1[i].expo == p2[j].expo)
        {
            p3[k].coff = p1[i].coff + p2[j].coff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        }
        else if(p1[i].expo > p2[j].expo)
        {
            p3[k].coff = p1[i].coff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        }
        else
        {
            p3[k].coff = p2[j].coff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }
    }
    
    while(i < t1)
    {
        p3[k].coff = p1[i].coff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }
    while(j < t2)
    {
        p3[k].coff = p2[j].coff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }
    return (k);
}

void display(poly p[30], int t)
{
    int i;
    for(i=0;i<t;i++)
        printf("%d(x^%d) ",p[i].coff,p[i].expo);
    printf("\n");
}

int main(void)
{
    poly p1[30], p2[30], p3[30];
    int t1,t2,t3;
    
    t1 = readPoly(p1);
    printf("\nFirst polynomial: ");
    display(p1,t1);
    
    t2 = readPoly(p2);
    printf("\nSecond polynomial: ");
    display(p2,t2);
    
    t3 = addPoly(p1,p2,p3,t1,t2);
    printf("\nSummation of polynomials: ");
    display(p3,t3);
    
    printf("\n");
    return 0;
}
