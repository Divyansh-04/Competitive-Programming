#include <bits/stdc++.h>
using namespace std;

vector<int> manacher(const string& arg){
    string s;
    for (auto c: arg) {
        s += string("#") + c;
    }
    s = '$' + s + string("#^");
    int n = s.size();

    vector<int> ans(n);
    int l=2, r=2;
    for(int i=2; i<n-2; ++i){
        long long temp = min(r-i, ans[l+ (r-i)]);
        ans[i] = max(0ll, temp);
        while(s[i-ans[i]] == s[i+ans[i]]) ++ans[i];

        if(i+ans[i] > r)
            l = i - ans[i],  r = i + ans[i];
    }

    return {ans.begin()+2, ans.end()-2};

}