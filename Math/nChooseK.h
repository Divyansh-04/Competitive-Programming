#ifndef CSES_NCHOOSEK_H
#define CSES_NCHOOSEK_H
#endif //CSES_NCHOOSEK_H

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007ll, mod2 = 998244353ll;

long long binaryExp(long long b, long long e, long long m=mod){
    long long ans = 1;
    while(e) {
        if (e & 1)
            ans = ans * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return ans;
}

long long modInverse(long long n, long long m=mod){
    return binaryExp(n, m-2, m);
}


vector<int> fact(100001, 1);
void initiateFact(int m=mod){
    for(int i=2; i<fact.size(); ++i){
        fact[i] = fact[i-1]*i%m;
    }
}

long long nChoosek(int n, int k){
    if(k<0 || k>n) return 0;
    if(k==0 || k==n) return 1;
    if(k==1 || k==n-1) return n;
    return fact[n]* modInverse(fact[k]*fact[n-k]%mod2, mod2) %mod2;
}

