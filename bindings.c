#include "bindings.h"
#include <stdlib.h>
#include <string.h>

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
    size_t sz_c_data = sizeof(float) * a->nrow * b->ncol;
    float *c_data = malloc(sz_c_data);
    memset(c_data, 0, sz_c_data);
    Matrix *c = create_matrix(a->nrow, b->ncol, c_data);
    cblas_sgemm(
        CblasRowMajor,
        CblasNoTrans,
        CblasNoTrans,
        a->nrow,
        b->ncol,
        a->ncol,
        1.0,
        a->data,
        a->ncol,
        b->data,
        b->ncol,
        0.0,
        c->data,
        c->ncol
    );
    return c;
}
