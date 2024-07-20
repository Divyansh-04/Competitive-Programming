#include <bits/stdc++.h>

#ifdef LOCAL
#include "C:\Users\Divyansh Goel\CLionProjects\debugging.h"
#endif

using namespace std;

#define int long long
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using pi = pair<int, int>;
using vvi = vector<vector<int>>;
using vcb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using mi = map<int, int>;
using si = set<int>;



#define endl "\n"
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define fmap(name, x) mi name; for(auto it:x) ++name[it]
#define F first
#define S second
#define elif else if
#define PB push_back
#define MP make_pair
#define REPi(a, b) for (int i = a; i < b; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPO(a) for (int i =0; i < a; i++)
#define vvl(ab, r, c, v)  vvi ab(r, vector<int>(c, v))
#define dbg(v)  cout << "Line(" << _LINE_ << ") -> " << #v << " = " << (v) << endl;

pi farthest(vvi &adj, int root, vector<bool> &visited ){
    pi ans = {root, 0};
    visited[root] = true;
    for(auto it: adj[root]) {
        if (visited[it]) continue;
        pi temp = farthest(adj, it, visited);

        if(temp.second >= ans.second){
            ans.second = temp.second+1;
            ans.first = temp.first;
        }
    }

    return ans;
}

vi core_diameter(vvi &adj, int root, int target, vb&visited){
    visited[root] = true;
    if(root == target) return vi(1, target);

    for(auto node: adj[root]){
        if(visited[node]) continue;
        vi temp = core_diameter(adj, node, target, visited);
        if(temp.size()){
            temp.push_back(root);
            return temp;
        }
    }

    return vi(0);
}

vi get_diameter(vvi &adj){
    int n = adj.size();
    vb visited(n, false);
    pi end = farthest(adj, 0, visited);

    fill(visited.begin(), visited.end(), false);
    pi secend = farthest(adj, end.first, visited);

    fill(visited.begin(), visited.end(), false);
    vi d = core_diameter(adj, end.first, secend.first, visited);

    return d;
}