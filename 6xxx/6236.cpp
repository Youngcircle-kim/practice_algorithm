#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
ll a[100005];
ll st = 0;
ll en = 0;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        st = max(st, a[i]);
        en += a[i];
    }

    while(st < en){
        ll mid = st + (en - st)/2;

        ll cnt = 0;
        ll cur = 0;
        for(ll e : a){
            if(cur < e){
                ++cnt;
                cur = mid;
            }
            cur -= e;
        }
        if(cnt <= m) en = mid;
        else st = mid + 1;
    }
    cout << st;
}
