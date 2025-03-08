using namespace std;

const long long mod = 1000000007ll, mod2 = 998244353ll;

long long binaryExp(long long b, long long e, long long m=mod){
    long long ans = 1;
    while(e) {
        if (e & 1)
            ans = ans * b % m;
        b = b * b % m;
        b >>= 1;
    }
    return ans;
}

long long modInverse(long long n, long long m=mod){
    return binaryExp(n, m-2, m);
}