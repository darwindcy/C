/*
 * CS 210:Machine Problem 6
 * Vector library-source file
 * Author: Darwin Charles Yadav
 */

#include "vector.h"

vector_t make_vector(double x, double y, double z){
    vector_t vector;

    vector.x = x;
    vector.y = y;
    vector.z = z;

    return vector;
}
void vec2a(vector_t v, char result[]){
    sprintf(result, "<%.3f,%.3f,%.3f>", v.x, v.y, v.z);
}
vector_t vec_add(vector_t u, vector_t v){
    vector_t sum;
    sum.x = u.x + v.x;
    sum.y = u.y + v.y;
    sum.z = u.z + v.z;
    return sum;
}
vector_t vec_sub(vector_t u, vector_t v){
    vector_t sub;
    sub.x = u.x - v.x;
    sub.y = u.y - v.y;
    sub.z = u.z - v.z;
    return sub;
}
vector_t vec_scale(vector_t u, double k){
    vector_t scale;
    scale.x = k * u.x;
    scale.y = k * u.y;
    scale.z = k * u.z;
    return scale;
}
double vec_dot(vector_t u, vector_t v){
    double dot;
    dot = u.x * v.x + u.y * v.y + u.z * v.z;
    return dot;
}
vector_t vec_cross(vector_t u, vector_t v){
    vector_t cross;
    cross.x = u.y * v.z - u.z * v.y;
    cross.y = u.z * v.x - u.x * v.z;
    cross.z = u.x * v.y - u.y * v.x;
    return cross;
}
double vec_magnitude(vector_t u){
    double magnitude;
    magnitude = pow((u.x * u.x + u.y * u.y + u.z * u.z), 0.5);
    return magnitude;
}
vector_t vec_unitvector(vector_t u){
    vector_t unitvector;
    double magnitude = vec_magnitude(u);
    unitvector.x = u.x / magnitude;
    unitvector.y = u.y / magnitude;
    unitvector.z = u.z / magnitude;
    return unitvector;
}
vector_t vec_unitnormal(vector_t u, vector_t v){
    vector_t unitnormal;
    unitnormal = vec_unitvector(vec_cross(u,v));

    return unitnormal;
}
