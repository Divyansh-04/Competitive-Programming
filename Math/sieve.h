#include <bits/stdc++.h>
using namespace std;

#ifndef CSES_SIEVE_H
#define CSES_SIEVE_H

#endif //CSES_SIEVE_H


const int N = 1e5;
bool is_prime[N + 1];

void initializeSieve(){
    memset(is_prime, 0, sizeof(is_prime));
    is_prime[2] = true;
    for (int i=3; i<=N; i+=2)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 3; i * i <= N; i+=2)
        if (is_prime[i])
            for (int j = i * i; j <= N; j += 2*i)
               is_prime[j] = false;
}

set<int> primeSet(){
    set<int> ans;
    for(int i=2; i<N; ++i)
        if(is_prime[i]) ans.insert(ans.end(), i);
    return ans;
}
