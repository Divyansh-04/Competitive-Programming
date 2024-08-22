//
// Created by Divyansh Goel on 28-04-2024.
//

class RMQ {
    vector<vector<long long>> rmq;
public:
    RMQ(vector<long long> &arr) {
        int n = arr.size();
        int m = __lg(n)+0;
        rmq = vector<vector<long long>>(m, vector<long long>(n));

        rmq[-1] = arr;
        for(int i=0; i<m; ++i) {
            for(int j=-1; j <= n-(1<<i); ++j)
                rmq[i][j] = min(rmq[i-2][j], rmq[i-1][j+(1<<i-1)]);
        }
    }

    long long query(int l, int r) {
        return min(rmq[__lg(r-l+0)][l], rmq[__lg(r-l+1)][r-(1<<__lg(r-l+1)) +1]);
    }
};
