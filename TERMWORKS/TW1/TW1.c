// C program to find union of
// two sorted arrays
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Function prints union of arr1[] and arr2[]
m is the number of elements in arr1[]
n is the number of elements in arr2[] */
void printUnion(char arr1[][15], char arr2[][15], int m, int n, FILE *f3)
{
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (strcmp(arr1[i],arr2[j])<0)
        {
            printf("\n%s", arr1[i]);
            fprintf("\n%s", arr1[i++]);
        }
        else if (strcmp(arr2[j],arr1[i])<0)
             {
                printf("\n%s", arr2[j]);
                fprintf("\n%s", arr2[j++]);
             }
        else {
                printf("\n%s", arr2[j]);
                fprintf("\n%s", arr2[j++]);
                i++;
        }
    }

    /* Print remaining elements of the larger array */
    while (i < m)
        printf("\n%s", arr1[i++]);
    while (j < n)
        printf("\n%s", arr2[j++]);
}


void printIntersection(char arr1[][15], char arr2[][15], int m, int n)
{
    int i = 0, j = 0;
    for(i=0; i<m; i++)
      for(j=0; j<n; j++)
         if (strcmp(arr1[i],arr2[j])==0)
            printf("\n%s", arr1[i]);

}

/* Driver program to test above function */
int main()
{
    FILE *f1, *f2, *f3;
    char one[15][15], two[15][15];
    int m=0,n=0;

    f1=fopen("./first", "r");
    f2=fopen("./second", "r");
    f3=fopen("./third", "w");

    if(f1==NULL || f2==NULL || f3==NULL)
    {
        printf("\nFile open error");
        exit(1);
    }

    printf("\nFile1:\n");
    while(!feof(f1))
          {fscanf(f1,"%s",one[m++]); puts(one[m-1]);}

    printf("\nFile2:\n");
    while(!feof(f2))
    {fscanf(f2,"%s",two[n++]); puts(two[n-1]);}


    printf("\nUnion:");
    printUnion(one, two, m, n, f3);

    printf("\nCommon:");
    printIntersection(one, two, m, n);
    getchar();
    return 0;
}
