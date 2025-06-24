#include<bits/stdc++.h>
using namespace std;
int n, k, v;
int d[10005];
vector<int> vv;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(d, d+10004, 100004);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> v;
        if(v >= 10000) continue;
        d[v] = 1;
        vv.push_back(v);
    }
    d[0] = 1;
    for(int i = 1; i <= k; i++){
        for(auto e : vv){
            if(i- e < 0 || e >= 10000){
                continue;
            }
            d[i] =min(d[i] ,d[e]+d[i-e]); 
        }
    }
    if(d[k] == 100004){
        cout << -1;
        return 0;
    }
    cout << d[k];
}
