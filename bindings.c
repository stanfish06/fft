#include "bindings.h"
#include <stdlib.h>
#include <string.h>

Matrix* create_matrix(size_t nrow, size_t ncol, double _Complex *data) {
    size_t n = nrow * ncol;
    Matrix* m = malloc(sizeof(*m));
    m->nrow = nrow;
    m->ncol = ncol;
    m->data = data;
    return m;
} 

void free_matrix(Matrix* m) {
    free(m);
}

Matrix* matrix_dot(Matrix* a, Matrix *b) {
    size_t sz_c_data = sizeof(double _Complex) * a->nrow * b->ncol;
    double _Complex *c_data = malloc(sz_c_data);
    memset(c_data, 0, sz_c_data);
    Matrix *c = create_matrix(a->nrow, b->ncol, c_data);
    double complex alpha = 1.0 + 0.0I;
    double complex beta = 0.0 + 0.0I;
    cblas_zgemm(
        CblasRowMajor,
        CblasNoTrans,
        CblasNoTrans,
        a->nrow,
        b->ncol,
        a->ncol,
        &alpha,
        a->data,
        a->ncol,
        b->data,
        b->ncol,
        &beta,
        c->data,
        c->ncol
    );
    return c;
}
