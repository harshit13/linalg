#include <iostream>
using namespace std;

class Matrix {
    private:
        double **mat;
    public:
        int n_row;
        int n_col;
        Matrix () {

        }
        Matrix (const int size_x, const int size_y) {
            mat = new double*[size_x];
            for ( int i = 0; i < size_x; i++ ) {
                mat[i] = new double[size_y];
            }
            n_row = size_x;
            n_col = size_y;
        }
        Matrix multiply(Matrix &n) {
            if ( n_col != n.n_row ) {
                cout << "ERROR: Cannot multiply, dimensions don't match" << endl;
                Matrix ret;
                return ret;
            }
            Matrix ans(n_row, n.n_col);
            for ( int i = 0; i < n_row; i++ ) {
                for ( int j = 0; j < n.n_col; j++ ) {
                    double value = 0.0;
                    for ( int k = 0; k < n_col; k++ ) {
                        value += mat[i][k] * n.get(k, j);
                    }
                    ans.set(i, j, value);
                }
            }

            return ans;
        }

        Matrix transpose() {
            Matrix ans(n_col, n_row);
            for ( int i = 0; i < n_col; i++ ) {
                for ( int j = 0; j < n_row; j++ ) {
                    ans.set(i, j, mat[j][i]);
                }
            }
            return ans;
        }

        double get(int r, int c) {
            if ( r >= n_row || r < 0 || c >= n_col || c < 0 ) {
                cout << "ERROR: Invalid index access" << endl;
                return 0.0;
            }
            return mat[r][c];
        }

        bool set(int r, int c, double val) {
            if ( r >= n_row || r < 0 || c >= n_col || c < 0 ) {
                cout << "ERROR: Invalid index access" << endl;
                return false;
            }
            mat[r][c] = val;
            return true;
        }

        friend ostream& operator<<(ostream& os, Matrix& mat) {
            os << '[';
            for ( int i = 0; i < mat.n_row; i++ ) {
                os << "[";
                for ( int j = 0; j < mat.n_col; j++ ) {
                    os << mat.get(i, j);
                    if ( j < mat.n_col - 1 )
                        os << ", ";
                }
                os << "]";
                if ( i < mat.n_row - 1 )
                    os << ",\n";

            }
            os << "]";
            return os;
        }

        // ~Matrix() {
        //     for ( int i = 0; i < n_row; i++ ) 
        //         delete[] mat[i];
        //     delete[] mat;
        // }
};