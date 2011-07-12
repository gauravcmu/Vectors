#include <stdio.h>
#include <stdlib.h>

typedef struct vector_ {
    int size; //size of the vector
    int * a;
} vector;

vector * create_vector (int size) 
{
    vector * vector = NULL;
    if(size)
    { 
        vector = calloc(1, sizeof(vector));
	vector->a = calloc(size, sizeof(int));
        if (vector->a)
            vector->size = size;
    } else {
        vector = NULL;
    }
    return vector; 
}

//inserts element in the back. increases the size of the vector if needed. 
push_back (int * vector, int value)
{

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


int main()
{

    //create a vector vec
    vector * vec = NULL;
    vec = create_vector(100);
    if (vec)
    printf("allocated %d", size(vec));
   return 0; 
}
