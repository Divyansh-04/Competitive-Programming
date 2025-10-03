//
// Created by Divya on 28-08-2025.
//
#include <bits/stdc++.h>
using namespace std;


template<class T>
void rotate(vector<vector<T>> &a) { // anti clockwise
    int n = sz(a), m = sz(a[0]);
    vector<vector<T>> temp(m, vector<T>(n));

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            temp[m-1-j][i] = a[i][j];
        }
    }

    a = move(temp);
}


