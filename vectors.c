#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_INCREMENT 5 
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


//inserts the element in the middle of the vector. 
insert()
{

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

    printf("address a[%p], a of offset[%p]", vec->a, (vec->a + vec->num_elements));
    memcpy((vec->a + vec->num_elements), &value, sizeof(value)); 
    printf("\n num_elements[%d]", vec->num_elements);

    vec->num_elements = vec->num_elements + 1;

    printf("\n num_elements[%d]", vec->num_elements);
    return 0;
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
    push_back(vec, 10); 
    vector_print(vec);

    vector_destroy(vec);
   return 0; 
}
