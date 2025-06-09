#include<bits/stdc++.h>
using namespace std;
int k;
int d[1004][4][4];
int r[1004], g[1004], b[1004];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;

    for(int i = 1; i <= k; i++) cin >> r[i] >> g[i] >> b[i];

    d[1][0][0] = r[1];
    d[1][1][0] = 1004;
    d[1][2][0] = 1004;

    d[1][0][1] = 1004;
    d[1][1][1] = g[1];
    d[1][2][1] = 1004;
    
    d[1][0][2] = 1004;
    d[1][1][2] = 1004;
    d[1][2][2] = b[1];

    for(int i = 2; i < k; i++){
        d[i][0][0] = min(d[i-1][1][0], d[i-1][2][0]) + r[i];
        d[i][1][0] = min(d[i-1][0][0], d[i-1][2][0]) + g[i];
        d[i][2][0] = min(d[i-1][0][0], d[i-1][1][0]) + b[i];

        d[i][0][1] = min(d[i-1][1][1], d[i-1][2][1]) + r[i];
        d[i][1][1] = min(d[i-1][0][1], d[i-1][2][1]) + g[i];
        d[i][2][1] = min(d[i-1][0][1], d[i-1][1][1]) + b[i];

        d[i][0][2] = min(d[i-1][1][2], d[i-1][2][2]) + r[i];
        d[i][1][2] = min(d[i-1][0][2], d[i-1][2][2]) + g[i];
        d[i][2][2] = min(d[i-1][0][2], d[i-1][1][2]) + b[i];

    }

    d[k][1][0] = min(d[k-1][0][0]+g[k],d[k-1][2][0]+g[k]);
    d[k][2][0] = min(d[k-1][0][0]+b[k],d[k-1][1][0]+b[k]);
    int minR = min(d[k][1][0], d[k][2][0]);

    d[k][0][1] = min(d[k-1][1][1]+r[k],d[k-1][2][1]+r[k]);
    d[k][2][1] = min(d[k-1][0][1]+b[k],d[k-1][1][1]+b[k]);
    int minG = min(d[k][0][1], d[k][2][1]);

    d[k][0][2] = min(d[k-1][1][2]+r[k],d[k-1][2][2]+r[k]);
    d[k][1][2] = min(d[k-1][0][2]+g[k],d[k-1][2][2]+g[k]);
    int minB = min(d[k][0][2], d[k][1][2]);

    cout << min(minB,min(minR, minG));
}
