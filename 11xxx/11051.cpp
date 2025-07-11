#include<bits/stdc++.h>
using namespace std;
int comb[1005][1005];
int mod = 10007;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 1000; i++){
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j < i; j++){
            comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%mod;
        }
    }
    int n, m;
    cin >> n >>m;
    cout << comb[n][m];

}
