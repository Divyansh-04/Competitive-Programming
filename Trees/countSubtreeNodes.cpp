#include <bits/stdc++.h>
using namespace std;

int count(vector<vector<int>> &adj, vector<int> &ans, int root=0){
    ans[root] = 1;
    for(auto child: adj[root]){
        if(ans[child]) continue;
        ans[root] += count(adj, ans, child);
    }

    return ans[root];
}

vector<int> subtreeNodes(vector<vector<int>> &adj, int root=0){
    int n = adj.size();
    vector<int> ans(n, 0);
    count(adj, ans);

    return ans;
}

