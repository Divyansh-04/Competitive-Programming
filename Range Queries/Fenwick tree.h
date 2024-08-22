#include <bits/stdc++.h>
using namespace std;

class FenwickTree{
    vector<long long> tree;

public:
    FenwickTree(vector<long long> &arr){
        int n = arr.size();
        tree = vector<long long>(n+1, 0);

        for(int i=1; i<=n; ++i){
            tree[i] = arr[i-1];
            for(int j = i-1; j > i-(i&-i); j -= j&-j)
                tree[i] += tree[j];
        }
    }

    // 1-indexed
    long long query(int i){
        long long ans = 0;

        while(i){
            ans += tree[i];
            i -= i&-i;
        }

        return ans;
    }

    // 1-indexed inclusive
    long long query(int l, int r){
        return query(r) - query(l-1);
    }


    // 1-indexed
    void update(int i, long long delta){
        while(i < tree.size()) {
            tree[i] += delta;
            i += i & -i;
        }
    }

    void display(){
        for(auto it: tree)
            cout << it << " ";
        cout << endl;
    }

};