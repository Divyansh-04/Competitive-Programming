#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
class FenwickTree2D{ // inner functions are 1-indexed, 2d functions are made 0-indexed
    vector<vector<long long>> tree;
    int n, m;

public:
    FenwickTree2D(int _n, int _m){
        n = _n, m = _m;
        tree = vector(n+1, vector<long long>(n+1, 0));
    }


    FenwickTree2D(vector<vector<long long>> &arr){
        n = arr.size();
        m = arr[0].size();
        tree = vector(n+1, vector<long long>(n+1, 0));

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                tree[i][j] = arr[i-1][j-1];
                for(int temp = j-1; temp> j-(j&-j); temp -= temp&-temp)
                    tree[i][j] += tree[i][temp];
            }
        }

        for(int i=1; i<=n; ++i)
            for(int j=1; j<= m; ++j)
                for(int temp = i-1; temp>i-(i&-i); temp -= temp&-temp)
                    tree[i][j] += tree[temp][j];

    }

    long long rowquery(int i, int j){ // sum till j of row i
        long long ans = 0;
        while(j) {
            ans += tree[i][j];
            ans %= mod;
            j -= j & -j;
        }
        return ans;
    }

    long long query(int i, int j){ // sum of square till (i, j)
        long long ans=0;
        int temp = i;
        while(temp){
            ans += rowquery(temp, j);
            ans %= mod;
            temp -= temp&-temp;
        }

        return ans;
    }

    long long query(int i, int j, int x, int y){
        ++i, ++j, ++x, ++y;                             // makes it 0 indexed
        long long a, b, c, d;
        a = query(x, y);
        b = query(x, j-1);
        c = query(i-1, y);
        d = query(i-1, j-1);

        return (a -b -c +d +mod)%mod;
    }

    void update(int i, int j, long long v){ // update ele i, j
        ++i, ++j;                                       // makes it 0 indexed
        for(;j<=m; j+=j&-j)
            for (; i<=n; i+=i&-i) {
                tree[i][j] += v;
                tree[i][j] %= mod;
            }
    }


    void display(){
        for(const auto& it: tree){
            for(auto jt: it) cerr << jt << "\t";
            cerr << endl;
        }
    }

    void display_base() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++)
                cerr << query(i, j, i, j) << " ";
            cerr << endl;
        }
        cerr << endl;
    }
};