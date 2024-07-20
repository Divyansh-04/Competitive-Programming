using namespace std;

const long long mod = 1000000007ll, mod2 = 998244353ll;

long long binaryExp(long long n, long long pow, long long m=mod){
    long long ans = 1;
    while(pow>0) {
        if (pow & 1)
            ans = ans * n % m;
        n = n * n % m;
        pow >>= 1;
    }
    return ans;
}

long long modInverse(long long n, long long m=mod){
    return binaryExp(n, m-2, m);
}