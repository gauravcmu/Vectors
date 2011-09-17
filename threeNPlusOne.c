#include<stdio.h>

int
findTrans(int n) 
{
    int cycles = 0;
    while (n) {
        if (n ==1) {
            cycles++;
            break;
        }
        if (n%2 == 0) {
             n>>=1; 
        } else {
           n = 3*n + 1;
        }
        cycles++;
    }
   return cycles;
}

int
func(int start, int end)
{
    int max = -1, cudBeMax = 0;
    int temp = start;

    while (temp <= end) {
        cudBeMax = findTrans(temp);
        if (cudBeMax > max) { 
            max = cudBeMax;
        }
        temp++;
    }
    return max;
}

int main()
{
    int result = 0;
    int start =0;
    int end = 0;

    while (scanf("%d%d", &start, &end)!=EOF) {
        if (start < end)
        result = func(start, end);
        else
        result = func(end, start);
     
        printf("%d %d %d\n", start, end, result);
    }
    return 0;
}
