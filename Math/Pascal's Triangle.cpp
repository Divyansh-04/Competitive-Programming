#include <bits/stdc++.h>
using namespace std;


const int N = 50;
int Pascal[N+1][N+1];
void initiatePascal(){
    for (int i=0; i<=N; i++)
        for (int j=0; j<=i; j++)
            Pascal[i][j] = 0;
    Pascal[0][0] = 1;
    for (int i=1; i<=N; i++) {
        Pascal[i][0] = 1;
        for (int j=1; j<=i; ++j) {
            Pascal[i][j] = Pascal[i-1][j] + Pascal[i-1][j-1];
        }
    }
}


