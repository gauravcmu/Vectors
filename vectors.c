#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_INCREMENT 5*sizeof(int) 
#define SIZE_INITIAL 10
#define SIZE_MAX 1000

typedef struct vector_ {
    int size; //size of the vector
    int num_elements;
    int * a;
} vector;

vector * create_vector (int size) 
{
    vector * vector = NULL;
    if(size)
    { 
        vector = malloc(sizeof(vector));
	vector->a = (int *)calloc(size, sizeof(int));
        if (vector->a) 
        {
            vector->size = size;
            vector->num_elements = 0;
            printf("\n init vector num_elements[%d]", vector->num_elements);
        }
    } else {
        vector = NULL;
    }
    return vector; 
}



//remove an element from the array
erase()
{

}

//returns the current size of the vector. 
int size (vector * vec) 
{
    return (vec->size);
}

void vector_print(vector * vec)
{
   int i = 0;
    printf("\n Vector is [");
    for (i = 0; i < vec->num_elements; i++)
    {
        printf(" %d,", vec->a[i]);
    }
    printf("]\n");
}

//inserts element in the back. increases the size of the vector if needed. 
int
push_back (vector * vec, int value)
{
    if (vec->num_elements == vec->size)
    {
        //vector should grow by X amount.
        vec->a = realloc(vec->a, SIZE_INCREMENT);
        if (!vec->a)
        {
           printf("\n ERROR re-allocating vector");
           return -1; 
        }
        vec->size += SIZE_INCREMENT;
    }

    memcpy((vec->a + vec->num_elements), &value, sizeof(value)); 
    vec->num_elements = vec->num_elements + 1;

    return 0;
}

void shift_right(vector * vec, int index) 
{
    int i = 0;
    if (vec->num_elements == vec->size) {
        vec->a = realloc(vec->a, vec->size + SIZE_INCREMENT);
    } 
    for (i=vec->num_elements; i > index ; i--) 
    {
       printf("\na[i]%d a[i-1]%d", vec->a[i], vec->a[i-1] );
       vec->a[i] = vec->a[i-1]; 
    }
}
//inserts the element in the middle of the vector. 
insert(vector * vec, int index, int value)
{
    if (index >= vec->num_elements) {
        if (index == vec->num_elements) 
        {
             push_back(vec, value);      
        } else {
           printf("\nNOT ALLOWED");
           return -1;
        }
    } else {
        shift_right(vec, index);
        vec->a[index] = value;
        vec->num_elements++;
    }
}

void vector_destroy(vector * vec) 
{
    free(vec->a);
    free(vec);
}

int main()
{

    //create a vector vec
    vector * vec = NULL;
    vec = create_vector(4);
    if (!vec)
    printf("\n FAILED");

    
    push_back(vec, 4); 
    push_back(vec, 5); 
    push_back(vec, 6); 
    push_back(vec, 7); 
    push_back(vec, 8); 
    push_back(vec, 9); 
    insert(vec, 2, 11);
    push_back(vec, 10); 
    vector_print(vec);

    vector_destroy(vec);
   return 0; 
}
