#ifndef BINDINGS_H
#define BINDINGS_H
#include <cblas.h>
#include <stdlib.h>

typedef struct Matrix {
    size_t nrow;
    size_t ncol;
    float data[];
} Matrix;

Matrix* create_matrix(int nrow, int ncol, float data[]); 
void free_matrix(Matrix* m);
Matrix* matrix_dot(Matrix* a, Matrix *b);

#endif
