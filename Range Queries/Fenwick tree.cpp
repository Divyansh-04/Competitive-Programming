#include <bits/stdc++.h>
using namespace std;

class fenwick_tree{
    vector<long long> tree;

public:
    fenwick_tree(vector<long long> &arr){
        int n = arr.size();
        tree = vector<long long>(n+1, 0);

        for(int i=1; i<=n; ++i){
            tree[i] = arr[i-1];

            for(int temp = i-1; temp > i-(i&-i); temp -= temp&-temp)
                tree[i] += tree[temp];
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

    // 1-indexed
    long long query(int l, int r){
        return query(r) - query(l-1);
    }


    // 1-indexed
    void update(int i, long long delta){
        for(int k= i&-i; i < tree.size(); k<<=1){
            tree[i] += delta;
            i += k;
        }
    }

    void display(){
        for(auto it: tree)
            cout << it << " ";
        cout << endl;
    }

};