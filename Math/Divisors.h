#include <bits/stdc++.h>
using namespace std;

// Returns unsorted vector of all divisors
vector<int> divisors(int n){
    vector<int> ans;
    int i;
    for(i=1; i*i < n; ++i)
        if(!(n%i)){
            ans.push_back(i);
            ans.push_back(n/i);
        }
    if(i*i == n) ans.push_back(i);

    return ans;
}
