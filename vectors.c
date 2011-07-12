#include <stdio.h>
#include <stdlib.h>

#define SIZE_INCREMENT 5 
#define SIZE_INITIAL 10
#define SIZE_MAX 1000

typedef struct vector_ {
    int size; //size of the vector
    int * a;
    int num_elements;
} vector;

vector * create_vector (int size) 
{
    vector * vector = NULL;
    if(size)
    { 
        vector = calloc(1, sizeof(vector));
	vector->a = calloc(size, sizeof(int));
        if (vector->a) 
        {
            vector->size = size;
            vector->num_elements = 0;
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
    int index = 0;
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
    index = vec->num_elements;
    printf("   index [%d]", index);
    vec->a[index] = value; 
    vec->num_elements++;
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
    vec = create_vector(5);
    if (!vec)
    printf("\n FAILED");

    vector_print(vec);
    
    push_back(vec, 1); 
    vector_print(vec);
    push_back(vec, 2); 
    vector_print(vec);
    push_back(vec, 3); 
    vector_print(vec);
    push_back(vec, 4); 
    vector_print(vec);
    push_back(vec, 5); 
    vector_print(vec);
    push_back(vec, 6); 
    vector_print(vec);
    push_back(vec, 7); 
    vector_print(vec);
   return 0; 
}
