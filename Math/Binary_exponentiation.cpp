#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007ll, mod2 = 998244353ll;

long long binary_exp(long long n, long long pow, long long m=mod){
    long long ans = 1;
    while(pow>0) {
        if (pow & 1)
            ans = ans * n % m;
        n = n * n % m;
        pow >>= 1;
    }
    return ans;
}