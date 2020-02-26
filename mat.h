#ifndef MAT_H
#define MAT_H
#include <iostream>
using namespace std;


class Matrix {
    private:
        double **mat;
    public:
        int n_row;  // defne number of rows
        int n_col;  // define number of cols

        // declare an empty constructor
        Matrix () {

        }

        // Constructor
        // create 2-d array to store matrix data
        Matrix (const int size_x, const int size_y) {
            mat = new double*[size_x];
            for ( int i = 0; i < size_x; i++ ) {
                mat[i] = new double[size_y];
            }
            n_row = size_x;
            n_col = size_y;
        }

        /*  Params: matrix B
        *   Return: new matrix as the product of this_matrix and B
        */
        Matrix* multiply(Matrix *n) {
            if ( n_col != n->n_row ) {
                throw "ERROR: Cannot multiply, dimensions don't match";
                Matrix *ret;
                return ret;
            }
            Matrix *ans = new Matrix(n_row, n->n_col);
            for ( int i = 0; i < n_row; i++ ) {
                for ( int j = 0; j < n->n_col; j++ ) {
                    double value = 0.0;
                    for ( int k = 0; k < n_col; k++ ) {
                        value += mat[i][k] * n->get(k, j);
                    }
                    ans->set(i, j, value);
                }
            }

            return ans;
        }

        /*  Return the transpose of this_matrix
        */
        Matrix* transpose() {
            Matrix* ans = new Matrix(n_col, n_row);
            for ( int i = 0; i < n_col; i++ ) {
                for ( int j = 0; j < n_row; j++ ) {
                    ans->set(i, j, mat[j][i]);
                }
            }
            return ans;
        }

        /*  Params: take matrix index to get data (r,c)
        *   Return: value at the index
        */
        double get(int r, int c) {
            if ( r >= n_row || r < 0 || c >= n_col || c < 0 ) {
                throw "ERROR: Invalid index access";
                return 0.0;
            }
            return mat[r][c];
        }

        /*  Params: 
                - take matrix index to set data (r,c)
                - value to cout << set
        *   Return: success/failure
        */
        bool set(int r, int c, double val) {
            if ( r >= n_row || r < 0 || c >= n_col || c < 0 ) {
                throw "ERROR: Invalid index access";
                return false;
            }
            mat[r][c] = val;
            return true;
        }

        /*  This function overloads the default cout << 
        *   output
        */
        friend ostream& operator<<(ostream& os, Matrix *mat) {
            os << '[';
            for ( int i = 0; i < mat->n_row; i++ ) {
                os << "[";
                for ( int j = 0; j < mat->n_col; j++ ) {
                    os << mat->get(i, j);
                    if ( j < mat->n_col - 1 )
                        os << ", ";
                }
                os << "]";
                if ( i < mat->n_row - 1 )
                    os << ",\n";

            }
            os << "]";
            return os;
        }

        // Destructor
        ~Matrix() {
            for ( int i = 0; i < n_row; i++ ) 
                delete[] mat[i];
            delete[] mat;
        }
};
#endif