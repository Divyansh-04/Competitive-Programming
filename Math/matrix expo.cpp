#include <bits/stdc++.h>
using namespace std;

int constexpr mod = 1e9+7;

template<typename T>
class Matrix{
    int n=0, m=0;
public:
    vector<vector<T>> mat;
    Matrix(vector<vector<T>> &a) {
        n = sz(a), m = sz(a[0]);
        mat = a;
    }

    bool isSquare() {
        return n == m;
    }

    Matrix(int _n, T &identity) { // identity square matrix of size _n
        n = _n, m = n;
        mat = vector(_n, vector<T>(m, identity));
        for (int i=0; i<n; ++i)
            mat[i][i] = 1;
    }

    Matrix operator * (const Matrix &b) {
        assert(m == b.n);
        vector res(n, vector<T>(b.m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    res[i][j] += mat[i][k]*b.mat[k][j];
                }
            }
        }
        return {res};
    }


    Matrix& operator %= (int m) {
        for (auto &i: mat)
            for (auto &j: i)
                j %= m;
        return *this;
    }
};

template<typename T>
Matrix<T> matExp(Matrix<T> b, long long e, long long m=mod){
    assert(b.isSquare());
    Matrix<T> ans = Matrix(b.size().first, b.mat[0][0]); // identity
    while(e) {
        if (e & 1) {
            ans = ans * b;
        }
        b = b * b;
        e >>= 1;
    }
    return ans;
}
