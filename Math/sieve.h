#include <bits/stdc++.h>
using namespace std;

#ifndef CSES_SIEVE_H
#define CSES_SIEVE_H

#endif //CSES_SIEVE_H


int N = 1e5;
vector<bool> is_prime(N + 1, true);

void initializeSieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++)
        if (is_prime[i])
            for (int j = i * i; j <= N; j += i)
               is_prime[j] = false;
}

set<int> primeSet(){
    set<int> ans;
    for(int i=2; i<N; ++i)
        if(is_prime[i]) ans.insert(ans.end(), i);
    return ans;
}