#include<stdio.h>

int
findPattern(char * word, char * pattern)
{
    int i, j;
    int patternLen, wordLen;
 
    patternLen = strlen(pattern);
    wordLen = strlen(word);

    for (i = 0; i<=(wordLen - patternLen); i++)
    {
        j = 0;
        while ((j<patternLen) && (word[i+j]== pattern[j]))
        {
            j++;
        }
        if (j==patternLen) return i;
    }
    return -1;
}
int main()
{
    char * pattern  = "the";
    char * word = "what is the name";
    int result = 0; 
    result = findPattern(word, pattern);
    printf("\nresult is %d", result);
}
