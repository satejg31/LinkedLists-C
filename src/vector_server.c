
/*

    @ DATE : 22/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : SERVER FILE FOR THE VECTOR DATA STRUCTURE

*/

#include <stdio.h>
#include <stdlib.h>

#include "../include/vector.h"


/* Vector Creation Routine */
vector_t *create_vector(void)
{
    vector_t *p_vec = NULL;
    p_vec = (vector_t *)xmalloc(sizeof(vector_t));

    p_vec->p_vector = NULL;
    p_vec->size = 0;

    return (p_vec);
}

/* Vector Specific Routines */
status_t push_back(vector_t *p_vec, data_t new_data)
{
    p_vec->p_vector = (data_t *)realloc(p_vec->p_vector, (p_vec->size + 1) * sizeof(data_t));
    if(p_vec->p_vector == NULL)
    {
        fprintf(stderr, "Error in Memory Allocation");
        return (EXIT_FAILURE);
    }

    p_vec->size = p_vec->size + 1;
    p_vec->p_vector[p_vec->size - 1] = new_data;

    return (SUCCESS); 
}

void show(vector_t *p_vec, const char* msg)
{
    if(msg)
    {
        puts(msg);
    }

    int i = 0;
    printf("[START]-");
    while(i < p_vec->size)
    {
        printf("[%d]-", p_vec->p_vector[i]);
        ++i;
    }

    printf("[END]");
}

status_t destroy_vector(vector_t *p_vec)
{
    free(p_vec->p_vector);
    p_vec->p_vector = NULL;
    free(p_vec);
    p_vec = NULL;

    return (SUCCESS);
}
