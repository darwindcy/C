#include <stdio.h>
#include <stdlib.h>

#include "vector.c"
#include "vector.h"

int main()
{
    char result[100];
    vector_t u, v;

    u = make_vector(1,2,3);
    v = make_vector(1,2,3);

    //vec2a(u, result);

    vec_add(u, v);
    vec_sub(u,v);
    vec_scale(u,2);
    vec_dot(u,v);
    vec_cross(u,v);
    vec_magnitude(u);
    vec_unitvector(u);
    vec_unitnormal(u,v);
    vec2a(vec_add(u,v), result);
    printf("The sum is %s\n", result);

    vec2a(vec_sub(u,v), result);
    printf("The difference is %s", result);
    //printf("The vector result %s", result);
   // printf("The vector is ");
    //printf("<%g, %g, %g>", u.x, u.y, u.z);
    printf("\n");
    return 0;
}



