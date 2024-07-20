#include <bits/stdc++.h>
using namespace std;


// Kahn's algorithm
vector<int> topological_sort(const vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> indegree(n, 0), ans;
    ans.reserve(n);

    for(int i=0; i<n; ++i)
        for(auto it: adj[i])
            ++indegree[it];

    queue<int> q;
    for(int i=0; i<n; ++i)
        if(!indegree[i]) q.push(i);

    while(!q.empty()){
        int top = q.front(); q.pop();
        for(auto it: adj[top]) {
            --indegree[it];
            if(!indegree[it]) q.push(it);
        }
        ans.push_back(top);
    }


    if(ans.size() != n)
        ans[0] = -1;

    return ans;
}