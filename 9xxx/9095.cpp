#include<bits/stdc++.h>
using namespace std;
int d[13];
int t,k;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    d[1] = 1; d[2] = 2; d[3] = 4;
    for(int i = 4; i < 12; i++){
        d[i] = d[i-3] + d[i-2] + d[i-1];
    }

    cin >> t;

    while (t--){
        cin >> k;
        cout << d[k] << "\n";
    }
}
