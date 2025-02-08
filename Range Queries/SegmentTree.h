// Created by Divya on 23-08-2024.

#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#include <bits/stdc++.h>
using namespace std;

template<class T>
class SegmentTree {
    vector<T> tree;
    T identity;
    function<T(T, T)> merge;
    int n;

public:
    explicit SegmentTree(vector<T> &arr, T _identity = INT_MAX, function<T(T, T)> _merge = [](T a, T b){return min(a, b);})
    :identity(_identity),  merge(std::move(_merge)) {
        n = arr.size();
        n = (n&-n)==n?n: 1<<__lg(n)+1;

        tree = vector<T>(2*n, identity);
        for(int i=0; i<arr.size(); ++i)
            tree[i+n] = arr[i];

        for(int i=n-1; i>0; --i)
            tree[i] = merge(tree[2*i] , tree[2*i+1]);
    }

    void update(int i, T val) {
        i += n;
        tree[i] = val;
        for(i >>= 1; i>0; i >>=1)
            tree[i] = merge(tree[i<<1] , tree[(i<<1)+1]);
    }

    T query(int l, int r, int l1=0, int r1 = -1, int i=1) {
        if(r1 == -1) r1 = n-1;
        if(l1 > r || r1 < l) return identity;
        if(l1 >= l && r1 <= r) return tree[i];
        int mid = l1 + (r1-l1)/2;
        return merge(query(l, r, l1, mid, 2*i) , query(l, r, mid+1, r1, 2*i+1));
    }
};

#endif // SEGMENTTREE_H
