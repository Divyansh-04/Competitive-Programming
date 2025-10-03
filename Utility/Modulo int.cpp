#include <bits/stdc++.h>
using namespace std;

int constexpr mod = 1e9+7;

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

int inv(long long n, long long m=mod){
    return binaryExp(n, m-2, m);
}


class Mint{
public:
    static int m;
    int val = 0;
    Mint(){val = 0;}
    Mint(int x):val(x%m) {
        if (val < 0)
            val += m;
    }

    Mint &operator += (const Mint &b) {
        val = val+b.val;
        if (val >= m)
            val -= m;
        return *this;
    }
    Mint &operator -= (const Mint &b) {
        val = val-b.val+m;
        if (val < 0)
            val += m;
        return *this;
    }
    Mint &operator *= (const Mint &b) {
        val = val*b.val%m;
        return *this;
    }
    Mint &operator /= (const Mint &b) {
        val = val*inv(b.val)%m;
        return *this;
    }
    Mint &operator=(const Mint &b) {
        val = b.val;
        return *this;
    }

    Mint operator+ (const Mint &b) const { return Mint(*this) += b; }
    Mint operator- (const Mint &b) const { return Mint(*this) -= b; }
    Mint operator* (const Mint &b) const { return Mint(*this) *= b; }
    Mint operator/ (const Mint &b) const { return Mint(*this) /= b; }
    bool operator==(const Mint &b) const { return val == b.val; }

    Mint operator++(){
        ++val;
        if (val == m)
            val = 0;
        return (*this);
    }

    Mint operator++(int){
        val++;
        if (val == m)
            val = 0;
        return Mint(val - 1);
    }

    Mint operator--(){
        --val;
        if (val == -1)
            val = m - 1;
        return (*this);
    }

    Mint operator--(int){
        val--;
        if (val == -1)
            val = m - 1;
        return Mint(val + 1);
    }


    friend ostream& operator<<(ostream &out, Mint &a) {
        return out << a.val;
    }

    friend istream& operator>>(istream &in, Mint &a) {
        in >> a.val;
        a = Mint(a.val);
        return in;
    }
};
int Mint::m = mod;