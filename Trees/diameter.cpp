#include <bits/stdc++.h>
using namespace std;

void fill_depth(vector<vector<int>> &adj, vector<int> &v, int node=0, int p=-1, int d = 0) {
    v[node] = d;
    for (int c: adj[node])
        if (c != p)
            fill_depth(adj, v, c, node, d+1);
}

void get_diameter_from_depth(vector<vector<int>> &adj, vector<int> &depth, vector<int>&path, int node, int p=-1) {
    path.push_back(node);
    if (!depth[node]) return;
    int nx = -1;
    for (int c: adj[node])
        if (c != p && (nx == -1 || depth[c] < depth[nx]))
            nx = c;
    get_diameter_from_depth(adj, depth, path, nx, node);
}

vector<int> diapath(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> depth(n, 0);
    fill_depth(adj, depth);
    int r = max_element(depth.begin(), depth.end()) - depth.begin();
    fill_depth(adj, depth, r);
    r = max_element(depth.begin(), depth.end()) - depth.begin();
    vector<int> path;
    get_diameter_from_depth(adj, depth, path, r);
    return path;
};

int main() {
    int n=1;
    vector<vector<int>> tree(n);




    return 0;
}

