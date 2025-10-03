#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<long long, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#if LOCAL
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
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define PB(x) push_back(x);
#define MP make_pair
#define dbg(v)  cout << #v << " = " << (v) << endl;
#define sz(v) ((int)v.size())
auto nxt = [] {
    int x;
    cin >> x;
    return x;
};
constexpr long long mod = 1000000007ll, mod2 = 998244353ll, hmod = mod+2;

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
