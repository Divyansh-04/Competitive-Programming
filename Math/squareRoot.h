#include <bits/stdc++.h>
using namespace std;

double sqrt(double n){
    double high = n, low = 0, mid = (high+low)/2;

    while(abs(mid*mid - n ) > 1e-8 && high > low){
        if(mid*mid > n) high = mid;
        else low = mid;

        mid = (high+low)/2;
    }

    return mid;
}
