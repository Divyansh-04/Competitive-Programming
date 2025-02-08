//
// Created by Divya on 09-02-2025.
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#ifdef LOCAL
#include "..\debugging.h"
#endif
#pragma GCC optimize("trapv")

#define int long long
using vi = vector<int>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
using pi = pair<int, int>;
using pd = pair<double, double>;
using vp = vector<pi>;
using vvi = vector<vi>;
using vvp = vector<vp>;
using mi = map<int, int>;
using si = set<int>;
using msi = multiset<int>;

#define endl "\n"
#define all(x) begin(x), end(x)
#define F first
#define S second
#define PB(x) push_back(x);
#define MP make_pair
#define dbg(v)  cout << #v << " = " << (v) << endl;
auto nxt = [] {
    int x;
    cin >> x;
    return x;
};

const long long mod = 1000000007ll, mod2 = 998244353ll;

#include "Range Queries\SegmentTree.h"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int &i : arr) cin >> i;

    SegmentTree<int> tree(arr);

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            tree.update(u-1, v);
        }
        else {
            cout << tree.query(u-1, v-1) << endl;
        }
    }

    return 0;
}
