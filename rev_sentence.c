#include <stdio.h>

void 
reverse (char A[] ) 
{
    char * temp = A;   
    char * word_begin = A;
    int length = 0;
 
    while (temp) {
        if (*temp != '\0') {
            if (*temp == ' ') {
                printf("\nspace");
                reverseWord(word_begin, length);
                temp = temp + 1;                
                word_begin = temp;
                length = 0;
            } else {
                printf("\n char");
                temp = temp + 1;
                length = length + 1;
            }
        } else {
            printf("\n end of string");
            reverseWord(word_begin, length);
            break;
        }
    }    
   reverseWord(A, strlen(A));
   printf("sentence is %s", A);
}

void 
reverseWord(char word[], int length) {
    char c;
    int i, j;
    printf("length is [%d]", length);
    if (length <= 1) return;
  
    for (i = 0, j = length - 1; i < j; i++, j--) {
        c = word[i];
        word[i] = word[j];
        word[j] = c;            
    }
}

int main() {
   char test[] =  "I am good";
   reverse (test);
}
