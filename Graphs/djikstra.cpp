#include <bits/stdc++.h>
using namespace std;

vector<long long> djikstra(vector<vector<pair<int, long long>>> &adj, int s) { // adj[i] is vector of pair in form: {node, weight}
    int n = adj.size();
    vector ans(n, LLONG_MAX/2);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [cost, node]= pq.top();
        pq.pop();
        if (ans[node] != LLONG_MAX/2) continue;
        ans[node] = cost;
        for (auto &e: adj[node]) {
            if (ans[e.first] == LLONG_MAX/2) {
                pq.emplace(cost + e.second, e.first);
            }
        }
    }

    return ans;
}
