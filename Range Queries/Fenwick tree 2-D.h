#include <bits/stdc++.h>
using namespace std;


class FenwickTree2D{
    vector<vector<long long>> tree;
    int n, m;

public:
    FenwickTree2D(vector<vector<long long>> &arr){
        n = arr.size();
        m = arr[0].size();
        tree = vector<vector<long long>>(n+1, vector<long long>(n+1, 0));

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

    long long rowquery(int i, int j){
        long long ans = 0;
        while(j) {
            ans += tree[i][j];
            j -= j & -j;
        }
        return ans;
    }

    long long query(int i, int j){
        long long ans=0;
        int temp = i;
        while(temp){
            ans += rowquery(temp, j);
            temp -= temp&-temp;
        }

        return ans;
    }

    long long query(int i, int j, int x, int y){
        long long a, b, c, d;
        a = query(x, y);
        b = query(x, j-1);
        c = query(i-1, y);
        d = query(i-1, j-1);

        return a -b -c +d;
    }

    void updaterow(int i, int j, long long v){
        while(j<=m){
            tree[i][j] += v;
            j += j&-j;
        }
    }

    void update(int i, int j, long long v){
        while(i<=n){
            updaterow(i, j, v);
            i += i&-i;
        }
    }


    void display(){
        for(const auto& it: tree){
            for(auto jt: it) cout << jt << "\t";
            cout << endl;
        }
    }

};