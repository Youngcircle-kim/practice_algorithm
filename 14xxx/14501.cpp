#include<bits/stdc++.h>
using namespace std;
int t[20], p[20];
int d[20];
int n;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <=n; i++) cin >> t[i] >> p[i];
    d[0] = 0;
    for(int i = 0; i <= n; i++){
        if(i + t[i] <= n+1){
            d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
        }
        d[i+1] = max(d[i+1], d[i]);
    }
    cout << d[n+1];
}
