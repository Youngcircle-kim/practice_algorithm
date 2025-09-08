#include<bits/stdc++.h>
using namespace std;
int n;
int v[100005];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int ans1 = 1e9+1;
    int ans2 = 1e9+1;

    for(int i = 0; i < n; i++){
        int idx = lower_bound(v, v+n, -v[i]) - v;
        if(idx+1 < n && i != idx+1 && abs(v[i] + v[idx+1]) < abs(ans1 + ans2)){
            ans1 = v[i];
            ans2 = v[idx+1];
        }
        if(idx < n && i != idx && abs(v[i] + v[idx]) < abs(ans1 + ans2)){
            ans1 = v[i];
            ans2 = v[idx];
        }
        if(idx != 0 && i != idx-1 && abs(v[i] + v[idx-1]) < abs(ans1 + ans2)){
            ans1 = v[i];
            ans2 = v[idx-1];
        }
    }
    if(ans1 > ans2) swap(ans1, ans2);
    cout << ans1 << ' ' << ans2;
}
