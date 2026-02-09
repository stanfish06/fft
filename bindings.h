#ifndef BINDINGS_H
#define BINDINGS_H
#include <cblas.h>
#include <stdlib.h>
#include <complex.h>

typedef struct Matrix {
    size_t nrow;
    size_t ncol;
    float _Complex *data; // manage data from rust
} Matrix;

Matrix* create_matrix(size_t nrow, size_t ncol, float _Complex *data); 
void free_matrix(Matrix* m);
Matrix* matrix_dot(Matrix* a, Matrix *b);

#endif
