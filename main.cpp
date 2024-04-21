#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "C:\Users\Divyansh Goel\CLionProjects\debugging.h"
#endif

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
#define F first
#define S second
#define elif else if
#define PB push_back
#define MP make_pair
#define REPi(a, b) for (int i = a; i < b; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPO(a) for (int i =0; i < a; i++)
#define vvl(ab, r, c, v)  vvi ab(r, vector<int>(c, v))
#define dbg(v)  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


const int mod = 1000000007ll, mod2 = 998244353ll;
static vb DEFAULT_BOOL_VECTOR;
static vi DEFAULT_INT_VECTOR;





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

int kadane(vi &v){
    int ans = 0;
    int curr = 0;
    for(auto i:v) {
        curr = max(i, curr + i);
        ans = max(ans, curr);
    }
    return ans;
}

int count_nodes(vvi &adj, vi &ans=DEFAULT_INT_VECTOR, int root=0){
    int n = adj.size();
    if(ans == DEFAULT_INT_VECTOR)
        ans = vi (n, 0);


    ans[root] = 1;
    for(auto it: adj[root]){
        if(ans[it]) continue;
        ans[root] += count_nodes(adj, ans, it);
    }

    return ans[root];
}

static vector<int> topological_sort(const vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> indegree(n, 0), ans; ans.reserve(n);

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


class staticarrayminquery{
    vvi data;
    int n=64, m;
public:
    staticarrayminquery(vi &arr){
        m = arr.size();

        data = vvi(n, vi(m));

        for(int i=0; i<m; ++i){
            data[0][i] = arr[i];
        }

        for(int i=1; i<n; ++i){
            for(int j=0; j<m-(1<<i)+1; ++j){
                data[i][j] = min(data[i-1][j], data[i-1][j]);
            }
        }




    }
};

class DSU {
public:
    vector<int> representative;
    vector<int> size;

    DSU(int sz) : representative(sz), size(sz, 1) {
        iota(representative.begin(), representative.end(), 0);
    }

    // Finds the representative of group x
    int findRepresentative(int x) {
        if (x == representative[x]) {
            return x;
        }

        // This is path compression
        return representative[x] = findRepresentative(representative[x]);
    }

    // Unite the group that contains "a" with the group that contains "b"
    void unionBySize(int a, int b) {
        int representativeA = findRepresentative(a);
        int representativeB = findRepresentative(b);

        // If nodes a and b already belong to the same group, do nothing.
        if (representativeA == representativeB) {
            return;
        }

        // Union by size: point the representative of the smaller
        // group to the representative of the larger group.
        if (size[representativeA] >= size[representativeB]) {
            size[representativeA] += size[representativeB];
            representative[representativeB] = representativeA;
        } else {
            size[representativeB] += size[representativeA];
            representative[representativeA] = representativeB;
        }
    }
};


signed main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
    int n, k;
    cin >> n >> k;

    int arr[n];
    fill(arr, arr+n, 1);

    int curr = n, slow = 0, fast = k%curr;

    while(curr){
        cout << fast+1 << " ";
        int ss = 1, fs = 2;
        --curr;
        arr[fs] = 0;
        while(ss){
            slow = (slow+1)%curr;
            if(arr[slow]) --ss;
        }
        while(fs){
            fast = (fast+1)%curr;
            if(arr[slow]) --fs;
        }

    }





//    int t;
//    cin >> t;
//    while(t--){
//        int n, c, s, m;
//        cin >> n >> c >> s >> m;
//        vi v(n);
//        REPO(n) cin >> v[i];
//
//
//
//
//    }


    return 0;
}

