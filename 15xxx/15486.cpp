#include<bits/stdc++.h>
using namespace std;
int t[1500004], p[1500004];
int d[1500004];
int n;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> t[i] >> p[i];
    
    for(int i = 1; i <= n; i++){
        if(i + t[i] <= n+1){
            d[i+t[i]] = max(d[i+t[i]], d[i] + p[i]);
        }
        d[i+1] = max(d[i+1], d[i]);
    }

    cout << d[n+1];
}
