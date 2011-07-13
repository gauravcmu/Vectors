#include <stdio.h>
#include <string.h>


void reverse_string (char sentence[], int start_index, int len)
{
    int i = 0; 
    int j = len - 1; 
    char temp;

    fflush(stdout);
    for(i = start_index, j; i < j; i++, j--) {
        temp = sentence[i];
        sentence[i] = sentence[j];
        sentence[j] = temp;
    }
    printf("sentece is [%s]", sentence); 
}

int
getToken(char sentence[], int *start_index, int *len)
{
   static int startFrom = 0;
   int i =0;
  // if (sentence[i] == '\0')
   if (startFrom == strlen(sentence))
   {
      printf("\n\n******returning -1 *********\n\n");
      return -1;
   }

   for (i = startFrom; i < strlen(sentence); i++)
   {
       (*len)++;
       if (sentence[i] == ' ')        
       {
           *start_index = startFrom; 
           startFrom = i+1;
           return 0;
       }
   } 
}

void reverse_sentence(char sentence[])
{
   int i = 0;
   int start_index = 0;
   int len = 0;
   reverse_string(sentence, 0, strlen(sentence)); 
   while (0 == getToken(sentence, &start_index, &len))
   {
       reverse_string(sentence, start_index, len);
   }
}

int main() 
{
    char sentence[] = "I m being interviewed";
    reverse_sentence(sentence);
}
