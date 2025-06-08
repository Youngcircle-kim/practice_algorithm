#include<bits/stdc++.h>
using namespace std;
int mod = 1000000009;
int k, t;
long long d[1000004];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i = 4; i < 1000001; i++){
        d[i] = d[i-1] + d[i-2] + d[i-3];
        d[i] %= mod;
    }
    while(t--){
        cin >> k;
        cout << d[k] << "\n";
    }
}
