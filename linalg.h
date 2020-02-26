#ifndef LINALG_H
#define LINALG_H
#include <iostream>
#include "mat.h"
using namespace std;

class LinAlg {
    public:
        /*  Params: 2 matrix to multiply
        *   Return: Product of input matrix
        */
        static Matrix* multiply(Matrix *m, Matrix *n) {
            if ( m->n_col != n->n_row ) {
                throw "ERROR: Cannot multiply, dimensions don't match";
                Matrix *ret;
                return ret;
            }
            Matrix *ans = new Matrix(m->n_row, n->n_col);
            for ( int i = 0; i < m->n_row; i++ ) {
                for ( int j = 0; j < n->n_col; j++ ) {
                    double value = 0.0;
                    for ( int k = 0; k < m->n_col; k++ ) {
                        value += m->get(i, k) * n->get(k, j);
                    }
                    ans->set(i, j, value);
                }
            }
            return ans;
        }
};
#endif