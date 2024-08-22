// // Created by Divya on 23-08-2024.
//

#include <bits/stdc++.h>
using namespace std;

#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#endif //SEGMENTTREE_H

class SegmentTree {
    vector<long long> tree;
    int n;
public:
    SegmentTree(vector<long long> &arr) {
        n = arr.size();
        n = (n&-n)==n?n: 1<<__lg(n)+1;
        tree = vector<long long>(2*n, INT_MAX);
        for(int i=0; i<arr.size(); ++i)
            tree[i+n] = arr[i];

        for(int i=n-1; i>0; --i)
            tree[i] = min(tree[2*i] , tree[2*i+1]);
    }

    void update(int i, int val) {
        i += n;
        tree[i] = val;
        for(i >>= 1; i>0; i >>=1)
            tree[i] = min(tree[i<<1] , tree[(i<<1)+1]);
    }

    int query(int l, int r, int l1=0, int r1 = -1, int i=1) {
        if(r1 == -1) r1 = n-1;
        if(l1 > r || r1 < l) return INT_MAX;
        if(l1 >= l && r1 <= r) return tree[i];
        return min(query(l, r, l1, l1+(r1-l1)/2, 2*i) , query(l, r, l1+(r1-l1+1)/2, r1, 2*i+1));
    }
};
