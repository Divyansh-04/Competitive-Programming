#include <bits/stdc++.h>
using namespace std;

int count(vector<vector<int>> &adj, vector<int> &ans, int node=0, int p=-1){
    for(auto c: adj[node]){
        if(c == p) continue;
        ans[node] += count(adj, ans, c, node);
    }

    return ans[node];
}

vector<int> subtreeNodes(vector<vector<int>> &adj, int root=0){
    int n = adj.size();
    vector ans(n, 1);
    count(adj, ans, root);

    return ans;
}

int main() {
    int n=1;
    vector<vector<int>> tree(n);

    vector<int> cnt(n, 1);
    auto subszdfs = [&](auto &&s, int node=0, int p=-1)->int {
        for (int c: tree[node])
            if (c!=p)
                cnt[node] += s(s, c, node);
        return cnt[node];
    };
    subszdfs(subszdfs);


    return 0;
}

