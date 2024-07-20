#include <bits/stdc++.h>
using namespace std;


int kadane(vector<long long> &v){
    long long ans = 0;
    long long curr = 0;
    for(auto i:v) {
        curr = max(i, curr + i);
        ans = max(ans, curr);
    }
    return ans;
}
