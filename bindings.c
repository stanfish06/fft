#include "bindings.h"
Matrix* create_matrix(size_t nrow, size_t ncol, float *data) {
    size_t n = nrow * ncol;
    Matrix* m = malloc(sizeof(*m));
    m->nrow = nrow;
    m->ncol = ncol;
    m->data = data;
    return m;
} 

void free_matrix(Matrix* m) {
    free(m);
    m = NULL;
}

Matrix* matrix_dot(Matrix* a, Matrix *b) {
    return NULL;
}
