#include <iostream>
#include "linalg.cpp"
using namespace std;

int main() {
    double mat1[2][3] = {
        {3.0, 2.0, 1.0},
        {4.0, 7.0, 5.0}
    };

    double mat2[3][4] = {
        {3.0, 2.0, 1.0, 4.0},
        {4.0, 7.0, 5.0, 8.0},
        {1.0, 7.0, 3.0, 2.0}
    };

    Matrix *m = new Matrix(2,3);
    for ( int i = 0; i < 2; i++ )
        for ( int j = 0; j < 3; j++ )
            m->set(i, j, mat1[i][j]);
    
    Matrix *n = new Matrix(3,4);
    for ( int i = 0; i < 3; i++ )
        for ( int j = 0; j < 4; j++ )
            n->set(i, j, mat2[i][j]);
    
    Matrix* mn = m->multiply(n);
    Matrix* m_t = m->transpose();
    Matrix* n_t = n->transpose();
    cout << mn << endl;
    cout << m_t << endl;
    cout << n_t << endl;
    return 0;
}