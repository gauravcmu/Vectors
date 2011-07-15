#include <stdio.h>


int A[] = {11, 32 ,2, 7, 1, 15 };

void
merge_sort(int A[], int startIndex, int endIndex)
{
    int q = 0;
    //Terminating condition
    if (!(startIndex < endIndex)) {
       return; 
    }

    q = (startIndex + endIndex) / 2;
    merge_sort(A, startIndex, q);
    merge_sort(A, q+1, endIndex);
    printf("\n merge with start[%d], q[%d], end[%d]", startIndex,q, endIndex);
    merge(A, startIndex, q, endIndex);
}

merge(int A[], int startIndex, int q, int endIndex)
{
   int i = 0; int j = 0; int k=0;  
   int C[endIndex - startIndex + 1];
   int A1[q - startIndex + 1];
   int A2[endIndex - q];
   int lenA1 =q - startIndex + 1;
   int lenA2 = endIndex - q; 
   int iterator = 0;
   int lenA = endIndex - startIndex + 1;

   for(iterator = 0; iterator < lenA1; iterator++) {
      A1[iterator] = A[iterator + startIndex]; 
      printf("\n Iterator1[%d]", iterator + startIndex);
   }

    dump(A1, lenA1);
   for(iterator = 0; iterator < lenA2; iterator++) {
      A2[iterator] = A[iterator + q + 1]; 
      printf("\n Iterator2[%d]", iterator + q + 1);
   }

    dump(A2, lenA2);

   for (iterator = startIndex; iterator < (endIndex - startIndex + 1) && ((i < lenA1) && (j<lenA2)); iterator++)
   {
       if (A1[i] <= A2[j]) {
           A[k] = A1[i]; 
           printf("\n\t--A[k]--");
           k+=1;
           i+=1; 
       } else {
           A[k] = A2[j];
           printf("\n\t****A[k]***");
           j+=1; 
           k+=1;      
       }
   }
   if (j < lenA2) {
      for (iterator = j; iterator < lenA2; iterator++)
      {
           A[k] = A2[j];
           j+=1; 
           k+=1;      
      }
   } else if (i < lenA1) {
           A[k] = A1[i]; 
           k+=1;
           i+=1; 
   }
    dump(A, lenA);
    fflush(stdout);

}

void dump(int A[], int len)
{
    int i;
    printf("\n --------");
    for(i=0; i<len; i++)
    {
        printf("[%d] ", A[i]);
    }
}

int main()
{
    merge_sort(A, 0, 6);
    dump(A, 7);
//    dump(C, 7);
}

