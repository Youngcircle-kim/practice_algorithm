#include<bits/stdc++.h>
using namespace std;
int k;
int d[1004][4];
int r[1004], g[1004], b[1004];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k;

    for(int i = 1; i <= k; i++) cin >> r[i] >> g[i] >> b[i];
    
    d[1][0] = r[1];
    d[1][1] = g[1];
    d[1][2] = b[1];

    for(int i = 2; i <= k; i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + r[i];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + g[i];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + b[i];
    }

    cout << min(d[k][2],min(d[k][0], d[k][1]));
}
